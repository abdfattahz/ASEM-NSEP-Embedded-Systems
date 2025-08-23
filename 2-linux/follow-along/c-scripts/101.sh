#!/bin/bash
global="global variable"

foo () {
	local inside="local variable"
	echo $global
	echo $inside
	global="modified global"
	}

echo $global
foo
echo $global
echo $inside
