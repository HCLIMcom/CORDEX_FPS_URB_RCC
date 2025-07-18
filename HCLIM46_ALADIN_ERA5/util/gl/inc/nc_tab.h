!
! Template for FA 2 NETCDF translation
!
!TYPE nctrans
!        CHARACTER(LEN=clen)          :: full_name =' '          ! Full FA name
!        INTEGER(KIND=jpim)           :: uvrelativetogrid = -1   ! valid for output winds relative to projection grid(1), geographical coordinates(0) or irrelevant (-1)
!        CHARACTER(LEN=clen)          :: ncname =' '             ! NETCDF name
!        CHARACTER(LEN=clen)          :: unit =' '               ! Unit as given in NETCDF file
!        CHARACTER(LEN=full_name_len) :: s_name =' '             ! NETCDF standard name
!        CHARACTER(LEN=full_name_len) :: l_name =' '             ! NETCDF long name
!        CHARACTER(LEN=clen)          :: lev_type =' '           ! NETCDF lev type
!        CHARACTER(LEN=clen)          :: positive =' '           ! NETCDF direction of fluxes on output (d|u), when u, flux is multiplied by -1
!END TYPE nctrans
!
!
! Surface and near surface
!
i=i+1
nc_tab( i ) = nctrans('INTSURFGEOPOTENT',-1,'phis_i','m2 s-2','surface_geopotential_int','Surface Geopotential Interpolated','','')
i=i+1
nc_tab( i ) = nctrans('SPECSURFGEOPOTEN',-1,'phis_s','m2 s-2','surface_geopotential_spec','Surface Geopotential Spectral','','')
i=i+1
nc_tab( i ) = nctrans('SURFIND.TERREMER',-1,'lsm','1','land_sea_mask','Land Sea Mask','','')
i=i+1
nc_tab( i ) = nctrans('MSLPRESSURE'     ,-1,'psl','Pa','air_pressure_at_mean_sea_level','Sea Level Pressure','','')
i=i+1
nc_tab( i ) = nctrans('CLSTEMPERATURE'  ,-1,'tas','K','air_temperature','Near-Surface Air Temperature','','')
i=i+1
nc_tab( i ) = nctrans('CLSMAXI.TEMPERAT',-1,'tasmax','K','air_temperature','Maximum Near-Surface Air Temperature','','')
i=i+1
nc_tab( i ) = nctrans('CLSMINI.TEMPERAT',-1,'tasmin','K','air_temperature','Minimum Near-Surface Air Temperature','','')
i=i+1
nc_tab( i ) = nctrans('CLSVENT.ZONAL'   , 0,'uas','m s-1','eastward_wind','Eastward Near-Surface Wind Speed','','')
i=i+1
nc_tab( i ) = nctrans('CLSVENT.ZONAL'   , 1,'x_wind','m s-1','x_wind',&
                      'Eastward Near-Surface Wind Speed In Model Coordinates','','')
i=i+1
nc_tab( i ) = nctrans('CLSVENT.MERIDIEN', 0,'vas','m s-1','northward_wind','Northward Near-Surface Wind Speed','','')
i=i+1
nc_tab( i ) = nctrans('CLSVENT.MERIDIEN', 1,'y_wind','m s-1','y_wind',&
                      'Northward Near-Surface Wind Speed In Model Coordinates','','')
i=i+1
nc_tab( i ) = nctrans('CLSHUMI.SPECIFIQ',-1,'huss','1','specific_humidity','Near-Surface Specific Humidity','','')
i=i+1
nc_tab( i ) = nctrans('CLSHUMI.RELATIVE',-1,'hurs','1','relative_humidity','Near-Surface Relative Humidity','','')
i=i+1
nc_tab( i ) = nctrans('SURFPRESSION'    ,-1,'ps','Pa','surface_air_pressure','Surface Air Pressure','','')
i=i+1
nc_tab( i ) = nctrans('SURFTEMPERATURE' ,-1,'ts_rad','K','radiative_surface_temperature','Radiative Surface Temperature','','')
i=i+1
nc_tab( i ) = nctrans('SURFPREC.EAU.GEC',-1,'srain','kg m-2','stratiform_rainfall_amount','Accumulated Stratiform Rain','','')
i=i+1
nc_tab( i ) = nctrans('SURFPREC.EAU.CON',-1,'crain','kg m-2','convective_rainfall_amount','Accumulated Convective Rain','','')
i=i+1
nc_tab( i ) = nctrans('SURFPREC.NEI.GEC',-1,'ssn','kg m-2','stratiform_snowfall_amount','Accumulated Stratiform Snow','','')
i=i+1
nc_tab( i ) = nctrans('SURFPREC.NEI.CON',-1,'csn','kg m-2','convective_snowfall_amount','Accumulated Convective Snow','','')
i=i+1
nc_tab( i ) = nctrans('SURFRESERV.NEIGE',-1,'snw','kg m-2','surface_snow_amount','Snow Depth In Liquid Water Equivalent','','')
i=i+1
nc_tab( i ) = nctrans('SURFNEBUL.TOTALE',-1,'clt_ins','1','cloud_area_fraction','Total Cloud Fraction','','')
i=i+1
nc_tab( i ) = nctrans('SURFNEBUL.CONVEC',-1,'clc_ins','1','convective_cloud_area_fraction','Convective Cloud Fraction','','')
i=i+1
nc_tab( i ) = nctrans('SURFNEBUL.HAUTE' ,-1,'clh_ins','1','cloud_area_fraction_in_atmosphere_layer','High Cloud Cover','','')
i=i+1
nc_tab( i ) = nctrans('SURFNEBUL.MOYENN',-1,'clm_ins','1','cloud_area_fraction_in_atmosphere_layer','Medium Cloud Cover','','')
i=i+1
nc_tab( i ) = nctrans('SURFNEBUL.BASSE' ,-1,'cll_ins','1','cloud_area_fraction_in_atmosphere_layer','Low Cloud Cover','','')
i=i+1
nc_tab( i ) = nctrans('ATMONEBUL.TOTALE',-1,'clt','s','accumulated_cloud_area_fraction',&
                      'Accumulated Total Cloud Fraction','','')
i=i+1
nc_tab( i ) = nctrans('ATMONEBUL.HAUTE' ,-1,'clh','s','accumulated_cloud_area_fraction_in_atmosphere_layer',&
                      'Accumulated High Cloud Fraction','','')
i=i+1
nc_tab( i ) = nctrans('ATMONEBUL.MOYENN',-1,'clm','s','accumulated_cloud_area_fraction_in_atmosphere_layer',&
                      'Accumulated Medium Cloud Fraction','','')
i=i+1
nc_tab( i ) = nctrans('ATMONEBUL.BASSE' ,-1,'cll','s','accumulated_cloud_area_fraction_in_atmosphere_layer',&
                      'Accumulated Low Cloud Fraction','','')
i=i+1
nc_tab( i ) = nctrans('CLSMAX.WIND.VELO',-1,'sfcWindmax','m s-1','wind_speed','Maximum Near-Surface Wind Speed','','')
i=i+1
nc_tab( i ) = nctrans('CLSU.RAF.MOD.XFU', 0,'ugs','m s-1','eastward_wind_speed_of_gust',&
                      'Eastward Near-Surface Wind Gust Velocity','','')
i=i+1
nc_tab( i ) = nctrans('CLSU.RAF.MOD.XFU', 1,'x_wind_gust','m s-1','x_wind_gust',&
                      'Eastward Near-Surface Wind Gust Velocity In Model Coordinates','','')
i=i+1
nc_tab( i ) = nctrans('CLSV.RAF.MOD.XFU', 0,'vgs','m s-1','northward_wind_speed_of_gust',&
                      'Northward Near-Surface Wind Gust Velocity','','')
i=i+1
nc_tab( i ) = nctrans('CLSV.RAF.MOD.XFU', 1,'y_wind_gust','m s-1','y_wind_gust',&
                      'Northward Near-Surface Wind Gust Velocity In Model Coordinates','','')
i=i+1
nc_tab( i ) = nctrans('CLSRAFALES.POS'  ,-1,'wsgsmax','m s-1','max_near_surface_wind_speed_of_gust',&
                      'Maximum Near Surface Wind Speed of Gust','','')
i=i+1
nc_tab( i ) = nctrans('SURFTENS.TURB.ZO', 0,'tauu','kg m-1 s-1','accumulated_surface_downward_eastward_stress',&
                      'Accumulated Surface Downward Eastward Wind Stress','','d')
i=i+1
nc_tab( i ) = nctrans('SURFTENS.TURB.ZO', 1,'x_stress','kg m-1 s-1','accumulated_surface_downward_x_stress',&
                      'Accumulated Surface Downward Eastward Wind Stress In Model Coordinates','','d')
i=i+1
nc_tab( i ) = nctrans('SURFTENS.TURB.ME', 0,'tauv','kg m-1 s-1','accumulated_surface_downward_northward_stress',&
                      'Accumulated Surface Downward Northward Wind Stress','','d')
i=i+1
nc_tab( i ) = nctrans('SURFTENS.TURB.ME', 1,'y_stress','kg m-1 s-1','accumulated_surface_downward_y_stress',&
                      'Accumulated Surface Downward Northward Wind Stress In Model Coordinates','','d')
i=i+1
nc_tab( i ) = nctrans('SURFFLU.RAY.THER',-1,'rlns','J m-2','accumulated_surface_net_longwave_flux_in_air',&
                      'Accumulated Surface Net Longwave Radiation','','d')
i=i+1
nc_tab( i ) = nctrans('SURFFLU.RAY.SOLA',-1,'rsns','J m-2','accumulated_surface_net_shortwave_flux_in_air',&
                      'Accumulated Surface Net Shortwave Radiation','','d')
i=i+1
nc_tab( i ) = nctrans('SURFDIR NORM IRR',-1,'rids','J m-2','accumulated_surface_direct_normal_irradiance',&
                      'Accumulated Surface Direct Normal Irradiance','','d')
i=i+1
nc_tab( i ) = nctrans('SURFRAYT DIR SUR',-1,'rsdsdir','J m-2','accumulated_surface_direct_downwelling_shortwave_flux_in_air',&
                      'Accumulated Surface Direct Downwelling Shortwave Radiation','','d')
i=i+1
nc_tab( i ) = nctrans('SURFRAYT THER DE',-1,'rlds','J m-2','accumulated_surface_downwelling_longwave_flux_in_air',&
                      'Accumulated Surface Downwelling Longwave Radiation','','d')
i=i+1
nc_tab( i ) = nctrans('SURFRAYT SOLA DE',-1,'rsds','J m-2','accumulated_surface_downwelling_shortwave_flux_in_air',&
                      'Accumulated Surface Downwelling Shortwave Radiation','','d')
i=i+1
nc_tab( i ) = nctrans('SURFRAYT THER CL',-1,'rlnscs','J m-2','accumulated_surface_net_longwave_flux_in_air_assuming_clear_sky',&
                      'Accumulated Surface Net Clear-Sky Longwave Radiation','','d')
i=i+1
nc_tab( i ) = nctrans('SURFRAYT SOL CL' ,-1,'rsnscs','J m-2','accumulated_surface_net_shortwave_flux_in_air_assuming_clear_sky',&
                      'Accumulated Surface Net Clear-Sky Shortwave Radiation','','d')
i=i+1
nc_tab( i ) = nctrans('SUNSHI. DURATION',-1,'sund','s','duration_of_sunshine', 'Daily Duration of Sunshine','','')
i=i+1
nc_tab( i ) = nctrans('SURFFLU.CHA.SENS',-1,'hfss','J m-2','accumulated_surface_upward_sensible_heat_flux',&
                      'Accumulated Surface Upward Sensible Heat Flux','','u')
i=i+1
nc_tab( i ) = nctrans('SURFFLU.LAT.MTOT',-1,'hfls','J m-2','accumulated_surface_upward_latent_heat_flux',&
                      'Accumulated Surface Upward Latent Heat Flux','','u')
i=i+1
nc_tab( i ) = nctrans('SURFFLU.LAT.MEVA',-1,'hfls_eva','J m-2','accumulated_surface_upward_latent_heat_flux_due_to_evaporation',&
                      'Accumulated Surface Upward Latent Heat Flux Due To Evaporation','','u')
i=i+1
nc_tab( i ) = nctrans('SURFFLU.LAT.MSUB',-1,'hfls_sbl','J m-2','accumulated_surface_upward_latent_heat_flux_due_to_sublimation',&
                      'Accumulated Surface Upward Latent Heat Flux Due To Sublimation','','u')
i=i+1
nc_tab( i ) = nctrans('SURFFLU.MEVAP.EA',-1,'evapt','kg m-2','water_evapotranspiration_amount',&
                      'Accumulated Surface Water Evaporation','','u')
i=i+1
nc_tab( i ) = nctrans('SURFFLU.MSUBL.NE',-1,'sbl_snow','kg m-2','surface_snow_sublimation_amount',&
                      'Accumulated Surface Snow Sublimation','','u')
i=i+1
nc_tab( i ) = nctrans('SURFFLU.MTOTA.NE',-1,'evspsbl','kg m-2','water_evapotranspiration_amount',&
                      'Accumulated Evaporation Including Sublimation and Transpiration','','u')

! Arome specific
i=i+1
nc_tab( i ) = nctrans('SURFACCPLUIE'    ,-1,'prrain','kg m-2','rainfall_amount','Accumulated Rain','','')
i=i+1
nc_tab( i ) = nctrans('SURFACCNEIGE'    ,-1,'prsn','kg m-2','snowfall_amount','Accumulated Snowfall','','')
i=i+1
nc_tab( i ) = nctrans('SURFACCGRAUPEL'  ,-1,'prgrpl','kg m-2','graupel_amount','Accumulated Graupel','','')
i=i+1
nc_tab( i ) = nctrans('SURFACCHAIL'     ,-1,'prha','kg m-2','hail_amount','Accumulated Hail','','')

!
! 2D diagnostic
!
i=i+1
nc_tab( i ) = nctrans('SURFCAPE.MOD.XFU',-1,'cape','J kg-1','atmosphere_convective_available_potential_energy_wrt_surface',&
                      'Convective Available Potential Energy','','')
i=i+1
nc_tab( i ) = nctrans('SURFCAPE.POS.F00',-1,'cape','J kg-1','atmosphere_convective_available_potential_energy_wrt_surface',&
                      'Convective Available Potential Energy','','')
i=i+1
nc_tab( i ) = nctrans('SURFCIEN.POS.F00',-1,'cin','J kg-1','atmosphere_convective_inhibition_wrt_surface',&
                      'Convective Inhibition','','')
i=i+1
nc_tab( i ) = nctrans('CAPE.POS'        ,-1,'pcape','J kg-1','postprocessed_cape','Postprocessed CAPE','')
i=i+1
nc_tab( i ) = nctrans('CIEN.POS'        ,-1,'pcin','J kg-1','postprocessed cin','Postprocessed CIN','')
i=i+1
nc_tab( i ) = nctrans('CLPMHAUT.MOD.XFU',-1,'zmla','m','atmosphere_boundary_layer_thickness','Height of Boundary Layer','','')
i=i+1
nc_tab( i ) = nctrans('SURFTOT.WAT.VAPO',-1,'prw','kg m-2','atmosphere_mass_content_of_water_vapor','Water Vapor Path','','')


!
! Top Of Atmosphere
!

i=i+1
nc_tab( i ) = nctrans('TOPRAYT DIR SOM' ,-1,'rsdt','J m-2','accumulated_toa_incoming_shortwave_flux',&
                      'Accumulated TOA Incident Shortwave Radiation','','d')
i=i+1
nc_tab( i ) = nctrans('SOMMFLU.RAY.SOLA',-1,'rsnt','J m-2','accumulated_toa_net_shortwave_flux',&
                      'Accumulated TOA Net Shortwave Radiation','','d')
i=i+1
nc_tab( i ) = nctrans('SOMMFLU.RAY.THER',-1,'rlnt','J m-2','accumulated_toa_net_longwave_flux',&
                      'Accumulated TOA Net Longwave Radiation','','d')
i=i+1
nc_tab( i ) = nctrans('S001RAYT THER CL',-1,'rlntcs_1','J m-2','toa_lw_clear_sky_radiation','TOA LW clear sky radiation','','d')
i=i+1
nc_tab( i ) = nctrans('S001RAYT SOL CL' ,-1,'rsntcs_1','J m-2','toa_sw_clear_sky_radiation','TOA SW clear sky radiation','','d')
i=i+1
nc_tab( i ) = nctrans('SOMMRAYT SOL CL' ,-1,'rsntcs','J m-2','accumulated_toa_net_downward_shortwave_flux_assuming_clear_sky', &
                      'Accumulated TOA Net Clear-Sky Shortwave Radiation','','d')
