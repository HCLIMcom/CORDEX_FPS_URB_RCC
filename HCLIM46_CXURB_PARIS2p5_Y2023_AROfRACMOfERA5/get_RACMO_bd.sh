#!/bin/bash

set -eu

hecdir='ec:/rus/HXEUR12/eR2v3-v578ec-Y2023-LU2015-MAC2SP-fERA5/RACMO_HarmLBC'
outdir=/ec/res4/scratch/nkl/HARMONIE/boundaries/RACMO/HXEUR12/eR2v3-v578ec-Y2023-LU2015-MAC2SP-fERA5/RACMO_HarmLBC
dtg=2019120100
dtge=2024010100

mkdir -p $outdir && cd $outdir

while [ $dtg -lt $dtge ]; do
  ym=${dtg:0:6}
  for dec in 1 2 3; do
    ff="$hecdir/RC-eR2v3-v578ec-Y2023-LU2015-MAC2SP-fERA5_${ym}_d${dec}.tar"
    printf "getting $ym $dec | $(els -l $ff) | "
    if [ -f $(basename $ff) ]; then
      printf "already there\\n"
    else
      ecp $ff .
      printf "OK\\n"
    fi
  done
  dtg=$(mandtg2.x $dtg +m 1)
done

echo "All done!"
