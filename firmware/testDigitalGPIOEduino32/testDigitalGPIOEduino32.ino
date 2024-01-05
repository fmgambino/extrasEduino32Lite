// inputs
const int in5 = 35; // IN5
const int in4 = 25; // IN4
const int in3 = 26; // IN3
const int in2 = 27; // IN2
const int in1 = 14; // IN1
const int in0 = 12; // IN0

// outputs
const int oq3 = 15; // Q3
const int oq2 = 2;  // Q2
const int oq1 = 23; // Q1 
const int oq0 = 33; // Q0
const int ot = 13; // TRIAC
const int ory = 32; // RELAY 

void setup() {

  Serial.begin(9600);
  pinMode(in5, INPUT);
  pinMode(in4, INPUT);
  pinMode(in3, INPUT);
  pinMode(in2, INPUT);
  pinMode(in1, INPUT);
  pinMode(in0, INPUT);

  pinMode(oq3, OUTPUT);
  pinMode(oq2, OUTPUT);
  pinMode(oq1, OUTPUT);
  pinMode(oq0, OUTPUT);
  pinMode(ot, OUTPUT);
  pinMode(ory, OUTPUT);

}

void loop() {

 // simple test inputs and outputs
  if (digitalRead(in5))
  {digitalWrite(oq3, 1);
  Serial.println("BT5 Activa: Q3");
  }else digitalWrite(oq3, 0);
  

  if (digitalRead(in4))
  {digitalWrite(oq2, 1);
  Serial.println("BT4 Activa: Q2");
  }else digitalWrite(oq2, 0);
  

  if (digitalRead(in3))
  {digitalWrite(oq1, 1);
  Serial.println("BT3 Activa: Q1");
  }else digitalWrite(oq1, 0);
 
  if (digitalRead(in2))
  {digitalWrite(oq0, 1);
  Serial.println("BT2 Activa: Q0");
  }else digitalWrite(oq0, 0);
 

  if (digitalRead(in1))
  {digitalWrite(ot, 1);
  Serial.println("BT1 Activa: TRIAC");
  }else digitalWrite(ot, 0);

  if (digitalRead(in0))
  {digitalWrite(ory, 1);
  Serial.println("BT0 Activa: RELAY");
  }else digitalWrite(ory, 0);

}