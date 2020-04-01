#define BaudRate 9600
int LEDPin = 8;
char income;


void setup() {
 pinMode(LEDPin,OUTPUT);
 Serial.begin(BaudRate);
}

void loop() {
 income = Serial.read();
 if(income == 'A'){
 digitalWrite(LEDPin,HIGH);
 }

 

}