i=i+1
nc_tab( i ) = nctrans('SOMMRAYT THER CL',-1,'rlntcs','J m-2','accumulated_toa_net_downward_longwave_flux_assuming_clear_sky', &
                      'Accumulated TOA Net Clear-Sky Longwave Radiation','','d')


!
! SURFEX
!

i=i+1
nc_tab( i ) = nctrans('ZON10M'          , 0,'uas','m s-1','eastward_wind','Eastward Near-Surface Wind Speed','','')
i=i+1
nc_tab( i ) = nctrans('ZON10M'          , 1,'x_wind','m s-1','x_wind',&
                      'Eastward Near-Surface Wind Speed In Model Coordinates','','')
i=i+1
nc_tab( i ) = nctrans('MER10M'          , 0,'vas','m s-1','northward_wind','Northward Near-Surface Wind Speed','','')
i=i+1
nc_tab( i ) = nctrans('MER10M'          , 1,'y_wind','m s-1','y_wind',&
                      'Northward Near-Surface Wind Speed In Model Coordinates','','')
i=i+1
nc_tab( i ) = nctrans('W10M'            ,-1,'sfcWind','m s-1','wind_speed','Near-Surface Wind Speed','','')
i=i+1
nc_tab( i ) = nctrans('W10MMAX'         ,-1,'sfcWindmax','m s-1','wind_speed','Maximum Near-Surface Wind Speed','','')
i=i+1
nc_tab( i ) = nctrans('T2MMAX'          ,-1,'tasmax','K','air_temperature','Maximum Near-Surface Air Temperature','','')
i=i+1
nc_tab( i ) = nctrans('T2MMIN'          ,-1,'tasmin','K','air_temperature','Minimum Near-Surface Air Temperature','','')
i=i+1
nc_tab( i ) = nctrans('T2M'             ,-1,'tas','K','air_temperature','Near-Surface Air Temperature','','')
i=i+1
nc_tab( i ) = nctrans('TS'              ,-1,'ts','K','surface_temperature','Surface Temperature','','')
i=i+1
nc_tab( i ) = nctrans('TSRAD'           ,-1,'ts_rad','K','radiative_surface_temperature','Radiative Surface Temperature','','')
i=i+1
nc_tab( i ) = nctrans('Q2M'             ,-1,'huss','kg kg-1','specific_humidity','Near-surface Specific Humidity','','')
i=i+1
nc_tab( i ) = nctrans('HU2M'            ,-1,'hurs','1','relative_humidity','Near-surface Relative Humidity','','')
i=i+1
nc_tab( i ) = nctrans('HU2MMIN'         ,-1,'hursmin','1','relative_humidity','Minimum Near-surface Relative Humidity','','')
i=i+1
nc_tab( i ) = nctrans('HU2MMAX'         ,-1,'hursmax','1','relative_humidity','Maximum Near-surface Relative Humidity','','')
i=i+1
nc_tab( i ) = nctrans('SWUC'            ,-1,'rsus','J m-2','accumulated_surface_upwelling_shortwave_flux_in_air',&
                      'Accumulated Surface Upwelling Shortwave Radiation','','')
i=i+1
nc_tab( i ) = nctrans('LWUC'            ,-1,'rlus','J m-2','accumulated_surface_upwelling_longwave_flux_in_air',&
                      'Accumulated Surface Upwelling Longwave Radiation','','')
i=i+1
nc_tab( i ) = nctrans('LWDC'            ,-1,'rlds','J m-2','accumulated_surface_downwelling_longwave_flux_in_air',&
                      'Accumulated Surface Downwelling Longwave Radiation','','')
i=i+1
nc_tab( i ) = nctrans('SWDC'            ,-1,'rsds','J m-2','accumulated_surface_downwelling_shortwave_flux_in_air',&
                      'Accumulated Surface Downwelling Shortwave Radiation','','')
i=i+1
nc_tab( i ) = nctrans('HC'              ,-1,'hfss','J m-2','accumulated_surface_upward_sensible_heat_flux',&
                      'Accumulated Surface Upward Sensible Heat Flux','','')
i=i+1
nc_tab( i ) = nctrans('LEC'             ,-1,'hfls','J m-2','accumulated_surface_upward_latent_heat_flux',&
                      'Accumulated Surface Upward latent heat flux','','')
i=i+1
nc_tab( i ) = nctrans('RNC'             ,-1,'rns','J m-2','accumulated_surface_net_radiation',&
		              'Accumulated Surface Net Radiation','','')
i=i+1
nc_tab( i ) = nctrans('FMUC'            , 0,'tauu','kg m-1 s-1','accumulated_surface_downward_eastward_stress',&
                      'Accumulated Surface Downward Eastward Wind Stress','','d')
i=i+1
nc_tab( i ) = nctrans('FMUC'            , 1,'x_stress','kg m-1 s-1','accumulated_surface_downward_x_stress',&
                      'Accumulated Surface Downward Eastward Wind Stress In Model Coordinates','','d')
i=i+1
nc_tab( i ) = nctrans('FMVC'            , 0,'tauv','kg m-1 s-1','accumulated_surface_downward_northward_stress',&
                      'Accumulated Surface Downward Northward Wind Stress','','d')
i=i+1
nc_tab( i ) = nctrans('FMVC'            , 1,'y_stress','kg m-1 s-1','accumulated_surface_downward_y_stress',&
                      'Accumulated Surface Downward Northward Wind Stress In Model Coordinates','','d')
i=i+1
nc_tab( i ) = nctrans('EVAPC'           ,-1,'evapt','kg m-2','water_evapotranspiration_amount',&
                      'Accumulated Evapotranspiration','','')
i=i+1
nc_tab( i ) = nctrans('H'               ,-1,'hfssi','J m-2 s-1','instantaneous_surface_upward_sensible_heat_flux',&
                      'Accumulated Surface Upward Sensible Heat Flux','','')
i=i+1
nc_tab( i ) = nctrans('LE'              ,-1,'hflsi','J m-2 s-1','instantaneous_surface_upward_latent_heat_flux',&
                      'Accumulated Surface Upward latent heat flux','','')
i=i+1
nc_tab( i ) = nctrans('RN'              ,-1,'rnsi','J m-2 s-1','instantaneous_surface_net_radiation', &
                      'Accumulated Surface Net Radiation','','')
i=i+1
nc_tab( i ) = nctrans('FMU'             , 0,'tauui','kg m-1 s-2','instantaneous_surface_downward_eastward_stress',&
                      'Instantaneous Surface Downward Eastward Wind Stress','','d')
i=i+1
nc_tab( i ) = nctrans('FMU'             , 1,'x_stressi','kg m-1 s-2','instantaneous_surface_downward_x_stress',&
                      'Instantaneous Surface Downward Eastward Wind Stress In Model Coordinates','','d')
i=i+1
nc_tab( i ) = nctrans('FMV'             , 0,'tauvi','kg m-1 s-2','instantaneous_surface_downward_northward_stress',&
                      'Instantaneous Surface Downward Northward Wind Stress','','d')
i=i+1
nc_tab( i ) = nctrans('FMV'             , 1,'y_stress1','kg m-1 s-2','instantaneous_surface_downward_y_stress',&
                      'Instantaneous Surface Downward Northward Wind Stress In Model Coordinates','','d')
i=i+1
nc_tab( i ) = nctrans('CD'              ,-1,'cddr','-','drag_coefficient_for_momentum','Drag coefficient for momentum','','')
i=i+1
nc_tab( i ) = nctrans('CE'              ,-1,'cedr','-','drag_coefficient_for_humidity','Drag coefficient for humidity','','')
i=i+1
nc_tab( i ) = nctrans('CH'              ,-1,'chdr','-','drag_coefficient_for_heat','Drag coefficient for heat','','')
i=i+1
nc_tab( i ) = nctrans('GFLUXC'          ,-1,'gfl','J m-2','accumulated_ground_conduct_flux', &
                      'Accumulated Surface Conduct Flux','','')
i=i+1
nc_tab( i ) = nctrans('GFLUX'           ,-1,'gfli','J m-2 s-1','instantaneous_ground_conduct_flux',&
                      'Instantaneous Surface Conduct Flux','','')
i=i+1
nc_tab( i ) = nctrans('Z0'              ,-1,'z0','m','surface_roughness_length','Surface Roughness Length','','')
i=i+1
nc_tab( i ) = nctrans('Z0H'             ,-1,'z0h','m','surface_roughness_length_for_heat_in_air',&
                      'Surface Roughness Length For Heat In Air','','')
i=i+1
nc_tab( i ) = nctrans('DX'              ,-1,'dx','m','grid_dx','Grid DX','','')
i=i+1
nc_tab( i ) = nctrans('DY'              ,-1,'dy','m','grid_dy','Grid DY','','')
i=i+1
nc_tab( i ) = nctrans('ZS'              ,-1,'orog','m','surface_altitude','Surface Altitude','','')
i=i+1
nc_tab( i ) = nctrans('FRAC_SEA'        ,-1,'sftof','1','sea_area_fraction','Fraction of the Grid Cell Occupied by Sea','','')
i=i+1
nc_tab( i ) = nctrans('FRAC_WATER'      ,-1,'sftlaf','1','lake_area_fraction','Fraction of the Grid Cell Occupied by Lake','','')
i=i+1
nc_tab( i ) = nctrans('FRAC_NATURE'     ,-1,'sftnf','1','nature_area_fraction',&
                      'Fraction of the Grid Cell Occupied by Nature','','')
i=i+1
nc_tab( i ) = nctrans('FRAC_TOWN'       ,-1,'sfturf','1','urban_area_fraction','Fraction of the Grid Cell Occupied by City','','')
i=i+1
nc_tab( i ) = nctrans('RI'              ,-1,'rin','-','Richardson_number','Richardson Number','','')
i=i+1
nc_tab( i ) = nctrans('EMIS'            ,-1,'emis','1','surface_emissivity','Surface Emissivity','','')

! Ecoclimap

i=i+1
nc_tab( i ) = nctrans('COVER001'        ,-1,'lsm','-','land_sea_mask','Land Sea Mask','')

! Layers

i=i+1
nc_tab( i ) = nctrans('TG1'             ,-1,'tg_L01','K','soil_temperature','Soil Layer 1 Temperature','X','')
i=i+1
nc_tab( i ) = nctrans('TG2'             ,-1,'tg_L02','K','soil_temperature','Soil Layer 2 Temperature','X','')
i=i+1
nc_tab( i ) = nctrans('TG3'             ,-1,'tg_L03','K','soil_temperature','Soil Layer 3 Temperature','X','')
i=i+1
nc_tab( i ) = nctrans('TG4'             ,-1,'tg_L04','K','soil_temperature','Soil Layer 4 Temperature','X','')
i=i+1
nc_tab( i ) = nctrans('TG5'             ,-1,'tg_L05','K','soil_temperature','Soil Layer 5 Temperature','X','')
i=i+1
nc_tab( i ) = nctrans('TG6'             ,-1,'tg_L06','K','soil_temperature','Soil Layer 6 Temperature','X','')
i=i+1
nc_tab( i ) = nctrans('TG7'             ,-1,'tg_L07','K','soil_temperature','Soil Layer 7 Temperature','X','')
i=i+1
nc_tab( i ) = nctrans('TG8'             ,-1,'tg_L08','K','soil_temperature','Soil Layer 8 Temperature','X','')
i=i+1
nc_tab( i ) = nctrans('TG9'             ,-1,'tg_L09','K','soil_temperature','Soil Layer 9 Temperature','X','')
i=i+1
nc_tab( i ) = nctrans('TG10'            ,-1,'tg_L10','K','soil_temperature','Soil Layer 10 Temperature','X','')
i=i+1
nc_tab( i ) = nctrans('TG11'            ,-1,'tg_L11','K','soil_temperature','Soil Layer 11 Temperature','X','')
i=i+1
nc_tab( i ) = nctrans('TG12'            ,-1,'tg_L12','K','soil_temperature','Soil Layer 12 Temperature','X','')
i=i+1
nc_tab( i ) = nctrans('TG13'            ,-1,'tg_L13','K','soil_temperature','Soil Layer 13 Temperature','X','')
i=i+1
nc_tab( i ) = nctrans('TG14'            ,-1,'tg_L14','K','soil_temperature','Soil Layer 14 Temperature','X','')
i=i+1
nc_tab( i ) = nctrans('WG1'             ,-1,'wsa_L01','m3 m-3','volume_fraction_of_liquid_water_in_soil_layer',&
                      'Volume Fraction Of Liquid Water In Soil Layer 1','X','')
i=i+1
nc_tab( i ) = nctrans('WG2'             ,-1,'wsa_L02','m3 m-3','volume_fraction_of_liquid_water_in_soil_layer',&
                      'Volume Fraction Of Liquid Water In Soil Layer 2','X','')
i=i+1
nc_tab( i ) = nctrans('WG3'             ,-1,'wsa_L03','m3 m-3','volume_fraction_of_liquid_water_in_soil_layer',&
                      'Volume Fraction Of Liquid Water In Soil Layer 3','X','')
i=i+1
nc_tab( i ) = nctrans('WG4'             ,-1,'wsa_L04','m3 m-3','volume_fraction_of_liquid_water_in_soil_layer',&
                      'Volume Fraction Of Liquid Water In Soil Layer 4','X','')
i=i+1
nc_tab( i ) = nctrans('WG5'             ,-1,'wsa_L05','m3 m-3','volume_fraction_of_liquid_water_in_soil_layer',&
                      'Volume Fraction Of Liquid Water In Soil Layer 5','X','')
i=i+1
nc_tab( i ) = nctrans('WG6'             ,-1,'wsa_L06','m3 m-3','volume_fraction_of_liquid_water_in_soil_layer',&
                      'Volume Fraction Of Liquid Water In Soil Layer 6','X','')
i=i+1
nc_tab( i ) = nctrans('WG7'             ,-1,'wsa_L07','m3 m-3','volume_fraction_of_liquid_water_in_soil_layer',&
                      'Volume Fraction Of Liquid Water In Soil Layer 7','X','')
i=i+1
nc_tab( i ) = nctrans('WG8'             ,-1,'wsa_L08','m3 m-3','volume_fraction_of_liquid_water_in_soil_layer',&
                      'Volume Fraction Of Liquid Water In Soil Layer 8','X','')
i=i+1
nc_tab( i ) = nctrans('WG9'             ,-1,'wsa_L09','m3 m-3','volume_fraction_of_liquid_water_in_soil_layer',&
                      'Volume Fraction Of Liquid Water In Soil Layer 9','X','')
i=i+1
nc_tab( i ) = nctrans('WG10'            ,-1,'wsa_L10','m3 m-3','volume_fraction_of_liquid_water_in_soil_layer',&
                      'Volume Fraction Of Liquid Water In Soil Layer 10','X','')
i=i+1
nc_tab( i ) = nctrans('WG11'            ,-1,'wsa_L11','m3 m-3','volume_fraction_of_liquid_water_in_soil_layer',&
                      'Volume Fraction Of Liquid Water In Soil Layer 11','X','')
i=i+1
nc_tab( i ) = nctrans('WG12'            ,-1,'wsa_L12','m3 m-3','volume_fraction_of_liquid_water_in_soil_layer',&
                      'Volume Fraction Of Liquid Water In Soil Layer 12','X','')
i=i+1
nc_tab( i ) = nctrans('WG13'            ,-1,'wsa_L13','m3 m-3','volume_fraction_of_liquid_water_in_soil_layer',&
                      'Volume Fraction Of Liquid Water In Soil Layer 13','X','')
i=i+1
nc_tab( i ) = nctrans('WG14'            ,-1,'wsa_L14','m3 m-3','volume_fraction_of_liquid_water_in_soil_layer',&
                      'Volume Fraction Of Liquid Water In Soil Layer 14','X','')
i=i+1
nc_tab( i ) = nctrans('WGI1'            ,-1,'isa_L01','m3 m-3','volume_fraction_of_frozen_water_in_soil_layer',&
                      'Volume Fraction Of Frozen Water In Soil Layer 1','X','')
i=i+1
nc_tab( i ) = nctrans('WGI2'            ,-1,'isa_L02','m3 m-3','volume_fraction_of_frozen_water_in_soil_layer',&
                      'Volume Fraction Of Frozen Water In Soil Layer 2','X','')
i=i+1
nc_tab( i ) = nctrans('WGI3'            ,-1,'isa_L03','m3 m-3','volume_fraction_of_frozen_water_in_soil_layer',&
                      'Volume Fraction Of Frozen Water In Soil Layer 3','X','')
i=i+1
nc_tab( i ) = nctrans('WGI4'            ,-1,'isa_L04','m3 m-3','volume_fraction_of_frozen_water_in_soil_layer',&
                      'Volume Fraction Of Frozen Water In Soil Layer 4','X','')
