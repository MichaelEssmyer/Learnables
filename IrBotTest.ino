//Declarations
int lightPin = 13; //LightTest pin
const int ProxSensor = A0; //IR pin value Sensor
int RightMotor = 9;
int LeftMotor = 10;
int irVal;
int irAvg;
//Storage Variables
int inputVal = 0; //iniates IR value Storage

void setup() 
{              
  pinMode(lightPin, OUTPUT);   // Pin 13 has an LED connected on most Arduino boards:  

  pinMode(ProxSensor,INPUT);    //Pin 2 is connected to the output of proximity sensor

  pinMode(RightMotor, OUTPUT); //Motor Voltage
  pinMode(LeftMotor, OUTPUT);
  
  Serial.begin(9600); //Start Board
}



void loop() 
{//Light Test
//  digitalWrite(lightPin, HIGH);
//  delay(2000);
//  digitalWrite(lightPin, LOW);
//  delay(2000);

  //IR read test
  if(digitalRead(ProxSensor)==HIGH)      //Check the sensor output
  {
    digitalWrite(13, HIGH);   // set the LED on
  }
  else
  {
    digitalWrite(13, LOW);    // set the LED off
  }

  //Read IR
  for(int i = 0 ; i <30 ; i++){
    irVal += analogRead(ProxSensor);
    //Serial.println(inputVal); // range of 0-1023
    delay(10);              // wait for a second
  }
  //Avg IR value aka smooth
  irAvg = irVal/30;
  Serial.println(irAvg); 
  irVal = 0;

  //Interact IR to Motors
  if(irAvg < 500)
  {
      digitalWrite(RightMotor, HIGH);
      digitalWrite(LeftMotor, HIGH);
    }
  else
  {
      digitalWrite(RightMotor, LOW);
       digitalWrite(LeftMotor, LOW);
    }
}
