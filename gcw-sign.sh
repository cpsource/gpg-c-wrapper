#!/bin/bash
make
for i in $*
do
echo $i
./gcw_add_filename $i
rm -f $i.gcw
gpg --output $i.gcw --clearsign $i
rm -f $i
done
