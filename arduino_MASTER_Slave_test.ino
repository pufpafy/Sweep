//Master
#include <Wire.h>

void setup() {
  Wire.begin(0);        // join i2c bus  (address optional for master)   address=0
  Serial.begin(9600);  // start serial for output
}

void loop() {

  Wire.requestFrom(1, 1);    // request 12 bytes from slave device #1

  while (Wire.available()) { // slave may send less than requested
    int a = Wire.read(); // receive a byte as int
    Serial.print(a);         // print the numbers
   Serial.print(' ');
}
Serial.print('\n');
delay(1);

  if (Serial.available() > 0)
  {              
    char inBuffer[4] = {0};
    Serial.readBytes(inBuffer, 3);
    byte consoleInputNumber = atoi(inBuffer);

    Wire.beginTransmission(1); // transmit to device #1
    Wire.write(consoleInputNumber);
    Wire.endTransmission();    // stop transmitting    
  }


//Slave
#include <Wire.h>


int S0=0;
int S1=0;
int S2=0;
int S3=0;


void setup() {

  pinMode(13, OUTPUT);    // s0
  /*
  pinMode(12, OUTPUT);    // s1
  pinMode(11, OUTPUT);    // s2
  pinMode(10, OUTPUT);    // S3

  pinMode(0, OUTPUT);    //Valve 1
  */
   
  Wire.begin(1);                // join i2c bus with address #1
  Wire.onRequest(requestEvent);
  Wire.onReceive(receiveEvent);

}

void loop() {
}


void requestEvent() {
 byte values;
/*
for(int i=0;i<13;i++){  

  //http://playground.arduino.cc/Learning/4051
  //MUX counter
 S0=bitRead(i,0);
 S1=bitRead(i,1);
 S2=bitRead(i,2);
 S3=bitRead(i,3);
   
digitalWrite(13,S0);
digitalWrite(12,S1);
digitalWrite(11,S2);
digitalWrite(10,S2);

values[i]=analogRead(A9);
delay(1);

}*/
values = analogRead(A9);
 Wire.write(values);
}

 
// function that executes whenever data is received from master

void receiveEvent(int howMany) {
  
  while (Wire.available())
  {
    char c = Wire.read(); // receive byte as a character
    if (c==1) digitalWrite(13, HIGH);
    if (c==2) digitalWrite(13, LOW);
  }
}