i=i+1
nc_tab( i ) = nctrans('WGI5'            ,-1,'isa_L05','m3 m-3','volume_fraction_of_frozen_water_in_soil_layer',&
                      'Volume Fraction Of Frozen Water In Soil Layer 5','X','')
i=i+1
nc_tab( i ) = nctrans('WGI6'            ,-1,'isa_L06','m3 m-3','volume_fraction_of_frozen_water_in_soil_layer',&
                      'Volume Fraction Of Frozen Water In Soil Layer 6','X','')
i=i+1
nc_tab( i ) = nctrans('WGI7'            ,-1,'isa_L07','m3 m-3','volume_fraction_of_frozen_water_in_soil_layer',&
                      'Volume Fraction Of Frozen Water In Soil Layer 7','X','')
i=i+1
nc_tab( i ) = nctrans('WGI8'            ,-1,'isa_L08','m3 m-3','volume_fraction_of_frozen_water_in_soil_layer',&
                      'Volume Fraction Of Frozen Water In Soil Layer 8','X','')
i=i+1
nc_tab( i ) = nctrans('WGI9'            ,-1,'isa_L09','m3 m-3','volume_fraction_of_frozen_water_in_soil_layer',&
                      'Volume Fraction Of Frozen Water In Soil Layer 9','X','')
i=i+1
nc_tab( i ) = nctrans('WGI10'           ,-1,'isa_L10','m3 m-3','volume_fraction_of_frozen_water_in_soil_layer',&
                      'Volume Fraction Of Frozen Water In Soil Layer 10','X','')
i=i+1
nc_tab( i ) = nctrans('WGI11'           ,-1,'isa_L11','m3 m-3','volume_fraction_of_frozen_water_in_soil_layer',&
                      'Volume Fraction Of Frozen Water In Soil Layer 11','X','')
i=i+1
nc_tab( i ) = nctrans('WGI12'           ,-1,'isa_L12','m3 m-3','volume_fraction_of_frozen_water_in_soil_layer',&
                      'Volume Fraction Of Frozen Water In Soil Layer 12','X','')
i=i+1
nc_tab( i ) = nctrans('WGI13'           ,-1,'isa_L13','m3 m-3','volume_fraction_of_frozen_water_in_soil_layer',&
                      'Volume Fraction Of Frozen Water In Soil Layer 13','X','')
i=i+1
nc_tab( i ) = nctrans('WGI14'           ,-1,'isa_L14','m3 m-3','volume_fraction_of_frozen_water_in_soil_layer',&
                      'Volume Fraction Of Frozen Water In Soil Layer 14','X','')
i=i+1
nc_tab( i ) = nctrans('TSWI1_P'         ,-1,'tswi_L01','-','total_soil_wetness_index','Total Soil Wetness Index Layer 1','X','')
i=i+1
nc_tab( i ) = nctrans('TSWI2_P'         ,-1,'tswi_L02','-','total_soil_wetness_index','Total Soil Wetness Index Layer 2','X','')
i=i+1
nc_tab( i ) = nctrans('TSWI3_P'         ,-1,'tswi_L03','-','total_soil_wetness_index','Total Soil Wetness Index Layer 3','X','')
i=i+1
nc_tab( i ) = nctrans('TSWI4_P'         ,-1,'tswi_L04','-','total_soil_wetness_index','Total Soil Wetness Index Layer 4','X','')
i=i+1
nc_tab( i ) = nctrans('TSWI5_P'         ,-1,'tswi_L05','-','total_soil_wetness_index','Total Soil Wetness Index Layer 5','X','')
i=i+1
nc_tab( i ) = nctrans('TSWI6_P'         ,-1,'tswi_L06','-','total_soil_wetness_index','Total Soil Wetness Index Layer 6','X','')
i=i+1
nc_tab( i ) = nctrans('TSWI7_P'         ,-1,'tswi_L07','-','total_soil_wetness_index','Total Soil Wetness Index Layer 7','X','')
i=i+1
nc_tab( i ) = nctrans('TSWI8_P'         ,-1,'tswi_L08','-','total_soil_wetness_index','Total Soil Wetness Index Layer 8','X','')
i=i+1
nc_tab( i ) = nctrans('TSWI9_P'         ,-1,'tswi_L09','-','total_soil_wetness_index','Total Soil Wetness Index Layer 9','X','')
i=i+1
nc_tab( i ) = nctrans('TSWI10_P'        ,-1,'tswi_L10','-','total_soil_wetness_index','Total Soil Wetness Index Layer 10','X','')
i=i+1
nc_tab( i ) = nctrans('TSWI11_P'        ,-1,'tswi_L11','-','total_soil_wetness_index','Total Soil Wetness Index Layer 11','X','')
i=i+1
nc_tab( i ) = nctrans('TSWI12_P'        ,-1,'tswi_L12','-','total_soil_wetness_index','Total Soil Wetness Index Layer 12','X','')
i=i+1
nc_tab( i ) = nctrans('TSWI13_P'        ,-1,'tswi_L13','-','total_soil_wetness_index','Total Soil Wetness Index Layer 13','X','')
i=i+1
nc_tab( i ) = nctrans('TSWI14_P'        ,-1,'tswi_L14','-','total_soil_wetness_index','Total Soil Wetness Index Layer 14','X','')
i=i+1
nc_tab( i ) = nctrans('WWILT1'          ,-1,'wwilt_L01','m3 m-3','volume_fraction_of_moisture_of_soil_layer_at_wilting_point',&
                      'Volume Fraction Of Moisture At Wilting Point Layer 1','','')
i=i+1
nc_tab( i ) = nctrans('WWILT2'          ,-1,'wwilt_L02','m3 m-3','volume_fraction_of_moisture_of_soil_layer_at_wilting_point',&
                      'Volume Fraction Of Moisture At Wilting Point Layer 2','','')
i=i+1
nc_tab( i ) = nctrans('WWILT3'          ,-1,'wwilt_L03','m3 m-3','volume_fraction_of_moisture_of_soil_layer_at_wilting_point',&
                      'Volume Fraction Of Moisture At Wilting Point Layer 3','','')
i=i+1
nc_tab( i ) = nctrans('WWILT4'          ,-1,'wwilt_L04','m3 m-3','volume_fraction_of_moisture_of_soil_layer_at_wilting_point',&
                      'Volume Fraction Of Moisture At Wilting Point Layer 4','','')
i=i+1
nc_tab( i ) = nctrans('WWILT5'          ,-1,'wwilt_L05','m3 m-3','volume_fraction_of_moisture_of_soil_layer_at_wilting_point',&
                      'Volume Fraction Of Moisture At Wilting Point Layer 5','','')
i=i+1
nc_tab( i ) = nctrans('WWILT6'          ,-1,'wwilt_L06','m3 m-3','volume_fraction_of_moisture_of_soil_layer_at_wilting_point',&
                      'Volume Fraction Of Moisture At Wilting Point Layer 6','','')
i=i+1
nc_tab( i ) = nctrans('WWILT7'          ,-1,'wwilt_L07','m3 m-3','volume_fraction_of_moisture_of_soil_layer_at_wilting_point',&
                      'Volume Fraction Of Moisture At Wilting Point Layer 7','','')
i=i+1
nc_tab( i ) = nctrans('WWILT8'          ,-1,'wwilt_L08','m3 m-3','volume_fraction_of_moisture_of_soil_layer_at_wilting_point',&
                      'Volume Fraction Of Moisture At Wilting Point Layer 8','','')
i=i+1
nc_tab( i ) = nctrans('WWILT9'          ,-1,'wwilt_L09','m3 m-3','volume_fraction_of_moisture_of_soil_layer_at_wilting_point',&
                      'Volume Fraction Of Moisture At Wilting Point Layer 9','','')
i=i+1
nc_tab( i ) = nctrans('WWILT10'         ,-1,'wwilt_L10','m3 m-3','volume_fraction_of_moisture_of_soil_layer_at_wilting_point',&
                      'Volume Fraction Of Moisture At Wilting Point Layer 10','','')
i=i+1
nc_tab( i ) = nctrans('WWILT11'         ,-1,'wwilt_L11','m3 m-3','volume_fraction_of_moisture_of_soil_layer_at_wilting_point',&
                      'Volume Fraction Of Moisture At Wilting Point Layer 11','','')
i=i+1
nc_tab( i ) = nctrans('WWILT12'         ,-1,'wwilt_L12','m3 m-3','volume_fraction_of_moisture_of_soil_layer_at_wilting_point',&
                      'Volume Fraction Of Moisture At Wilting Point Layer 12','','')
i=i+1
nc_tab( i ) = nctrans('WWILT13'         ,-1,'wwilt_L13','m3 m-3','volume_fraction_of_moisture_of_soil_layer_at_wilting_point',&
                      'Volume Fraction Of Moisture At Wilting Point Layer 13','','')
i=i+1
nc_tab( i ) = nctrans('WWILT14'         ,-1,'wwilt_L14','m3 m-3','volume_fraction_of_moisture_of_soil_layer_at_wilting_point',&
                      'Volume Fraction Of Moisture At Wilting Point Layer 14','','')
i=i+1
nc_tab( i ) = nctrans('WFC1'            ,-1,'wfc_L01','m3 m-3','volume_fraction_of_moisture_of_soil_layer_at_field_capacity',&
                      'Volume Fraction Of Moisture At Field Capacity Layer 1','','')
i=i+1
nc_tab( i ) = nctrans('WFC2'            ,-1,'wfc_L02','m3 m-3','volume_fraction_of_moisture_of_soil_layer_at_field_capacity',&
                      'Volume Fraction Of Moisture At Field Capacity Layer 2','','')
i=i+1
nc_tab( i ) = nctrans('WFC3'            ,-1,'wfc_L03','m3 m-3','volume_fraction_of_moisture_of_soil_layer_at_field_capacity',&
                      'Volume Fraction Of Moisture At Field Capacity Layer 3','','')
i=i+1
nc_tab( i ) = nctrans('WFC4'            ,-1,'wfc_L04','m3 m-3','volume_fraction_of_moisture_of_soil_layer_at_field_capacity',&
                      'Volume Fraction Of Moisture At Field Capacity Layer 4','','')
i=i+1
nc_tab( i ) = nctrans('WFC5'            ,-1,'wfc_L05','m3 m-3','volume_fraction_of_moisture_of_soil_layer_at_field_capacity',&
                      'Volume Fraction Of Moisture At Field Capacity Layer 5','','')
i=i+1
nc_tab( i ) = nctrans('WFC6'            ,-1,'wfc_L06','m3 m-3','volume_fraction_of_moisture_of_soil_layer_at_field_capacity',&
                      'Volume Fraction Of Moisture At Field Capacity Layer 6','','')
i=i+1
nc_tab( i ) = nctrans('WFC7'            ,-1,'wfc_L07','m3 m-3','volume_fraction_of_moisture_of_soil_layer_at_field_capacity',&
                      'Volume Fraction Of Moisture At Field Capacity Layer 7','','')
i=i+1
nc_tab( i ) = nctrans('WFC8'            ,-1,'wfc_L08','m3 m-3','volume_fraction_of_moisture_of_soil_layer_at_field_capacity',&
                      'Volume Fraction Of Moisture At Field Capacity Layer 8','','')
i=i+1
nc_tab( i ) = nctrans('WFC9'            ,-1,'wfc_L09','m3 m-3','volume_fraction_of_moisture_of_soil_layer_at_field_capacity',&
                      'Volume Fraction Of Moisture At Field Capacity Layer 9','','')
i=i+1
nc_tab( i ) = nctrans('WFC10'           ,-1,'wfc_L10','m3 m-3','volume_fraction_of_moisture_of_soil_layer_at_field_capacity',&
                      'Volume Fraction Of Moisture At Field Capacity Layer 10','','')
i=i+1
nc_tab( i ) = nctrans('WFC11'           ,-1,'wfc_L11','m3 m-3','volume_fraction_of_moisture_of_soil_layer_at_field_capacity',&
                      'Volume Fraction Of Moisture At Field Capacity Layer 11','','')
i=i+1
nc_tab( i ) = nctrans('WFC12'           ,-1,'wfc_L12','m3 m-3','volume_fraction_of_moisture_of_soil_layer_at_field_capacity',&
                      'Volume Fraction Of Moisture At Field Capacity Layer 12','','')
i=i+1
nc_tab( i ) = nctrans('WFC13'           ,-1,'wfc_L13','m3 m-3','volume_fraction_of_moisture_of_soil_layer_at_field_capacity',&
                      'Volume Fraction Of Moisture At Field Capacity Layer 13','','')
i=i+1
nc_tab( i ) = nctrans('WFC14'           ,-1,'wfc_L14','m3 m-3','volume_fraction_of_moisture_of_soil_layer_at_field_capacity',&
                      'Volume Fraction Of Moisture At Field Capacity Layer 14','','')
i=i+1
nc_tab( i ) = nctrans('WSAT1'           ,-1,'wsat_L01','m3 m-3','volume_fraction_of_moisture_of_soil_layer_at_saturation_capacity',&
                      'Volume Fraction Of Moisture At Saturation Capacity Layer 1','','')
i=i+1
nc_tab( i ) = nctrans('WSAT2'           ,-1,'wsat_L02','m3 m-3','volume_fraction_of_moisture_of_soil_layer_at_saturation_capacity',&
                      'Volume Fraction Of Moisture At Saturation Capacity Layer 2','','')
i=i+1
nc_tab( i ) = nctrans('WSAT3'           ,-1,'wsat_L03','m3 m-3','volume_fraction_of_moisture_of_soil_layer_at_saturation_capacity',&
                      'Volume Fraction Of Moisture At Saturation Capacity Layer 3','','')
i=i+1
nc_tab( i ) = nctrans('WSAT4'           ,-1,'wsat_L04','m3 m-3','volume_fraction_of_moisture_of_soil_layer_at_saturation_capacity',&
                      'Volume Fraction Of Moisture At Saturation Capacity Layer 4','','')
i=i+1
nc_tab( i ) = nctrans('WSAT5'           ,-1,'wsat_L05','m3 m-3','volume_fraction_of_moisture_of_soil_layer_at_saturation_capacity',&
                      'Volume Fraction Of Moisture At Saturation Capacity Layer 5','','')
i=i+1
nc_tab( i ) = nctrans('WSAT6'           ,-1,'wsat_L06','m3 m-3','volume_fraction_of_moisture_of_soil_layer_at_saturation_capacity',&
                      'Volume Fraction Of Moisture At Saturation Capacity Layer 6','','')
i=i+1
nc_tab( i ) = nctrans('WSAT7'           ,-1,'wsat_L07','m3 m-3','volume_fraction_of_moisture_of_soil_layer_at_saturation_capacity',&
                      'Volume Fraction Of Moisture At Saturation Capacity Layer 7','','')
i=i+1
nc_tab( i ) = nctrans('WSAT8'           ,-1,'wsat_L08','m3 m-3','volume_fraction_of_moisture_of_soil_layer_at_saturation_capacity',&
                      'Volume Fraction Of Moisture At Saturation Capacity Layer 8','','')
i=i+1
nc_tab( i ) = nctrans('WSAT9'           ,-1,'wsat_L09','m3 m-3','volume_fraction_of_moisture_of_soil_layer_at_saturation_capacity',&
                      'Volume Fraction Of Moisture At Saturation Capacity Layer 9','','')
i=i+1
nc_tab( i ) = nctrans('WSAT10'          ,-1,'wsat_L10','m3 m-3','volume_fraction_of_moisture_of_soil_layer_at_saturation_capacity',&
                      'Volume Fraction Of Moisture At Saturation Capacity Layer 10','','')
i=i+1
nc_tab( i ) = nctrans('WSAT11'          ,-1,'wsat_L11','m3 m-3','volume_fraction_of_moisture_of_soil_layer_at_saturation_capacity',&
                      'Volume Fraction Of Moisture At Saturation Capacity Layer 11','','')
i=i+1
nc_tab( i ) = nctrans('WSAT12'          ,-1,'wsat_L12','m3 m-3','volume_fraction_of_moisture_of_soil_layer_at_saturation_capacity',&
                      'Volume Fraction Of Moisture At Saturation Capacity Layer 12','','')
i=i+1
nc_tab( i ) = nctrans('WSAT13'          ,-1,'wsat_L13','m3 m-3','volume_fraction_of_moisture_of_soil_layer_at_saturation_capacity',&
                      'Volume Fraction Of Moisture At Saturation Capacity Layer 13','','')
i=i+1
nc_tab( i ) = nctrans('WSAT14'          ,-1,'wsat_L14','m3 m-3','volume_fraction_of_moisture_of_soil_layer_at_saturation_capacity',&
                      'Volume Fraction Of Moisture At Saturation Capacity Layer 14','','')
