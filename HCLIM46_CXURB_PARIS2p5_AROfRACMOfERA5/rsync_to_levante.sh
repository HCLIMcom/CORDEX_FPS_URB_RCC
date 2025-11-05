#!/usr/bin/env bash
# rsync CMORized files for this exp to DKRZ's levante machine
# Follow SMHI's dir structure example: /work/bg1369/FPS-URB-RCC/STAGE-1/PARIS-3/HCLIMcom-SMHI/ERA5/evaluation/r1i1p1f1/HCLIM46-AROME/v1-r2/mon/pr/v202510

set -eu

echo "$0 started at $(date)"

dry="" # "--dry-run"
server=levante # assumes host is set up properly in .ssh/config

exp=HCLIM46_PARIS-3_AROME_v1-r1_URBRCC_EVAL
sourcedir=$SCRATCH/URB-RCC/CMOR/$exp

targetdir_fmt='/work/bg1369/FPS-URB-RCC/STAGE-1/PARIS-3/HCLIMcom-KNMI/ERA5/evaluation/r1i1p1f1/HCLIM46-AROME/v1-r1/%s/%s/v202510'

if [ ! -d $sourcedir ]; then
  echo "$sourcedir doesn't exist ... exit"
  exit 1
fi

for ttype in 1hr 6hr day mon fx; do
  cd $sourcedir/$ttype
  for var in $(ls); do
    cd $sourcedir/$ttype/$var
    tgdir=$(printf "$targetdir_fmt\n" $ttype $var)

    echo "rsync $(pwd) to ${server}:$tgdir"

    # Create target directory (probably can be done by rsync)
    ssh levante mkdir -vp $tgdir
    
    # rsync
    rsync $dry \
      --progress --update -avz \
      $(pwd)/ $server:$tgdir
  done
done

echo "$0 finished at $(date)"
