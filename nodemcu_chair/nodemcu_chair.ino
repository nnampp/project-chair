#include <ESP8266WiFi.h>
#include <SoftwareSerial.h>
#include <String>
const char* ssid = "N_N";
const char* password = "25012545Nun";
const char* host = "172.20.10.9";        
SoftwareSerial NodeSerial(D2, D3); // RX | TX
String str = "";
char str2[31];
int left1;
int left2;
int left3;
int left4;
void setup() {
  Serial.begin(9600);
  delay(10);
  Serial.println();
  Serial.println();
  Serial.print("Connecting to ");
  Serial.println(ssid);
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("");
  Serial.println("WiFi connected");
  Serial.println("IP address: ");
  Serial.println(WiFi.localIP());
  NodeSerial.begin(4800);
}
int value = 0;
void loop() { 
NodeSerial.print(0xA0);
NodeSerial.print("\n");

while (NodeSerial.available() > 0) {
  char ch = (char)NodeSerial.read();
  str += ch;
  if(ch == '\n'){
  str.toCharArray(str2,31);
  //Serial.println(str2);
  char *p = strtok(str2,",");
  left1 = atoi(p);
  p=strtok(NULL,",");
  left2 = atoi(p);
  p=strtok(NULL,",");
  left3 = atoi(p);
  p=strtok(NULL,",");
  left4 = atoi(p);
  str = "";
  }
}   
  delay(1000);
  ++value;
  Serial.print("connecting to ");
  Serial.println(host);
  WiFiClient client;
  
  const int httpPort = 80;
  if (!client.connect(host, httpPort)) {
    Serial.println("connection failed");
    return;
  }
  String url = "/Project_Chair/add.php?left1="; //ชุด Directory ที่เก็บไฟล์ และตัวแปรที่ต้องการจะฝาก
  url += left1; //ส่งค่าตัวแปร
  url += "&left2=";
  url += left2;
  url += "&left3=";
  url += left3;
  url += "&left4=";
  url += left4;
  //Serial.print("\nAnalog reading = ");
  //Serial.println(fsrReading);     // the raw analog reading
  Serial.print("Requesting URL: ");
  Serial.println(url);
  client.print(String("GET ") + url + " HTTP/1.1\r\n" +
               "Host: " + host + "\r\n" +
               "Connection: close\r\n\r\n");
  /*unsigned long timeout = millis();
  while (client.available() == 0) {
    if (millis() - timeout > 5000) {
      Serial.println(">>> Client Timeout !");
      client.stop();
      return;
    }
  }*/
  // Read all the lines of the reply from server and print them to Serial
  /*while (client.available()) {
    String line = client.readStringUntil('\r');
    Serial.print(line);
  } 
  Serial.println();
  Serial.println("closing connection");
}      */
  delay(100);
}