i=i+1
nc_tab( i ) = nctrans('DG1'             ,-1,'dsoil_L01','m','depth_of_soil_layer','Soil Depth Layer 1','X','')
i=i+1
nc_tab( i ) = nctrans('DG2'             ,-1,'dsoil_L02','m','depth_of_soil_layer','Soil Depth Layer 2','X','')
i=i+1
nc_tab( i ) = nctrans('DG3'             ,-1,'dsoil_L03','m','depth_of_soil_layer','Soil Depth Layer 3','X','')
i=i+1
nc_tab( i ) = nctrans('DG4'             ,-1,'dsoil_L04','m','depth_of_soil_layer','Soil Depth Layer 4','X','')
i=i+1
nc_tab( i ) = nctrans('DG5'             ,-1,'dsoil_L05','m','depth_of_soil_layer','Soil Depth Layer 5','X','')
i=i+1
nc_tab( i ) = nctrans('DG6'             ,-1,'dsoil_L06','m','depth_of_soil_layer','Soil Depth Layer 6','X','')
i=i+1
nc_tab( i ) = nctrans('DG7'             ,-1,'dsoil_L07','m','depth_of_soil_layer','Soil Depth Layer 7','X','')
i=i+1
nc_tab( i ) = nctrans('DG8'             ,-1,'dsoil_L08','m','depth_of_soil_layer','Soil Depth Layer 8','X','')
i=i+1
nc_tab( i ) = nctrans('DG9'             ,-1,'dsoil_L09','m','depth_of_soil_layer','Soil Depth Layer 9','X','')
i=i+1
nc_tab( i ) = nctrans('DG10'            ,-1,'dsoil_L10','m','depth_of_soil_layer','Soil Depth Layer 10','X','')
i=i+1
nc_tab( i ) = nctrans('DG11'            ,-1,'dsoil_L11','m','depth_of_soil_layer','Soil Depth Layer 11','X','')
i=i+1
nc_tab( i ) = nctrans('DG12'            ,-1,'dsoil_L12','m','depth_of_soil_layer','Soil Depth Layer 12','X','')
i=i+1
nc_tab( i ) = nctrans('DG13'            ,-1,'dsoil_L13','m','depth_of_soil_layer','Soil Depth Layer 13','X','')
i=i+1
nc_tab( i ) = nctrans('DG14'            ,-1,'dsoil_L14','m','depth_of_soil_layer','Soil Depth Layer 14','X','')
i=i+1
nc_tab( i ) = nctrans('DSN_ICE_01'      ,-1,'dsnow_i_L01','m','snow_thickness_sea_ice','Snow thickness Layer 1','X','')
i=i+1
nc_tab( i ) = nctrans('DSN_ICE_02'      ,-1,'dsnow_i_L02','m','snow_thickness_sea_ice','Snow thickness Layer 2','X','')
i=i+1
nc_tab( i ) = nctrans('DSN_ICE_03'      ,-1,'dsnow_i_L03','m','snow_thickness_sea_ice','Snow thickness Layer 3','X','')
i=i+1
nc_tab( i ) = nctrans('DSN_ICE_04'      ,-1,'dsnow_i_L04','m','snow_thickness_sea_ice','Snow thickness Layer 4','X','')
i=i+1
nc_tab( i ) = nctrans('DSN_ICE_05'      ,-1,'dsnow_i_L05','m','snow_thickness_sea_ice','Snow thickness Layer 5','X','')
i=i+1
nc_tab( i ) = nctrans('DSN_ICE_06'      ,-1,'dsnow_i_L06','m','snow_thickness_sea_ice','Snow thickness Layer 6','X','')
i=i+1
nc_tab( i ) = nctrans('DSN_ICE_07'      ,-1,'dsnow_i_L07','m','snow_thickness_sea_ice','Snow thickness Layer 7','X','')
i=i+1
nc_tab( i ) = nctrans('DSN_ICE_08'      ,-1,'dsnow_i_L08','m','snow_thickness_sea_ice','Snow thickness Layer 8','X','')
i=i+1
nc_tab( i ) = nctrans('DSN_ICE_09'      ,-1,'dsnow_i_L09','m','snow_thickness_sea_ice','Snow thickness Layer 9','X','')
i=i+1
nc_tab( i ) = nctrans('DSN_ICE_10'      ,-1,'dsnow_i_L10','m','snow_thickness_sea_ice','Snow thickness Layer 10','X','')
i=i+1
nc_tab( i ) = nctrans('DSN_ICE_11'      ,-1,'dsnow_i_L11','m','snow_thickness_sea_ice','Snow thickness Layer 11','X','')
i=i+1
nc_tab( i ) = nctrans('DSN_ICE_12'      ,-1,'dsnow_i_L12','m','snow_thickness_sea_ice','Snow thickness Layer 12','X','')
i=i+1
nc_tab( i ) = nctrans('DSN_T_ICE'       ,-1,'snd_ice','m','snow_thickness_sea_ice','Snow Depth Over Sea Ice','','')
i=i+1
nc_tab( i ) = nctrans('HSN_ICE_01'      ,-1,'hs_i_L01','J m-2','snow_heat_sea_ice','Snow heat content Layer 1','X','')
i=i+1
nc_tab( i ) = nctrans('HSN_ICE_02'      ,-1,'hs_i_L02','J m-2','snow_heat_sea_ice','Snow heat content Layer 2','X','')
i=i+1
nc_tab( i ) = nctrans('HSN_ICE_03'      ,-1,'hs_i_L03','J m-2','snow_heat_sea_ice','Snow heat content Layer 3','X','')
i=i+1
nc_tab( i ) = nctrans('HSN_ICE_04'      ,-1,'hs_i_L04','J m-2','snow_heat_sea_ice','Snow heat content Layer 4','X','')
i=i+1
nc_tab( i ) = nctrans('HSN_ICE_05'      ,-1,'hs_i_L05','J m-2','snow_heat_sea_ice','Snow heat content Layer 5','X','')
i=i+1
nc_tab( i ) = nctrans('HSN_ICE_06'      ,-1,'hs_i_L06','J m-2','snow_heat_sea_ice','Snow heat content Layer 6','X','')
i=i+1
nc_tab( i ) = nctrans('HSN_ICE_07'      ,-1,'hs_i_L07','J m-2','snow_heat_sea_ice','Snow heat content Layer 7','X','')
i=i+1
nc_tab( i ) = nctrans('HSN_ICE_08'      ,-1,'hs_i_L08','J m-2','snow_heat_sea_ice','Snow heat content Layer 8','X','')
i=i+1
nc_tab( i ) = nctrans('HSN_ICE_09'      ,-1,'hs_i_L09','J m-2','snow_heat_sea_ice','Snow heat content Layer 9','X','')
i=i+1
nc_tab( i ) = nctrans('HSN_ICE_10'      ,-1,'hs_i_L10','J m-2','snow_heat_sea_ice','Snow heat content Layer 10','X','')
i=i+1
nc_tab( i ) = nctrans('HSN_ICE_11'      ,-1,'hs_i_L11','J m-2','snow_heat_sea_ice','Snow heat content Layer 11','X','')
i=i+1
nc_tab( i ) = nctrans('HSN_ICE_12'      ,-1,'hs_i_L12','J m-2','snow_heat_sea_ice','Snow heat content Layer 12','X','')
i=i+1
nc_tab( i ) = nctrans('LWSN_ICE_01'     ,-1,'lwsnow_i_L01','m','snow_liquid_water_sea_ice',&
                      'Snow liquid water content Layer 1','X','')
i=i+1
nc_tab( i ) = nctrans('LWSN_ICE_02'     ,-1,'lwsnow_i_L02','m','snow_liquid_water_sea_ice',&
                      'Snow liquid water content Layer 2','X','')
i=i+1
nc_tab( i ) = nctrans('LWSN_ICE_03'     ,-1,'lwsnow_i_L03','m','snow_liquid_water_sea_ice',&
                      'Snow liquid water content Layer 3','X','')
i=i+1
nc_tab( i ) = nctrans('LWSN_ICE_04'     ,-1,'lwsnow_i_L04','m','snow_liquid_water_sea_ice',&
                      'Snow liquid water content Layer 4','X','')
i=i+1
nc_tab( i ) = nctrans('LWSN_ICE_05'     ,-1,'lwsnow_i_L05','m','snow_liquid_water_sea_ice',&
                      'Snow liquid water content Layer 5','X','')
i=i+1
nc_tab( i ) = nctrans('LWSN_ICE_06'     ,-1,'lwsnow_i_L06','m','snow_liquid_water_sea_ice',&
                      'Snow liquid water content Layer 6','X','')
i=i+1
nc_tab( i ) = nctrans('LWSN_ICE_07'     ,-1,'lwsnow_i_L07','m','snow_liquid_water_sea_ice',&
                      'Snow liquid water content Layer 7','X','')
i=i+1
nc_tab( i ) = nctrans('LWSN_ICE_08'     ,-1,'lwsnow_i_L08','m','snow_liquid_water_sea_ice',&
                      'Snow liquid water content Layer 8','X','')
i=i+1
nc_tab( i ) = nctrans('LWSN_ICE_09'     ,-1,'lwsnow_i_L09','m','snow_liquid_water_sea_ice',&
                      'Snow liquid water content Layer 9','X','')
i=i+1
nc_tab( i ) = nctrans('LWSN_ICE_10'     ,-1,'lwsnow_i_L10','m','snow_liquid_water_sea_ice',&
                      'Snow liquid water content Layer 10','X','')
i=i+1
nc_tab( i ) = nctrans('LWSN_ICE_11'     ,-1,'lwsnow_i_L11','m','snow_liquid_water_sea_ice',&
                      'Snow liquid water content Layer 11','X','')
i=i+1
nc_tab( i ) = nctrans('LWSN_ICE_12'     ,-1,'lwsnow_i_L12','m','snow_liquid_water_sea_ice',&
                      'Snow liquid water content Layer 12','X','')
i=i+1
nc_tab( i ) = nctrans('RSN_ICE_01'      ,-1,'rs_i_L01','kg m-3','snow_density_sea_ice','Snow density Layer 1','X','')
i=i+1
nc_tab( i ) = nctrans('RSN_ICE_02'      ,-1,'rs_i_L02','kg m-3','snow_density_sea_ice','Snow density Layer 2','X','')
i=i+1
nc_tab( i ) = nctrans('RSN_ICE_03'      ,-1,'rs_i_L03','kg m-3','snow_density_sea_ice','Snow density Layer 3','X','')
i=i+1
nc_tab( i ) = nctrans('RSN_ICE_04'      ,-1,'rs_i_L04','kg m-3','snow_density_sea_ice','Snow density Layer 4','X','')
i=i+1
nc_tab( i ) = nctrans('RSN_ICE_05'      ,-1,'rs_i_L05','kg m-3','snow_density_sea_ice','Snow density Layer 5','X','')
i=i+1
nc_tab( i ) = nctrans('RSN_ICE_06'      ,-1,'rs_i_L06','kg m-3','snow_density_sea_ice','Snow density Layer 6','X','')
i=i+1
nc_tab( i ) = nctrans('RSN_ICE_07'      ,-1,'rs_i_L07','kg m-3','snow_density_sea_ice','Snow density Layer 7','X','')
i=i+1
nc_tab( i ) = nctrans('RSN_ICE_08'      ,-1,'rs_i_L08','kg m-3','snow_density_sea_ice','Snow density Layer 8','X','')
i=i+1
nc_tab( i ) = nctrans('RSN_ICE_09'      ,-1,'rs_i_L09','kg m-3','snow_density_sea_ice','Snow density Layer 9','X','')
i=i+1
nc_tab( i ) = nctrans('RSN_ICE_10'      ,-1,'rs_i_L10','kg m-3','snow_density_sea_ice','Snow density Layer 10','X','')
i=i+1
nc_tab( i ) = nctrans('RSN_ICE_11'      ,-1,'rs_i_L11','kg m-3','snow_density_sea_ice','Snow density Layer 11','X','')
i=i+1
nc_tab( i ) = nctrans('RSN_ICE_12'      ,-1,'rs_i_L12','kg m-3','snow_density_sea_ice','Snow density Layer 12','X','')
i=i+1
nc_tab( i ) = nctrans('TICE_01'          ,-1,'ti_L01','K','ice_temperature','Ice Layer 1 Temperature','X','')
i=i+1
nc_tab( i ) = nctrans('TICE_02'          ,-1,'ti_L02','K','ice_temperature','Ice Layer 2 Temperature','X','')
i=i+1
nc_tab( i ) = nctrans('TICE_03'          ,-1,'ti_L03','K','ice_temperature','Ice Layer 3 Temperature','X','')
i=i+1
nc_tab( i ) = nctrans('TICE_04'          ,-1,'ti_L04','K','ice_temperature','Ice Layer 4 Temperature','X','')
i=i+1
nc_tab( i ) = nctrans('TICE_05'          ,-1,'ti_L05','K','ice_temperature','Ice Layer 5 Temperature','X','')
i=i+1
nc_tab( i ) = nctrans('TICE_06'          ,-1,'ti_L06','K','ice_temperature','Ice Layer 6 Temperature','X','')
i=i+1
nc_tab( i ) = nctrans('TICE_07'          ,-1,'ti_L07','K','ice_temperature','Ice Layer 7 Temperature','X','')
i=i+1
nc_tab( i ) = nctrans('TICE_08'          ,-1,'ti_L08','K','ice_temperature','Ice Layer 8 Temperature','X','')
i=i+1
nc_tab( i ) = nctrans('TICE_09'          ,-1,'ti_L09','K','ice_temperature','Ice Layer 9 Temperature','X','')
i=i+1
nc_tab( i ) = nctrans('TICE_10'          ,-1,'ti_L10','K','ice_temperature','Ice Layer 10 Temperature','X','')
i=i+1
nc_tab( i ) = nctrans('TICE_11'          ,-1,'ti_L11','K','ice_temperature','Ice Layer 11 Temperature','X','')
i=i+1
nc_tab( i ) = nctrans('TICE_12'          ,-1,'ti_L12','K','ice_temperature','Ice Layer 12 Temperature','X','')
i=i+1
nc_tab( i ) = nctrans('TSN_ICE_01'    ,-1,'tsnow_i_L01','K','snow_temperature_sea_ice','Snow temperature Layer 1','X','')
i=i+1
nc_tab( i ) = nctrans('TSN_ICE_02'    ,-1,'tsnow_i_L02','K','snow_temperature_sea_ice','Snow temperature Layer 2','X','')
i=i+1
nc_tab( i ) = nctrans('TSN_ICE_03'    ,-1,'tsnow_i_L03','K','snow_temperature_sea_ice','Snow temperature Layer 3','X','')
i=i+1
nc_tab( i ) = nctrans('TSN_ICE_04'    ,-1,'tsnow_i_L04','K','snow_temperature_sea_ice','Snow temperature Layer 4','X','')
i=i+1
nc_tab( i ) = nctrans('TSN_ICE_05'    ,-1,'tsnow_i_L05','K','snow_temperature_sea_ice','Snow temperature Layer 5','X','')
i=i+1
nc_tab( i ) = nctrans('TSN_ICE_06'    ,-1,'tsnow_i_L06','K','snow_temperature_sea_ice','Snow temperature Layer 6','X','')
i=i+1
nc_tab( i ) = nctrans('TSN_ICE_07'    ,-1,'tsnow_i_L07','K','snow_temperature_sea_ice','Snow temperature Layer 7','X','')
i=i+1
nc_tab( i ) = nctrans('TSN_ICE_08'    ,-1,'tsnow_i_L08','K','snow_temperature_sea_ice','Snow temperature Layer 8','X','')
i=i+1
nc_tab( i ) = nctrans('TSN_ICE_09'    ,-1,'tsnow_i_L09','K','snow_temperature_sea_ice','Snow temperature Layer 9','X','')
i=i+1
nc_tab( i ) = nctrans('TSN_ICE_10'    ,-1,'tsnow_i_L10','K','snow_temperature_sea_ice','Snow temperature Layer 10','X','')
i=i+1
nc_tab( i ) = nctrans('TSN_ICE_11'    ,-1,'tsnow_i_L11','K','snow_temperature_sea_ice','Snow temperature Layer 11','X','')
i=i+1
nc_tab( i ) = nctrans('TSN_ICE_12'    ,-1,'tsnow_i_L12','K','snow_temperature_sea_ice','Snow temperature Layer 12','X','')
i=i+1
nc_tab( i ) = nctrans('WSN_ICE_01'      ,-1,'swe_i_L01','kg m-2','swe_sea_ice','Snow water equivalent Layer 1','X','')
i=i+1
nc_tab( i ) = nctrans('WSN_ICE_02'      ,-1,'swe_i_L02','kg m-2','swe_sea_ice','Snow water equivalent Layer 2','X','')
i=i+1
nc_tab( i ) = nctrans('WSN_ICE_03'      ,-1,'swe_i_L03','kg m-2','swe_sea_ice','Snow water equivalent Layer 3','X','')
i=i+1
nc_tab( i ) = nctrans('WSN_ICE_04'      ,-1,'swe_i_L04','kg m-2','swe_sea_ice','Snow water equivalent Layer 4','X','')
i=i+1
nc_tab( i ) = nctrans('WSN_ICE_05'      ,-1,'swe_i_L05','kg m-2','swe_sea_ice','Snow water equivalent Layer 5','X','')
i=i+1
nc_tab( i ) = nctrans('WSN_ICE_06'      ,-1,'swe_i_L06','kg m-2','swe_sea_ice','Snow water equivalent Layer 6','X','')
i=i+1
nc_tab( i ) = nctrans('WSN_ICE_07'      ,-1,'swe_i_L07','kg m-2','swe_sea_ice','Snow water equivalent Layer 7','X','')
i=i+1
nc_tab( i ) = nctrans('WSN_ICE_08'      ,-1,'swe_i_L08','kg m-2','swe_sea_ice','Snow water equivalent Layer 8','X','')
i=i+1
nc_tab( i ) = nctrans('WSN_ICE_09'      ,-1,'swe_i_L09','kg m-2','swe_sea_ice','Snow water equivalent Layer 9','X','')
i=i+1
nc_tab( i ) = nctrans('WSN_ICE_10'      ,-1,'swe_i_L10','kg m-2','swe_sea_ice','Snow water equivalent Layer 10','X','')
i=i+1
nc_tab( i ) = nctrans('WSN_ICE_11'      ,-1,'swe_i_L11','kg m-2','swe_sea_ice','Snow water equivalent Layer 11','X','')
i=i+1
nc_tab( i ) = nctrans('WSN_ICE_12'      ,-1,'swe_i_L12','kg m-2','swe_sea_ice','Snow water equivalent Layer 12','X','')
i=i+1
nc_tab( i ) = nctrans('ASN_ICE'         ,-1,'asn_i','','snow_albedo_sea_ice','Snow albedo over sea ice','X','')
i=i+1
nc_tab( i ) = nctrans('ICE_ALB'         ,-1,'alb_i','','albedo_sea_ice','Albedo over snow-free sea ice','X','')
i=i+1
nc_tab( i ) = nctrans('WSNOW_VEG1'      ,-1,'snwl_L01','kg m-2','snow_reservoir','Snow Reservoir over Land Layer 1','X','')
i=i+1
nc_tab( i ) = nctrans('RSNOW_VEG1'      ,-1,'rsnl_L01','kg m-3','snow_density','Snow density over Land Layer 1','X','')
i=i+1
nc_tab( i ) = nctrans('WSN_VEG1'        ,-1,'snwl_L01','kg m-2','snow_reservoir','Snow Reservoir over Land Layer 1','X','')
i=i+1
nc_tab( i ) = nctrans('RSN_VEG1'        ,-1,'rsnl_L01','kg m-3','snow_density','Snow density over Land Layer 1','X','')
i=i+1
nc_tab( i ) = nctrans('ASN_VEG'         ,-1,'asnl_L01','kg m-3','snow_albedo','Snow albedo over Land','X','')
i=i+1
nc_tab( i ) = nctrans('WR'              ,-1,'wr','unknown','canopy_liquid_water_amount','Liquid Water Retained By Foliage','X','')


