int led1 = 8;                       //This are the pins via which switch is connected to Arduino
int led2 = 9;
int led3 = 10;
int led4 = 11;
int sound = 12;                     //buzzer is connected to arduino pin 12


void setup() {                     //This runs only once when Arduino powered up

  Serial.begin(9600);             //this is default baud rate for bluetooth module Hm 10

  pinMode(led1, OUTPUT);          //Pins worked as output
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);
  pinMode(led4, OUTPUT);
  pinMode(sound, OUTPUT);



  digitalWrite(led1, HIGH);       //By default all the switches are off
  digitalWrite(led2, HIGH);
  digitalWrite(led3, HIGH);
  digitalWrite(led4, HIGH);



}

void loop() {                              //This is a loop that runs repeatedly
  if (Serial.available() > 0)             //If there is an input from the app
  {
    int received = Serial.read();       //input stored in received variable

    switch (received) {

      case 'c':                           //if connection is successfully established then it will make an sound of 3 beep
        tone(sound, 2637, 250);
        delay(500);
        tone(sound, 2637, 250);
        delay(500);
        tone(sound, 2637, 250);
        break;


      case '1':                          //if it receives 1 then switch 1 is on
        digitalWrite(led1, LOW);
        tone(sound, 2349, 300);         //it makes an tone of 1 beep as a feedback
        break;

      case '2':                          //if it receives 1 then switch 2 is off and so on
        digitalWrite(led1, HIGH);
        tone(sound, 2349, 300);
        break;

      case '3':
        digitalWrite(led2, LOW);
        tone(sound, 2349, 300);
        break;

      case '4':
        digitalWrite(led2, HIGH);
        tone(sound, 2349, 300);
        break;

      case '5':
        digitalWrite(led3, LOW);
        tone(sound, 2349, 300);
        break;

      case '6':
        digitalWrite(led3, HIGH);
        tone(sound, 2349, 300);
        break;

      case '7':
        digitalWrite(led4, LOW);
        tone(sound, 2349, 300);
        break;

      case '8':
        digitalWrite(led4, HIGH);
        tone(sound, 2349, 300);
        break;

      case 'u':                       //if user swipe up on the screen then all the switches will be on
        digitalWrite(led1, LOW);
        delay(100);
        digitalWrite(led2, LOW);
        delay(100);
        digitalWrite(led3, LOW);
        delay(100);
        digitalWrite(led4, LOW);
        tone(sound, 2349, 300);

        break;

      case 'd':                       //if user swipe down on the screen then all the switches will be off
        digitalWrite(led1, HIGH);
        delay(100);
        digitalWrite(led2, HIGH);
        delay(100);
        digitalWrite(led3, HIGH);
        delay(100);
        digitalWrite(led4, HIGH);
        tone(sound, 2349, 300);

        break;


    }

  }



}
