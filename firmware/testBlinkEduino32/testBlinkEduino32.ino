/*
  Blink

  Turns an LED on for one second, then off for one second, repeatedly.

  Most Arduinos have an on-board LED you can control. On the UNO, MEGA and ZERO
  it is attached to digital pin 13, on MKR1000 on pin 6. LED_BUILTIN is set to
  the correct LED pin independent of which board is used.
  If you want to know what pin the on-board LED is connected to on your Arduino
  model, check the Technical Specs of your board at:
  https://www.arduino.cc/en/Main/Products

  modified 8 May 2014
  by Scott Fitzgerald
  modified 2 Sep 2016
  by Arturo Guadalupi
  modified 8 Sep 2016
  by Colby Newman

  This example code is in the public domain.

  https://www.arduino.cc/en/Tutorial/BuiltInExamples/Blink
*/
int led01 = 2;
int led02 = 13;
int led03 = 15;
int led04 = 23;
int led05 = 34;
int led06 = 35;
// the setup function runs once when you press reset or power the board
void setup() {
  // initialize digital pin LED_BUILTIN as an output.
  pinMode(led01, OUTPUT);
  pinMode(led02, OUTPUT);
  pinMode(led03, OUTPUT);
  pinMode(led04, OUTPUT);
  pinMode(led05, OUTPUT);
  pinMode(led06, OUTPUT);
}

// the loop function runs over and over again forever
void loop() {
  digitalWrite(led01, HIGH);  // turn the LED on (HIGH is the voltage level)
  delay(300);                      // wait for a second
  digitalWrite(led01, LOW);   // turn the LED off by making the voltage LOW
  delay(300);                      // wait for a second

  digitalWrite(led02, HIGH);  // turn the LED on (HIGH is the voltage level)
  delay(300);                      // wait for a second
  digitalWrite(led02, LOW);   // turn the LED off by making the voltage LOW
  delay(300);                      // wait for a second


  digitalWrite(led03, HIGH);  // turn the LED on (HIGH is the voltage level)
  delay(300);                      // wait for a second
  digitalWrite(led03, LOW);   // turn the LED off by making the voltage LOW
  delay(300);                      // wait for a second

  digitalWrite(led04, HIGH);  // turn the LED on (HIGH is the voltage level)
  delay(300);                      // wait for a second
  digitalWrite(led04, LOW);   // turn the LED off by making the voltage LOW
  delay(300);   
  
  digitalWrite(led05, HIGH);  // turn the LED on (HIGH is the voltage level)
  delay(300);                      // wait for a second
  digitalWrite(led05, LOW);   // turn the LED off by making the voltage LOW
  delay(300);   

  digitalWrite(led06, HIGH);  // turn the LED on (HIGH is the voltage level)
  delay(300);                      // wait for a second
  digitalWrite(led06, LOW);   // turn the LED off by making the voltage LOW
  delay(300);   
}