! ISBA

i=i+1
nc_tab( i ) = nctrans('T2M_ISBA'        ,-1,'tas_nature','K','air_temperature_over_land','Near-Surface Land Temperature','','')
i=i+1
nc_tab( i ) = nctrans('T2MMIN_ISBA'     ,-1,'tasmin_nature','K','air_temperature_over_land',&
                      'Minimum Near-Surface Temperature Over Land','','')
i=i+1
nc_tab( i ) = nctrans('T2MMAX_ISBA'     ,-1,'tasmax_nature','K','air_temperature_over_land',&
                      'Maximum Near-Surface Temperature Over Land','','')
i=i+1
nc_tab( i ) = nctrans('ZON10M_ISBA'     , 0,'uas_isba','m s-1','eastward_wind_over_land',&
                      'Eastward Near-Surface Wind Speed Over Land','','')
i=i+1
nc_tab( i ) = nctrans('ZON10M_ISBA'     , 1,'x_wind_isba','m s-1','x_wind_over_land',&
                      'Eastward Near-Surface Wind Speed Over Land In Model Coordinates','','')
i=i+1
nc_tab( i ) = nctrans('MER10M_ISBA'     , 0,'vas_isba','m s-1','northward_wind_over_land',&
                      'Northward Near-Surface Wind Speed Over Land','','')
i=i+1
nc_tab( i ) = nctrans('MER10M_ISBA'     , 1,'y_wind_isba','m s-1','y_wind_over_land',&
                      'Northward Near-Surface Wind Speed Over Land In Model Coordinates','','')
i=i+1
nc_tab( i ) = nctrans('Q2M_ISBA'        ,-1,'huss_nature','kg kg-1','specific_humidity',&
                      'Near-surface Specific Humidity Over Land','','')
i=i+1
nc_tab( i ) = nctrans('HU2M_ISBA'       ,-1,'hurs_nature','1','relative_humidity','Near-Surface Relative humidity Over Land','','')
i=i+1
nc_tab( i ) = nctrans('TS_ISBA'         ,-1,'ts_nature','K','surface_land_temperature','Surface Temperature over Land','','')
i=i+1
nc_tab( i ) = nctrans('W10M_ISBA'       ,-1,'sfcWindl','m s-1','wind_speed','Near-Surface Wind Speed Over Land','','')
i=i+1
nc_tab( i ) = nctrans('W10MMAX_ISBA'    ,-1,'sfcWindmaxl','m s-1','wind_speed','Maximum Near-Surface Wind Speed Over Land','','')
i=i+1
nc_tab( i ) = nctrans('PSN_ISBA'        ,-1,'snc','1','surface_snow_area_fraction','Snow Area Fraction','','')
i=i+1
nc_tab( i ) = nctrans('PSNG_ISBA'       ,-1,'sncg','1','surface_snow_area_fraction_over_ground',&
                      'Snow Area Fraction Over Ground','','')
i=i+1
nc_tab( i ) = nctrans('PSNV_ISBA'       ,-1,'sncv','1','surface_snow_area_fraction_over_vegetation',&
                      'Snow Area Fraction Over Veg','','')
i=i+1
nc_tab( i ) = nctrans('TALB_ISBA'       ,-1,'albl','-','surface_total_albedo','Surface Total Albedo Over Land','','')
i=i+1
nc_tab( i ) = nctrans('WSN_T_ISBA'      ,-1,'snw','kg m-2','surface_snow_amount','Surface Snow Amount','','')
i=i+1
nc_tab( i ) = nctrans('DSN_T_ISBA'      ,-1,'snd','m','surface_snow_tickness','Snow Depth','','')
i=i+1
nc_tab( i ) = nctrans('TSWI_T_ISBA'     ,-1,'tswi','-','total_soil_wetness_index','Total Soil Wetness Index','','')
i=i+1
nc_tab( i ) = nctrans('WGTOT_T_ISBA'    ,-1,'mrso','kg m-2','mass_content_of_water_in_soil','Total Soil Moisture Content','','')
i=i+1
nc_tab( i ) = nctrans('WGI_T_ISBA'      ,-1,'mrfso','kg m-2','soil_frozen_water_content','Soil Frozen Water Content','','')
i=i+1
nc_tab( i ) = nctrans('RNC_ISBA'        ,-1,'rnsl','J m-2','accumulated_surface_net_radiation',&
                      'Accumulated Surface Net Radiation Land','','')
i=i+1
nc_tab( i ) = nctrans('SWUC_ISBA'       ,-1,'rsusl','J m-2','accumulated_surface_upwelling_shortwave_flux_in_air',&
                      'Accumulated Surface Upwelling Shortwave Radiation Over Land','','')
i=i+1
nc_tab( i ) = nctrans('LWUC_ISBA'       ,-1,'rlusl','J m-2','accumulated_surface_upwelling_longwave_flux_in_air',&
                      'Accumulated Surface Upwelling Longwave Radiation Over Land','','')
i=i+1
nc_tab( i ) = nctrans('LWDC_ISBA'       ,-1,'rldsl','J m-2','accumulated_surface_downwelling_longwave_flux_in_air',&
                      'Accumulated Surface Downwelling Longwave Radiation Over Land','','')
i=i+1
nc_tab( i ) = nctrans('SWDC_ISBA'       ,-1,'rsdsl','J m-2','accumulated_surface_downwelling_shortwave_flux_in_air',&
                      'Accumulated Surface Downwelling Shortwave Radiation Over Land','','')
i=i+1
nc_tab( i ) = nctrans('HC_ISBA'         ,-1,'hfssl','J m-2','accumulated_surface_upward_sensible_heat_flux',&
                      'Accumulated Surface Upward Sensible Heat Flux Over Land','','')
i=i+1
nc_tab( i ) = nctrans('LEC_ISBA'        ,-1,'hflsl','J m-2','accumulated_surface_upward_latent_heat_flux',&
                      'Accumulated Surface Upward latent heat flux Over Land','','')
i=i+1
nc_tab( i ) = nctrans('RUNOFFC_ISBA'    ,-1,'mrros','kg m-2','accumulated_surface_runoff_flux','Accumulated Surface Runoff','','')
i=i+1
nc_tab( i ) = nctrans('HORTONC_ISBA'    ,-1,'mrrosh','kg m-2','accumulated_surface_Horton_runoff_flux',&
                      'Accumulated Surface Horton Runoff','','')
i=i+1
nc_tab( i ) = nctrans('DRAINC_ISBA'     ,-1,'mrrod','kg m-2','accumulated_subsurface_runoff',&
                      'Accumulated Subsurface Runoff','','')
i=i+1
nc_tab( i ) = nctrans('EVAPC_ISBA'      ,-1,'evaptl','kg m-2','water_evapotranspiration_land_amount',&
                      'Accumulated Evapotranspiration Over Land','','')
i=i+1
nc_tab( i ) = nctrans('SNOMLTC_ISBA'    ,-1,'snm','kg m-2','surface_snow_melt_amount',&
                      'Accumulated Surface Snow Melt','','')
i=i+1
nc_tab( i ) = nctrans('FMUC_ISBA'       , 0,'tauul','kg m-1 s-1','accumulated_surface_downward_eastward_stress_over_land',&
                      'Accumulated Surface Downward Eastward Wind Stress Over Land','','d')
i=i+1
nc_tab( i ) = nctrans('FMUC_ISBA'       , 1,'x_stressl','kg m-1 s-1','accumulated_surface_downward_x_stress_over_land',&
                      'Accumulated Surface Downward Eastward Wind Stress Over Land In Model Coordinates','','d')
i=i+1
nc_tab( i ) = nctrans('FMVC_ISBA'       , 0,'tauvl','kg m-1 s-1','accumulated_surface_downward_northward_stress_over_land',&
                      'Accumulated Surface Downward Northward Wind Stress Over Land','','d')
i=i+1
nc_tab( i ) = nctrans('FMVC_ISBA'       , 1,'y_stressl','kg m-1 s-1','accumulated_surface_downward_y_stress_over_land',&
                      'Accumulated Surface Downward Northward Wind Stress Over Land In Model Coordinates','','d')
i=i+1
nc_tab( i ) = nctrans('DTOTDF_ISBA'     ,-1,'dmoisture','m','total_soil_depth_for_moisture','Total Soil Depth For Moisture','','')


! Layers (isba)

i=i+1
nc_tab( i ) = nctrans('TG1_ISBA'        ,-1,'tsl_L01','K','soil_temperature','Soil Layer 1 Temperature Land','X','')
i=i+1
nc_tab( i ) = nctrans('TG2_ISBA'        ,-1,'tsl_L02','K','soil_temperature','Soil Layer 2 Temperature Land','X','')
i=i+1
nc_tab( i ) = nctrans('TG3_ISBA'        ,-1,'tsl_L03','K','soil_temperature','Soil Layer 3 Temperature Land','X','')
i=i+1
nc_tab( i ) = nctrans('TG4_ISBA'        ,-1,'tsl_L04','K','soil_temperature','Soil Layer 4 Temperature Land','X','')
i=i+1
nc_tab( i ) = nctrans('TG5_ISBA'        ,-1,'tsl_L05','K','soil_temperature','Soil Layer 5 Temperature Land','X','')
i=i+1
nc_tab( i ) = nctrans('TG6_ISBA'        ,-1,'tsl_L06','K','soil_temperature','Soil Layer 6 Temperature Land','X','')
i=i+1
nc_tab( i ) = nctrans('TG7_ISBA'        ,-1,'tsl_L07','K','soil_temperature','Soil Layer 7 Temperature Land','X','')
i=i+1
nc_tab( i ) = nctrans('TG8_ISBA'        ,-1,'tsl_L08','K','soil_temperature','Soil Layer 8 Temperature Land','X','')
i=i+1
nc_tab( i ) = nctrans('TG9_ISBA'        ,-1,'tsl_L09','K','soil_temperature','Soil Layer 9 Temperature Land','X','')
i=i+1
nc_tab( i ) = nctrans('TG10_ISBA'       ,-1,'tsl_L10','K','soil_temperature','Soil Layer 10 Temperature Land','X','')
i=i+1
nc_tab( i ) = nctrans('TG11_ISBA'       ,-1,'tsl_L11','K','soil_temperature','Soil Layer 11 Temperature Land','X','')
i=i+1
nc_tab( i ) = nctrans('TG12_ISBA'       ,-1,'tsl_L12','K','soil_temperature','Soil Layer 12 Temperature Land','X','')
i=i+1
nc_tab( i ) = nctrans('TG13_ISBA'       ,-1,'tsl_L13','K','soil_temperature','Soil Layer 13 Temperature Land','X','')
i=i+1
nc_tab( i ) = nctrans('TG14_ISBA'       ,-1,'tsl_L14','K','soil_temperature','Soil Layer 14 Temperature Land','X','')
i=i+1
nc_tab( i ) = nctrans('TSWI1_ISBA'      ,-1,'tswil_L01','-','total_soil_wetness_index',&
                      'Total Soil Wetness Index Land Layer 1','X','')
i=i+1
nc_tab( i ) = nctrans('TSWI2_ISBA'      ,-1,'tswil_L02','-','total_soil_wetness_index',&
                      'Total Soil Wetness Index Land Layer 2','X','')
i=i+1
nc_tab( i ) = nctrans('TSWI3_ISBA'      ,-1,'tswil_L03','-','total_soil_wetness_index',&
                      'Total Soil Wetness Index Land Layer 3','X','')
i=i+1
nc_tab( i ) = nctrans('TSWI4_ISBA'      ,-1,'tswil_L04','-','total_soil_wetness_index',&
                      'Total Soil Wetness Index Land Layer 4','X','')
i=i+1
nc_tab( i ) = nctrans('TSWI5_ISBA'      ,-1,'tswil_L05','-','total_soil_wetness_index',&
                      'Total Soil Wetness Index Land Layer 5','X','')
i=i+1
nc_tab( i ) = nctrans('TSWI6_ISBA'      ,-1,'tswil_L06','-','total_soil_wetness_index',&
                      'Total Soil Wetness Index Land Layer 6','X','')
i=i+1
nc_tab( i ) = nctrans('TSWI7_ISBA'      ,-1,'tswil_L07','-','total_soil_wetness_index',&
                      'Total Soil Wetness Index Land Layer 7','X','')
i=i+1
nc_tab( i ) = nctrans('TSWI8_ISBA'      ,-1,'tswil_L08','-','total_soil_wetness_index',&
                      'Total Soil Wetness Index Land Layer 8','X','')
i=i+1
nc_tab( i ) = nctrans('TSWI9_ISBA'      ,-1,'tswil_L09','-','total_soil_wetness_index',&
                      'Total Soil Wetness Index Land Layer 9','X','')
i=i+1
nc_tab( i ) = nctrans('TSWI10_ISBA'     ,-1,'tswil_L10','-','total_soil_wetness_index',&
                      'Total Soil Wetness Index Land Layer 10','X','')
i=i+1
nc_tab( i ) = nctrans('TSWI11_ISBA'     ,-1,'tswil_L11','-','total_soil_wetness_index',&
                      'Total Soil Wetness Index Land Layer 11','X','')
i=i+1
nc_tab( i ) = nctrans('TSWI12_ISBA'     ,-1,'tswil_L12','-','total_soil_wetness_index',&
                      'Total Soil Wetness Index Land Layer 12','X','')
i=i+1
nc_tab( i ) = nctrans('TSWI13_ISBA'     ,-1,'tswil_L13','-','total_soil_wetness_index',&
                      'Total Soil Wetness Index Land Layer 13','X','')
i=i+1
nc_tab( i ) = nctrans('TSWI14_ISBA'     ,-1,'tswil_L14','-','total_soil_wetness_index',&
                      'Total Soil Wetness Index Land Layer 14','X','')
