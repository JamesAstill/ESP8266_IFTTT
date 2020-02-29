#include <ESP8266WiFi.h>
#define LED D7 // Led in NodeMCU at D7.
#define PIR D0 // Motion sensor in NodeMCU at pin GPIO16 (D0).
const char* ssid     = "xxxxxx";   // SSID of local network
const char* password = "xxxxxx";   // Password on network

void setup() 
{
  pinMode(LED, OUTPUT); // set the digital pin as output.
  pinMode(PIR, INPUT);
  Serial.begin(9600); // must match setting if debugging in arduino studio
  delay(1000);
  WiFi.hostname("ESP8266MotionSensor"); //This changes the hostname of the ESP8266 to display neatly on the network esp on router.
  WiFi.begin(ssid, password);
}

void ifttt() //Wifi connection and send all the data to IFTTT
{
  const char host[ ]        = "maker.ifttt.com";          // maker channel of IFTTT
  const char trigger[ ]     = "device_name";              //name of the trigger you would like to send to IFTTT
  const char APIKey[ ]      = "xxxxxxxxxxxxx";            //Your maker key for Webhooks on IFTTT
  Serial.print("Connect to: ");
  Serial.println(host);
  // WiFiClient to make HTTP connection
  WiFiClient client;
  if (!client.connect(host, 80)) {
    Serial.println("connection failed");
    return;
    }

// Build URL
  String url = String("/trigger/") + trigger + String("/with/key/") + APIKey;
  Serial.print("Requesting URL: ");
  Serial.println(url);

// Send request to IFTTT
  client.print(String("GET ") + url + " HTTP/1.1\r\n" + "Host: " + host + "\r\n" + "Connection: close\r\n\r\n"); 
  //FYI rn rn is just two new lines to comply with http format

// Read all the lines of the reply from server and print them to Serial
  Serial.println("Respond:");
  while(client.available()){
    String line = client.readStringUntil('\r');
    Serial.print(line);
    }
  Serial.println();
  Serial.println("closing connection");
  Serial.println();
  client.stop(); 
 }
  
void loop() // Main Loop
{
  digitalWrite(LED, LOW);// turn the LED off.
  Serial.println(digitalRead(16));
  if (digitalRead(16) == 1) 
  {
    digitalWrite(LED, HIGH); // turn the LED on.
    ifttt(); //Tell IFTTT that intruder detected
    delay (20000); //This delay here just to stop spamming of notifications - to be improved
  } 
  else 
  {
    //Serial.println("no trigger"); //enable for debugging of no event being triggered
  }
  delay(100); // Check 10 times a second
}


  
