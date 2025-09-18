import yaml
import sys

namelist_file = sys.argv[1]

with open(namelist_file,'r') as f:
    namelist = yaml.safe_load(f)

print('------------\n WRITE SUITE FILES\n------------\n')

cmor_directory = namelist['CMOR_dir']

for experiment in namelist['experiment']:

    print(f'- Writing current file: {cmor_directory}/suites/CMOR_{experiment}.def\n')

    with open(f"{cmor_directory}/suites/CMOR_{experiment}.def", "w") as suite_file:

        suite_file.write(f'suite CMOR_{experiment}\n\n')

        # Header 
        suite_file.write(f'\tedit HOST_DIR "{cmor_directory}"\n')
        suite_file.write(f'\tedit ECF_INCLUDE "{cmor_directory}/inc"\n')
        suite_file.write(f'\tedit ECF_HOME "{cmor_directory}/suites"\n')
        suite_file.write(f'\tedit ECF_OUT "{cmor_directory}/suites"\n')
        suite_file.write('\tedit ECF_JOB_CMD ssh -o \'StrictHostKeyChecking=no\' hpc-batch \'ecsbatch %ECF_JOB% 1> %ECF_JOBOUT% 2>&1 &\'\n')
        suite_file.write('\tedit ECF_TRIES 1\n')
        suite_file.write(f'\tedit CMOR_EXP "{experiment}"\n\n')
        suite_file.write(f'\tlimit numCMOR {namelist['ecflow_settings']['maximum_number_simultaneous_tasks']}\n\n')

        # Write family and task blocks
        last_frequency = None
        for frequency in ['fx','subday','day','mon']:

            write_family_header = True
            write_family_end = False

            for block in namelist['ecflow_blocks']:
                block_info = namelist['ecflow_blocks'][block]

                if frequency in block_info['frequency']:

                    if write_family_header:
                        suite_file.write(f'\tfamily CMOR_{frequency}\n')
                        suite_file.write('\t  inlimit numCMOR\n\n')

                        if last_frequency is not None:
                           suite_file.write(f'\t  trigger CMOR_{last_frequency} eq complete\n\n')

                        suite_file.write(f'\t  edit CMOR_FREQ "{frequency}"\n\n')

                        write_family_header = False
                        write_family_end = True

                    suite_file.write(f'\t  task CMOR_compute_{block}\n')
                    if ('AROME' in experiment or 'arome' in experiment) and ( 'prc' in block_info["variables"]):
                        suite_file.write(f'\t    edit CMOR_VAR_LIST "{block_info["variables"].replace(",prc","")}"\n')
                    else:
                        suite_file.write(f'\t    edit CMOR_VAR_LIST "{block_info["variables"]}"\n')
                    suite_file.write(f'\t    edit CMOR_CASE "{block}"\n\n')

            if write_family_end:
                suite_file.write(f'\tendfamily\n\n')
                last_frequency = frequency

        suite_file.write('endsuite')



























