#include <EEPROM.h>

String theCode = String();
String expression1 = "NIX";
String expression3 = "STATUS";
String expression4 = "FW";
String expression5 = "CHGADDR";
String expression6 = "SETPOS";
String expression7 = "GETPOS";
String expression8 = "SCAN";
String on = "ON";
String off = "OFF";
int position_var = 0;

void setup() {
  Serial.begin(9600);
  pinMode(2,OUTPUT);//A
  pinMode(3,OUTPUT);//B
  pinMode(4,OUTPUT);//C
  pinMode(5,OUTPUT);//D
  pinMode(6,OUTPUT);//HV
}

void loop() {
  int eepromvalue = EEPROM.read(0);
  if (Serial.available() > 0) {
    theCode = Serial.readString();

    if (theCode.substring(0, 3) == expression1) {
      if (theCode.substring(4, 7).toInt() == eepromvalue) {
        if (theCode.substring(8, 14) == expression3) {
          Serial.println(String(eepromvalue) + ",OK");
        }
        else if (theCode.substring(8, 10) == expression4) {
          Serial.println(String(eepromvalue) + ",1.0");
        }
        else if (theCode.substring(8, 15) == expression5) {
          if (eepromvalue != theCode.substring(16, 19).toInt()) {
            EEPROM.write(0, theCode.substring(16, 19).toInt());
            eepromvalue = EEPROM.read(0);
            Serial.println(String(eepromvalue) + ",OK");
          }
          else {
            Serial.println("Choose different address value");
          }
        }
        else if (theCode.substring(8, 14) == expression6) {
          position_var = theCode.substring(15, 17).toInt();
          Serial.println(String(eepromvalue) + ",OK");
          //setting position
          bool D = position_var / 8 ;
          bool C = (position_var/4) % 2;
          bool B = (position_var/2) % 2;
          bool A = position_var % 2;
          digitalWrite(2,A);//A
          digitalWrite(3,B);//B
          digitalWrite(4,C);//C
          digitalWrite(5,D);//D
        }
        else if (theCode.substring(8, 14) == expression7) {
          Serial.println(String(position_var));
        }
        else if (theCode.substring(8,11) == off)  {
          Serial.println(String(eepromvalue)+",OFF");
          digitalWrite(6, 0);//HV
        }
        else if (theCode.substring(8,10) == on) {
          Serial.println(String(eepromvalue)+",ON"); 
          digitalWrite(6, 1);//HV 
        }
      }
      else if (theCode.substring(4, 8) == expression8) {
        Serial.println(String(eepromvalue) + ",OK");
      }
    }
  }
}
