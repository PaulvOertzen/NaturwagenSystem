# ComWrapper
 Communication between Esp32 and Raspberry Pi
-  The communication is caried by MQTT as binary packages designed as layed out here
## System structure
- each esp32 is connected to a network hosted by the Raypberry Pi
- The Raspberry Pi hosts a MQTT server
- each esp32 is connected to its own channel in MQTT
- To send data each esp32 broadcasts a package to the Raspberry Pi
- The Pi analyses the package and Sends the contents to each esp32 which is supscribed to the specific variable
* * *
## Package Structure
The Package contains 
- identefier refferenced as "ID", specific to the respective esp32 (16bit)
- package type refferenced as "type"  (4bit)
- package destination reffrenced as "dest" (16bit)
- data type refferenced as "dt" (8bit)
- data length refferenced as "dl" (16)
- checksum refferenced as "cs" (4bit)
- value refferenced as value
## Header
- the header contains all data encoded in 64 bits (8bytes)
- contains ID, type, dest, dt, dl, cs
## Package parts
### ID
- is for ease of life and logging
- is some 8 bit number specific to each deviceooooo
### type
- is used to secify what the package acctually means
- is some 4 bit number
#### type: 0
- reading a value
#### type: 1
- supscribing to value
- when a esp is supscribes to a value by this command, it gets an update eyery time the value is changed
#### type: 2
  - unsubscribing a value
  - unsubscribes the esp from a variable
#### type: 3
  - write a value
### dest
  - defines the destination variable
  - on the pi this translates to a value in the database
  - on an esp this translates to what value is ment
 ### dt
 - defines the type of data
#### dt: 0
- defines an integer
####  dt: 1
- defines a float
#### dt: 2
- defines a string or a char array
### dl
- defines the data length in bytes
- eg. 64 bit data woul mean that dl is 8
### cs
- is a schecksum where a hash (pearson hash xored) is stored in 4 bits
- the input to the hash function is the headerwith cs set to 0 0 0 0 and all data in order
- the 8bits from the pearson hash are split in 2 4 bit arrays and those are XOr'ed to get 4 distinctive bits
## Value
- value is of unspecified length and unspecified type
- length and type are set in header
- all data is in binary
* * *
10/12/2024 12:27
