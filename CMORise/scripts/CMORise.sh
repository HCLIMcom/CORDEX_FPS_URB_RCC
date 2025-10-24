#!/bin/bash
	
# CMORise
# ------------------------------------
CMORise()
{
    # Function to handle each case
    function handle_case {
        case $1 in
            setup | launch)
		echo " "
                ;;
            *)
                echo "Invalid option."
                echo " "
		echo "Possible options:"
                echo "     setup: setup suites and inc files"
                echo "     launch: launch CMOR suites"
                echo " "
                echo "Optional options:"
                echo "     --all : launch all available suites"
                exit 1
                ;;
        esac
    }

    # Function to handle optional arguments with values
    function handle_optional_args {
        while [[ $# -gt 0 ]]; do
            case $1 in
                --all)
                    # Launch all available suites
                    launch_all="TRUE"
                    shift
                    ;;
		*)
                    echo "Unknown optional argument: $1"
                    ;;
            esac
            shift
        done
    }

    echo ' '
    echo '-----------------------------------'
    echo '----------- CMORise ---------------'
    echo '-----------------------------------'
    echo ' '

    case_argument="$1"
    shift  # Shift arguments to handle optional parameters

    # Handle the provided case
    handle_case "$case_argument"

    # Handle optional arguments if provided
    handle_optional_args "$@"

    if [ $case_argument == 'setup' ]; then

        CMOR_setup

    elif [ $case_argument == 'launch' ]; then
        
	if [ -z "$launch_all" ] ; then
            launch_all="FALSE"
        fi

        CMOR_launch

    fi
}

CMOR_setup()
{
	# Create suites folder
	mkdir -p suites

	# Create submit files
	python3 scripts/create_ecflow_submit.py config/config_ecflow.yaml

	# Create suite files
	python3 scripts/create_ecflow_suites.py config/config_ecflow.yaml

	# Prepare suite folder
	python3 scripts/prepare_ecflow_suites.py config/config_ecflow.yaml
}

CMOR_launch()
{
	echo '------------'
        echo 'LAUNCH SUITE FILES'
        echo '------------'

	# Initialise and launch suites
        ecf_port=${ECF_PORT-3141}
	cd suites

	# Get list of possible suites
	readarray -d '' ecflow_suites < <(find . -type f -name '*.def' -print0)
	ecflow_suites=("${ecflow_suites[@]#./}")

	for ecflow_suite in "${ecflow_suites[@]}"; do

		if [ "$launch_all" == "TRUE" ]; then
		   action="y"
		else
    		   echo " - Do you want to start $ecflow_suite ? [y/n]"
    		   read action
		fi

    		if [ "$action" == "y" ]; then

		   echo "    ... Uploading $ecflow_suite to ecFlow and starting it ..."
		
                   ecf_host_list="ecflow-gen-$USER-001 ecfg-$USER-1"
                   if [ "no$ECF_HOST" = "no" ]; then
                      printf " Selecting ECF_HOST ... "
                      nfound=0
                      for ecf_host in $ecf_host_list; do
                         if ping -c1 -W1 $ecf_host &> /dev/null; then
                            printf "found $ecf_host ... "
                            ECF_HOST=$ecf_host
                            ((nfound+=1))
                         fi
                      done
                     if [ $nfound -ne 1 ]; then
                        echo "expected 1 ecFlow host, but found $nfound, EXIT"
                        exit 1
                     fi
                     echo "OK"
                   fi

                   if suitestate=$(ecflow_client --query state /${ecflow_suite%.def} --host=$ECF_HOST --port=$ecf_port 2> /dev/null); then
                     # Suite with this name exists on the server
                     if [ "$suitestate" = "active" ]; then
                       echo "Suite $ecflow_suite is already active, abort"
                       exit 1
                     else
		       ecflow_client --replace=${ecflow_suite%.def} $ecflow_suite --host=$ECF_HOST --port=$ecf_port
                     fi
                   else
		     ecflow_client --load=$ecflow_suite --host=$ECF_HOST --port=$ecf_port
                   fi
		   ecflow_client --begin=${ecflow_suite%.def} --host=$ECF_HOST --port=$ecf_port

    		else
		   echo "    ... Skipping ..."
    		fi

	done
}

CMORise "$@"
