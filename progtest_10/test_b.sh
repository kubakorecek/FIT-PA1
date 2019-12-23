#!/bin/bash
g++ -Wall ./new.c -o ./cv_outb

PROG=/home/kubak182/FIT/pa1/progtest_g/cv_outb	

for IN_FILE in /home/kubak182/FIT/pa1/progtest_g/sample_b/CZE/*_in.txt ; do
	
	echo $IN_FILE;
	$PROG < $IN_FILE

done		
