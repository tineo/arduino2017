#include "DHT.h" //cargamos la librería DHT
#define DHTPIN 7 //Seleccionamos el pin en el que se conectará el sensor
#define DHTTYPE DHT22 //Se selecciona el DHT22(hay otros DHT)

#define LED_BLUE 3
#define LED_GREEN 4
#define LED_RED 5

#define LED_GREEN2 10 
#define LED_RED2 9

DHT dht(DHTPIN, DHTTYPE); //Se inicia una variable que será usada por Arduino para comunicarse con el sensor//Variables


int chk;
float hum;  //humedad
float temp; //temperatura

void setup()
{
  Serial.begin(9600);
  dht.begin();
  
  pinMode(LED_BLUE, OUTPUT);
  pinMode(LED_GREEN, OUTPUT);
  pinMode(LED_RED, OUTPUT);
  pinMode(LED_GREEN2, OUTPUT);
  pinMode(LED_RED2, OUTPUT);
}

void loop()
{
  
    //leer data de temperatura y humedad
    hum = dht.readHumidity();
    temp= dht.readTemperature();
    //enviar al serial la hum y temp
    Serial.print("Humedad: ");
    Serial.print(hum);
    Serial.print(" %, Temperatura: ");
    Serial.print(temp);


    //LED de TEMP
    if(temp > 22){
      digitalWrite(LED_RED, HIGH);   
      delay(1000);                   
      digitalWrite(LED_RED, LOW);     
    }else if(temp <=22 && temp >= 19.5){
      digitalWrite(LED_GREEN, HIGH);   
      delay(1000);                     
      digitalWrite(LED_GREEN, LOW);
    }else{
      digitalWrite(LED_BLUE, HIGH);   
      delay(1000);                    
      digitalWrite(LED_BLUE, LOW);
    }

    //LED de HUM
    if(hum >= 76  && hum <=81.5){
      digitalWrite(LED_GREEN2, HIGH);   
      delay(500);                     
      digitalWrite(LED_GREEN2, LOW);
    }else{
      digitalWrite(LED_RED2, HIGH);   
      delay(500);                    
      digitalWrite(LED_RED2, LOW);
    }

    Serial.println(" Cº");
    delay(500);
}

   
