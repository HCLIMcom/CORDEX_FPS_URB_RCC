#!/bin/bash

#######################################################################
####                                                               ####
####            processing variables from netcdf files             ####
####                         CORDEX format                         ####
####                              fix                              ####
####                                                               ####
#######################################################################

echo
echo ---------------------------------------------------------------------------------------------------------------------
echo
echo ' '     HCLIM CMORise - fix
echo
echo ---------------------------------------------------------------------------------------------------------------------
echo

# --- load Modules ---
module load python3
module load cdo/1.9.8
module load nco
module load netcdf4/4.9.3

# Modules. Can be conflicts with conda installation
# See output for binaries used.
echo
echo Loaded modules:
echo

echo "- cdo    :" `which cdo`
echo "- netcdf :" `which nccopy`
echo "- nco    :" `which ncatted`
echo
echo ---------------------------------------------------------------------------------------------------------------------
echo

# -------------------
# - WORK DIRECTORY --
# -------------------

CMOR_dir=$1;

export DIRECTORY_META=$CMOR_dir/meta/
export DIRECTORY_CONFIG=$CMOR_dir/config/
export DIRECTORY_PYTHON=$CMOR_dir/scripts/

# --------------------
# --- SIMULATIONS  ---
# --------------------
run_in=($2); shift 2

# --------------------
# ---   VARIABLES  ---
# --------------------
var_in=("$@")

# ---------------------------------------
# --- NUMBER OF YEARS in OUTPUT FILES ---
# ---------------------------------------
# - Daily: 5yr
# - 3H/6H: 1yr
# - 1H: 1yr

sy_in=1

# -----------------------------------------
# --- Crop domain (relaxation zone; 8 points)
# --- trim: Specify how many points to remove
# -----------------------------------------
trim=8

# --------------------
# --- PREPARATION  ---
# --------------------

# --- META INFO ---
path_meta=$DIRECTORY_META     # path to meta files
cdo='cdo -s'

