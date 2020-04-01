#define ledGreen 4
#define ledRed 3
#define input1 8
#define input2 9
#define input3 10
#define trig1 50
#define echo1 51
#define A     22
#define A_bar 24
#define B     26
#define B_bar 28
#define x     6000
#define stepsPerRevolution 200
#define facerec 11

int state1,state2,state3,face=LOW;
long duration, distance, liftSensor,doorSensor;
char income;

void setup() {
 Serial.begin(9600);
 pinMode(input1,INPUT);
 pinMode(input2,INPUT);
 pinMode(input3,INPUT);
 pinMode(ledGreen,OUTPUT);
 pinMode(ledRed,OUTPUT);
 pinMode(trig1, OUTPUT);
 pinMode(echo1, INPUT);
 pinMode(facerec,INPUT);
 pinMode(A, OUTPUT);
 pinMode(A_bar, OUTPUT);
 pinMode(B, OUTPUT);
 pinMode(B_bar, OUTPUT);

}

void loop() {
  state1 = digitalRead(input1);
  state2 = digitalRead(input2);
  state3 = digitalRead(input3);
  face = digitalRead(facerec);
  Sensor(trig1, echo1);
  liftSensor = distance;
  
  Serial.println(liftSensor);
 



  //Go Level 1
  if(state1 == HIGH && state2 ==LOW &&state3 ==LOW &&face == HIGH)
  {
    Serial.println("LEVEL 1");
    if(liftSensor==22||liftSensor==23 || liftSensor > 23){
      Serial.println("At level 1");
      digitalWrite(ledGreen,HIGH);
      digitalWrite(ledRed,LOW);
    }
    else if(liftSensor < 22&&liftSensor>3){
      Serial.println("At Level 2");
      digitalWrite(ledGreen,LOW);
      digitalWrite(ledRed,HIGH);
      liftDown();
  }
        
    else if(liftSensor <= 3 && liftSensor >=1){
      Serial.println("At Level 3");
      digitalWrite(ledGreen,LOW);
      digitalWrite(ledRed,HIGH);
      liftDown();
  }
     
    else{
      Serial.println("Sensor Not Connected");
  }
    }

  //Go Level 2
  else if(state2 ==HIGH && state1==LOW && state3 == LOW&&face == HIGH)
  { 
    Serial.println("LEVEL 2");
    if(liftSensor<=25&&liftSensor>14){
      Serial.println("At level 1");
      digitalWrite(ledRed,HIGH);
      digitalWrite(ledGreen,LOW);
      liftUp();
      }
    else if(liftSensor >= 14&&liftSensor<=24){
      Serial.println("At Level 2");
       digitalWrite(ledRed,LOW);
       digitalWrite(ledGreen,HIGH);
       
       }
    else if(liftSensor <= 12 && liftSensor >=1){
      Serial.println("At Level 3");
      digitalWrite(ledRed,HIGH);
      digitalWrite(ledGreen,LOW);
      liftDown();
      }
    else
      Serial.println("Sensor Not Connected");
  }


  //go level 3
  else if(state3==HIGH && state1 ==LOW &&state2 == LOW&&face == HIGH)
  {
    Serial.println("LEVEL 3");

    if(liftSensor<=25&&liftSensor>13){
      Serial.println("At level 1");
      digitalWrite(ledRed,HIGH);
      digitalWrite(ledGreen,LOW);
      liftUp();
      }
    else if(liftSensor <= 13&&liftSensor>4){
      Serial.println("At Level 2");
      digitalWrite(ledRed,HIGH);
      digitalWrite(ledGreen,LOW);
      liftUp();
      
      } 
    else if(liftSensor == 4||liftSensor == 3 || liftSensor ==2 || liftSensor == 1){
      Serial.println("At Level 3");
       digitalWrite(ledRed,LOW);
       digitalWrite(ledGreen,HIGH);
      }
    else
      Serial.println("Sensor Not Connected");
    
  }
  else{
    Serial.println("No INPUT"); 
    digitalWrite(ledRed,LOW);
    digitalWrite(ledGreen,LOW);
  }

}


void Sensor(int trigPin,int echoPin)
{
digitalWrite(trigPin, LOW);
delayMicroseconds(2);
digitalWrite(trigPin, HIGH);
delayMicroseconds(10);
digitalWrite(trigPin, LOW);
duration = pulseIn(echoPin, HIGH);
distance = (duration/2) / 29.1;
 
}

void liftDown(){
      for (int i = 0; i < (stepsPerRevolution/4); i++) {
      digitalWrite(A, LOW);
      digitalWrite(A_bar, LOW);
      digitalWrite(B, LOW);
      digitalWrite(B_bar, HIGH);
      delayMicroseconds (x);
  
      digitalWrite(A, LOW);
      digitalWrite(A_bar, HIGH);
      digitalWrite(B, LOW);
      digitalWrite(B_bar, LOW);
      delayMicroseconds (x);
  
      digitalWrite(A, LOW);
      digitalWrite(A_bar, LOW);
      digitalWrite(B, HIGH);
      digitalWrite(B_bar, LOW);
      delayMicroseconds (x);
  
      digitalWrite(A, HIGH);
      digitalWrite(A_bar, LOW);
      digitalWrite(B, LOW);
      digitalWrite(B_bar, LOW);
      delayMicroseconds (x);

}
}

void liftUp(){
   for (int i = 0; i < (stepsPerRevolution/4) ; i++) {
    digitalWrite(A, HIGH);
    digitalWrite(A_bar, LOW);
    digitalWrite(B, HIGH);
    digitalWrite(B_bar, LOW);
    delayMicroseconds (x);

    digitalWrite(A, LOW);
    digitalWrite(A_bar, HIGH);
    digitalWrite(B, HIGH);
    digitalWrite(B_bar, LOW);
    delayMicroseconds (x);

    digitalWrite(A, LOW);
    digitalWrite(A_bar, HIGH);
    digitalWrite(B, LOW);
    digitalWrite(B_bar, HIGH);
    delayMicroseconds (x);

    digitalWrite(A, HIGH);
    digitalWrite(A_bar, LOW);
    digitalWrite(B, LOW);
    digitalWrite(B_bar, HIGH);
    delayMicroseconds (x);
  }
}
