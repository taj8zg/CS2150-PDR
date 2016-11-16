#Ashley Nguyen - apn2my
#PostLab06 - averagetime.sh
#3.15.16

#!/bin/bash 

#Write a shell script that will prompt the user for the
#dictionary & grid file names used by executable 

#does not expect script to have if.case.for.while loops 
#should have 5 separate commands WITHOUT a LOOP

#shell script must be called a.out

#Prompting user for input
echo 'Enter dictionary file: '
read dFile

echo 'Enter grid file: '
read gFile

#Obtaining 5 different run times of same parameters 
RUN=`./a.out $dFile $gFile | tail -1`
RUN1=`./a.out $dFile $gFile | tail -1`
RUN2=`./a.out $dFile $gFile | tail -1`
RUN3=`./a.out $dFile $gFile | tail -1`
RUN4=`./a.out $dFile $gFile | tail -1`

#Printing out the average time 
echo 'Average Time: ' $(((RUN + RUN1 + RUN2 + RUN3 + RUN4)/ (5))) 'milliseconds'

