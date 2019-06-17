#!/bin/tcsh

#DIRNAME=/usr/bin
#FILETYPE="shell script"
#LOGFILE=logfile
#file "$DIRNAME"/* | fgrep "$FILETYPE" | tee $LOGFILE | wc -l
#exit 0

set DIRNAME = /usr/bin
set FILETYPE = "shell script"
set LOGFILE = logfile
file "$DIRNAME"/* | fgrep "$FILETYPE" | tee $LOGFILE | wc -l
