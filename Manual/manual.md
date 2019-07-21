# Hardware setup
## Master setup
We decided to distinguish between a master PI and Slave Pis. It is absolutely possible to combine them in software and hardware.   
The weather station has an anemometer which closes contacts every circulation of the rotor.  Therefore an interrupt on the controller side is needed. 
The wind vane of the station has a resistor network explained here https://www.sparkfun.com/datasheets/Sensors/Weather/Weather%20Sensor%20Assembly..pdf which therefore can be used in a voltage divider to evaluate the wind direction.
As the values of the resistors are precisely defined each wind direction gets a certain resistor value and therefore in the voltage divider a specific voltage.
To convert this voltage to a value for the data analysis a kind of analog digital converter is needed. As the PI does not have one an external one needs to be defined. We decided for an arduino for various reasons:
* it is widely used
* it is easy to program
* it is available and cheap
A discrete ADC would be possible as the values are predefined, but as there are 16 different directions possible this would be to complex to build up.
The vane and the anemometer are connected together in one wire. Therefore and to keep the setup clean and structured, both are used by the Arduino. 
To connect it to the PI we use the SPI bus. This results in the following schematic:  
![schematic](schematic.PNG)  
The weather station brings a Plug but we cut the wire and soldered it directly as no such plug was available. If one wants to test this circuitry one can do this with the following breadboard setup.
We use the same coloring in the diagram as in the real wires.  
![breadboard](breadboard.PNG)  
To make it feasable for measuring one should solder it, so the connections do not get lost. We suppose the following:  
![perfboard](perfboard.PNG)  
Which then results in the real assembly with the same coloring:  
![assambly](assambly.jpg)  
We stayed with jumper wires between the Pi and the Arduino as the master PI may change and it is better for transport. With this Hardware the system is ready to be used in the field.
For transportation we highly recommend to transport the anemometer in its box as it is very fragile. the rest of the system is relatively robust.
After soldering the bread board connect the jumpers from Arduino to the master PI, as shown in the picture. The connections are 5V(orange), GND(blue), SCL(green) and SDA(yellow).

## Slave setup
the connection of a slave to a PM sensor is very simple. Just connect to wire from the PM sensor directly to the PI. Pay attention that the empty pin of the plug is above a pin of the Pi.
![connectPM](connectPM.jpg)    
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

