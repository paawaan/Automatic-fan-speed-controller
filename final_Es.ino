#include <DFRobot_DHT11.h> //library file for DHT11 temperature sensor
DFRobot_DHT11 DHT;

//Initialiasing each component with a pin
#define DHT11_PIN 10 //Data Pin

int enA = 9;//pin to control motor speed
int in1 = 8; //direction of motor rotation

void setup(){
  Serial.begin(9600);
  pinMode(enA, OUTPUT);
  pinMode(in1, OUTPUT);
  digitalWrite(in1, LOW);//turning of motor
}

//controlling motor speed
void speedControl(int speed) {
  // Turn on motor
  digitalWrite(in1,HIGH);
  // Specifying motor speed
  analogWrite(enA,speed);
}

void loop(){
  DHT.read(DHT11_PIN); //reads temperature and humidity
  //Serial.print("temp:");
  Serial.print(DHT.temperature);
  Serial.print(" ");
  //Serial.print("humi:");
  Serial.print(DHT.humidity);
  Serial.print(" ");
  //controlling speed of fan speed
  if(DHT.temperature>=40){
    speedControl(255);//set motor speed to 255
    Serial.print("225");
  }
  else if(DHT.temperature>=35){
    speedControl(180);//set motor speed to 35
    Serial.print("180");
  }
  else if(DHT.temperature>=30){
    speedControl(125);//set motor speed to 30
    Serial.print("125");
  }
  else if(DHT.temperature>=22){
    speedControl(50);//set motor speed to 22
    Serial.print("20");
  }
  else{
    speedControl(0);//set motor speed to 0(OFF)
    Serial.print("0");
  }
  delay(1000);
}
