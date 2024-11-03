// C++ code
// UltraSonicSensorBasedAutonomousCar 

const int enA = 3;
const int in1 = 2;	//left side motors
const int in2 = 4;

const int enB = 11;
const int in3 = 12;	//right side motors
const int in4 = 13;

const int trigPin = 7;	//US sensor
const int echoPin = 8;

long duration;
int distance;

void setup()
{
  pinMode(enA, OUTPUT);
  pinMode(in1, OUTPUT);	//left side motor
  pinMode(in2, OUTPUT);
  
  pinMode(enB, OUTPUT);
  pinMode(in3, OUTPUT); //right side motor
  pinMode(in4, OUTPUT);
  
  analogWrite(enA, 255);
  digitalWrite(in1, HIGH);	//left side motor
  digitalWrite(in2, LOW);
  
  analogWrite(enB, 255);
  digitalWrite(in3, HIGH);	//right side motor
  digitalWrite(in4, LOW);
  
  pinMode(trigPin, OUTPUT);	//US sensor
  pinMode(echoPin, INPUT);
  Serial.begin(9600);
}

void loop()
{
  //analogWrite(enA, 255);
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
  
  //analogWrite(enB, 255);
  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);
  
  //Ultra Sonic Sensor
  digitalWrite(trigPin, LOW);
  delayMicroseconds(5);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  
  duration = pulseIn(echoPin, HIGH);
  distance = duration * 0.034 / 2;
  
  Serial.print("Distance: ");
  Serial.println(distance);
  
  if(distance>=300)
  {
  	setSpeed(100);
  }
  else if(distance>=200 && distance<=300)
  {
    setSpeed(80);
  }
  else if(distance>=100 && distance<=200)
  {
    setSpeed(60);
  }
  else if(distance>=50 && distance<=100)
  {
    setSpeed(40);
  }
  else if(distance<50)
  {
    setSpeed(20);
  } 
  
}

void setSpeed(int value)
{
  value = 2.55 * value;
  analogWrite(enA, value);
  analogWrite(enB, value);
  Serial.print("Value: ");
  Serial.println(value);
}