import numpy as np
import sys
import subprocess
import glob
import os
from netCDF4 import Dataset


infile = sys.argv[1]
cover_file = sys.argv[2]


# Check if file exists
if not os.path.exists(infile):
    sys.exit()

f = Dataset(cover_file,'r')

cover = {}
for n in range(10):
    try:
        cover[n] = f.variables['SFX.COVER0'+str(24+n)][0,:-11,:-11]
    except:
        cover[n] = np.zeros(cover[0].shape)
f.close()

height= [75.,20.,5.,75.,20.,5.,3.,5.,5.,10.]

building_height = np.zeros(cover[0].shape)
urban_fraction  = np.zeros(cover[0].shape)
for n in range(10): 
    building_height[:,:] = building_height[:,:] + 0.5*height[n]*cover[n]
    urban_fraction[:,:] = urban_fraction[:,:] + cover[n]

building_height[np.where(urban_fraction>0.)] = building_height[np.where(urban_fraction>0.)]/urban_fraction[np.where(urban_fraction>0.)]

outfile = infile.replace('sfx','height_sfx')

subprocess.run(["rm", "-rf",f"{outfile}"])
subprocess.run(["cp", "-r",f"{infile}",f"{outfile}"])

f = Dataset(outfile,'r+')

lat_nc = f.dimensions['y'].name
lon_nc = f.dimensions['x'].name

buiref_nc= f.createVariable('height',np.float64,(lat_nc,lon_nc))

building_height[building_height==0] = 1e20

buiref_nc[:,:] = building_height[:,:]

buiref_nc.units= "m"
buiref_nc.long_name = 'Reference height at mid-canyon'
buiref_nc.standard_name = 'reference_height_mid_canyon'
buiref_nc.missing_value= 1e20
buiref_nc.positive = "up"
buiref_nc.axis = "Z"
buiref_nc.patch='Town'
buiref_nc.coordinates= "lon lat"
buiref_nc.grid_mapping="Lambert_Conformal"

f.close()
