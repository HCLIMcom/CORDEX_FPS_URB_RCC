"""anthroheat.py: Correct the odd values at the beginning of each month."""

import numpy as np
import sys
import os
import glob
import subprocess
from netCDF4 import Dataset

input_directory = sys.argv[1]

if not os.path.isdir(input_directory):
    sys.exit()

input_directory_split = input_directory.split('/')

year_current, month_current = input_directory_split[-5:-3]

month_past = int(month_current)-1
if month_past == 0:
    month_past = 12
    year_past = int(year_current)-1
else:
    year_past = int(year_current)

input_directory_past_split = input_directory_split[:]
input_directory_past_split[-5] = str(year_past)
input_directory_past_split[-4] = str(month_past).zfill(2)

input_directory_past = '/'.join(input_directory_past_split)

print(input_directory)
print(input_directory_past)

if os.path.isdir(input_directory_past):
    for file in sorted(glob.glob(f'{input_directory_past}anthroheat_sfx*')):
        f = Dataset(file,'r')
        last_value = f.variables['anthroheat'][-1,:,:]
        f.close()
else:
    last_value = None

for file in sorted(glob.glob(f'{input_directory}anthroheat_sfx*')):
    file_new = file.replace('anthroheat','anthroheat_corrected')

    subprocess.run(['rm','-rf',f'{file_new}'])
    subprocess.run(['cp','-r',f'{file}',f'{file_new}'])

    if last_value is not None:
        f = Dataset(file_new,'r+')
        anthroheat = f.variables['anthroheat']
        anthroheat[0,:,:] = last_value
        f.close()
