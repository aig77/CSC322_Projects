#!/bin/tcsh
# Get important information when executed
echo "UID=`id -ur`"
echo "GID=`id -G`"
echo "Groups=`id -Gn`"
echo "SHELL=`which tcsh`"
echo "HOME=$HOME"
echo "PATH=$PATH"
