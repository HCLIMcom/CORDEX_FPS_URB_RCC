#!/bin/bash

#######################################################################
####                                                               ####
####            processing variables from netcdf files             ####
####                         CORDEX format                         ####
####                        daily statistics                       ####
####                                                               ####
#######################################################################

echo
echo ---------------------------------------------------------------------------------------------------------------------
echo
echo ' '     HCLIM CMORise - day
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
ref_time='1950-01-01,00:00'   # reference time
mm_s=(01 02 03 04 05 06 07 08 09 10 11 12 01) # months
cdo='cdo -s'
freq=day

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

    # ----------------------------
    #---- FIRST and LAST YEARS ---
    # ----------------------------

    # Separat the spinup year (first year)
    fy_in=($first_year $(($first_year + 1)))
    ly_in=($first_year $last_year)

    # ---------------------------------------
    # --- NUMBER OF YEARS in OUTPUT FILES ---
    # ---------------------------------------
    # - Monthly: 10yr
    # - Daily: 5yr
    # - 3H/6H: 1yr
    # - 1H: 1yr

    # The spinup year is treated separately
    sy_in=(1 5)

    num_fy=${#sy_in[@]}

    # ---------------------
    # --- VARIABLE LOOP ---
    # ---------------------
    for ((var=0;var<=num_var-1;var++)); do   # variable loop

        # --- read variable info (SMHI) ---
        file_var=$path_meta'harmonie_var_info_cordex.txt'
        . $file_var

        # --- unset output frequency related varibales ---
        unset ts1_time ts2_time ts1_hh ts2_hh ts1_mm ts2_mm delta_hh delta_mm delta_ss shift_ss shift_ts


        # --- YEAR LOOP ---
        for ((nn=0;nn<num_fy;nn++)); do

            fy=${fy_in[$nn]}
            ly=${ly_in[$nn]}
            sy=${sy_in[$nn]}

            year_p=$(($ly - $fy + 1))  # number of years

            # --- number of output files ----
            if [ $sy -eq 0 ]; then
                sy=$year_p
                file_p=1
            else
                file_p=$((year_p/sy))
                if [ $((year_p%sy)) -ne 0 ]; then
                    file_p=$((file_p+1))
                fi
            fi


            # -----------------------
            # ---  CDO operation  ---
            # -----------------------

            # --- OUTPUT FILE LOOP ---
            for ((ff=1;ff<=file_p;ff++)); do

                bft="$(date +%s)"

                # --- first and last year in output file ---
                fy_out=$((fy+(ff-1)*sy)) #  first year in output file
                ly_out=$((fy_out+sy-1))  #  last year in output file

                # --- output and temporary files ---
                file_out=$path_tmp${var_in[$var]}'_'$domain_id'_'$driving_source_id'_'$experiment_id'_'$experiment_version'_'$source_id'_'$fy_out'-'$ly_out'.tmp.nc'
                file_tmp0=$path_tmp'tmp0_'${var_in[$var]}'_'$domain_id'_'$driving_source_id'_'$experiment_id'_'$experiment_version'_'$source_id'_'$fy_out'-'$ly_out'.tmp.nc'
                file_tmp1=$path_tmp'tmp1_'${var_in[$var]}'_'$domain_id'_'$driving_source_id'_'$experiment_id'_'$experiment_version'_'$source_id'_'$fy_out'-'$ly_out'.tmp.nc'
                file_tmp2=$path_tmp'tmp2_'${var_in[$var]}'_'$domain_id'_'$driving_source_id'_'$experiment_id'_'$experiment_version'_'$source_id'_'$fy_out'-'$ly_out'.tmp.nc'

                # --- remove output and temporary files ---
                [ -f $file_out ] && rm $file_out
                [ -f $file_tmp0 ] && rm $file_tmp0
                [ -f $file_tmp1 ] && rm $file_tmp1
                [ -f $file_tmp2 ] && rm $file_tmp2

                # --- post-processing info ---
                echo ... VARIABLE NETCDF      ' '... ${var_in[$var]} '|' ${st_name} '|' ${long_name} '|' ${units} '|' ${cell_methods}
                echo ... SIMULATION    '      '... ${run_in[$run]} '|' $domain_id '|' $experiment_id '|' $driving_experiment_id '|' $experiment_version '|' $source_id '|'  $fy_out'-'$ly_out '|'
                echo ... OUTPUT PATH  '    ' ... $path_out
                echo ... TEMPORARY FILE   ' ' ... $file_out
                echo

                # --- YEAR LOOP ---
                for ((yy=fy_out;yy<=ly_out;yy++)); do
                    # --- MONTH LOOP ---
                    for mm in 0 1 2 3 4 5 6 7 8 9 10 11; do

			if [ $mm -eq 11 ]; then
				yynext=$((yy + 1))
			else
				yynext=$yy
			fi

                        case ${var_in[$var]} in

                            z0 | tastown | taswater | ts \
                               | tsskin | tspav | tsroof | tsgree | tswater )
                            
                                file_in=$path_in$yy'/'${mm_s[$mm]}'/01/00/'$harm_name'_sfx_'$domain_hclim'_'$exp_name'_1hr_'$yy${mm_s[$mm]}'010000-'$yynext${mm_s[$mm+1]}'010000.nc';;

			    anthroheat )

				python3 $DIRECTORY_PYTHON/anthroheat.py $path_in$yy'/'${mm_s[$mm]}'/01/00/'

                                file_in=$path_in$yy'/'${mm_s[$mm]}'/01/00/'$harm_name'_corrected_sfx_'$domain_hclim'_'$exp_name'_1hr_'$yy${mm_s[$mm]}'010000-'$yynext${mm_s[$mm+1]}'010000.nc';;
				
                            taspav | tasgree | tascan | hurscan | husscan | sfcWindcan )

                                python3 $DIRECTORY_PYTHON/building_height.py $path_in$yy'/'${mm_s[$mm]}'/01/00/'$harm_name'_sfx_'$domain_hclim'_'$exp_name'_1hr_'$yy${mm_s[$mm]}'010000-'$yynext${mm_s[$mm+1]}'010000.nc' $path_meta/${domain_hclim}_covers.nc

                                file_in=$path_in$yy'/'${mm_s[$mm]}'/01/00/'$harm_name'_height_sfx_'$domain_hclim'_'$exp_name'_1hr_'$yy${mm_s[$mm]}'010000-'$yynext${mm_s[$mm+1]}'010000.nc';;

                            tsl )

                                python3 $DIRECTORY_PYTHON/tsl.py $path_in$yy'/'${mm_s[$mm]}'/01/00/' $path_meta/${domain_hclim}_soil_depth.nc
                                
                                file_in=$path_in$yy'/'${mm_s[$mm]}'/01/00/'$harm_name'_sfx_'$domain_hclim'_'$exp_name'_6hr_'$yy${mm_s[$mm]}'010000-'$yynext${mm_s[$mm+1]}'010000.nc';;

                            ua[0-9][0-9][0-9][0-9] | ua[0-9][0-9][0-9] | va[0-9][0-9][0-9][0-9] | va[0-9][0-9][0-9] \
                               | ta[0-9][0-9][0-9][0-9] | ta[0-9][0-9][0-9] | zg[0-9][0-9][0-9][0-9] | zg[0-9][0-9][0-9])
                                file_in=$path_in$yy'/'${mm_s[$mm]}'/01/00/'$harm_name'_fp_'$domain_hclim'_'$exp_name'_6hr_'$yy${mm_s[$mm]}'010000-'$yynext${mm_s[$mm+1]}'010000.nc';;

                            clt | evspsbl | hfls | hfss | rsds | rlds | pr | prsn | prc)
                                file_in=$path_in$yy'/'${mm_s[$mm]}'/01/00/'$harm_name'_fp_'$domain_hclim'_'$exp_name'_day_'$yy${mm_s[$mm]}'010000-'$yynext${mm_s[$mm+1]}'010000.nc';;

                            *)
                                file_in=$path_in$yy'/'${mm_s[$mm]}'/01/00/'$harm_name'_fp_'$domain_hclim'_'$exp_name'_1hr_'$yy${mm_s[$mm]}'010000-'$yynext${mm_s[$mm+1]}'010000.nc';;
                        esac

                        #----------------------------------
                        # --- FREQUENCY in INPUT FILES ----
                        #----------------------------------
                        if [ ${#ts1_time} -eq 0 -o ${#ts1_time} -eq 0 -o ${#delta_hh} -eq 0  ]; then
                            ts1_time=`$cdo showtime -seltimestep,1 $file_in`; ts1_hh=${ts1_time:1:2}; ts1_mm=${ts1_time:4:2};
                            ts2_time=`$cdo showtime -seltimestep,2 $file_in`; ts2_hh=${ts2_time:1:2}; ts2_mm=${ts2_time:4:2};

                            echo --------------------------------
                            echo ... OUTPUT FREQUENCY ...
                            echo ... 1st step time ... $ts1_time
                            echo ... 2nd step time ... $ts2_time
                            echo
                            echo ... 1st step hour ... $ts1_hh
                            echo ... 2nd step hour ... $ts2_hh
                            echo
                            echo ... 1st step mins ... $ts1_mm
                            echo ... 2nd step mins ... $ts2_mm
                            echo

                            delta_hh=$(( $ts2_hh-$ts1_hh ))
                            delta_mm=$(( $ts2_mm-$ts1_mm ))

                            echo ... delta hour ... $delta_hh
                            echo ... delta mins ... $delta_mm

                            delta_ss=$(( 3600*$delta_hh+60*$delta_mm ))
                            shift_ss=$(( $delta_ss/2 ))
                            shift_ts=$shift_ss'sec'
                            echo ... delta sec ... $delta_ss
                            echo ... shift sec ... $shift_ss
                            echo ... shift time step ... $shift_ts
                            echo --------------------------------
                            echo

                        fi

                        if [ -f $file_in ]; then
                            echo ... now processing ... $file_in

                            # --- select only given months ---
                            f_date=$yy'-'${mm_s[$mm]}'-01T00:00:00'
                            l_date=$yy'-'${mm_s[$mm]}'-31T23:55:00'

                            case ${var_in[$var]} in

                                pr | hfls | hfss | clt | rsds | rlds | evspsbl )
                                    $cdo -L cat -selname,$harm_name -seldate,$f_date,$l_date $file_in $file_tmp0;;
                                tsl)
                                    $cdo -L cat -daymean -selname,$harm_name,depth -seldate,$f_date,$l_date $file_in $file_tmp0;;
                                taspav | tasgree | tascan | hurscan | husscan | sfcWindcan)
                                    $cdo -L cat -daymean -selname,$harm_name,height -seldate,$f_date,$l_date $file_in $file_tmp0;;
                                *)
                                    $cdo -L cat -daymean -selname,$harm_name -seldate,$f_date,$l_date $file_in $file_tmp0;;
                            esac
                        else
                            echo ... not exists $file_in
                        fi
                    done  # month loop
                done # year loop

                if [ -f "$file_tmp0" ]; then
                    echo
                    echo
                    echo ... FINALIZING FILE ... $file_out
                    echo
                    end_ct="$(date +%s)"

		    # ---------------------
                    # --- RENAME VAR    ---
                    # ---------------------

		    if [[ "$harm_name" != "${var_in[$var]}" ]]; then
                    	ncrename -v $harm_name,${var_in[$var]} -h $file_tmp0
	            fi

                    # --------------------
                    # ---  TIME SHIFT  ---
                    # --------------------
                    case ${var_in[$var]} in
			pr | prc | prsn | evspsbl | rsds | rlds | hfls | hfss | clt | tasmax | tasmin )

                            sh_time=$(( 0 ));;

                        tas | psl | ps | sfcWind | huss |  hurs \
                            | ts | uas | vas | z0 | taspav | tasgree \
                            | tastown | taswater | anthroheat  \
                            | tsskin | tspav | tsroof | tsgree | tswater | zmla  \
                            | ta[0-9][0-9]m | hus[0-9][0-9]m | ua[0-9][0-9]m | va[0-9][0-9]m \
                            | clt | ua[0-9][0-9][0-9][0-9] | ua[0-9][0-9][0-9]  \
                            | va[0-9][0-9][0-9][0-9] | va[0-9][0-9][0-9] \
                            | ta[0-9][0-9][0-9][0-9] | ta[0-9][0-9][0-9] \
                            | zg[0-9][0-9][0-9][0-9] | zg[0-9][0-9][0-9] \
                            | tsl | tascan | hurscan | husscan | sfcWindcan )

                            sh_time=$(($shift_ss));;

                        *)
                            echo ...   NO VARIABEL   '"'${var_in[$var]}'"'  TERMINATED
                            exit;;
                    esac

                    echo ... shift time ... $sh_time
                    $cdo -L setmissval,1.e20 -setreftime,$ref_time -settunits,days -shifttime,$sh_time'sec' -setcalendar,$calendar $file_tmp0 $file_out

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


                    # -----------------------
                    # --- TIME ATRIBUTES  ---
                    # -----------------------
                    ncatted -a long_name,time,o,c,"time" \
                        -a bounds,time,o,c,"time_bnds" -h $file_out

                    ncatted -a cell_methods,${var_in[$var]},o,c,"time: mean" -h $file_out

                    # ---------------------
                    # ---  TIME BOUNDS  ---
                    # ---------------------
                    ncap2 -h -O -s 'time_bnds[$time, bnds]=0.; time_bnds(:, 0)=time-0.5; time_bnds(:, 1)=time+0.5;' $file_out $file_out


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


                    case ${var_in[$var]} in
                        taswater | tastown | taspav | tasgree \
                            | tswater | tsroof | tsgree | tspav | tsskin \
			    | tascan | hurscan | husscan | sfcWindcan | anthroheat )
                            ncatted -a patch,${var_in[$var]},o,c,"${area}" -h $file_out;;
                    esac

                    # -----------------------------
                    # ---   NEGATIVE VALUES     ---
                    # -----------------------------
                    case ${var_in[$var]} in
                        pr | prc | prsn )
                            ncap2 -O -h -s "where(${var_in[$var]} < 0) ${var_in[$var]}=0.;" $file_out $file_out;;
                        clt )
                            ncap2 -O -h -s "where(${var_in[$var]} < 0) ${var_in[$var]}=0.;" $file_out $file_out
                            ncap2 -O -h -s "where(${var_in[$var]} > 100) ${var_in[$var]}=100.;" $file_out $file_out;;
                    esac

                    # -----------------------------
                    # ---  VERTICAL COORDINATE  ---
                    # -----------------------------
                    case ${var_in[$var]} in
                        tas | hurs | huss | sfcWind | uas | vas \
                            | ta[0-9][0-9]m | hus[0-9][0-9]m \
                            | ua[0-9][0-9]m | va[0-9][0-9]m | tasmin | tasmax )
                            ncatted -a _CoordinateAxisType,height,d,, -h $file_out
                            ncatted -a long_name,height,o,c,"height" -h $file_out;;

                        tastown | taswater)
                            ncap2 -O -h -s "height=double($height);" $file_out $file_out
                            ncatted -a standard_name,height,o,c,"height" -h $file_out
                            ncatted -a long_name,height,o,c,"height" -h $file_out
                            ncatted -a units,height,o,c,"m" -h $file_out
                            ncatted -a positive,height,o,c,"up" -h $file_out
                            ncatted -a axis,height,o,c,"Z" -h $file_out
                            ncatted -a coordinates,${var_in[$var]},o,c,"lon lat height" -h $file_out;;
                        
                        taspav | tasgree | tascan | hurscan | husscan | sfcWindcan )
                            ncatted -a ancillary_variables,${var_in[$var]},o,c,"height" -h $file_out
                            ncatted -a coordinates,${var_in[$var]},o,c,"lon lat height" -h $file_out;;

                        tsl ) 
                            ncatted -a standard_name,depth,o,c,"soil_layer_depth" -h $file_out
                            ncatted -a long_name,depth,o,c,"Soil layer depth" -h $file_out
                            ncatted -a units,depth,o,c,"m" -h $file_out
                            ncatted -a positive,depth,o,c,"down" -h $file_out
                            ncatted -a axis,lev,o,c,"Z" -h $file_out
                            ncatted -a coordinates,depth,o,c,"lon lat" -h $file_out
                            ncatted -a coordinates,${var_in[$var]},o,c,"lon lat depth" -h $file_out;;

                        z0 | anthroheat | tsskin \
                           | tspav  | tsroof  | tsgree | tswater )
                            ncatted -a coordinates,${var_in[$var]},o,c,"lon lat" -h $file_out
                            ncks -O -x -v height -h $file_out $file_out;;
                    esac


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
		        -a frequency,global,o,c,"$freq" \
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
		        -a variable_id,global,o,c,"${var_in[$var]}" \
                        -a tracking_id,global,o,c,"$(python3 $DIRECTORY_PYTHON/get_uuid.py)" \
		        -a license,global,o,c,"https://cordex.org/data-access/cordex-cmip6-data/cordex-cmip6-terms-of-use" \
		        -a comment,global,o,c,"$comment" -h $file_out

                    # Create var folder if it's not exits
                    if [ ! -d "${path_out}/${freq}/${var_in[$var]}" ]; then
                        echo " "
                        echo "... Creating variable folder in path: ${path_out}/${freq}/${var_in[$var]}"
                        echo " "
                        mkdir -p ${path_out}/${freq}/${var_in[$var]} || { echo 'Could not create folder, terminated!' ; exit 1; }
                    fi

                    # -------------------------------------
                    # ---  DATES in FILE NAME: YYYYMMDD ---
                    # -------------------------------------
                    num_time=`$cdo ntime $file_out`
                    f_date=`$cdo showdate -seltimestep,1 $file_out`; f_date=${f_date// /}; f_date=${f_date//-/}
                    f_time=`$cdo showtime -seltimestep,1 $file_out`; f_time=${f_time:1:2}
                    l_date=`$cdo showdate -seltimestep,$num_time $file_out`; l_date=${l_date// /}; l_date=${l_date//-/}
                    l_time=`$cdo showtime -seltimestep,$num_time $file_out`; l_time=${l_time:1:2}

                    file_cordex=$path_out/${freq}/${var_in[$var]}/${var_in[$var]}'_'$domain_id'_'$driving_source_id'_'$driving_experiment_id'_'$driving_variant_label'_'$institution_id'_'$source_id'_'$experiment_version'_'$freq'_'$f_date$f_hhmm'-'$l_date$l_hhmm'.nc'

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

            done  # output file loop
        done  # year loop
    done  # variable loop
done  # simulation loop

end_time="$(date +%s)"
echo ELAPSED TOTAL TIME: "$(expr $end_time - $beg_time)" sec
echo
echo "END"
