import numpy as np
import sys
import os
import glob
from netCDF4 import Dataset


indir = sys.argv[1]
soil_file = sys.argv[2]

file_depth = Dataset(soil_file,'r')
for lev in range(14):

    data = file_depth.variables['SFX.DG'+str(lev+1)+'_ISBA'][0,:-11,:-11]

    if lev == 0: levels = np.zeros((15,data.shape[0],data.shape[1]))

    levels[lev+1,:,:] = data[:,:]


    for file in sorted(glob.glob(indir+'wfc_L'+str(lev+1).zfill(2)+'*')):

        file_wfc = Dataset(file,'r')

        try:
            data = file_wfc.variables['wfc_L'+str(lev+1).zfill(2)][0,:,:]
        except:
            data = file_wfc.variables['wfc_L'+str(lev+1).zfill(2)][:,:]

        if lev == 0: 

            file_new = file.replace('wfc_L01','mrsofc')

            command = 'rm -rf '+file_new
            os.system(command)

            command = 'cp -r '+file+' '+file_new
            os.system(command)
            mrsofc = np.zeros((data.shape[0],data.shape[1]))

        mrsofc[:,:] = mrsofc[:,:] + 1000*data*(levels[lev+1,:,:] - levels[lev,:,:])
    file_wfc.close()

file_depth.close()

mrsofc[mrsofc==0] = 1e20

for file in glob.glob(indir+'mrsofc_*'):

    f = Dataset(file,'r+')
    lat_nc = f.dimensions['y'].name
    lon_nc = f.dimensions['x'].name

    mrsofc_nc= f.createVariable('mrsofc',np.float64,(lat_nc,lon_nc))

    mrsofc_nc[:,:] = mrsofc[:,:]

    mrsofc_nc.units= "kg m-2"
    mrsofc_nc.long_name = 'Capacity of Soil to Store Water  (Field Capacity)'
    mrsofc_nc.standard_name = 'soil_moisture_content_at_field_capacity'
    mrsofc_nc.missing_value= 1e20
    mrsofc_nc.FA_name= 'SFX.WFCXX'
    mrsofc_nc.coordinates= "lon lat"
    mrsofc_nc.grid_mapping="Lambert_Conformal"

    f.close()
