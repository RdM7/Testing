//Uncomment the lines for each method

//SoftwareSerial
//#include <Sodaq_PcInt.h>
//#include <SoftwareSerial.h>
//SoftwareSerial mySerial(5, 4);

//Sodaq_SoftSerial
//#include <Sodaq_PcInt.h>
//#include <Sodaq_SoftSerial.h>
//SoftwareSerial mySerial(5, 4);

//Hardware Serial1
#define mySerial Serial1
#define HARDWARE_SERIAL

void setup()
{
  Serial.begin(57600);
  mySerial.begin(9600);
  //mySerial.println("$PMTK251,38400*27");
  //delay(2000);
  //mySerial.begin(38400);
}

void loop()
{
  while(mySerial.available()) 
    Serial.write(mySerial.read());
  
  #ifndef HARDWARE_SERIAL
    if (mySerial.overflow())
    {
      Serial.println();
      Serial.println("Overflow triggered");
    }
  #endif
  
  while(Serial.available())
    mySerial.write(Serial.read());
}

