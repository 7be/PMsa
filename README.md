# PMsa
Particulate matter small area: a client-master measurement system to gather data via W-LAN
We build a scalable system based on the SDS011 sensor. In addition we take wind data with a weather station.

## Preface
The master system service a wireless network on which the client systems connect to. 
Data gathered will be stored via a ssh connection to 'master.dcaiti'. 
For time synchronization a NTP service runs on this master, which polls its timedata from a gpsd-service. 

