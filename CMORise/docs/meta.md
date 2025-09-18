## Directory _meta_
----------------------------------

This directory contains auxiliary data required for the CMORisation. The current version contains the following data:

### I - Cover fractions available in the domain of interest

- **Description**: netCDF file containing all the available covers (**SFX.COVERXXX**) in the domain of interest. This file is required by **scripts/building_height.py** to compute the average height of the urban canyon.

- **Name of file**: _<domain_name>_\_covers.nc

- **How to construct it**: The cover information can be extracted in HCLIM from the **Const.Clim.sfx** file in the climate folder. 

### II - Soil level depth in the domain of interest

- **Description**: netCDF file containing all the available soil level depths (**SFX.DGXX_ISBA**) in the domain of interest. This file is required by **scripts/tsl.py** and by **scripts/mrsofc.py**.

- **Name of file**: _<domain_name>_\_soil_depths.nc

- **How to construct it**: The soil depth can be extracted in HCLIM from the **SURFXINI.fa** file in the archive folder. 

### III - Variable information 

- **Description**: file containing information from the different variables (e.g. long name, short name, units). This information will appeared in the attributes of the variable in the CMORised netcdf file.

- **Name of file**: harmonie_var_info_cordex.txt

- **How to add a new variable**: Add a new block to **harmonie_var_info_cordex.txt** with the information of the new variable. These are the possible attributes:

| Attribute | Mandatory | Description |
| :-------- | :-------: | :--------- |
| **harm_name** | yes |  Name of the variable in the model. For some variables this name may be different from the standard CORDEX name. |
| **st_name** | yes | Short name of the variable. |
| **long_name** | yes | Long name of the variable. |
| **units** | yes | Units of the variable. |
| **realm** | yes | Realm to which the variable belongs to [```atmos``` \| ```land```]. |
| **cell_methods** | yes | ```time: point``` for instantaneous fields, ```time: mean``` for accumulated fields, ```time: maximum``` for maximum fields, or ```time: minimum``` for minimum fields. |
| **height** | no | Refence height at which the variable is measured. |
| **positive** | no | Defines the direction in which positive values of the variable are considered. |
| **area** | no | Defines a sub-realm, mostly used for urban variables [```town```]. |




















































    

