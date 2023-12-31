#!/bin/bash

# ROOT version as argument, default value is 6 for ROOT6
#ROOT_ARG=5
ROOT_ARG=6

if [ ! -z "$1" ] ; then
	echo "ROOT version requested to be: ${1}"
	ROOT_ARG=$1
fi

############################
# CMAKE
############################

export PATH=/usr/local/cmake-3.26.0/bin/:$PATH

############################
# ROOT/CERN
############################

if [[ "$ROOT_ARG" == 5 ]] ; then 
	echo "Use ROOT5"
	# Note: official ROOT 5.34 installation on sukap is not compatible with cmake
	#  Temporary use Guillaume Pronost's version. Should change in the future.
	#
	export ROOT_DIR=/home/pronost/software/root-5.34.38-build
	export ROOT_STR=ROOT5
else
	echo "Use ROOT6"
	# Note: There is no official ROOT 6 installation 
	#  Temporary use Guillaume Pronost's version. Should change in the future.
	export ROOT_DIR=/home/pronost/software/root-6.22.00-build
	export ROOT_STR=ROOT6
fi
	
# Note: There is no official ROOT 6 installation 
#  Temporary use Guillaume Pronost's version. Should change in the future.
#export ROOT_DIR=/home/pronost/software/root-6.22.00-build
source ${ROOT_DIR}/bin/thisroot.sh

alias root='root -l'

############################
# GEANT4
############################

pwd=$PWD
cd /usr/local/sklib_gcc8/geant4.10.05.p01/bin
source geant4.sh
cd /usr/local/sklib_gcc8/geant4.10.05.p01/share/Geant4-10.5.1/geant4make
source geant4make.sh
echo "Connect a PATH of Geant4.10"
cd "$pwd"

############################
# WCSim
############################
export BRANCH_NAME=$(git rev-parse --abbrev-ref HEAD)
export WCSIMDIR=/disk02/usr7/licheng/ORNL_SNS/WCSim_Roger/WCSim_build/WCSim_dev
export LD_LIBRARY_PATH=$LD_LIBRARY_PATH:$WCSIMDIR
export BONSAIDIR=/disk02/usr7/licheng/ORNL_SNS/WCSim_Roger/WCSim_build/WCSim_dev/hk-BONSAI-1.2.1

