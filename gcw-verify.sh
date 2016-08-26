#!/bin/bash
for i in $*
do
echo $i
gpg --verify $i
done
