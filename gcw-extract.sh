#!/bin/bash
make gcw_filename
for i in $*
do
OFILE=`./gcw_filename $i`
echo $i
rm -f ${OFILE}
gpg --output ${OFILE} --decrypt $i
done
