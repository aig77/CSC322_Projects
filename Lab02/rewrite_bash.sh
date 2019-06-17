#!/bin/bash
DIRNAME=/usr/bin
FILETYPE="shell script"
LOGFILE=logfile
file "$DIRNAME"/* | fgrep "$FILETYPE" | tee $LOGFILE | wc -l
exit 0
