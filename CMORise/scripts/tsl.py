import numpy as np
import sys
import os
import glob
from netCDF4 import Dataset


indir = sys.argv[1]
soil_file = sys.argv[2]

if not os.path.isdir(indir):
    sys.exit()

levels = np.array([0.01, 0.04, 0.1, 0.2, 0.4, 0.6, 0.8, 1.0, 1.5, 2, 3, 5, 8, 12])

lev = 0
for file in sorted(glob.glob(indir+'tsl_L*')):

    f = Dataset(file,'r')
    data = f.variables['tsl_L'+str(lev+1).zfill(2)][:,:,:]
    f.close()

    if lev == 0: 

        file_new = file.replace('tsl_L01','tsl')

        command = 'rm -rf '+file_new
        os.system(command)

        command = 'cp -r '+file+' '+file_new
        os.system(command)
        tsl = np.zeros((data.shape[0],14,data.shape[1],data.shape[2]))
    tsl[:,lev,:,:] = data
    lev +=1

f = Dataset(soil_file,'r')
for lev in range(14):

    if lev == 0: levels = np.zeros((14,tsl.shape[2],tsl.shape[3]))

    data = f.variables['SFX.DG'+str(lev+1)+'_ISBA'][0,:-11,:-11]
    levels[lev,:,:] = data[:,:]

f.close()

for file in glob.glob(indir+'tsl_sfx*'):

    f = Dataset(file,'r+')
    lev_nc = f.createDimension('lev', 14)
    lat_nc = f.dimensions['y'].name
    lon_nc = f.dimensions['x'].name
    time_nc = f.dimensions['time'].name

    lev0_nc= f.createVariable('lev',np.float64,(lev_nc,))

    level_nc= f.createVariable('depth',np.float64,(lev_nc, lat_nc, lon_nc))

    tsl_nc= f.createVariable('tsl',np.float64,(time_nc,lev_nc,lat_nc,lon_nc))

    tsl_nc[:,:,:,:] = tsl

    tsl_nc.units= "K"
    tsl_nc.long_name = 'Temperature of Soil'
    tsl_nc.standard_name = 'soil_temperature'
    tsl_nc.missing_value= -99999
    tsl_nc.FA_name= 'SFX.TGXX_ISBA'
    tsl_nc.coordinates= "lon lat lev"
    tsl_nc.grid_mapping="Lambert_Conformal"
    tsl_nc.cell_methods="time: point"
    tsl_nc.ancillary_variables = "depth"

    level_nc[:,:,:] = levels

    level_nc.units="m"
    level_nc.standard_name="soil_layer_depth"
    level_nc.long_name="Soil layer depth"
    level_nc._CoordinateAxisType= "Depth"
    level_nc.missing_value= -99999

    lev0_nc[:] = np.arange(1,15)
    lev0_nc.standard_name="soil_layer_level"
    lev0_nc.long_name="Soil layer level"

    f.close()
