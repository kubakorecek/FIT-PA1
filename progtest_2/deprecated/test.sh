#!/bin/bash

PROG=/home/kubak182/FIT/pa1/progtest_2/cv2	

for IN_FILE in /home/kubak182/FIT/pa1/progtest_2/test/CZE/*_in.txt ; do
	
	echo $IN_FILE;

	REF_FILE=`echo -n $IN_FILE | sed -e 's/\(.*\)_in.txt/\1_out.txt/'`
	echo $REF_FILE;
	$PROG < $IN_FILE > my_out.txt
	if ! diff $REF_FILE my_out.txt ; then
		echo "Fail: $IN_FILE";
		exit
	else
	   	echo "OK: $IN_FILE";
	fi
done	
