#define LEDpin D4   //set led pin
const  String myName = "Elon";

// the setup function runs once when you press reset or power the board
void setup() {
  // initialize digital pin LED_BUILTIN as an output.
  pinMode(LEDpin, OUTPUT);
  Serial.begin(9600);
}
// the loop function runs over and over again forever
void loop() {

  Serial.println(Name + " the Light is On");
  digitalWrite(LEDpin, HIGH);   //turn the LED on (HIGH is the voltage level)
  delay(50);                       // wait for a second
  Serial.println("Light Off");
  digitalWrite(LEDpin, LOW);    // turn the LED off by making the voltage LOW
  delay(50);                       // wait for a second
} 