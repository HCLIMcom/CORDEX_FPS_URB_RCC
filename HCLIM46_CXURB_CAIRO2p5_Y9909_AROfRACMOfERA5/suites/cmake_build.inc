#
# Template for build part of tdf files
#
   family Build
      complete [ $ENV{BUILD} eq 'no' ]
      trigger ( InitRun == complete )
  if ( $ENV{FP_PRECISION} eq 'dual' )
      edit FP_PREC_LOCAL double
  else
      edit FP_PREC_LOCAL $ENV{FP_PRECISION}
  endif
      task CMake_prerequisites
      task CMake_configure
         trigger ( CMake_prerequisites == complete )
      task CMake_build
         trigger ( CMake_configure == complete )
  if ( $ENV{LOOPS} eq 'yes' )	 
      task CMake_OOPS
         trigger ( CMake_build == complete ) 
  endif 
  if ( $ENV{FP_PRECISION} eq 'dual' )
      family Build_single
         edit FP_PREC_LOCAL single
         task CMake_prerequisites
         task CMake_configure
            trigger ( CMake_prerequisites == complete )
         task CMake_build
            trigger ( CMake_configure == complete )
      endfamily # Build_single
  endif
      family Utilities
         task CMake_gl
            trigger ( ../CMake_build == complete )
#No SP gl, aborts and not needed  if ( $ENV{FP_PRECISION} eq 'dual' )
#No SP gl, aborts and not needed         task CMake_gl_single
#No SP gl, aborts and not needed            trigger ( ../CMake_build == complete )
#No SP gl, aborts and not needed  endif
         task CMake_obsmon
            trigger ( ../CMake_build == complete )
  if ( $ENV{COMPILE_DABYFA} eq 'yes' )
         task Make_FldAlgn
            trigger ( ../CMake_build == complete )
  endif
  if ( $ENV{PYSURFEX} ne '' or $ENV{PLAYFILE} eq 'testbed' or $ENV{USE_MSG} eq 'yes')
         task Install_pysurfex
  endif

      endfamily # Utilities
   endfamily # Build

   task CollectLogs
      trigger ( ( Build == aborted or Build == complete ) and InitRun == complete )
      edit ENVT 'FROM=Build'
