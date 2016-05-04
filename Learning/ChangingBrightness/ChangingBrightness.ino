//Light
int ledPin = 11;
//Button
int buttonPin = 12;
int potPin = A5;
int flag = 0;
int brightness = 0;
int value;

void setup() {
  // put your setup code here, to run once:
  
  pinMode(ledPin, OUTPUT);
  pinMode(buttonPin, INPUT);

  Serial.begin(9600);
}

void loop() {
  //Pressed is LOW, Unpressed if HIGH
  //If flag is one, LED should be turned on
  value = analogRead(potPin);
  brightness = map(value, 0, 1024, 0, 255);
  
 if (digitalRead(buttonPin) == LOW){
    flag = !flag;
    delay(500);
 }
  if (flag == 1){
    Serial.println(brightness);
    analogWrite(ledPin, brightness);
  }
  else{
    analogWrite(ledPin, 0);
  }


  
  

}
