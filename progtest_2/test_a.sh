#!/bin/bash
g++ -Wall ./get_bin3.c -o ./cv_out

PROG=/home/kubak182/FIT/pa1/progtest_3/cv_out	

for IN_FILE in /home/kubak182/FIT/pa1/progtest_3/sample/CZE/*_in.txt ; do
	
	echo $IN_FILE;

	REF_FILE=`echo -n $IN_FILE | sed -e 's/\(.*\)_in.txt/\1_out.txt/'`
	echo $REF_FILE;
	$PROG < $IN_FILE > my_outv2.txt
	if ! diff $REF_FILE my_outv2.txt ; then
		echo "Fail: $IN_FILE";
	
		exit
	else
	   	echo "OK: $IN_FILE";
	fi
done	
