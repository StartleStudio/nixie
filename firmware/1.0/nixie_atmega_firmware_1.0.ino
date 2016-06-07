#include <EEPROM.h>

String theCode = String();
String expression1 = "NIX";
String expression3 = "STATUS";
String expression4 = "FW";
String expression5 = "CHGADDR";
String expression6 = "SETPOS";
String expression7 = "GETPOS";
String expression8 = "SCAN";
int position_var = 0;

void setup() {
  Serial.begin(9600);

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
        }
        else if (theCode.substring(8, 14) == expression7) {
          Serial.println(String(position_var));
        }
      }
      else if (theCode.substring(4, 8) == expression8) {
        Serial.println(String(eepromvalue) + ",OK");
      }
    }
  }
}
