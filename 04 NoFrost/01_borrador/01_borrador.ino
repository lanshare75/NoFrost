//Controlador Heladera No Frost para Fermentar y Madurar  (by JMT 25/02/2020)

/*Inicio carga de Librerias*/
#include <OneWire.h> 
#include <DallasTemperature.h>//Lee sensor DS18B20 (temperatura)
#include <Wire.h>
#include <LiquidCrystal_I2C.h>

/*Fin carga de Librerias*/

//Crear el objeto lcd  dirección  "0x3F" y configuro las caracteristicas del lcd (20 columnas x 4 filas)
LiquidCrystal_I2C lcd(0x3F, 20, 4);

//asignacion de salidas
const int pinD2 = 2;   //Sondas (Evaporador y Ambiente)
const int pinD3 = 3;   //
const int pinD4 = 4;   //LCD
const int pinD5 = 5;   //LCD

const int K1 = A0;       //Motor Heladera
const int K2 = A1;       //Ventilador/Forzador
const int K3 = A2;       //Resistencia Deshielo/Defrost

// Instancia a las clases OneWire y DallasTemperature
OneWire oneWireObj(pinD2);
DallasTemperature sensorDS18B20(&oneWireObj);

//Defino en variables las direcciones de las sondas
DeviceAddress address1 = {0x28, 0xAA, 0x7A, 0xB6, 0x13, 0x13, 0x2, 0x6E};//dirección del sensor 1
DeviceAddress address2 = {0x28, 0xAA, 0x6, 0x2A, 0x13, 0x13, 0x2, 0xD1};//dirección del sensor 2
DeviceAddress address3 = {0x28, 0xAA, 0x2E, 0x31, 0x13, 0x13, 0x2, 0xBB};//dirección del sensor 3

void setup() {
  Serial.begin(9600); // Inicio la comunicación serie
  sensorDS18B20.begin(); //Inicio las Sondas
  
//  lcd.backlight(); //enciendo el Backlight del LCD
//  lcd.init(); //Inicio el LCD
//  lcd.clear();
//  lcd.setCursor(0, 1);
//  lcd.print("Iniciando...");
  
  pinMode(K1, OUTPUT);
  pinMode(K2, OUTPUT);
  pinMode(K3, OUTPUT);
  digitalWrite(K1, HIGH); // Todos apagados al INICO
  digitalWrite(K2, HIGH);
  digitalWrite(K3, HIGH);
}

void loop() {
  
//Senso las temperaturas del Evaporador y el Fermentador
sensorDS18B20.requestTemperatures(); //envía el comando para obtener las temperaturas
float temp0= sensorDS18B20.getTempC(address1);//Se obtiene la temperatura en °C del sensor 1
float temp1= sensorDS18B20.getTempC(address2);//Se obtiene la temperatura en °C del sensor 2
float temp2= sensorDS18B20.getTempC(address3);//Se obtiene la temperatura en °C del sensor 3

Serial.print("Temperatura 0 = ");
Serial.print(temp0);
Serial.print("° C");
Serial.print("   Temperatura 1 = ");
Serial.print(temp1);
Serial.print("° C");
Serial.print("   Temperatura 2 = ");
Serial.print(temp2);
Serial.println("° C");

String Forzador, Motor;

 if (temp1 > 18) {
    //Generar FRIO
    Forzador = "ON";
    Motor = "ON";
    //encender Relay K1
    digitalWrite(K1, LOW);
  
    Serial.println("tempON: " + String(temp1));
    }
  else
  {
    //Apagar FRIO
    //apagar Relay K1
    Forzador = "OFF";
    Motor = "OFF";
    digitalWrite(K1, HIGH);
    
    Serial.println("tempOFF: " + String(temp1));
  }
  
}  
/*Encender heladera*/


/* "INICIO"
//Sensar la temperatura del Fermentador
Si la Temperatura del Fermentador es superior a 18° enciendo Motor
*/
/* /     String Forzador, Motor;
//    
//    lcd.clear();
//    lcd.setCursor(0, 0);
//

//
////NoFrostProgram
//  if(temp0 <= -23) {
//  digitalWrite(K3, LOW);
// }   
 
//  lcd.clear();
//  lcd.setCursor(0, 0);
//  lcd.print("Temp Evapo: " + String(temp0) + "°");
//  
//  lcd.setCursor(0, 1);
//  lcd.print("Temp Mosto: " + String(temp1) + "°");
//
//  lcd.setCursor(0, 2);
//  lcd.print("Temp Ambiente: " + String(temp2) + "°");
//  
//  lcd.setCursor(0, 3);
//  lcd.print("Forz: " + Forzador + ", " + "Hel: " + Motor);
//  Serial.println("Fin Programa");

 //retraso de 0,5 segundos entre loops


*/
