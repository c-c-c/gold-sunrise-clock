#include <DS3231.h>

// settings

int fadeTime = 1;
int setHour = 16; 
int setMin = 05;

// pin ~9 PWM

int uled = 9;

// pin 8 

int button = 8;

int buttonState = 0;

int maxBrightness = 255;


DS3231 rtc(SDA, SCL);
Time t;

void setup() {

  // sets our light as the output on pin ~ 9 which is PWM
  
  pinMode(uled, OUTPUT);

  // sets our button

  pinMode(button, INPUT);
  
  // begins serial communication
  
  Serial.begin(9600);
  
  rtc.begin();
  t = rtc.getTime();

}

void loop() {

Serial.print(" -- ");

  // checks if its time to start getting bright 
  // aka when it's time to wake up.
  
  Serial.print("SET: ");
  Serial.print(setHour);
  Serial.print(":");
  Serial.print(setMin);
  Serial.print(" NOW:");
  Serial.print(t.hour);
  Serial.print(":");
  Serial.print(t.min);
  
  Serial.print(" CLOCK:");
  Serial.println(rtc.getTimeStr());
  
//if (t.hour == setHour && t.min == setMin) {

  // reads the state of the pushbutton value;

  buttonState = digitalRead(button);

  if (buttonState == 1) {
    Serial.println("button pressed");

    // button for demo purposes
    
    active();

    // resets the button to 0
    
    buttonState = 0;
  } else if (t.hour == setHour) {
    active();
  } 
 
  // waits one second before repeating 
  
  delay(500);

}

void active() {
  
  Serial.println(" led turned on");

  // fade begin
  
  // the delay functions are to prevent the LED from becoming too bright 
  // in the early stages of the fadetime. 
  
  analogWrite(uled, 1);
  delay((fadeTime * 60000)/50);

  analogWrite(uled, 2);
  delay((fadeTime * 60000)/50);

  analogWrite(uled, 3);
  delay((fadeTime * 60000)/50);

  analogWrite(uled, 4);
  delay((fadeTime * 60000)/50);

  analogWrite(uled, 5);
  delay((fadeTime * 60000)/50);


  // for statement controls the speed 
  // at which the light should get brighter and brighter
  // depending on the fadetime.

  for (int i = 6; i <= 255; i++) {
    analogWrite(uled, i);
    delay(((fadeTime * 60000)/306));
    Serial.print(" mil sec : ");
    Serial.println(((fadeTime * 60000)/306));
    Serial.print(" PWM : ");
    Serial.println(i);
    }
    
    delay((fadeTime * 60000)/5); 
    
    // shuts the light off. 
    analogWrite(uled, 0);
  
  }



  
