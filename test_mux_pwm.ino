//Mux PWM test

void setup() {
  // put your setup code here, to run once:
pinMode(13, OUTPUT);      // sets the digital pin as output
pinMode(9, OUTPUT);      // sets the digital pin as output
}

void loop() {
for(int i = 0;i<500;i++){
  digitalWrite(13,HIGH);// A=1 C1 edit
  analogWrite(9,255);  // C1=HIGH
 delay(1);
  digitalWrite(13,LOW); // A=0  C2 edit
  analogWrite(9,255);  //C2 HIGH
  delay(1);
}

for(int i = 0;i<500;i++){
  digitalWrite(13,HIGH);// A=1 C1 edit
  analogWrite(9,0);  // C1=HIGH
 delay(1);
  digitalWrite(13,LOW); // A=0  C2 edit
  analogWrite(9,0);  //C2 HIGH
  delay(1);
}
 

}
