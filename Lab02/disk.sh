#!/bin/tcsh

# extract percentage of sda1 and warn user if it exceeds number given as option
if($# < 1) then
    echo "ERROR: improper arguments\nPlease run script with a numeric argument"
    exit 1
endif

@ sda1_perc = `df | grep 'sda1' | awk '{print +$5}'`
if($sda1_perc > $1) then
    echo "WARNING: sda1 percent usage exceeds given percent - $sda1_perc%"
endif
