#!/bin/bash
welcome () {
	echo Welcome $1 to $2

	if [[ $# -eq 2 ]]; then
		return 0
	else
		return 1
	fi
	}

welcome Ali Mars
echo "Last return: $?"
welcome Muthu Jupiter Venus
echo "Last return: $?"
welcome Grace
echo "Last return: $?"
