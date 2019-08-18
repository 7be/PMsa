#!/bin/bash

# check if connected to dcaiti network
nslookup master.dcaiti

if [ "$?" != 0 ]
then
	echo "network unreachable.. exiting!"
	exit 1
fi
sudo systemctl stop ntp > /dev/null
#sudo ntpd -q -g -x 
sudo ntpdate-debian -b master.dcaiti  > /dev/null
if [ "$?" != 0 ]
then
	echo "ntpq -qgx failed.. exiting!"
	exit 1
fi
sudo systemctl start ntp > /dev/null

MAC=`cat /sys/class/net/wlan0/address`
MAC=`echo $MAC | sed s/\://g`
DATE=`date +"%Y%m%d%H%M"`
FNAME="${MAC}_${DATE}.csv"



echo "Writing to file $FNAME"

# -oL line buffered
stdbuf -oL python /usr/local/bin/dcaiti/aqi.py | ssh pi@master.dcaiti "cat - > $FNAME"
