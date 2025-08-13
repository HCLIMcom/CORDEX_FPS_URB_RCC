# CORDEX_FPS_URB_RCC

- Experiment created based on the HCLIM46_develop Commits on July 18, 2025 (Commit c68d367)
- These setup are used: NPATCH=3, NHINCSOL=4, 'Dry Soil Layer' activated by default (see nam/surfex_namelists.pm).
- ~~We still need to get in the fix for the latent heat flux, once that has been approved in NWP.~~ See PR Hirlam/Harmonie#1203

---

## SMHI: HCLIM46-ALADIN --> HCLIM46-AROME

### HCLIM46_EUR12_ALADIN_v1_URBRCC_EVAL

---

## KNMI: RACMO nested experiments

### RACMO: eR2v3-v578ec-Y9909-LU2015-MAC2SP-fERA5 (1999-2009)
*RACMO run on the EUR12 domain, nested in ERA5.1, restarted on 1998120100 from a simulation started in 1979.*

Boundaries for HCLIM created from this experiment are stored in ECFS in `ec:/rus/HXEUR12/eR2v3-v578ec-Y9909-LU2015-MAC2SP-fERA5/RACMO_HarmLBC`.

### RACMO: eR2v3-v578ec-Y2023-LU2015-MAC2SP-fERA5 (2020-2023)
*Same as eR2v3-v578ec-Y9909-LU2015-MAC2SP-fERA5, but from different years, with many observations. Restarted on 2019120100 from a simulation started in 1979.*

Boundaries for HCLIM created from this experiment are stored in ECFS in `ec:/rus/HXEUR12/eR2v3-v578ec-Y2023-LU2015-MAC2SP-fERA5/RACMO_HarmLBC`.

### HCLIM46_CXURB_PARIS2p5_AROfRACMOfERA5 (1999-2009)
*HCLIM46-AROME experiment nested in RACMO for a small domain centered around Paris. 1999 is a spin-up year.*

