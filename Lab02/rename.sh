#!/bin/tcsh

# changes all files' extension of a given type to another

if("$#" < 2) then
    echo "ERROR: incorrect arguments\nRun file in this manner: ./rename.sh
        (type searched) (type changed)"
    exit 1
endif

echo "---------------------------------------------------"
# search files in directory with extension $1 (first argument)
foreach file (`find . -name "*.$1" | cut -c 3-`)
    echo "Finding information for $file\n"
#-----check if file exists
    if(-e $file) then
        echo "$file exists"
#-----check read permission
        if(-r $file) then
            echo "$file has read permissions"
        else
            echo "$file does NOT have read permissions"
        endif
        if(-w $file) then
            echo "$file has write permissions"
        else
            echo "$file does NOT have write permissions"
        endif
 29 #-----Converts file type to given extension
        mv -v "$file" "`echo $file | sed 's/$1/$2/g'`"
    else echo "$file does NOT exist"
    endif
    echo "---------------------------------------------------"
end
