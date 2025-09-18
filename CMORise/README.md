# CMORise tool
-----------------------------------------------------

CMORisation scripts for URB-RCC simulations. The variable naming convention is taken from the [URB-RCC protocol](https://docs.google.com/spreadsheets/d/1BofRmcRIBz2QCX6BH9kvT2S93HGWbsPTjq65PABF4w0/edit?gid=0#gid=0) while the global attributes are following the [CORDEX-CMIP6 archiving specifications](https://cordex.org/wp-content/uploads/2023/11/CORDEX-CMIP6_archive_specs_SOD_landscape.pdf).

> [!IMPORTANT]  
> The current scripts are written for HCLIM output only, for other model outputs modify accordingly the **cmor_nc2nc_\<freq\>.sh** in the **scripts** folder. Moreover, the scripts currently do not retrieve data from ECFS, the netCDF files to be CMORised are expected to be stored in one of the ECMWF filesystems (**HOME,PERM,HPCPERM,SCRATCH**).

## Quick start

1 - Load the needed modules to run ecFlow and the CMOR scripts.
```
module load ecflow
module load python
```

2 - Modify the namelist files in the **config** folder accordingly. More info about the namelist files can be found [here](docs/config.md).

3 - Make sure that all the auxiliary data need for your experiment is in the **meta** folder. More info about the auxiliary data can be found [here](docs/meta.md).

4 - Setup and prepare the ecFlow suites and tasks:
```
./CMORise.sh setup
```

5 - Launch the ecflow suites:
```
./CMORise.sh launch [--all]
```

The optional argument ```--all``` will launch all the available suites in the **suites** folder. Otherwise, the script will ask which all the suites need to be launched. 

## Content

- **CMORise.sh**: main script.
- **[config](docs/config.md)**: contains the namelist files to describe the experiemtns and setup ecFlow. 
- **docs**: contains the documentation files.
- **ecf**: contains the ecf files to describe the different ecFlow tasks.
- **inc**: contains the include files (__.h__ files) for ecFlow.
- **[meta](docs/meta.md)**: contains auxiliary data such as the variables metada or domain specific information.
- **scripts**: contains the main scripts use to setup and compute the CMORisation.
- **suites**: this directory is created after ```./CMORise.sh setup```. It contains all the ecFlow suites and outputs.

## Notes about the CMORisation

- Each CMORised filed is stored under this directory:
```
<path_out>/<experiment_name>/<frequency>/<varname>/
```

- The time spans that have to be included into a single file depend on the frequency:
    - 1-hourly or 6-hourly: one year
    - daily: 5 years or less
    - monthly: 10 years or less
    - invariant (```fx```): single file

- The spinup up year (```first_year``` in **config_experiment**) is treated separately. For example for a simulation that covers from 2000-2009 the CMORised files would be arranged as follows:

| frequency | files |
| :-------: | :---- |
| 1hr/6hr   | 1999, 2000, 2001, 2002, 2003, 2004, 2005, 2006, 2007, 2008, 2009 |
| daily     | 1999, 2000-2004, 2005-2009 |
| monthly   | 1999, 2000-2009 |