i=i+1
nc_tab( i ) = nctrans('WG1_ISBA'        ,-1,'wsal_L01','m3 m-3','volume_fraction_of_liquid_water_in_soil_layer',&
                      'Volume Fraction Of Liquid Water In Soil Layer 1','X','')
i=i+1
nc_tab( i ) = nctrans('WG2_ISBA'        ,-1,'wsal_L02','m3 m-3','volume_fraction_of_liquid_water_in_soil_layer',&
                      'Volume Fraction Of Liquid Water In Soil Layer 2','X','')
i=i+1
nc_tab( i ) = nctrans('WG3_ISBA'        ,-1,'wsal_L03','m3 m-3','volume_fraction_of_liquid_water_in_soil_layer',&
                      'Volume Fraction Of Liquid Water In Soil Layer 3','X','')
i=i+1
nc_tab( i ) = nctrans('WG4_ISBA'        ,-1,'wsal_L04','m3 m-3','volume_fraction_of_liquid_water_in_soil_layer',&
                      'Volume Fraction Of Liquid Water In Soil Layer 4','X','')
i=i+1
nc_tab( i ) = nctrans('WG5_ISBA'        ,-1,'wsal_L05','m3 m-3','volume_fraction_of_liquid_water_in_soil_layer',&
                      'Volume Fraction Of Liquid Water In Soil Layer 5','X','')
i=i+1
nc_tab( i ) = nctrans('WG6_ISBA'        ,-1,'wsal_L06','m3 m-3','volume_fraction_of_liquid_water_in_soil_layer',&
                      'Volume Fraction Of Liquid Water In Soil Layer 6','X','')
i=i+1
nc_tab( i ) = nctrans('WG7_ISBA'        ,-1,'wsal_L07','m3 m-3','volume_fraction_of_liquid_water_in_soil_layer',&
                      'Volume Fraction Of Liquid Water In Soil Layer 7','X','')
i=i+1
nc_tab( i ) = nctrans('WG8_ISBA'        ,-1,'wsal_L08','m3 m-3','volume_fraction_of_liquid_water_in_soil_layer',&
                      'Volume Fraction Of Liquid Water In Soil Layer 8','X','')
i=i+1
nc_tab( i ) = nctrans('WG9_ISBA'        ,-1,'wsal_L09','m3 m-3','volume_fraction_of_liquid_water_in_soil_layer',&
                      'Volume Fraction Of Liquid Water In Soil Layer 9','X','')
i=i+1
nc_tab( i ) = nctrans('WG10_ISBA'       ,-1,'wsal_L10','m3 m-3','volume_fraction_of_liquid_water_in_soil_layer',&
                      'Volume Fraction Of Liquid Water In Soil Layer 10','X','')
i=i+1
nc_tab( i ) = nctrans('WG11_ISBA'       ,-1,'wsal_L11','m3 m-3','volume_fraction_of_liquid_water_in_soil_layer',&
                      'Volume Fraction Of Liquid Water In Soil Layer 11','X','')
i=i+1
nc_tab( i ) = nctrans('WG12_ISBA'       ,-1,'wsal_L12','m3 m-3','volume_fraction_of_liquid_water_in_soil_layer',&
                      'Volume Fraction Of Liquid Water In Soil Layer 12','X','')
i=i+1
nc_tab( i ) = nctrans('WG13_ISBA'       ,-1,'wsal_L13','m3 m-3','volume_fraction_of_liquid_water_in_soil_layer',&
                      'Volume Fraction Of Liquid Water In Soil Layer 13','X','')
i=i+1
nc_tab( i ) = nctrans('WG14_ISBA'       ,-1,'wsal_L14','m3 m-3','volume_fraction_of_liquid_water_in_soil_layer',&
                      'Volume Fraction Of Liquid Water In Soil Layer 14','X','')
i=i+1
nc_tab( i ) = nctrans('WGI1_ISBA'       ,-1,'isal_L01','m3 m-3','volume_fraction_of_frozen_water_in_soil_layer',&
                      'Volume Fraction Of Frozen Water In Soil Layer 1','X','')
i=i+1
nc_tab( i ) = nctrans('WGI2_ISBA'       ,-1,'isal_L02','m3 m-3','volume_fraction_of_frozen_water_in_soil_layer',&
                      'Volume Fraction Of Frozen Water In Soil Layer 2','X','')
i=i+1
nc_tab( i ) = nctrans('WGI3_ISBA'       ,-1,'isal_L03','m3 m-3','volume_fraction_of_frozen_water_in_soil_layer',&
                      'Volume Fraction Of Frozen Water In Soil Layer 3','X','')
i=i+1
nc_tab( i ) = nctrans('WGI4_ISBA'       ,-1,'isal_L04','m3 m-3','volume_fraction_of_frozen_water_in_soil_layer',&
                      'Volume Fraction Of Frozen Water In Soil Layer 4','X','')
i=i+1
nc_tab( i ) = nctrans('WGI5_ISBA'       ,-1,'isal_L05','m3 m-3','volume_fraction_of_frozen_water_in_soil_layer',&
                      'Volume Fraction Of Frozen Water In Soil Layer 5','X','')
i=i+1
nc_tab( i ) = nctrans('WGI6_ISBA'       ,-1,'isal_L06','m3 m-3','volume_fraction_of_frozen_water_in_soil_layer',&
                      'Volume Fraction Of Frozen Water In Soil Layer 6','X','')
i=i+1
nc_tab( i ) = nctrans('WGI7_ISBA'       ,-1,'isal_L07','m3 m-3','volume_fraction_of_frozen_water_in_soil_layer',&
                      'Volume Fraction Of Frozen Water In Soil Layer 7','X','')
i=i+1
nc_tab( i ) = nctrans('WGI8_ISBA'       ,-1,'isal_L08','m3 m-3','volume_fraction_of_frozen_water_in_soil_layer',&
                      'Volume Fraction Of Frozen Water In Soil Layer 8','X','')
i=i+1
nc_tab( i ) = nctrans('WGI9_ISBA'       ,-1,'isal_L09','m3 m-3','volume_fraction_of_frozen_water_in_soil_layer',&
                      'Volume Fraction Of Frozen Water In Soil Layer 9','X','')
i=i+1
nc_tab( i ) = nctrans('WGI10_ISBA'      ,-1,'isal_L10','m3 m-3','volume_fraction_of_frozen_water_in_soil_layer',&
                      'Volume Fraction Of Frozen Water In Soil Layer 10','X','')
i=i+1
nc_tab( i ) = nctrans('WGI11_ISBA'      ,-1,'isal_L11','m3 m-3','volume_fraction_of_frozen_water_in_soil_layer',&
                      'Volume Fraction Of Frozen Water In Soil Layer 11','X','')
i=i+1
nc_tab( i ) = nctrans('WGI12_ISBA'      ,-1,'isal_L12','m3 m-3','volume_fraction_of_frozen_water_in_soil_layer',&
                      'Volume Fraction Of Frozen Water In Soil Layer 12','X','')
i=i+1
nc_tab( i ) = nctrans('WGI13_ISBA'      ,-1,'isal_L13','m3 m-3','volume_fraction_of_frozen_water_in_soil_layer',&
                      'Volume Fraction Of Frozen Water In Soil Layer 13','X','')
i=i+1
nc_tab( i ) = nctrans('WGI14_ISBA'      ,-1,'isal_L14','m3 m-3','volume_fraction_of_frozen_water_in_soil_layer',&
                      'Volume Fraction Of Frozen Water In Soil Layer 14','X','')
i=i+1
nc_tab( i ) = nctrans('WG1_T_ISBA'      ,-1,'mrsll_L01','kg m-2','liquid_water_content_in_soil_layer',&
                      'Liquid Water Content In Soil Layer 1','X','')
i=i+1
nc_tab( i ) = nctrans('WG2_T_ISBA'      ,-1,'mrsll_L02','kg m-2','liquid_water_content_in_soil_layer',&
                      'Liquid Water Content In Soil Layer 2','X','')
i=i+1
nc_tab( i ) = nctrans('WG3_T_ISBA'      ,-1,'mrsll_L03','kg m-2','liquid_water_content_in_soil_layer',&
                      'Liquid Water Content In Soil Layer 3','X','')
i=i+1
nc_tab( i ) = nctrans('WG4_T_ISBA'      ,-1,'mrsll_L04','kg m-2','liquid_water_content_in_soil_layer',&
                      'Liquid Water Content In Soil Layer 4','X','')
i=i+1
nc_tab( i ) = nctrans('WG5_T_ISBA'      ,-1,'mrsll_L05','kg m-2','liquid_water_content_in_soil_layer',&
                      'Liquid Water Content In Soil Layer 5','X','')
i=i+1
nc_tab( i ) = nctrans('WG6_T_ISBA'      ,-1,'mrsll_L06','kg m-2','liquid_water_content_in_soil_layer',&
                      'Liquid Water Content In Soil Layer 6','X','')
i=i+1
nc_tab( i ) = nctrans('WG7_T_ISBA'      ,-1,'mrsll_L07','kg m-2','liquid_water_content_in_soil_layer',&
                      'Liquid Water Content In Soil Layer 7','X','')
i=i+1
nc_tab( i ) = nctrans('WG8_T_ISBA'      ,-1,'mrsll_L08','kg m-2','liquid_water_content_in_soil_layer',&
                      'Liquid Water Content In Soil Layer 8','X','')
i=i+1
nc_tab( i ) = nctrans('WG9_T_ISBA'      ,-1,'mrsll_L09','kg m-2','liquid_water_content_in_soil_layer',&
                      'Liquid Water Content In Soil Layer 9','X','')
i=i+1
nc_tab( i ) = nctrans('WG10_T_ISBA'     ,-1,'mrsll_L10','kg m-2','liquid_water_content_in_soil_layer',& 
                      'Liquid Water Content In Soil Layer 10','X','')
i=i+1
nc_tab( i ) = nctrans('WG11_T_ISBA'     ,-1,'mrsll_L11','kg m-2','liquid_water_content_in_soil_layer',&
                      'Liquid Water Content In Soil Layer 11','X','')
i=i+1
nc_tab( i ) = nctrans('WG12_T_ISBA'     ,-1,'mrsll_L12','kg m-2','liquid_water_content_in_soil_layer',&
                      'Liquid Water Content In Soil Layer 12','X','')
i=i+1
nc_tab( i ) = nctrans('WG13_T_ISBA'     ,-1,'mrsll_L13','kg m-2','liquid_water_content_in_soil_layer',&
                      'Liquid Water Content In Soil Layer 13','X','')
i=i+1
nc_tab( i ) = nctrans('WG14_T_ISBA'     ,-1,'mrsll_L14','kg m-2','liquid_water_content_in_soil_layer',&
                      'Liquid Water Content In Soil Layer 14','X','')
i=i+1
nc_tab( i ) = nctrans('WGI1_T_ISBA'     ,-1,'mrsfl_L01','kg m-2','frozen_water_content_in_soil_layer',&
                      'Frozen Water Content In Soil Layer 1','X','')
i=i+1
nc_tab( i ) = nctrans('WGI2_T_ISBA'     ,-1,'mrsfl_L02','kg m-2','frozen_water_content_in_soil_layer',&
                      'Frozen Water Content In Soil Layer 2','X','')
i=i+1
nc_tab( i ) = nctrans('WGI3_T_ISBA'     ,-1,'mrsfl_L03','kg m-2','frozen_water_content_in_soil_layer',&
                      'Frozen Water Content In Soil Layer 3','X','')
i=i+1
nc_tab( i ) = nctrans('WGI4_T_ISBA'     ,-1,'mrsfl_L04','kg m-2','frozen_water_content_in_soil_layer',&
                      'Frozen Water Content In Soil Layer 4','X','')
i=i+1
nc_tab( i ) = nctrans('WGI5_T_ISBA'     ,-1,'mrsfl_L05','kg m-2','frozen_water_content_in_soil_layer',&
                      'Frozen Water Content In Soil Layer 5','X','')
i=i+1
nc_tab( i ) = nctrans('WGI6_T_ISBA'     ,-1,'mrsfl_L06','kg m-2','frozen_water_content_in_soil_layer',&
                      'Frozen Water Content In Soil Layer 6','X','')
i=i+1
nc_tab( i ) = nctrans('WGI7_T_ISBA'     ,-1,'mrsfl_L07','kg m-2','frozen_water_content_in_soil_layer',&
                      'Frozen Water Content In Soil Layer 7','X','')
i=i+1
nc_tab( i ) = nctrans('WGI8_T_ISBA'     ,-1,'mrsfl_L08','kg m-2','frozen_water_content_in_soil_layer',&
                      'Frozen Water Content In Soil Layer 8','X','')
i=i+1
nc_tab( i ) = nctrans('WGI9_T_ISBA'     ,-1,'mrsfl_L09','kg m-2','frozen_water_content_in_soil_layer',&
                      'Frozen Water Content In Soil Layer 9','X','')
i=i+1
nc_tab( i ) = nctrans('WGI10_T_ISBA'    ,-1,'mrsfl_L10','kg m-2','frozen_water_content_in_soil_layer',&
                      'Frozen Water Content In Soil Layer 10','X','')
i=i+1
nc_tab( i ) = nctrans('WGI11_T_ISBA'    ,-1,'mrsfl_L11','kg m-2','frozen_water_content_in_soil_layer',&
                      'Frozen Water Content In Soil Layer 11','X','')
i=i+1
nc_tab( i ) = nctrans('WGI12_T_ISBA'    ,-1,'mrsfl_L12','kg m-2','frozen_water_content_in_soil_layer',&
                      'Frozen Water Content In Soil Layer 12','X','')
i=i+1
nc_tab( i ) = nctrans('WGI13_T_ISBA'    ,-1,'mrsfl_L13','kg m-2','frozen_water_content_in_soil_layer',&
                      'Frozen Water Content In Soil Layer 13','X','')
i=i+1
nc_tab( i ) = nctrans('WGI14_T_ISBA'    ,-1,'mrsfl_L14','kg m-2','frozen_water_content_in_soil_layer',&
                      'Frozen Water Content In Soil Layer 14','X','')
i=i+1
nc_tab( i ) = nctrans('WGT1_T_ISBA'     ,-1,'mrsol_L01','kg m-2','total_water_content_in_soil_layer',&
                      'Total water content (liquid+solid) In Soil Layer 1','X','')
i=i+1
nc_tab( i ) = nctrans('WGT2_T_ISBA'     ,-1,'mrsol_L02','kg m-2','total_water_content_in_soil_layer',&
                      'Total water content (liquid+solid) In Soil Layer 2','X','')
i=i+1
nc_tab( i ) = nctrans('WGT3_T_ISBA'     ,-1,'mrsol_L03','kg m-2','total_water_content_in_soil_layer',&
                      'Total water content (liquid+solid) In Soil Layer 3','X','')
i=i+1
nc_tab( i ) = nctrans('WGT4_T_ISBA'     ,-1,'mrsol_L04','kg m-2','total_water_content_in_soil_layer',&
                      'Total water content (liquid+solid) In Soil Layer 4','X','')
i=i+1
nc_tab( i ) = nctrans('WGT5_T_ISBA'     ,-1,'mrsol_L05','kg m-2','total_water_content_in_soil_layer',&
                      'Total water content (liquid+solid) In Soil Layer 5','X','')
i=i+1
nc_tab( i ) = nctrans('WGT6_T_ISBA'     ,-1,'mrsol_L06','kg m-2','total_water_content_in_soil_layer',&
                      'Total water content (liquid+solid) In Soil Layer 6','X','')
i=i+1
nc_tab( i ) = nctrans('WGT7_T_ISBA'     ,-1,'mrsol_L07','kg m-2','total_water_content_in_soil_layer',&
                      'Total water content (liquid+solid) In Soil Layer 7','X','')
i=i+1
nc_tab( i ) = nctrans('WGT8_T_ISBA'     ,-1,'mrsol_L08','kg m-2','total_water_content_in_soil_layer',&
                      'Total water content (liquid+solid) In Soil Layer 8','X','')
i=i+1
nc_tab( i ) = nctrans('WGT9_T_ISBA'     ,-1,'mrsol_L09','kg m-2','total_water_content_in_soil_layer',&
                      'Total water content (liquid+solid) In Soil Layer 9','X','')
i=i+1
nc_tab( i ) = nctrans('WGT10_T_ISBA'    ,-1,'mrsol_L10','kg m-2','total_water_content_in_soil_layer',&
                      'Total water content (liquid+solid) In Soil Layer 10','X','')
i=i+1
nc_tab( i ) = nctrans('WGT11_T_ISBA'    ,-1,'mrsol_L11','kg m-2','total_water_content_in_soil_layer',&
                      'Total water content (liquid+solid) In Soil Layer 11','X','')
