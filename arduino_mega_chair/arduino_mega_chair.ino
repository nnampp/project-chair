#include <SoftwareSerial.h>

SoftwareSerial ArduinoSerial(13, 12); // RX, TX
void setup() {
  pinMode(A0,INPUT);
  pinMode(A5,INPUT);
  pinMode(A7,INPUT);
  pinMode(A8,INPUT);
Serial.begin(9600);
ArduinoSerial.begin(4800);
}
 void loop() {
           while (ArduinoSerial.available() > 0) {
           float val = ArduinoSerial.parseFloat();
             if (ArduinoSerial.read() == '\n') {
                   if (val == 0xA0) {
                    //ArduinoSerial.print("111,222,333,444");
                       int A0 = analogRead(A0);
                       if(A0>=100&&A0<1000)
                       {
                          ArduinoSerial.print("0");
                          ArduinoSerial.print(A0);
                       }
                       else if(A0>=10&&A0<100)
                       {
                          ArduinoSerial.print("00");
                          ArduinoSerial.print(A0);
                       }
                       else if(A0<10)
                       {
                          ArduinoSerial.print("000");
                          ArduinoSerial.print(A0);
                       }
                       else ArduinoSerial.print(A0);
                       ArduinoSerial.print(",");

                       int A2 = analogRead(A5);
                       if(A2>=100&&A2<1000)
                       {
                          ArduinoSerial.print("0");
                          ArduinoSerial.print(A2);
                       }
                       else if(A2>=10&&A2<100)
                       {
                          ArduinoSerial.print("00");
                          ArduinoSerial.print(A2);
                       }
                       else if(A2<10)
                       {
                          ArduinoSerial.print("000");
                          ArduinoSerial.print(A2);
                       }
                       else ArduinoSerial.print(A2);
                       ArduinoSerial.print(",");
                       
                       int A3 = analogRead(A7);
                       if(A3>=100&&A3<1000)
                       {
                          ArduinoSerial.print("0");
                          ArduinoSerial.print(A3);
                       }
                       else if(A3>=10&&A3<100)
                       {
                          ArduinoSerial.print("00");
                          ArduinoSerial.print(A3);
                       }
                       else if(A3<10)
                       {
                          ArduinoSerial.print("000");
                          ArduinoSerial.print(A3);
                       }
                       else ArduinoSerial.print(A3);
                       ArduinoSerial.print(",");

                       int A4 = analogRead(A8);
                       if(A4>=100&&A4<1000)
                       {
                          ArduinoSerial.print("0");
                          ArduinoSerial.print(A4);
                       }
                       else if(A4>=10&&A4<100)
                       {
                          ArduinoSerial.print("00");
                          ArduinoSerial.print(A4);
                       }
                       else if(A4<10)
                       {
                          ArduinoSerial.print("000");
                          ArduinoSerial.print(A4);
                       }
                       else ArduinoSerial.print(A4);
                      
                       ArduinoSerial.print("\n");
                   }
             }
       }
delay(2000);
}
