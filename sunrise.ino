#include <DS3231.h>

int fadeTime = 10;
int setHour = 11; 
int setMin = 06;
int uled = 9;

int maxBrightness = 255;


DS3231 rtc(SDA, SCL);
Time t;

void setup() {
  pinMode(uled, OUTPUT);
  Serial.begin(9600);
  rtc.begin();
  t = rtc.getTime();

}

void loop() {

Serial.print(" -- ");


// send time
//Serial.println();

// check if its time to start getting bright
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
//  Serial.print("SET: ");
//  Serial.print(setHour);
//  Serial.print(":");
//  Serial.print(setMin);
//  Serial.print(" NOW:");
//  Serial.println(rtc.getTimeStr());

if (t.hour == setHour) {
  active();
  }

  

// wait one second before repeating
delay(1000);

}

void active() {
  Serial.println(" led turned on");
//
//  analogWrite(uled, maxBrightness);
//  delay(1000);
//  analogWrite(uled,  0);
//  delay(1000);

  
//  analogWrite(uled, 1);
//  delay((fadeTime * 60000)/50);

//  analogWrite(uled, 2);
//  delay((fadeTime * 60000)/50);

//  analogWrite(uled, 3);
//  delay((fadeTime * 60000)/50);

//  analogWrite(uled, 4);
//  delay((fadeTime * 60000)/50);

//  analogWrite(uled, 5);
//  delay((fadeTime * 60000)/50);

  // fade begin

//  for (int i = 6; i <= 255; i++) {
//    analogWrite(uled, i);
//    delay(((fadeTime * 60000)/306));
//    Serial.print(" mil sec ");
//    Serial.print(((fadeTime * 60000)/306));
//    Serial.print(" PWM ");
//    Serial.print(i);
//    }

    // set bright for 1/5 of the set time
//    delay((fadeTime * 60000)/5); 
    // set back to OFF
//    analogWrite(uled, 0);
  
  }



  