#!/bin/bash
# @author Landon Clipp
# @email clipp2@illinois.edu
# @date Oct 11, 2017

usage(){

    description="Usage: $0 [OPTS] [ADDR]
DESCRIPTION:
\tThis script is a GDB wrapper that initializes GDB so that
\tdebugging the tux ioctls can happen. This script automatically
\timplements the steps in the Debugging the Tux Controller
\tportion of the mp2-tux documentation and returns your shell to the
\tGDB prompt. Your test_debug machine must be open before running
\tthis script. Place script in the mp2 directory and run with sudo
\tin your devel machine. You will need to answer \"y\" when GDB prompts.

ARGUMENTS:
\t[OPTS]	-h Display this help message
\t[ADDR]    The tuxctl address in your test machine. Found by executing
\t          cat /proc/modules in your test machine.
"
    while read -r line; do
        printf "$line\n"
    done <<< "$description"
}

tuxctlAddr=''

if [ "$1" == "-h" -o $# -ne 1 ]; then
	usage
	exit 1
else
    tuxctlAddr="$1"
fi

SCRIPT_PATH="$( cd "$( dirname "${BASH_SOURCE[0]}" )" && pwd )"  # Get abs path of this script

if [ "$(basename $SCRIPT_PATH)" != "mp2_sfpotem2" ]; then
	echo "Error: Place this script in the mp2 directory and try again!"
	exit 1
fi

cd module

sudo gdb -ex "add-symbol-file ./tuxctl.o ${tuxctlAddr}" -ex "target remote 10.0.2.2:1234"
