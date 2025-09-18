import yaml
import sys

namelist_file = sys.argv[1]

with open(namelist_file,'r') as f:
    namelist = yaml.safe_load(f)

ecmwf_account = namelist['account']
cmor_directory = namelist['CMOR_dir']
submit_info = namelist['ecflow_submit']


print('------------\n WRITE SUBMIT FILES\n------------\n')

for frequency in submit_info.keys():

    walltime = submit_info[frequency]['walltime']
    max_memory = submit_info[frequency]['max_memory']
    
    memory_info = {frequency:'8GB',f'{frequency}_mem':max_memory}

    for case in memory_info.keys():

        if memory_info[case] is None:
            continue

        print(f'- Writing current file: {cmor_directory}/inc/submit_{case}.h\n')

        with open(f"{cmor_directory}/inc/submit_{case}.h", "w") as inc_file:

            inc_file.write(f'#SBATCH --account={ecmwf_account}\n')
            inc_file.write(f'#SBATCH --output=%ECF_OUT%/CMOR_%CMOR_EXP%/CMOR_%CMOR_FREQ%/CMOR_compute_%CMOR_CASE%.%ECF_TRYNO%\n')
            inc_file.write(f'#SBATCH --error=%ECF_OUT%/CMOR_%CMOR_EXP%/CMOR_%CMOR_FREQ%/CMOR_compute_%CMOR_CASE%.%ECF_TRYNO%\n')
            inc_file.write('#SBATCH --qos=nf\n')
            inc_file.write(f'#SBATCH --time={walltime}\n')
            inc_file.write(f'#SBATCH --job-name=CMOR_%CMOR_FREQ%_%CMOR_CASE%\n')
            inc_file.write(f'#SBATCH --mem={memory_info[case]}\n\n')

