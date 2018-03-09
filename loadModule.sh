#!/bin/bash
# @author Landon Clipp
# @email clipp2@illinois.edu
# @date Oct 11, 2017

usage(){

    description="Usage: $0 [OPTS]
DESCRIPTION:
\tThis script handles loading the tuxctl module as described in the
\tMP2 documentation.

ARGUMENTS:
\t[OPTS]	-h Display this help message
\t        -m make the files in mp2/module before loading the module.
"
    while read -r line; do
        printf "$line\n"
    done <<< "$description"
}

SCRIPT_PATH="$( cd "$( dirname "${BASH_SOURCE[0]}" )" && pwd )"  # Get abs path of this script
if [ "$(basename $SCRIPT_PATH)" != "mp2_sfpotem2" ]; then
	echo "Error: Place this script in the mp2 directory and try again!"
	exit 1
fi

cd "$SCRIPT_PATH"/module

m="$1"

if [ "$m" == "-h" ]; then
	usage
	exit 1
elif [ "$m" == "-m" ]; then
	echo "Building ioctls..."
	make
	retVal=$?
	if [ "$retVal" -ne 0 ]; then
		echo "Failed to make tux ioctls." >&2
		exit 1
	fi
	echo "Done."
	echo
elif [ $# -ne 0 ]; then
	echo "Unrecognized command: $m" >&2
	exit 1
fi

echo "Adding module..."
# Remove module if it's already loaded
sudo /sbin/rmmod tuxctl 2> /dev/null

# Load the module
sudo /sbin/insmod ./tuxctl.ko


# Print out where the module has been loaded
tuxctlLine="$(cat /proc/modules | grep tuxctl | cut -d' ' -f6)"
echo "Done."

echo "Loaded at address:"
echo "${tuxctlLine}"

exit 0