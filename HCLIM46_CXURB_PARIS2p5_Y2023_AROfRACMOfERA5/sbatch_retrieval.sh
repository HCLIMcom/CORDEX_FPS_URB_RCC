#!/usr/bin/env bash
#SBATCH --qos=nf
#SBATCH --ntasks=1
#SBATCH --cpus-per-task=1
#SBATCH --job-name=get_nc_from_ECFS_2020
#SBATCH --mem-per-cpu=16000
#SBATCH -t 48:00:00
#SBATCH --output=/scratch/nkl/hm_home/HCLIM46_CXURB_PARIS2p5_Y2023_AROfRACMOfERA5/archive/get_nc_from_ECFS/log.get_nc_from_ECFS_2020.txt

~nkl/hm_home/CORDEX_FPS_URB_RCC/HCLIM46_CXURB_PARIS2p5_Y2023_AROfRACMOfERA5/get_nc_from_ECFS.sh 2020010100 2023120100


