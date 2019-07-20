# PMsa
Particulate matter small area: a client-master measurement system to gather data via W-LAN

## Preface
The master system service a wireless network on which the client systems connect to. Data gathered will be stored via a ssh connection to 'master.dcaiti'. For time synchronization a NTP service runs on this master, which polls its timedata from a gpsd-service. 
