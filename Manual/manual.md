# Hardware setup
##Master setup
schematic: ![schematic](schematic.PNG)

breadboard: ![breadboard](breadboard.PNG)
perfboard: ![perfboard](perfboard.PNG)
assambly: ![assambly](assambly.jpg)
After soldering the bread board connect the jumpers from Arduino to the master PI, as shown in the picture. The connections are 5V(orange), GND(blue), SCL(green) and SDA(yellow).

##Slave setup
the connection of a slave to a PM sensor is very simple. Just connect to wire from the PM sensor directly to the PI. Pay attention that the empty pin of the plug is above a pin of the Pi.
connectPM: ![connectPM](connectPM.jpg)
This connection is valid for all PIs regardless of the kind as they have the same pinout.
# Measurement Setup
In this section we describe how to set up the measuring units for a measurement.

## Master station
* The wind vane is already soldered to the Arduino. Connect the Arduino to the master PI according to the description above, if it is not connected already.
* Connect the GPS Module to a USB-Plug.
* Build up the weather station like described here https://www.sparkfun.com/datasheets/Sensors/Weather/Weather%20Sensor%20Assembly..pdf and plug in the anemometer to the vane. The anemometer is connected through the vane to the PI.

## Slave setup
* Mount all the PM sensors and according PIs with their power banks, where they should be placed for the measurement. You may want to save them from water and secure them from theft. 
* Pay attention to not put them in airtight compartments as this might result in wrong measurement. For accurate values it is important to place the sensors upright.
* Connect all PIs to their power bank. The measurement starts automatically.

## Gathering Data
Connect to the Network 'DCAITI_Feldversuch' with the password 'dcaiti_wlan_passwort'. You can now connect to the master system via sftp://pi@master.dcaiti and find the measurements with a timestamp and its MAC-Adress in the home directory. The files have the form '$MAC_YYYYMMDDHHSS.csv'.

# Software Installation
## Master

### W-Lan AP
Collection of data and synchronization of time will be achieved via W-Lan. Connect to your device via cable and add following lines to `/etc/dhcpcd.conf`:
```
interface wlan0
static ip_address=10.0.0.1/16 # 10.0.0.0 - 10.0.255.255
```
#### hostapd
Restart the dhcp client daemon via `sudo systemctl restart dhcpcd`. Install the necessary software packages for an Access Point:
`sudo apt install dnsmasq hostapd`. Backup the hostapd config file via `cp /etc/hostapd/hostapd.conf /etc/hostapd/hostapd.conf.old` and replace it by the one in this Repo (`service_files/hostapd.conf`). Keep in mind to change the password and make it only readable by root `chmod 600 /etc/hostapd/hostapd.conf`. Edit `/etc/defaults/hostapd` to contain following lines:
```
DAEMON_CONF="/etc/hostapd/hostapd.conf"
```
RUN_DAEMON=yes
Start and enable the service:
```
systemctl unmask hostapd
systemctl restart hostapd
systemctl start hostapd
```


### SSH Server
Generate a rsa key-pair and push the public key via `ssh-copy-id` to your designated master system. The private key will be used by the measurement clients. 
Run the `install_master.sh` script via `ssh pi@IP_OF_MASTER_SYSTEM 'sudo bash -s' < install_master.sh`. 