i=i+1
nc_tab( i ) = nctrans('WGT12_T_ISBA'    ,-1,'mrsol_L12','kg m-2','total_water_content_in_soil_layer',&
                      'Total water content (liquid+solid) In Soil Layer 12','X','')
i=i+1
nc_tab( i ) = nctrans('WGT13_T_ISBA'    ,-1,'mrsol_L13','kg m-2','total_water_content_in_soil_layer',&
                      'Total water content (liquid+solid) In Soil Layer 13','X','')
i=i+1
nc_tab( i ) = nctrans('WGT14_T_ISBA'    ,-1,'mrsol_L14','kg m-2','total_water_content_in_soil_layer',&
                      'Total water content (liquid+solid) In Soil Layer 14','X','')

! Sea

i=i+1
nc_tab( i ) = nctrans('Z0SEA'           ,-1,'z0_sea','m','roughness_length','Roughness Length For Momentum Over Sea','','')
i=i+1
nc_tab( i ) = nctrans('T2M_SEA'         ,-1,'tas_sea','K','air_temperature_over_sea',&
                      'Near-surface Air Temperature Over Sea','','')
i=i+1
nc_tab( i ) = nctrans('ZON10M_SEA'      , 0,'uas_sea','m s-1','eastward_wind_over_sea',&
                      'Eastward Near-Surface Wind Speed Over Sea','','')
i=i+1
nc_tab( i ) = nctrans('ZON10M_SEA'      , 1,'x_wind_sea','m s-1','x_wind_over_sea',&
                      'Eastward Near-Surface Wind Speed Over Sea In Model Coordinates','','')
i=i+1
nc_tab( i ) = nctrans('MER10M_SEA'      , 0,'vas_sea','m s-1','northward_wind_over_sea',&
                      'Northward Near-Surface Wind Speed Over Sea','','')
i=i+1
nc_tab( i ) = nctrans('MER10M_SEA'      , 1,'y_wind_sea','m s-1','y_wind_over_sea',&
                      'Northward Near-Surface Wind Speed Over Sea In Model Coordinates','','')
i=i+1
nc_tab( i ) = nctrans('W10M_SEA'        ,-1,'sfcWindSea','m s-1','wind_speed','Near-surface Wind Speed Over Sea','','')
i=i+1
nc_tab( i ) = nctrans('W10MMAX_SEA'     ,-1,'sfcWindmaxSea','m s-1','wind_speed','Maximum Near-surface Wind Speed Over Sea','','')
i=i+1
nc_tab( i ) = nctrans('T2M_SEAICE'      ,-1,'tas_seaice','K','near_surface_air_temperature_over_seaice',&
                      'Near-surface Air Temperature Over Sea-ice','','')
i=i+1
nc_tab( i ) = nctrans('W10M_SEAICE'     ,-1,'sfcWindSeaice','m s-1','wind_speed','Near-surface Wind Speed Over Sea-ice','','')
i=i+1
nc_tab( i ) = nctrans('SST'             ,-1,'tos','K','sea_surface_temperature','Sea Surface Temperature','','')
i=i+1
nc_tab( i ) = nctrans('SURFSEA.TEMPERA' ,-1,'sst_b','K','sea_surface_temperature','Sea Surface Temperature SURFSEA.TEMPERA','','')
i=i+1
nc_tab( i ) = nctrans('SIC'             ,-1,'siconca','1','sea_ice_area_fraction','Sea Ice Area Fraction','','')
i=i+1
nc_tab( i ) = nctrans('ICE_THK'         ,-1,'sit','m','sea_ice_thickness','Sea Ice Thickness','','')
i=i+1
nc_tab( i ) = nctrans('SURFSEA.ICECONC' ,-1,'sic_b','1','sea_ice_concentration','Sea Ice Concentration SURFSEA.ICECONC','','')
i=i+1
nc_tab( i ) = nctrans('RNC_SEA'         ,-1,'rnss','J m-2','accumulated_surface_net_radiation',&
                      'Accumulated Surface Net Radiation Over Sea','','')
i=i+1
nc_tab( i ) = nctrans('SWUC_SEA'        ,-1,'rsuss','J m-2','accumulated_surface_upwelling_shortwave_flux_in_air',&
                      'Accumulated Surface Upwelling Shortwave Radiation Over Sea','','')
i=i+1
nc_tab( i ) = nctrans('LWUC_SEA'        ,-1,'rluss','J m-2','accumulated_surface_upwelling_longwave_flux_in_air',&
                      'Accumulated Surface Upwelling Longwave Radiation Over Sea','','')
i=i+1
nc_tab( i ) = nctrans('LWDC_SEA'        ,-1,'rldss','J m-2','accumulated_surface_downwelling_longwave_flux_in_air',&
                      'Accumulated Surface Downwelling Longwave Radiation Over Sea','','')
i=i+1
nc_tab( i ) = nctrans('SWDC_SEA'        ,-1,'rsdss','J m-2','accumulated_surface_downwelling_shortwave_flux_in_air',&
                      'Accumulated Surface Downwelling Shortwave Radiation Over Sea','','')
i=i+1
nc_tab( i ) = nctrans('HC_SEA'          ,-1,'hfsss','J m-2','accumulated_surface_upward_sensible_heat_flux',&
                      'Accumulated Surface Upward Sensible Heat Flux Over Sea','','')
i=i+1
nc_tab( i ) = nctrans('LEC_SEA'         ,-1,'hflss','J m-2','accumulated_surface_upward_latent_heat_flux',&
                      'Accumulated Surface Upward latent heat flux Over Sea','','')
i=i+1
nc_tab( i ) = nctrans('EVAPC_SEA'       ,-1,'evapts','kg m-2','water_evaporation_sea_amount',&
                      'Accumulated Evaporation Over Sea','','')
i=i+1
nc_tab( i ) = nctrans('HU2M_SEA'        ,-1,'hurs_sea','1','relative_humidity_sea','Near-Surface Relative Humidity Over Sea','','')
i=i+1
nc_tab( i ) = nctrans('Q2M_SEA'         ,-1,'huss_sea','kg kg-1','specific_humidity_sea',&
                      'Near-Surface Specific Humidity Over Sea','','')


! Water

i=i+1
nc_tab( i ) = nctrans('Z0WATER'         ,-1,'z0_water','m','roughness_length_over_inland_water',&
                      'Roughness Length For Momentum Over Inland Water','','')
i=i+1
nc_tab( i ) = nctrans('T2M_WAT'         ,-1,'tas_water','K','air_temperature_over_inland_water',&
                      'Near-surface Air Temperature Over Inland Water','','')
i=i+1
nc_tab( i ) = nctrans('T2MMIN_WAT'      ,-1,'tasmin_water','K','air_temperature_over_inland_water',&
                      'Minimum Near-Surface Temperature Over Inland Water','','')
i=i+1
nc_tab( i ) = nctrans('T2MMAX_WAT'      ,-1,'tasmax_water','K','air_temperature_over_inland_water',&
                      'Maximum Near-Surface Temperature Over Inland Water','','')
i=i+1
nc_tab( i ) = nctrans('ZON10M_WAT'      , 0,'uas_water','m s-1','eastward_wind_over_inland_water',&
                      'Eastward Near-Surface Wind Speed Over Inland Water','','')
i=i+1
nc_tab( i ) = nctrans('ZON10M_WAT'      , 1,'x_wind_water','m s-1','x_wind_over_inland_water',&
                      'Eastward Near-Surface Wind Speed Over Inland Water In Model Coordinates','','')
i=i+1
nc_tab( i ) = nctrans('MER10M_WAT'      , 0,'vas_water','m s-1','northward_wind_over_inland_water',&
                      'Northward Near-Surface Wind Speed Over Inland Water','','')
i=i+1
nc_tab( i ) = nctrans('MER10M_WAT'      , 1,'y_wind_water','m s-1','y_wind_over_inland_water',&
                      'Northward Near-Surface Wind Speed Over Inland Water In Model Coordinates','','')
i=i+1
nc_tab( i ) = nctrans('HU2M_WAT'        ,-1,'hurs_water','1','relative_humidity_over_inland_water',&
                      'Near-Surface Relative Humidity Over Inland Water','','')
i=i+1
nc_tab( i ) = nctrans('Q2M_WAT'         ,-1,'huss_water','kg kg-1','specific_humidity_over_inland_water',&
                      'Near-Surface Specific Humidity Over Inland Water','','')
i=i+1
nc_tab( i ) = nctrans('TS_WATER'        ,-1,'ts_water','K','surface_temperature_water','Surface Temperature over Lakes','','')
i=i+1
nc_tab( i ) = nctrans('T_WML'           ,-1,'twml','K','mixed_layer_temperature_water','Mixed Layer Water Temperature','','')
i=i+1
nc_tab( i ) = nctrans('T_BOT'           ,-1,'twb','K','bottom_layer_temperature_water','Bottom Layer Water Temperature','','')
i=i+1
nc_tab( i ) = nctrans('H_ML'            ,-1,'hml','m','mixed_layer_height_water','Water Mixed Layer Height','','')
i=i+1
nc_tab( i ) = nctrans('H_SNOW'          ,-1,'sndw','m','snow_depth_water','Snow Depth Over Water','','')
i=i+1
nc_tab( i ) = nctrans('H_ICE'           ,-1,'hiw','m','ice_thickness_water','Ice Thickness Over Water','','')


! Town

i=i+1
nc_tab( i ) = nctrans('T2M_TEB'         ,-1,'tas_town','K','air_temperature_town',&
                      'Near-Surface Air Temperature In Town','','')
i=i+1
nc_tab( i ) = nctrans('T2MMIN_TEB'      ,-1,'tasmin_town','K','air_temperature_town',&
                      'Minimum Near-Surface Temperature In Town','','')
i=i+1
nc_tab( i ) = nctrans('T2MMAX_TEB'      ,-1,'tasmax_town','K','air_temperature_town',&
                      'Maximum Near-Surface Temperature In Town','','')
i=i+1
nc_tab( i ) = nctrans('Q2M_TEB'         ,-1,'huss_town','kg kg-1','specific_humidity_town',&
                      'Near-Surface Specific Humidity In Town','','')
i=i+1
nc_tab( i ) = nctrans('HU2M_TEB'        ,-1,'hurs_town','1','relative_humidity_town',&
                      'Near-Surface Relative Humidity In Town','','')
i=i+1
nc_tab( i ) = nctrans('ZON10M_TEB'      , 0,'uas_town','m s-1','eastward_wind_town',&
                      'Eastward Near-Surface Wind Speed In Town','','')
i=i+1
nc_tab( i ) = nctrans('ZON10M_TEB'      , 1,'x_wind_town','m s-1','x_wind_town',&
                      'Eastward Near-Surface Wind Speed In Town In Model Coordinates','','')
i=i+1
nc_tab( i ) = nctrans('MER10M_TEB'      , 0,'vas_town','m s-1','northward_wind_town',&
                      'Northward Near-Surface Wind Speed In Town','','')
i=i+1
nc_tab( i ) = nctrans('MER10M_TEB'      , 1,'y_wind_town','m s-1','y_wind_town',&
                      'Northward Near-Surface Wind Speed In Town In Model Coordinates','','')
i=i+1
nc_tab( i ) = nctrans('XQF_TOWN'      , -1,'anthroheat','W m-2','anthropogenic_heatflux',&
                      'Anthropogenic heat flux','','')
i=i+1
nc_tab( i ) = nctrans('TS_TOWN'      , -1,'tsskin','K','skin_temperature',&
                      'Skin temperature','','')
i=i+1
nc_tab( i ) = nctrans('TSGARDEN'      , -1,'tsgree','K','greenspaces_surface_temperature',&
                      'Surface temperature green spaces','','')
i=i+1
nc_tab( i ) = nctrans('TROAD1'        , -1,'tspav','K','pavement_surface_temperature',&
                      'Surface temperature pavements','','')
i=i+1
nc_tab( i ) = nctrans('TROOF1'        , -1,'tsroof','K','roof_surface_temperature',&
                      'Surface temperature roof','','')

! TEB - UTCI 

i=i+1
nc_tab( i ) = nctrans('UTCI_IN'      , -1,'utci_in','degC','utci_in',&
                      'UTCI for person indoors','','')
i=i+1
nc_tab( i ) = nctrans('UTCI_OUTSUN'      , -1,'utci_outsun','degC','utci_outsun',&
                      'UTCI for person outdoors at sun','','')
i=i+1
nc_tab( i ) = nctrans('UTCI_OUTSHAD'      , -1,'utci_outsha','degC','utci_outsha',&
                      'UTCI for person outdoors at shade','','')
i=i+1
nc_tab( i ) = nctrans('UTCI_OUTAGG'      , -1,'utci_outagg','degC','utci_outagg',&
                      'UTCI for person outdoors aggregated (sun + shade)','','')
i=i+1
nc_tab( i ) = nctrans('TRAD_SUN'      , -1,'trad_outsun','K','trad_outsun',&
                      'mean radiant temperature seen by person outdoors at sun','','')
i=i+1
nc_tab( i ) = nctrans('TRAD_SHADE'      , -1,'trad_outsha','K','trad_outsha',&
                      'mean radiant temperature seen by person outdoors at shade','','')

! TEB - canyon diagnostics
i=i+1
nc_tab( i ) = nctrans('T_CAN'        , -1,'tascan','K','mid_canyon_temperature',&
                      'Mid-height urban canyon temperature','','')
i=i+1
nc_tab( i ) = nctrans('T_RD_CAN'     , -1,'tascan_rd','K','mid_canyon_temperature_pavement',&
                      'Mid-height urban canyon temperature above pavement','','')
i=i+1
nc_tab( i ) = nctrans('T_GD_CAN'     , -1,'tascan_gd','K','mid_canyon_temperature_greenspaces',&
                      'Mid-height urban canyon temperature above greenspaces','','')
i=i+1
nc_tab( i ) = nctrans('Q_CAN'      , -1,'husscan','kg kg-1','mid_canyon_specific_humidity',&
                      'Mid-height urban canyon specific humidity','','')
i=i+1
nc_tab( i ) = nctrans('Q_RD_CAN'     , -1,'husscan_rd','kg kg-1','mid_canyon_specific_humidity_pavement',&
                      'Mid-height urban canyon specific humidity above pavement','','')
i=i+1
nc_tab( i ) = nctrans('Q_GD_CAN'     , -1,'husscan_gd','kg kg-1','mid_canyon_specific_humidity_greenspaces',&
                      'Mid-height urban canyon specific humidity above greenspaces','','')
i=i+1
nc_tab( i ) = nctrans('HU_CAN'       , -1,'hurscan','1','mid_canyon_relative_humidity',&
                      'Mid-height urban canyon relative humidity','','')
i=i+1
nc_tab( i ) = nctrans('U_CAN'        , -1,'sfcWindcan','m s-1','mid_canyon_horizontal_wind',&
                      'Mid-height urban canyon horizontal wind','','')

! Patch

i=i+1
nc_tab( i ) = nctrans('T2M_P'           ,-1,'tas','K','air_temperature','Near-Surface Air Temperature','','')
i=i+1
nc_tab( i ) = nctrans('T2MMAX_P'        ,-1,'tasmax','K','air_temperature','Maximum Near-Surface Air Temperature','','')
i=i+1
nc_tab( i ) = nctrans('T2MMIN_P'        ,-1,'tasmin','K','air_temperature','Minimum Near-Surface Air Temperature','','')
i=i+1
nc_tab( i ) = nctrans('Q2M_P'           ,-1,'huss','kg kg-1','specific_humidity','Near-Surface Specific Humidity','','')
i=i+1
nc_tab( i ) = nctrans('HU2M_P'          ,-1,'hurs','1','relative_humidity','Near-Surface Relative Humidity','','')
i=i+1
nc_tab( i ) = nctrans('W10M_P'          ,-1,'sfcWind','m s-1','wind_speed','Near-Surface Wind Speed','','')
i=i+1
nc_tab( i ) = nctrans('PSN_P'           ,-1,'snc','1','snow_fraction','Snow Fraction','','')
i=i+1
nc_tab( i ) = nctrans('TALB_P'          ,-1,'alb','-','surface_total_albedo','Surface Total Albedo','','')
i=i+1
nc_tab( i ) = nctrans('WSNOW_VEGT'      ,-1,'snw_b','kg m-2','total_snow_reservoir','Total Snow Reservoir','','')
i=i+1
nc_tab( i ) = nctrans('DSNOW_VEGT'      ,-1,'snd','m','snow_depth','Snow Depth','','')
i=i+1
nc_tab( i ) = nctrans('RNC_P'           ,-1,'rns','J m-2','accumulated_surface_net_radiation',&
                      'Accumulated Surface Net Radiation','','')
i=i+1
nc_tab( i ) = nctrans('GFLUXC_P'        ,-1,'gfl','J m-2','accumulated_ground_conduct_flux',&
                      'Accumulated Surface Conduct Flux','','')
