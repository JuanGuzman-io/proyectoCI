#include <ESP8266HTTPClient.h>
#include <ESP8266WiFi.h>

const char* ssid = "iPhone de Juan";
const char* password = "adrianshow1927";

const int SOUNDPin = 0;  //D3

const int Trigger = 4;   //D2 del NodeMCU para Trigger del sensor
const int Echo = 2;   //D4 del NodeMCU para el Echo del sensorNUMERIC

String direccion = "Calle 32 # 36-75";
String alerta = "Aviso: Nivel excesivo de ruido";

void setup() {
  Serial.begin(115200); //Serial connection
  pinMode(SOUNDPin, INPUT);

  pinMode(Trigger, OUTPUT); //pin como salida
  pinMode(Echo, INPUT);  //pin como entrada
  digitalWrite(Trigger, LOW);//Inicializamos el pin con 0
  setup_wifi(); //WiFi connection
  delay(1500);
}

void setup_wifi() {
  delay(10);
  // We start by connecting to a WiFi network
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
}

void loop() {
  float t; //tiempo que demora en llegar el eco
  float d; 

  digitalWrite(Trigger, HIGH);
  delayMicroseconds(10);          //Enviamos un pulso de 10us
  digitalWrite(Trigger, LOW);

  t = pulseIn(Echo, HIGH); //obtenemos el ancho del pulso
  d = t / 59;         //escalamos el tiempo a una distancia en cm

  String json1 =  "{\"nivelsonoro\":" + String(d) + ",\"idnodo\":" + "\"Calle 32 # 36-75\"" + ",\"alerta\":" + "\"Aviso: Nivel normal de ruido\"" "}";
  String json2 =  "{\"nivelSonoro\":" + String(d) + ",\"idNodo\":" + "\"Calle 32 # 36-75\"" + ",\"alerta\":" + "\"Aviso: Nivel excesivo de ruido\"" "}";

    WiFiClient client;
    
  if (d > 5) {
    HTTPClient http; //Declare object of class HTTPClient
    http.begin(client, "http://172.20.10.4:3001/datos/post"); //Specify request destination
    http.addHeader("Content-Type", "application/json");

    Serial.println(json2);

    int alerta2 = http.POST(json2); //Send the request

    
    String payload = http.getString(); //Get the response payload
    Serial.println(payload); //Print request response payload
    http.end();
  } else {
    Serial.println(json1);
  }

  delay(5000); //Send a request every 30 seconds
}
