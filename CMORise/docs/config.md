## Directory _config_
----------------------------------

This directory contains the namelist files to describe the experiments and setup ecFlow. :

### _config_ecflow.yaml_

- **Description**: yaml file that contains the needed parameters to configure the ecFlow suite and tasks.

- These are the **parameters** to be set:

    - **CMOR_dir**: Path to the _CMORise_ main directory.
    - **account**: ECMWF project account.
    - **experiment**: List of experiments to CMOR (the names should much the ones in _config/config_experiment_)
    - **ecflow_blocks**: List of different tasks with their corresponding variables and frequencies to cmorize.  
        - **<name_of_block>**: Name of the block
            - **frequency**: frequencies considered in this block ( ```fx | subday | day | mon```).
            - **variables**: list of variables that belong to this block.
            - **memory**: If memory is true, the SBATCH script will use the memory assign  in ecflow_submit block (further down).
    - **ecflow_submit**: Specify walltime and maximum memory for the different frequencies. If **max_memory** is not defined the scripts will use the default 8GB value.
    - **ecflow_settings**: Other ecflow settings
        - **maximum_number_simultaneous_tasks**: maximum number of simultaneous tasks.
        
### _config_experiment_

- **Description**: file that contains all the information regarding the experiment such as the domain, the model used, projection etc.

- **How to add a new experiment**: Add a new block to **config_experiment** with the _name of the experiment_ and add the information of the new experiment. These are the required fields:

| Field | Mandatory | Description |
| :-------- | :-------: | :--------- |
| **exp_name** | yes |  Name of the original experiment. |
| **path_in** | yes | Path to the input data. |
| **path_out** | yes | Path to the output data. |
| **domain_hclim** | yes | Name of domain in HCLIM. |
| **first_year** | yes | First year of the simulation. |
| **last_year** | yes | Last year of the simulation. |
| **calendar** | yes | ```standard``` |
| **activity_id** | yes | ```DD``` |
| **contact** | yes | Contact information. |
| **comment** | yes | |
| **domain** | yes | ```Europe```|
| **domain_id** | yes | ```EUR-12``` \| ```PARIS-2.5```|
| **driving_experiment** | yes | ```reanalysis simulation of the recent past```|
| **driving_experiment_id** | yes | ```evaluation```|
| **driving_institution** | yes | ```European Centre for Medium-Range Weather Forecasts, Reading RG2 9AX, UK```|
| **driving_institution_id** | yes | ```ECMWF```|
| **driving_source** | yes | ```ECMWF Reanalysis v5.1```|
| **driving_source_id** | yes | ```ERA5```|
| **driving_variant_label** | yes | ```r1i1p1f1```|
| **experiment** | yes | Description of the experiment, check the protocol of stage-1 (e.g.```Evaluation runs for Paris region```)|
| **experiment_id** | yes | ```URBRCC_EVAL``` \| ```URBRCC-EXT```|
| **experiment_version** | yes | ```v1-fpsurbrcc-s1r1```|
| **institution** | yes | ```HARMONIE Climate Modelling Community (HCLIMcom) partner: Swedish Meteorological and Hydrological Institute (SMHI), Norrkoping, Sweden``` \| ```HARMONIE Climate Modelling Community (HCLIMcom) partner: Royal Netherlands Meteorological Institute (KNMI), De Bilt, The Netherlands```|
| **institution_id** | yes | ```HCLIMcom-SMHI``` \| ```HCLIMcom-KNMI``` |
| **grid_info** | yes | ```Lambert conic conformal with XX km grid spacing ```. Substitute _XX_ by the horizontal resolution of the domain. |
| **project_id** | yes | ```CORDEX FPS URB-RCC \| stage-1```|
| **source** | yes | ```HARMONIE Climate model cycle 46 with XX physics```. Substitute _XX_ by ```ALADIN``` \| ```AROME```. |
| **source_id** | yes | ```HCLIM46-XX```. Substitute _XX_ by ```ALADIN``` \| ```AROME```. |
| **source_type** | yes | ```ARCM``` |
| **nested**  | yes | Is it a nested run? ```TRUE``` \| ```FALSE```|
| **parent_source** | if **nested**=```TRUE```| parent model source|
| **parent_source_type** | if **nested**=```TRUE``` | ```ARCM``` |
| **parent_source_id** | if **nested**=```TRUE``` | parent source id |
| **parent_domain_id** | if **nested**=```TRUE``` | parent domain id |

For more information check the [CORDEX-CMIP6 archiving specifications](https://cordex.org/wp-content/uploads/2023/11/CORDEX-CMIP6_archive_specs_SOD_landscape.pdf).

> [!NOTE]  
> This is the metadata for RACMO:
> - institution: Royal Netherlands Meteorological Institute (KNMI), De Bilt, The Netherlands
> - institution_id: KNMI
> - source: The KNMI Regional Climate Model RACMO, version xx
> - source_id: RACMOXX 
> XX corresponds to the version of RACMO.






















































    

