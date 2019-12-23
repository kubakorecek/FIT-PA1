#!/bin/bash

PROG=/home/kubak182/FIT/pa1/proseminar/kvadratic_equation/Kvadratic

for IN_FILE in /home/kubak182/FIT/pa1/proseminar/kvadratic_equation/test/in_*.txt; do
	echo $IN_FILE;

	REF_FILE=`echo -n $IN_FILE | sed -e 's/in_\(.*\)$/\out_\1/'`
	echo $REF_FILE;
	$PROG <$IN_FILE > my_out.txt
	
	if ! diff $REF_FILE my_out.txt ; then
		echo "Fail: $IN_FILE";
		exit
	else
		echo "OK: $IN_FILE";
	fi
done	

 