i=i+1
nc_tab( i ) = nctrans('SWUC_P'          ,-1,'rsus','J m-2','accumulated_surface_upwelling_shortwave_flux_in_air',&
                      'Accumulated Surface Upwelling Shortwave Radiation','','')
i=i+1
nc_tab( i ) = nctrans('LWUC_P'          ,-1,'rlus','J m-2','accumulated_surface_upwelling_longwave_flux_in_air',&
                      'Accumulated Surface Upwelling Longwave Radiation','','')
i=i+1
nc_tab( i ) = nctrans('LWDC_P'          ,-1,'rlds','J m-2','accumulated_surface_downwelling_longwave_flux_in_air',&
                      'Accumulated Surface Downwelling Longwave Radiation','','')
i=i+1
nc_tab( i ) = nctrans('SWDC_P'          ,-1,'rsds','J m-2','accumulated_surface_downwelling_shortwave_flux_in_air',&
                      'Accumulated Surface Downwelling Shortwave Radiation','','')
i=i+1
nc_tab( i ) = nctrans('HC_P'            ,-1,'hfss','J m-2','accumulated_surface_upward_sensible_heat_flux',&
                      'Accumulated Surface Upward Sensible Heat','','')
i=i+1
nc_tab( i ) = nctrans('LEC_P'           ,-1,'hfls','J m-2','_accumulated_surface_upward_latent_heat_flux',&
                      'Accumulated Surface Upward latent heat flux','','')
i=i+1
nc_tab( i ) = nctrans('H_P'             ,-1,'hfssi','J m-2 s-1','instantaneous_surface_upward_sensible_heat_flux',&
                      'Instantaneous Surface Upward Sensible Heat','','')
i=i+1
nc_tab( i ) = nctrans('LE_P'            ,-1,'hflsi','J m-2 s-1','instantaneous_surface_upward_latent_heat_flux',&
                      'Instantaneous Surface Upward latent heat flux','','')
i=i+1
nc_tab( i ) = nctrans('EVAPC_P'         ,-1,'evaptl','kg m-2','water_evapotranspiration_amount',&
                      'Accumulated Evapotranspiration','','')
i=i+1
nc_tab( i ) = nctrans('DRAINC_P'        ,-1,'drain','kg m-2','accumulated_soil_drainage_flux',&
                      'Accumulated Soil Drainage Flux','','')
i=i+1
nc_tab( i ) = nctrans('RUNOFFC_P'       ,-1,'runoff','kg m-2','accumulated_runoff','Accumulated Supersaturation Runoff','','')
i=i+1
nc_tab( i ) = nctrans('HORTONC_P'       ,-1,'horton','kg m-2','accumulated_runoff_horton','Accumulated Horton Runoff','','')
i=i+1
nc_tab( i ) = nctrans('SNOMLTC_P'       ,-1,'snmlt','kg m-2','accumulated_snow_melt_flux','Accumulated Snow Melt Flux','','')
i=i+1
nc_tab( i ) = nctrans('FMUC_P'          , 0,'tauu','kg m-1 s-1','accumulated_surface_downward_eastward_stress',&
                      'Accumulated Surface Downward Eastward Wind Stress','','d')
i=i+1
nc_tab( i ) = nctrans('FMUC_P'          , 1,'x_stress','kg m-1 s-1','accumulated_surface_downward_x_stress',&
                      'Accumulated Surface Downward Eastward Wind Stress In Model Coordinates','','d')
i=i+1
nc_tab( i ) = nctrans('FMVC_P'          , 0,'tauv','kg m-1 s-1','accumulated_surface_downward_northward_stress',&
                      'Accumulated Surface Downward Northward Wind Stress','','d')
i=i+1
nc_tab( i ) = nctrans('FMVC_P'          , 1,'y_stress','kg m-1 s-1','accumulated_surface_downward_y_stress',&
                      'Accumulated Surface Downward Northward Wind Stress In Model Coordinates','','d')
i=i+1
nc_tab( i ) = nctrans('LAI'             ,-1,'lai','-','leaf_area_index','Leaf Area Index','','')
i=i+1
nc_tab( i ) = nctrans('VEG'             ,-1,'vegf','-','vegetation_fraction_of_total_patch_value','Vegetation Fraction','','')
i=i+1
nc_tab( i ) = nctrans('ZON10M_P'        , 0,'uas','m s-1','eastward_wind','Eastward Near-Surface Wind Speed','','')
i=i+1
nc_tab( i ) = nctrans('ZON10M_P'        , 1,'x_wind','m s-1','x_wind',&
                      'Eastward Near-Surface Wind Speed In Model Coordinates','','')
i=i+1
nc_tab( i ) = nctrans('MER10M_P'        , 0,'vas','m s-1','northward_wind','Northward Near-Surface Wind Speed','','')
i=i+1
nc_tab( i ) = nctrans('MER10M_P'        , 1,'y_wind','m s-1','y_wind',&
                      'Northward Near-Surface Wind Speed In Model Coordinates','','')
i=i+1
nc_tab( i ) = nctrans('DTOT_DIF'        ,-1,'dmoisture','m','total_soil_depth_for_moisture','Total Soil Depth For Moisture','','')
i=i+1
nc_tab( i ) = nctrans('DROOT_DIF'       ,-1,'droot','m','root_depth','Root Depth','','')


!
! Atmosphere
!

! Pressure levels

i=i+1
nc_tab( i ) = nctrans('PNNNNNPOT_VORTIC',-1,'pv','s-1','potential_vorticity','Potential Vorticity','P','')
i=i+1
nc_tab( i ) = nctrans('PNNNNNTHETA_PRIM',-1,'thetaE','K','equivivalent_potential_temperature',&
 &'Equivivalent Potential Temperature','P','')
i=i+1
nc_tab( i ) = nctrans('PNNNNNTEMPE_POTE',-1,'theta','K','potential_temperature','Potential Temperature','P','')
i=i+1
nc_tab( i ) = nctrans('PNNNNNVITESSE_VE',-1,'omega','Pa s-1','vertical_velocity','Vertical Velocity','P','')
i=i+1
nc_tab( i ) = nctrans('PNNNNNWIND_DIREC',-1,'wdir','degree','wind_from_direction','Wind From Direction','P','')
i=i+1
nc_tab( i ) = nctrans('PNNNNNWIND_VELOC',-1,'wspeed','m s-1','wind_speed','Wind Speed','P','')
i=i+1
nc_tab( i ) = nctrans('PNNNNNWIND.U.PHY', 0,'ua','m s-1','eastward_wind','Eastward Wind','P','')
i=i+1
nc_tab( i ) = nctrans('PNNNNNWIND.U.PHY', 1,'x_wind','m s-1','x_wind','Eastward Wind In Model Coordinates','P','')
i=i+1
nc_tab( i ) = nctrans('PNNNNNWIND.V.PHY', 0,'va','m s-1','northward_wind','Northward Wind','P','')
i=i+1
nc_tab( i ) = nctrans('PNNNNNWIND.V.PHY', 1,'y_wind','m s-1','y_wind','Northward Wind In Model Coordinates','P','')
i=i+1
nc_tab( i ) = nctrans('PNNNNNHUMI.SPECI',-1,'hus','1','specific_humidity','Specific Humidity','P','')
i=i+1
nc_tab( i ) = nctrans('PNNNNNHUMI_RELAT',-1,'hur','1','relative_humidity','Relative Humidity','P','')
i=i+1
nc_tab( i ) = nctrans('PNNNNNTEMPERATUR',-1,'ta','K','air_temperature','Air Temperature','P','')
i=i+1
nc_tab( i ) = nctrans('PNNNNNSOLID_WATE',-1,'cli','kg kg-1','cloud_ice','Cloud Ice','P','')
i=i+1
nc_tab( i ) = nctrans('PNNNNNLIQUID_WAT',-1,'clw','kg kg-1','cloud_water','Cloud Water','P','')
i=i+1
nc_tab( i ) = nctrans('PNNNNNGEOPOTENTI',-1,'phi','m2 s-2','geopotential','Geopotential','P','')
i=i+1
nc_tab( i ) = nctrans('PNNNNNGEOPOTHEIG',-1,'zg','gpm','geopotential_height','Geopotential Height','P','')
i=i+1
nc_tab( i ) = nctrans('PNNNNNVERT.VELOC',-1,'wa','m s-1','vertical_velocity','Vertical Velocity','P','')


!
! Height levels
!

i=i+1
nc_tab( i ) = nctrans('HNNNNNPRESSURE'  ,-1,'p','Pa','air_pressure','Air Pressure','H','')
i=i+1
nc_tab( i ) = nctrans('HNNNNNWIND_DIREC',-1,'wdir','degree','wind_from_direction','Wind From Direction','H','')
i=i+1
nc_tab( i ) = nctrans('HNNNNNWIND_VELOC',-1,'wspeed','m s-1','wind_speed','Wind Speed','H','')
i=i+1
nc_tab( i ) = nctrans('HNNNNNWIND.U.PHY', 0,'ua','m s-1','eastward_wind','Eastward Wind','H','')
i=i+1
nc_tab( i ) = nctrans('HNNNNNWIND.U.PHY', 1,'x_wind','m s-1','x_wind','Eastward Wind In Model Coordinates','H','')
i=i+1
nc_tab( i ) = nctrans('HNNNNNWIND.V.PHY', 0,'va','m s-1','northward_wind','Northward Wind','H','')
i=i+1
nc_tab( i ) = nctrans('HNNNNNWIND.V.PHY', 1,'y_wind','m s-1','y_wind','Northward Wind In Model Coordinates','H','')
i=i+1
nc_tab( i ) = nctrans('HNNNNNHUMI.SPECI',-1,'hus','1','specific_humidity','Specific Humidity','H','')
i=i+1
nc_tab( i ) = nctrans('HNNNNNHUMI_RELAT',-1,'hur','1','relative_humidity','Relative Humidity','H','')
i=i+1
nc_tab( i ) = nctrans('HNNNNNTEMPERATUR',-1,'ta','K','air_temperature','Air Temperature','H','')
i=i+1
nc_tab( i ) = nctrans('HNNNNNSOLID_WATE',-1,'cli','kg kg-1','cloud_ice','Cloud Ice','H','')
i=i+1
nc_tab( i ) = nctrans('HNNNNNLIQUID_WAT',-1,'clw','kg kg-1','cloud_water','Cloud Water','H','')
i=i+1
nc_tab( i ) = nctrans('HNNNNNCLOUD_FRAC',-1,'clt','1','cloud_fraction','Cloud Fraction','H','')
i=i+1
nc_tab( i ) = nctrans('HNNNNNTKE'       ,-1,'tke','m2 s-2','turbulent_kinetic_energy','Turbulent Kinetic Energy','H','')
i=i+1
nc_tab( i ) = nctrans('HNNNNNVERT.VELOC',-1,'wa','m s-1','vertical_velocity','Vertical Velocity','H','')


!
! Model levels
!

i=i+1
nc_tab( i ) = nctrans('SNNNPRESSURE'    ,-1,'p','Pa','air_pressure','Air Pressure','S','')
i=i+1
nc_tab( i ) = nctrans('SNNNGEOPOTENTIEL',-1,'phi','m2 s-2','geopotential','Geopotential','S','')
i=i+1
nc_tab( i ) = nctrans('SNNNWIND.U.PHYS' , 0,'ua','m s-1','eastward_wind','Eastward Wind','S','')
i=i+1
nc_tab( i ) = nctrans('SNNNWIND.U.PHYS' , 1,'x_wind','m s-1','x_wind','Eastward Wind In Model Coordinates','S','')
i=i+1
nc_tab( i ) = nctrans('SNNNWIND.V.PHYS' , 0,'va','m s-1','northward_wind','Northward Wind','S','')
i=i+1
nc_tab( i ) = nctrans('SNNNWIND.V.PHYS' , 1,'y_wind','m s-1','y_wind','Northward Wind In Model Coordinates','S','')
i=i+1
nc_tab( i ) = nctrans('SNNNHUMI.SPECIFI',-1,'hus','1','specific_humidity','Specific Humidity','S','')
i=i+1
nc_tab( i ) = nctrans('SNNNTEMPERATURE' ,-1,'ta','K','air_temperature','Air Temperature','S','')
i=i+1
nc_tab( i ) = nctrans('SNNNCLOUD_FRACTI',-1,'clt','1','cloud_area_fraction_in_atmosphere_layer','Cloud Area Fraction','S','')
i=i+1
nc_tab( i ) = nctrans('SNNNSOLID_WATER' ,-1,'cli','kg kg-1','mass_fraction_of_cloud_ice_in_air','Cloud Ice','S','')
i=i+1
nc_tab( i ) = nctrans('SNNNLIQUID_WATER',-1,'clw','kg kg-1','mass_fraction_of_cloud_liquid_water_in_air','Cloud Water','S','')
i=i+1
nc_tab( i ) = nctrans('SNNNTKE'         ,-1,'tke','m2 s-2','tke','Turbulent Kinetic Energy','S','')
i=i+1
nc_tab( i ) = nctrans('SNNNVERT.VELOCIT',-1,'wa','m s-1','vertical_velocity','Vertical Velocity','S','')


!
! Derived quantities names
!

i=i+1
nc_tab( i ) = nctrans('TOT.WATER.PRECIP',-1,'pr','kg m-2','precipitation_amount','Accumulated Precipitation','','')
i=i+1
nc_tab( i ) = nctrans('#acpcp'          ,-1,'prc','kg m-2','convective_precipitation_amount',&
                      'Accumulated Convective Precipitation','','')
i=i+1
nc_tab( i ) = nctrans('TOT.SOLID.PRECIP',-1,'prsolid','kg m-2','solid_precipitation_amount',&
                      'Accumulated Solid Precipitation','','')
i=i+1
nc_tab( i ) = nctrans('TOT.NEB.WAT'     ,-1,'clqvi','kg m-2','atmosphere_mass_content_of_cloud_liquid_water',&
                      'Liquid Water Path','','')
i=i+1
nc_tab( i ) = nctrans('TOT.NEB.ICE'     ,-1,'clivi','kg m-2','atmosphere_mass_content_of_cloud_ice','Ice Water Path','','')
i=i+1
nc_tab( i ) = nctrans('TOT.NEB.RAIN'    ,-1,'clrvi','kg m-2','atmosphere_mass_content_of_rain',&
                      'Vertical Integral Of Mass Content Of Rain','','')
i=i+1
nc_tab( i ) = nctrans('TOT.NEB.SNOW'    ,-1,'clsvi','kg m-2','atmosphere_mass_content_of_snow',&
                      'Vertical Integral Of Mass Content Of Snow','','')
i=i+1
nc_tab( i ) = nctrans('TOT.NEB.GRAUPEL' ,-1,'clgvi','kg m-2','atmosphere_mass_content_of_graupel',&
                      'Vertical Integral Of Mass Content Of Graupel','','')
i=i+1
nc_tab( i ) = nctrans('#ulwrs'          ,-1,'rlus','J m-2','accumulated_surface_upwelling_longwave_flux_in_air',&
                      'Accumulated Surface Upwelling Longwave Radiation','','u')
i=i+1
nc_tab( i ) = nctrans('#uswrs'          ,-1,'rsus','J m-2','accumulated_surface_upwelling_shortwave_flux_in_air',&
                      'Accumulated Surface Upwelling Shortwave Radiation','','u')
i=i+1
nc_tab( i ) = nctrans('#uswrt'          ,-1,'rsut','J m-2','accumulated_toa_outgoing_shortwave_flux',&
                      'Accumulated TOA Outgoing Shortwave Radiation','','u')
i=i+1
nc_tab( i ) = nctrans('CLSWIND.VELOCITY',-1,'sfcWind','m s-1','wind_speed','Near-Surface Wind Speed','','')
i=i+1
nc_tab( i ) = nctrans('CLSWIND.DIRECT'  ,-1,'sfcWindDir','degree','wind_direction','Wind Direction','','')
i=i+1
nc_tab( i ) = nctrans('CLSDEWPOINTTEMP' ,-1,'td','K','dew_point_temperature','Dew Point Temperature','','')


!
! Misc
!
i=i+1
nc_tab( i ) = nctrans('PATCH'           ,-1,'patchf','-','patch_fraction_of_total_grid_value','Patch Fraction','','')


!
! For wind farm parameterization
!

i=i+1
nc_tab( i ) = nctrans('WFPOWERINS'  ,-1,'wfpower_ins','MW','instantaneous_power_prod_windfarm',&
                      'Instantaneous Power Production Of Wind Farms','','')
i=i+1
nc_tab( i ) = nctrans('WFPOWERACC'  ,-1,'wfpower_acc','MJ','accumulated_power_prod_windfarm',&
                      'Accumulated Power production of wind farms','','')
