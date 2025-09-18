import sys

cmor_dir = sys.argv[1]
frequency = sys.argv[2]
case = sys.argv[3]
experiment = sys.argv[4]
variable_list = sys.argv[5]

with open(f"{cmor_dir}/suites/CMOR_{experiment}/CMOR_{frequency}/{experiment}_{frequency}_{case}.sh", "w") as script_file:
    script_file.write('#!/bin/bash\n\n')
    script_file.write(f'input_variables=({variable_list.replace(","," ")})\n')
    script_file.write(f'experiment_case={experiment}\n')
    script_file.write(f'source {cmor_dir}/scripts/cmor_nc2nc_{frequency}.sh {cmor_dir} $experiment_case \"${{input_variables[@]}}\"\n')
