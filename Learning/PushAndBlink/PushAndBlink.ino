//Light
int ledPin = 13;
//Button
int buttonPin = 12;
int flag = 0;

void setup() {
  // put your setup code here, to run once:
  
  pinMode(ledPin, OUTPUT);
  pinMode(buttonPin, INPUT);
}

void loop() {
  //Pressed is LOW, Unpressed if HIGH
  //If flag is one, LED should be turned on
 if (digitalRead(buttonPin) == LOW){
    flag = !flag;
    delay(500);
 }
  if (flag == 1){
    digitalWrite(ledPin, HIGH);
  }
  else{
    digitalWrite(ledPin, LOW);
  }


  
  

}
