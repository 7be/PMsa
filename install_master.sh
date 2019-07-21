#/bin/bash
export LC_ALL=C.UTF-8
# This script will copy configuration and service files to form a master measurement system
# and installs necessary tools

apt-get install hostapd dnsmasq ntpd gpsd

# copy AP relateded configurations
cp service_files/hosts /etc/hosts
cp service_files/dnsmasq.conf /etc/dnsmasq.conf
cp service_files/hostapd /etc/defaults/hostapd
cp service_files/hostapd.conf /etc/hostapd.conf
cp service_files/gpsd /etc/defaults/gpsd
cp service_files/ntp.conf /etc/ntp.conf

systemctl enable dnsmasq
systemctl enable hostapd
systemctl enable gpsd
systemctl enable ntp
