edit HM_REV $ENV{HM_REV}
edit HM_WD "$ENV{HM_WD}"
edit HM_DATA "$ENV{HM_DATA}"
edit HM_LIB "$ENV{HM_LIB}"
edit ECF_INCLUDE $ENV{HM_LIB}/ecf
edit ECF_FILES   $ENV{HM_LIB}/ecf
edit ECF_TRIES 2
edit ECF_HOME $ENV{JOBOUTDIR}
edit ECF_KILL_CMD "echo not working"
edit ECF_OUT $ENV{JOBOUTDIR}
edit ECF_JOBOUT $ENV{JOBOUTDIR}%ECF_NAME%.%ECF_TRYNO%
edit SIMULATION_TYPE $ENV{SIMULATION_TYPE}
if ( $ENV{STREAM} ne '' )
  edit STREAM $ENV{STREAM}
else
  edit STREAM undefined
endif
if ( $ENV{SIMULATION_TYPE} eq 'climate' && $ENV{PLAYFILE} eq 'climsim' )
  edit YMD 99999999
  edit HH 99
  edit ECF_JOB_CMD_BASE perl -S %HM_LIB%/scr/Submit.pl -l %HM_LIB% -e %ENSMBR% -g %DTG% -d %HM_DATA% -o %ECF_JOBOUT% -s %ECF_HOST% -p %ECF_PORT% -j %ECF_JOB% -t $ENV{STREAM} >> %HM_DATA%/ECF$ENV{STREAM}.log 2>&1
else
  edit DTG 9999999999
  edit ECF_JOB_CMD_BASE perl -S %HM_LIB%/scr/Submit.pl -l %HM_LIB% -e %ENSMBR% -y %YMD% -h %HH% -d %HM_DATA% -o %ECF_JOBOUT% -s %ECF_HOST% -p %ECF_PORT% -j %ECF_JOB% -t $ENV{STREAM} >> %HM_DATA%/ECF$ENV{STREAM}.log 2>&1
endif
if ( $ENV{SUBMITHOST} ne '' )
  edit ECF_JOB_CMD "$ENV{RSH} -o 'StrictHostKeyChecking=no' $ENV{SUBMITHOST} '%ECF_JOB_CMD_BASE%'"
else
  edit ECF_JOB_CMD "%ECF_JOB_CMD_BASE%"
endif
edit ECF_LOGHOST $ENV{ECF_LOGHOST}
edit ECF_LOGPORT $ENV{ECF_LOGPORT}
