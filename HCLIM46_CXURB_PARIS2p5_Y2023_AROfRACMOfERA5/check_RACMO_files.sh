#!/bin/bash

set -eu

ardir=/ec/res4/scratch/nkl/HARMONIE/boundaries/RACMO/HXEUR12/eR2v3-v578ec-Y2023-LU2015-MAC2SP-fERA5/RACMO_HarmLBC
outdir=$klad/hm_home/HCLIM46_CXURB_PARIS2p5_Y2023_AROfRACMOfERA5/RACMO/archive
dtg=2020050100
dtge=2024010100

mkdir -p $outdir && cd $outdir

while [ $dtg -lt $dtge ]; do
  ym=${dtg:0:6}
  yy=${dtg:0:4}
  mm=${dtg:4:2}
  dtgn=$(mandtg2.x $dtg +m 1)
  nhrs=$(mandtg2.x $dtgn -h $dtg)
  mkdir -p $outdir/$yy/$mm && cd $outdir/$yy/$mm
  for dec in 1 2 3; do
    ff="$ardir/RC-eR2v3-v578ec-Y2023-LU2015-MAC2SP-fERA5_${ym}_d${dec}.tar"
    printf "untar $ym $dec"
    tar xvf $ff
  done
  
  i=1
  for ff in rc*; do
    printf $ff
    diasim.x -s $ff &> /dev/null || printf "EEEEEEEEEERRRRRRRRRRRRRRRRRRRRRRRRROOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOORRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRR"
    printf "\n"
    ((i+=1))
  done
  
  if [ $i -ne $nhrs ]; then
    echo "ERROR: month $ym misses files: $i <> $nhrs"
  fi
  
  dtg=$dtgn
done

echo "All done!"
