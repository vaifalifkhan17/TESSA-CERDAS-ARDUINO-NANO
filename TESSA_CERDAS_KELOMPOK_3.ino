#include <SoftwareSerial.h>
#include <LiquidCrystal_I2C.h> // library LCD
#include <DFPlayer_Mini_Mp3.h> // library DFPlayer
#include <NewPing.h> // library sensor ultrasonic
#include <Servo.h>  // library motor servo

//Pendeteksi ada tidaknya orang (sensor ultrasonik luar)
#define TRIGGER_PIN 5 
#define ECHO_PIN 6 
#define MAX_DISTANCE 100

//Pendeteksi sensor ultrasonik dalam
#define TRIGGER_PIN1 8 
#define ECHO_PIN1 9 
#define MAX_DISTANCE1 22

LiquidCrystal_I2C lcd(0x3F, 16, 2);
Servo myservo;
SoftwareSerial mySerial(10, 11);
NewPing sonar(TRIGGER_PIN, ECHO_PIN, MAX_DISTANCE); // NewPing setup of pins and maximum distance.
NewPing sonar1(TRIGGER_PIN1, ECHO_PIN1, MAX_DISTANCE1); // NewPing setup of pins and maximum distance.

void setup () {
myservo.attach(2);
mySerial.begin (9600);
mp3_set_serial (mySerial);
mp3_set_volume (100);
lcd.begin();
}

void loop () {
delay(50); 
int jarak = sonar.ping_cm(); // Send out the ping, get the results in centimeters.
int kapasitas = sonar1.ping_cm(); // Send out the ping, get the results in centimeters.

if(jarak>0)
{
myservo.write(0); // membuka tutup kotak sampah
mp3_play (1);
delay(5000);
mp3_play (2);
delay(4000);
mp3_play (3);
delay(3000);
}
else
{
  myservo.write(120);  // menutup kotak sampah
}

if((kapasitas>15)&&(kapasitas<21))
{
lcd.setCursor(0,0);
lcd.print("Kapasitas Sampah");
lcd.setCursor(5,1);
lcd.print("25%            ");
}
else if((kapasitas>10)&&(kapasitas<16))
{
lcd.setCursor(0,0);
lcd.print("Kapasitas Sampah");
lcd.setCursor(5,1);
lcd.print("50%  ");
}
else if((kapasitas>5)&&(kapasitas<11))
{
lcd.setCursor(0,0);
lcd.print("Kapasitas Sampah");
lcd.setCursor(5,1);
lcd.print("75%            ");
}
else if((kapasitas>1)&&(kapasitas<=5))
{
lcd.setCursor(0,0);
lcd.print("Kapasitas Sampah");
lcd.setCursor(5,1);
lcd.print("100%(FULL) ");
}
else
{
lcd.setCursor(0,0);
lcd.print("Kapasitas Sampah");
lcd.setCursor(5,1);
lcd.print("25%             ");
}
}
