#!/bin/bash
# Retrieve all selected variables for the whole period from ECFS again, and store them in a single directory (to be able to use ECFS more effectively)
# Expect 2 arguments
# 1: start dtg for retrieval
# 2: end dtg for retrieval

set -eu

echo "$0 started ($(date) on $(hostname))"
if [ $# -ne 2 ]; then
  echo "ERROR: incorrect number of arguments: dtg1 & dtg2 expected."
fi

dtg=$1
dtge=$2
dtgbeg=2020010100  # retrieve fx files
dtglast=2024010100 # only 1 time step expected

EXP=HCLIM46_CXURB_PARIS2p5_Y2023_AROfRACMOfERA5
hecdir="ec:harmonie/CORDEX_FPS_URB_RCC/stage1/$EXP"
houtdir=/scratch/nkl/hm_home/$EXP/archive/get_nc_from_ECFS

# Create sort of format list with files to retrievem dtg1 & dtg2 will be replaced
vars_fx=" \
  orog_clim_PARIS2.5_${EXP}_fx.nc \
  sftnf_clim_PARIS2.5_${EXP}_fx.nc \
  sfturf_clim_PARIS2.5_${EXP}_fx.nc \
  sftlaf_clim_PARIS2.5_${EXP}_fx.nc"

vars=" \
  tas_fp_PARIS2.5_${EXP}_1hr_{dtg1}00-{dtg2}00.nc \
  tasmax_fp_PARIS2.5_${EXP}_1hr_{dtg1}00-{dtg2}00.nc \
  tasmin_fp_PARIS2.5_${EXP}_1hr_{dtg1}00-{dtg2}00.nc \
  pr_fp_PARIS2.5_${EXP}_1hr_{dtg1}00-{dtg2}00.nc \
  pr_fp_PARIS2.5_${EXP}_day_{dtg1}00-{dtg2}00.nc \
  pr_fp_PARIS2.5_${EXP}_mon_{dtg1}00-{dtg2}00.nc \
  evspsbl_fp_PARIS2.5_${EXP}_1hr_{dtg1}00-{dtg2}00.nc \
  evspsbl_fp_PARIS2.5_${EXP}_day_{dtg1}00-{dtg2}00.nc \
  evspsbl_fp_PARIS2.5_${EXP}_mon_{dtg1}00-{dtg2}00.nc \
  huss_fp_PARIS2.5_${EXP}_1hr_{dtg1}00-{dtg2}00.nc \
  hurs_fp_PARIS2.5_${EXP}_1hr_{dtg1}00-{dtg2}00.nc \
  ps_fp_PARIS2.5_${EXP}_1hr_{dtg1}00-{dtg2}00.nc \
  psl_fp_PARIS2.5_${EXP}_1hr_{dtg1}00-{dtg2}00.nc \
  sfcWind_fp_PARIS2.5_${EXP}_1hr_{dtg1}00-{dtg2}00.nc \
  uas_fp_PARIS2.5_${EXP}_1hr_{dtg1}00-{dtg2}00.nc \
  vas_fp_PARIS2.5_${EXP}_1hr_{dtg1}00-{dtg2}00.nc \
  clt_fp_PARIS2.5_${EXP}_1hr_{dtg1}00-{dtg2}00.nc \
  clt_fp_PARIS2.5_${EXP}_day_{dtg1}00-{dtg2}00.nc \
  clt_fp_PARIS2.5_${EXP}_mon_{dtg1}00-{dtg2}00.nc \
  rsds_fp_PARIS2.5_${EXP}_1hr_{dtg1}00-{dtg2}00.nc \
  rsds_fp_PARIS2.5_${EXP}_day_{dtg1}00-{dtg2}00.nc \
  rsds_fp_PARIS2.5_${EXP}_mon_{dtg1}00-{dtg2}00.nc \
  rlds_fp_PARIS2.5_${EXP}_1hr_{dtg1}00-{dtg2}00.nc \
  rlds_fp_PARIS2.5_${EXP}_day_{dtg1}00-{dtg2}00.nc \
  rlds_fp_PARIS2.5_${EXP}_mon_{dtg1}00-{dtg2}00.nc \
  hfls_fp_PARIS2.5_${EXP}_1hr_{dtg1}00-{dtg2}00.nc \
  hfls_fp_PARIS2.5_${EXP}_day_{dtg1}00-{dtg2}00.nc \
  hfls_fp_PARIS2.5_${EXP}_mon_{dtg1}00-{dtg2}00.nc \
  hfss_fp_PARIS2.5_${EXP}_1hr_{dtg1}00-{dtg2}00.nc \
  hfss_fp_PARIS2.5_${EXP}_day_{dtg1}00-{dtg2}00.nc \
  hfss_fp_PARIS2.5_${EXP}_mon_{dtg1}00-{dtg2}00.nc \
  ts_sfx_PARIS2.5_${EXP}_1hr_{dtg1}00-{dtg2}00.nc \
  z0_sfx_PARIS2.5_${EXP}_1hr_{dtg1}00-{dtg2}00.nc \
  tsl_L01_sfx_PARIS2.5_${EXP}_6hr_{dtg1}00-{dtg2}00.nc \
  tsl_L02_sfx_PARIS2.5_${EXP}_6hr_{dtg1}00-{dtg2}00.nc \
  tsl_L03_sfx_PARIS2.5_${EXP}_6hr_{dtg1}00-{dtg2}00.nc \
  tsl_L04_sfx_PARIS2.5_${EXP}_6hr_{dtg1}00-{dtg2}00.nc \
  tsl_L05_sfx_PARIS2.5_${EXP}_6hr_{dtg1}00-{dtg2}00.nc \
  tsl_L06_sfx_PARIS2.5_${EXP}_6hr_{dtg1}00-{dtg2}00.nc \
  tsl_L07_sfx_PARIS2.5_${EXP}_6hr_{dtg1}00-{dtg2}00.nc \
  tsl_L08_sfx_PARIS2.5_${EXP}_6hr_{dtg1}00-{dtg2}00.nc \
  tsl_L09_sfx_PARIS2.5_${EXP}_6hr_{dtg1}00-{dtg2}00.nc \
  tsl_L10_sfx_PARIS2.5_${EXP}_6hr_{dtg1}00-{dtg2}00.nc \
  tsl_L11_sfx_PARIS2.5_${EXP}_6hr_{dtg1}00-{dtg2}00.nc \
  tsl_L12_sfx_PARIS2.5_${EXP}_6hr_{dtg1}00-{dtg2}00.nc \
  tsl_L13_sfx_PARIS2.5_${EXP}_6hr_{dtg1}00-{dtg2}00.nc \
  tsl_L14_sfx_PARIS2.5_${EXP}_6hr_{dtg1}00-{dtg2}00.nc \
  ua1000_fp_PARIS2.5_${EXP}_6hr_{dtg1}00-{dtg2}00.nc \
  ua925_fp_PARIS2.5_${EXP}_6hr_{dtg1}00-{dtg2}00.nc \
  ua850_fp_PARIS2.5_${EXP}_6hr_{dtg1}00-{dtg2}00.nc \
  ua700_fp_PARIS2.5_${EXP}_6hr_{dtg1}00-{dtg2}00.nc \
  va1000_fp_PARIS2.5_${EXP}_6hr_{dtg1}00-{dtg2}00.nc \
  va925_fp_PARIS2.5_${EXP}_6hr_{dtg1}00-{dtg2}00.nc \
  va850_fp_PARIS2.5_${EXP}_6hr_{dtg1}00-{dtg2}00.nc \
  va700_fp_PARIS2.5_${EXP}_6hr_{dtg1}00-{dtg2}00.nc \
  ta1000_fp_PARIS2.5_${EXP}_6hr_{dtg1}00-{dtg2}00.nc \
  ta925_fp_PARIS2.5_${EXP}_6hr_{dtg1}00-{dtg2}00.nc \
  ta850_fp_PARIS2.5_${EXP}_6hr_{dtg1}00-{dtg2}00.nc \
  ta700_fp_PARIS2.5_${EXP}_6hr_{dtg1}00-{dtg2}00.nc \
  zg1000_fp_PARIS2.5_${EXP}_6hr_{dtg1}00-{dtg2}00.nc \
  zg925_fp_PARIS2.5_${EXP}_6hr_{dtg1}00-{dtg2}00.nc \
  zg850_fp_PARIS2.5_${EXP}_6hr_{dtg1}00-{dtg2}00.nc \
  zg700_fp_PARIS2.5_${EXP}_6hr_{dtg1}00-{dtg2}00.nc \
  taspav_sfx_PARIS2.5_${EXP}_1hr_{dtg1}00-{dtg2}00.nc \
  tasgree_sfx_PARIS2.5_${EXP}_1hr_{dtg1}00-{dtg2}00.nc \
  tas_water_sfx_PARIS2.5_${EXP}_1hr_{dtg1}00-{dtg2}00.nc \
  anthroheat_sfx_PARIS2.5_${EXP}_1hr_{dtg1}00-{dtg2}00.nc \
  tsskin_sfx_PARIS2.5_${EXP}_1hr_{dtg1}00-{dtg2}00.nc \
  tspav_sfx_PARIS2.5_${EXP}_1hr_{dtg1}00-{dtg2}00.nc \
  tsroof_sfx_PARIS2.5_${EXP}_1hr_{dtg1}00-{dtg2}00.nc \
  tsgree_sfx_PARIS2.5_${EXP}_1hr_{dtg1}00-{dtg2}00.nc \
  ts_water_sfx_PARIS2.5_${EXP}_1hr_{dtg1}00-{dtg2}00.nc \
  tascan_sfx_PARIS2.5_${EXP}_1hr_{dtg1}00-{dtg2}00.nc \
  hurscan_sfx_PARIS2.5_${EXP}_1hr_{dtg1}00-{dtg2}00.nc \
  husscan_sfx_PARIS2.5_${EXP}_1hr_{dtg1}00-{dtg2}00.nc \
  sfcWindcan_sfx_PARIS2.5_${EXP}_1hr_{dtg1}00-{dtg2}00.nc \
  ta50m_fp_PARIS2.5_${EXP}_1hr_{dtg1}00-{dtg2}00.nc \
  hus50m_fp_PARIS2.5_${EXP}_1hr_{dtg1}00-{dtg2}00.nc \
  ua50m_fp_PARIS2.5_${EXP}_1hr_{dtg1}00-{dtg2}00.nc \
  va50m_fp_PARIS2.5_${EXP}_1hr_{dtg1}00-{dtg2}00.nc \
  zmla_fp_PARIS2.5_${EXP}_1hr_{dtg1}00-{dtg2}00.nc"


mkdir -p $houtdir && cd $houtdir

# create a list with files, so we can use ECSF's --order=tape option
sourcelist=ECFS_sourcelist_${dtg}-${dtge}.txt
echo "Using sourcelist=$(pwd)/$sourcelist"
rm -f $sourcelist
while [ $dtg -le $dtge ]; do
  echo "--------------------------------------------------------------------------------------------------------------------------------------"
  echo "Working on DTG=$dtg ($(date) on $(hostname))"
  if [ $dtg -lt $dtglast ]; then
    dtg2=$(mandtg2.x $dtg +m 1)
  else
    # last month has only 1 time step
    dtg2=$dtg
  fi
  y4=${dtg:0:4}
  m2=${dtg:4:2}

  if [ $dtg -eq $dtgbeg ]; then
    echo "  Adding fx files"
    for ff in $vars_fx; do
      if [ -f $ff ]; then
        echo "  - $ff already exists"
      else
        echo ec:$y4/$m2/01/00/$ff >> $sourcelist
        echo "  - $ff added to list"
      fi
    done
  fi
  
  echo "  Adding files"
  for ff in $vars; do
    ff1=${ff/'{dtg1}'/$dtg}
    ff2=${ff1/'{dtg2}'/$dtg2}
      if [ -f $ff2 ]; then
        echo "  - $ff2 already exists"
      else
        echo ec:$y4/$m2/01/00/$ff2 >> $sourcelist
        echo "  - $ff2 added to list"
      fi
  done

  # Next month
  dtg=$(mandtg2.x $dtg +m 1)
done

# Retrieve files, first ecd to hecdir!
echo "Starting retrieval to $(pwd) ($(date) on $(hostname))"
echo "Contents of sourcelist $sourcelist"
cat $sourcelist
ecd $hecdir
ecp --order=tape -F $sourcelist .

echo "All done! ($(date) on $(hostname))"
