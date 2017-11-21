//www.elegoo.com
//2016.12.9

#include <SimpleDHT.h>

// for DHT11, 
//      VCC: 5V or 3V
//      GND: GND
//      DATA: 2
int pinDHT11 = 2;
SimpleDHT11 dht11;
int buzzer = 7;

void setup() {
  Serial.begin(9600);
  pinMode(buzzer, OUTPUT);
}

void noise() {
   unsigned char i;
   
   //output an frequency
   for(i=0;i<180;i++)
   {
    digitalWrite(buzzer,HIGH);
    delay(1);//wait for 1ms
    digitalWrite(buzzer,LOW);
    delay(1);//wait for 1ms
    }
    //output another frequency
     for(i=0;i<100;i++)
      {
        digitalWrite(buzzer,HIGH);
        delay(2);//wait for 2ms
        digitalWrite(buzzer,LOW);
        delay(2);//wait for 2ms
      }
  }

void loop() {
  // start working...
  Serial.println("=================================");
  Serial.println("Sample DHT11...");
  // read with raw sample data.
  byte temperature = 0;
  byte humidity = 0;
  byte data[40] = {0};
  char result[10]; //= "arduino";
  if (dht11.read(pinDHT11, &temperature, &humidity, data)) {
    Serial.print("Read DHT11 failed");
    return;
  }
  
  Serial.print("Sample RAW Bits: ");
  Serial.print("Sample  ");
  
  for (int i = 0; i < 40; i++) {
    Serial.print((int)data[i]);
    if (i > 0 && ((i + 1) % 4) == 0) {
      Serial.print(' ');
    }
  }
  Serial.println("");
  if (temperature < 20 || temperature > 22){
    Serial.print("bad ");
    noise();
  }  
  else {
    Serial.print("OK ");
  }


  Serial.print((int)temperature); Serial.print(" *C, ");
  Serial.print((int)humidity); Serial.println(" %");

  // DHT11 sampling rate is 1HZ.
  delay(2000);
}
