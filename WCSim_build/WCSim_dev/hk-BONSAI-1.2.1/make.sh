#!/bin/bash

ROOT_LIBDIR=$($ROOTSYS/bin/root-config --libdir)
echo $ROOT_LIBDIR
if [[ -z "${LD_LIBRARY_PATH}" ]]; then
	export LD_LIBRARY_PATH=$ROOT_LIBDIR
else
	export LD_LIBRARY_PATH=$LD_LIBRARY_PATH:$ROOT_LIBDIR
fi

export PATH=$PATH:$ROOTSYS/bin

make  $1
