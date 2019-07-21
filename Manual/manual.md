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
