import yaml
import sys
import subprocess

namelist_file = sys.argv[1]

with open(namelist_file,'r') as f:
    namelist = yaml.safe_load(f)

print('------------\n PREPARE SUITE FILES\n------------\n')

cmor_directory = namelist['CMOR_dir']

for experiment in namelist['experiment']:

    print(f'- Preparing files in suite: {cmor_directory}/suites/CMOR_{experiment}\n')

    for frequency in ['fx','subday','day','mon']:

            family_present = True
            for block in namelist['ecflow_blocks']:
                block_info = namelist['ecflow_blocks'][block]

                if frequency in block_info['frequency']:

                    if family_present:
                        subprocess.run(["mkdir", "-p",f"{cmor_directory}/suites/CMOR_{experiment}/CMOR_{frequency}"])
                        print(f'  - Preparing files in family: {cmor_directory}/suites/CMOR_{experiment}/CMOR_{frequency}\n')
                        family_present=False
            
                    if block_info['memory']:
                        subprocess.run(["ln", "-sf",f"{cmor_directory}/ecf/CMOR_compute_mem.ecf",f"{cmor_directory}/suites/CMOR_{experiment}/CMOR_{frequency}/CMOR_compute_{block}.ecf"])
                    else:
                        subprocess.run(["ln", "-sf",f"{cmor_directory}/ecf/CMOR_compute.ecf",f"{cmor_directory}/suites/CMOR_{experiment}/CMOR_{frequency}/CMOR_compute_{block}.ecf"])

                    print(f'     - Creating ... {cmor_directory}/suites/CMOR_{experiment}/CMOR_{frequency}/CMOR_compute_{block}.ecf\n')


