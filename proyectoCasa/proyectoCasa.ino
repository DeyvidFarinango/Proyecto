#include <FirebaseESP8266.h>
#include <ESP8266WiFi.h>9
#include <Servo.h>
Servo servoMotor;

// definir wifi
#define WIFI_SSID "Deyvid"
#define WIFI_PASSWORD "12345678"

// definir URL de BASE DE DATOS
#define FIREBASE_HOST "https://casa-domotica-13548-default-rtdb.firebaseio.com/"
#define FIREBASE_AUTH "vxpEUun4M36aUJKbZ9dURL1qEVUUCKwl5qj1Htwn"

//Definir pines

#define led1 16 //D0
#define led2 5 // D1
#define led3 4 // D2
#define led4 0 //D3
#define led5 2 // D4
#define led6 14 // D5
#define servo 12//D6P0



FirebaseData fbdo;

String dato = "";
String nodo = "prueba";
String ledOn = "";
String ledOff = "";

 
void setup() {

  Serial.begin(9600);
  servoMotor.attach(servo);

  
  Serial.begin(115200);
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);
  pinMode(led4, OUTPUT);
  pinMode(led5, OUTPUT);
  pinMode(led6, OUTPUT);

  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
  delay (2000);
  Serial.println();
  Serial.println("Conectando a Red Wifi");
  while (WiFi.status() != WL_CONNECTED)
  {
    Serial.print(".");
    delay(500);
  }
  Serial.println();
  Serial.print("Conexion Exitosa IP: ");
  Serial.println(WiFi.localIP());
  Serial.println();


  // Conexion a Firebase
  Firebase.begin(FIREBASE_HOST, FIREBASE_AUTH);
  Firebase.reconnectWiFi (true);
}


void loop() {
  ledUno();
  ledDos();
  ledTres();
  ledCuatro();
  ledCinco();
  ledSeis();
  servofb();
  
}


//Metodo del Led Uno
void ledUno() {
  if (Firebase.getString(fbdo, nodo + "/Led1")) {
    dato = fbdo.stringData();
  }
  if (dato == "1")
    digitalWrite(led1, HIGH);

  else if (dato == "0")
    digitalWrite(led1, LOW);
  
}
// Metodo del Led dos
void ledDos() {
  if (Firebase.getString(fbdo, nodo + "/Led2")) {
    dato = fbdo.stringData();
  }
  if (dato == "1")
    digitalWrite(led2, HIGH);

  else if (dato == "0")
    digitalWrite(led2, LOW);
  
}

//Metodo led Tres
void ledTres(){
if (Firebase.getString(fbdo, nodo + "/Led3")) {
    dato = fbdo.stringData();
  }
  if (dato == "1")
    digitalWrite(led3, HIGH);

  else if (dato == "0")
    digitalWrite(led3, LOW);
}
//Metodo led Cuatro
void ledCuatro(){
if (Firebase.getString(fbdo, nodo + "/Led4")) {
    dato = fbdo.stringData();
  }
  if (dato == "1")
    digitalWrite(led4, HIGH);

  else if (dato == "0")
    digitalWrite(led4, LOW);
}

//Metodo led cinco
void ledCinco(){
if (Firebase.getString(fbdo, nodo + "/Led5")) {
    dato = fbdo.stringData();
  }
  if (dato == "1")
    digitalWrite(led5, HIGH);

  else if (dato == "0")
    digitalWrite(led5, LOW);
}
//Metodo led Seis
void ledSeis(){
if (Firebase.getString(fbdo, nodo + "/Led6")) {
    dato = fbdo.stringData();
  }
  if (dato == "1")
    digitalWrite(led6, HIGH);

  else if (dato == "0")
    digitalWrite(led6, LOW);

}
void servofb(){
if (Firebase.getString(fbdo, nodo + "/Servo")) {
    dato = fbdo.stringData();
  }
  if (dato == "1")
    servoMotor.write(0);

  else if (dato == "0")
    servoMotor.write(180);


}
