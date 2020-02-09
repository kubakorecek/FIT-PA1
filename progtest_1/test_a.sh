#!/bin/bash
g++ -Wall ./cv2av2.c -o ./cv2_av2

PROG=/home/kubak182/FIT/pa1/progtest_2/cv2_av2	

for IN_FILE in /home/kubak182/FIT/pa1/progtest_2/test_a/CZE/*_in.txt ; do
	
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