|                |     |
|----            |---- |
| Domain         | PARIS2.5  |
| nlev           | 65        |
| dynamics       | nh        |
| physics        | arome     |
| boundaries     | RACMO from ec:/rus/HXEUR12/eR2v3-v578ec-Y9909-LU2015-MAC2SP-fERA5/RACMO_HarmLBC |
| BDINT          | 1         |
| climate files  | created for this experiment |
| machine        | ECMWF.atos, 4 nodes (14x18+4, 4 threads)|
| setup command  | `Harmonie setup -h ECMWF.atos -r /perm/nkl/git/github/Hirlam/HCLIM/HCLIM46_develop`, then added mods |
| start command  | `Harmonie start DTG=1999010100 DTGEND=2010010100 BUILD=yes` |
| started on     | 20250730 |
| completed on   | 20250813 |
| ran by         | Bert van Ulft (nkl) |
| archive        | `ec:harmonie/CORDEX_FPS_URB_RCC/stage1/HCLIM46_CXURB_PARIS2p5_AROfRACMOfERA5` |
| HCLIM git      | Hirlam/HCLIM, taken from $PERM/git/github/Hirlam/HCLIM/HCLIM46_develop|
| HCLIM revision | [branch HCLIM46_develop@c68d3678](https://github.com/Hirlam/HCLIM/commit/c68d3678cd891b003d4c9e1261be41bf3e8c3912) |
| CX EXP revision@start | [26d23457](https://github.com/HCLIMcom/CORDEX_FPS_URB_RCC/commit/26d23457614444377cf1d2dd13d9ed0d0d20640a) |
| CX EXP revision@end   | [f48e5168](https://github.com/HCLIMcom/CORDEX_FPS_URB_RCC/commit/f48e5168adc044800ebbac53a3562cca50b7e7d6) |

#### Modifications
* mods with fixes and extra output for TEB from [Aitor's PR 193 `SURFEX/TEB/GARDEN - Urban canyons`](https://github.com/Hirlam/HCLIM/pull/193)
* compilation: switch from GNU to INTEL, compile with dual precision, dont't build gl_single
* Use RACMO as host model, with BDINT=1
* PARIS2.5 domain added
* Output adapted to project requirements (mainly for SURFEX/TEB) in `surfex_selected_output.pm`, `Select_postp.pl`, `convertFA`, `yomxfu.F90` (to allow hourly min/max T)
* `surfex_namelists.pm`:
  * `LGARDEN=.TRUE.`
  * `CSEA_FLUX=ECUME6`
  * `LSURF_MISC_BUDGET=.TRUE.`
  * `LUTCI=.TRUE.`
* Disable abort for `DIF` and `LSOC` in `init_teb_garden_pgdn.F90`
* Split Archiving from Postprocessing family in climsim.tdf for speed-up
* Minor other changes:
  * Submission settings in Env_submit
  * Archiving path `HM_ARC` in Env_system
  * In config_exp.h (e.g. domain, hourly reset of min/max temp, FA time format & compression)
  * Archiving of logs slightly modified (archive)

### HCLIM46_CXURB_PARIS2p5_Y2023_AROfRACMOfERA5 (2020-2023)
*Same as HCLIM46_CXURB_PARIS2p5_AROfRACMOfERA5, but for different period, with lots of observations. 2020 is a spin-up year.*

|                |     |
|----            |---- |
| Domain         | PARIS2.5  |
| nlev           | 65        |
| dynamics       | nh        |
| physics        | arome     |
| boundaries     | RACMO from ec:/rus/HXEUR12/eR2v3-v578ec-Y2023-LU2015-MAC2SP-fERA5/RACMO_HarmLBC |
| BDINT          | 1         |
| climate files  | used from `HCLIM46_CXURB_PARIS2p5_AROfRACMOfERA5` |
| machine        | ECMWF.atos, 4 nodes (14x18+4, 4 threads)|
| setup command  | copied from `HCLIM46_CXURB_PARIS2p5_AROfRACMOfERA5`, removed experiment is locked, added mods |
| start command  | `Harmonie start DTG=2020010100 DTGEND=2024010100` |
| started on     | 20250811 |
| completed on   |  |
| ran by         | Bert van Ulft (nkl) |
| archive        | `ec:harmonie/CORDEX_FPS_URB_RCC/stage1/HCLIM46_CXURB_PARIS2p5_Y2023_AROfRACMOfERA5` |
| HCLIM git      | Hirlam/HCLIM, taken from $PERM/git/github/Hirlam/HCLIM/HCLIM46_develop|
| HCLIM revision | [branch HCLIM46_develop@c68d3678](https://github.com/Hirlam/HCLIM/commit/c68d3678cd891b003d4c9e1261be41bf3e8c3912) |
| CX EXP revision@start | [f48e5168](https://github.com/HCLIMcom/CORDEX_FPS_URB_RCC/commit/f48e5168adc044800ebbac53a3562cca50b7e7d6) |
| CX EXP revision@end   |  |

#### Modifications
* all those from HCLIM46_CXURB_PARIS2p5_AROfRACMOfERA5
* point BINDIR and CLIMDIR to HCLIM46_CXURB_PARIS2p5_AROfRACMOfERA5 exp

## Domains

### PARIS12.5

```
   'PARIS12.5'=>{
      'TSTEP'  => '450',
      'NLON'   => '216',
      'NLAT'   => '180',
      'LONC'   => '5',
      'LATC'   => '47',
      'LON0'   => '10.5',
      'LAT0'   => '49.5',
      'GSIZE'  => '12500.',
   },
```

### Paris2.5
```
   'PARIS2.5'=>{
      'TSTEP'  => '75',
      'NLON'   => '300',
      'NLAT'   => '300',
      'LONC'   => '2.7',
      'LATC'   => '48.7',
      'LON0'   => '10.5',
      'LAT0'   => '49.5',
      'GSIZE'  => '2500.',
   },
```