# --- Number of variables, runs etc..  ---
num_var=${#var_in[@]}
num_run=${#run_in[@]}

# --------------------
# ---  MAIN BLOCK  ---
# --------------------
echo
beg_time="$(date +%s)"

# --- SIMULATION LOOP ---
for ((run=0;run<=num_run-1;run++)); do

    # --- read simulation info ---
    file_run=$DIRECTORY_CONFIG'config_experiment'
    . $file_run

    # Temporary folder
    path_tmp=$path_out/tmp/

    mkdir -p $path_tmp

    if [ ! -d "$path_out" ]; then
        echo ... "$path_out"
        echo ... OUTPUT PATH DOESN*T EXIST TERMINATED !!!!!!
        exit
    fi

    # First year of simulation
    year=$first_year
    month=01

    # ---------------------
    # --- VARIABLE LOOP ---
    # ---------------------
    for ((var=0;var<=num_var-1;var++)); do   # variable loop

        # --- read variable info (SMHI) ---
        file_var=$path_meta'harmonie_var_info_cordex.txt'
        . $file_var

        bft="$(date +%s)"

        case ${var_in[$var]} in
         
            mrsofc )
                python3 $DIRECTORY_PYTHON/mrsofc.py $path_in$year'/'$month'/01/00/' $path_meta/${domain_hclim}_soil_depth.nc
                                
                file_in=$path_in$year'/'$month'/01/00/'$harm_name'_clim_'$domain_hclim'_'$exp_name'_fx.nc';;
            * )
                file_in=$path_in$year'/'$month'/01/00/'$harm_name'_clim_'$domain_hclim'_'$exp_name'_fx.nc';;
        esac


        # --- output and temporary files ---
        file_out=$path_tmp${var_in[$var]}'_'$domain_id'_'$driving_source_id'_'$experiment_id'_'$experiment_version'_'$source_id'_fx.tmp.nc'
        file_tmp0=$path_tmp'tmp0_'${var_in[$var]}'_'$domain_id'_'$driving_source_id'_'$experiment_id'_'$experiment_version'_'$source_id'_fx.tmp.nc'
        file_tmp1=$path_tmp'tmp1_'${var_in[$var]}'_'$domain_id'_'$driving_source_id'_'$experiment_id'_'$experiment_version'_'$source_id'_fx.tmp.nc'
        file_tmp2=$path_tmp'tmp2_'${var_in[$var]}'_'$domain_id'_'$driving_source_id'_'$experiment_id'_'$experiment_version'_'$source_id'_fx.tmp.nc'

        # --- remove output and temporary files ---
        [ -f $file_out ] && rm $file_out
        [ -f $file_tmp0 ] && rm $file_tmp0
        [ -f $file_tmp1 ] && rm $file_tmp1
        [ -f $file_tmp2 ] && rm $file_tmp2

        # --- post-processing info ---
        echo ... VARIABLE NETCDF      ' '... ${var_in[$var]} '|' ${st_name} '|' ${long_name} '|' ${units} '|'
        echo ... SIMULATION    '      '... ${run_in[$run]} '|' $domain_id '|' $experiment_id '|' $driving_experiment_id '|' $experiment_version '|' $source_id '|'
        echo ... OUTPUT PATH  '    ' ... $path_out
        echo ... TEMPORARY FILE   ' ' ... $file_out
        echo

        if [ -f $file_in ]; then
            
            echo ... now processing ... $file_in

            case ${var_in[$var]} in

                sftlf)

                    echo ... Land sea mask ...
                    file_nat=$file_in
                    file_urb=${file_in/'sftnf_'/'sfturf_'}

                    echo ... 'Nature            ' ... $file_nat
                    echo ... 'Urban             ' ... $file_urb

                    $cdo -L -chname,sftnf,${var_in[$var]} -enssum $file_nat $file_urb $file_tmp1
                    $cdo -L cat -selname,sftlf $file_tmp1 $file_tmp0
                    [ -f $file_tmp1 ] && rm $file_tmp1;;

                *)
                   $cdo -L cat -selname,$harm_name $file_in $file_tmp0;;

            esac

        else
            echo ... not exists $file_in
        fi

        if [ -f "$file_tmp0" ]; then
            echo
            echo
            echo ... FINALIZING FILE ... $file_out
            echo
            end_ct="$(date +%s)"

            mv $file_tmp0 $file_out

            # -----------------------------------
            # ---------  COORDINATES  -----------
            # -----------------------------------
            ncatted -a long_name,lon,o,c,"longitude" -h $file_out
            ncatted -a long_name,lat,o,c,"latitude" -h $file_out
            ncatted -a _CoordinateAxisType,lon,d,, -h $file_out
            ncatted -a _CoordinateAxisType,lat,d,, -h $file_out


            # -----------------------------------
            # ---------  FLOAT --> DOUBLE -------
            # -----------------------------------
            ncap2 -O -h -s "lon=double(lon); lat=double(lat); x=double(x); y=double(y);" $file_out $file_out

            # -------------------------------------------------
            # --- TRIM POINTS: TOP/BOTTOM and LEFT/RIGHT  ---
            # -------------------------------------------------
            if [ $trim !=  0 ]; then
                xx=`ncdump -h ${file_out} | grep -w "x ="`
                xx=${xx/"x = "/""}
                xx=${xx/" ;"/""}
                xx=${xx//[[:blank:]]/}

                yy=`ncdump -h ${file_out} | grep -w "y ="`
                yy=${yy/"y = "/""}
                yy=${yy/" ;"/""}
                yy=${yy//[[:blank:]]/}

                x1=$(( $trim+1 ))
                y1=$(( $trim+1 ))
                x2=$(( $xx-$trim ))
                y2=$(( $yy-$trim ))

                echo
                echo --------------------------------------
                echo ...   CROPPING DOMAIN
                echo "... Dimensions before; x-y:" $xx"-"$yy
                echo "... Dimensions after;  x-y:" $(( $x2-$trim ))"-"$(( $y2-$trim ))
                echo ---------------------------------------

                ncks -O -h -F -d x,$x1,$x2 -d y,$y1,$y2 $file_out $file_out
            fi

            # ---------------------------
            # --- VARIABLE ATTRIBUTES ---
            # ---------------------------

            ncatted -a table,${var_in[$var]},d,, \
                -a standard_name,${var_in[$var]},o,c,"${st_name}" \
                -a long_name,${var_in[$var]},o,c,"${long_name}" \
                -a units,${var_in[$var]},o,c,"${units}" -h $file_out
            ncatted -a FA_name,${var_in[$var]},d,, \
                -a lev,${var_in[$var]},d,, \
                -a lvt,${var_in[$var]},d,, \
                -a par,${var_in[$var]},d,, \
                -a tri,${var_in[$var]},d,, -h $file_out

            # -------------------------
            # --- GLOBAL ATRIBUTES  ---
            # -------------------------
            ncatted -a Conventions,global,d,, \
                -a title,global,d,, \
                -a domain,global,d,, \
                -a comment,global,d,, \
                -a model_id,global,d,, \
		-a driving_model_id,global,d,, \
                -a institute_id,global,d,, \
                -a activity_id,global,o,c,"$activity_id" \
                -a contact,global,o,c,"$contact" \
                -a creation_date,global,o,c,"$( date +%Y'-'%m'-'%d'-T'%T'Z')" \
                -a domain_id,global,o,c,"$domain_id" \
                -a domain,global,o,c,"$domain" \
                -a driving_experiment_id,global,o,c,"$driving_experiment_id" \
                -a driving_experiment,global,o,c,"$driving_experiment" \
                -a driving_institution_id,global,o,c,"$driving_institution_id" \
                -a driving_institution,global,o,c,"$driving_institution" \
                -a driving_source_id,global,o,c,"$driving_source_id" \
                -a driving_variant_label,global,o,c,"$driving_variant_label" \
                -a experiment_id,global,o,c,"$experiment_id" \
                -a experiment,global,o,c,"$experiment" \
                -a frequency,global,o,c,"fx" \
                -a grid,global,o,c,"$grid_info" \
	  	-a institution_id,global,o,c,"$institution_id" \
                -a institution,global,o,c,"$institution" \
                -a mip_era,global,o,c,"CMIP6" -h $file_out

            if [[ "$nested" == "TRUE" ]]; then
                ncatted -a parent_source,global,o,c,"$parent_source" \
                -a parent_source_id,global,o,c,"$parent_source_id" \
                -a parent_source_type,global,o,c,"$parent_source_type" \
                -a parent_domain_id,global,o,c,"$parent_domain_id" -h $file_out
            fi

            ncatted -a product,global,o,c,"model-output" \
                -a project_id,global,o,c,"$project_id" \
                -a realm,global,o,c,"$realm" \
                -a source_id,global,o,c,"$source_id" \
                -a source,global,o,c,"$source" \
                -a source_type,global,o,c,"$source_type" \
                -a version_realization,global,o,c,"$experiment_version" \
                -a variable_id,global,o,c,"$harm_name" \
                -a tracking_id,global,o,c,"$(python3 $DIRECTORY_PYTHON/get_uuid.py)" \
                -a license,global,o,c,"https://cordex.org/data-access/cordex-cmip6-data/cordex-cmip6-terms-of-use" \
                -a comment,global,o,c,"$comment" -h $file_out

            # Create var folder if it's not exits
            if [ ! -d "${path_out}/fx/${var_in[$var]}" ]; then
                echo " "
                echo "... Creating variable folder in path: ${path_out}/fx/${var_in[$var]}"
                echo " "
                mkdir -p ${path_out}/fx/${var_in[$var]} || { echo 'Could not create folder, terminated!' ; exit 1; }
            fi

            # -------------------------------------
            # ---  DATES in FILE NAME: YYYYMMDD ---
            # -------------------------------------
            file_cordex=$path_out/fx/${var_in[$var]}/${var_in[$var]}'_'$domain_id'_'$driving_source_id'_'$driving_experiment_id'_'$driving_variant_label'_'$institution_id'_'$source_id'_'$experiment_version'_fx.nc'


            # --------------------------------
            # ---       OUTPUT FILE        ---
            # --------------------------------
            echo
            echo ...  WRITING OUTPUT FILE ' ' ... $file_cordex
            echo

            nccopy -k 4 -d 1 -s $file_out $file_cordex
            [ -f $file_out ] && rm $file_out


            # --------------------------------
            # --- REMOVE GLOBAL ATTRIBUTES ---
            # --------------------------------
            ncatted -a history,global,d,, \
                -a CDI,global,d,, \
                -a CDO,global,d,, \
                -a NCO,global,d,, -h $file_cordex

            # --------------------------------
            # ---  REMOVE TEMPORARY FILES  ---
            # --------------------------------
            [ -f $file_out ] && rm $file_out
            [ -f $file_tmp0 ] && rm $file_tmp0
            [ -f $file_tmp1 ] && rm $file_tmp1
        else
            echo ... TEMPORARY FILE does not exist $file_tmp0
        fi # if file_out exists

        echo
        echo ... CONVERSION TIME: "$(expr $end_ct - $bft)" sec
        end_ft="$(date +%s)"
        echo ... FORMATTING TIME: "$(expr $end_ft - $end_ct)" sec
        eft="$(date +%s)"
        echo ... '   'ELAPSED TIME: "$(expr $eft - $bft)" sec
        echo
        echo ---------------------------------------------------------------------------------------------------------------------
        echo

    done  # variable loop
done  # simulation loop

end_time="$(date +%s)"
echo ELAPSED TOTAL TIME: "$(expr $end_time - $beg_time)" sec
echo
echo "END"
