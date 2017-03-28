#!/bin/sh

if [ "$1" = "" ]; then
	echo "$0 [project name]"
	exit
fi

kwinject make -j 4

#rm is added by zhangyu, following Lena's advice
rm -rf kwtables

#kwbuildproject -I -j 4 -o kwtables kwinject.out
# -I means incremental scan. Replace -I with --force to use full scan according to Lena's advice
kwbuildproject --force -j 4 -o kwtables kwinject.out

echo Uploading result to OTC klockwork server...
kwadmin --url https://otckw.jf.intel.com:8080 load $1 kwtables

