 // include LCD library code
#include <LiquidCrystal.h>
// include DHT library code
#include <DHT.h> 
int temp;
int hum;
int sensor = 8;


DHT dht (sensor, DHT11);



int M_Sensor = A0;
int Pwd = 13;
int fan =1;


LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

void setup()
 {
    // set up the LCD's number of columns and rows
  lcd.begin(16, 2);
  dht.begin();
    pinMode(M_Sensor, INPUT);
    pinMode(13,OUTPUT);
    pinMode(9,OUTPUT);
    pinMode(1,OUTPUT);
    
    lcd.setCursor(0,0);
    lcd.print("Temperature");
    lcd.setCursor(0,1);
    lcd.print("Soil Moisture");
    delay(500);
}

void loop()
{
  
  //delay(100);           // wait 1s between readings
  hum=dht.readHumidity();
  temp=dht.readTemperature();
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("Temperature: ");
  lcd.print(temp);
  lcd.print("C");
  lcd.setCursor(0,1);
  lcd.print("Humidity: ");
  lcd.print(hum);
  lcd.print("%");
 
  delay(500);
  lcd.clear();
  
  
  int Moisture = analogRead(M_Sensor); //Read Moisture Sensor Value 

  if (temp > 30 && hum > 50)
  {
    lcd.setCursor(0,0);
    lcd.print("FAN ON");
    digitalWrite(1,HIGH);
    delay(100);
    
  }else{
    lcd.setCursor(0,0);
    lcd.print("FAN OFF");
    digitalWrite(1,LOW);
    delay(500);
    
  }

 
 if (Moisture> 700)   // for dry soil
  { 
        lcd.setCursor(11,0);
        lcd.print("DRY");
        lcd.setCursor(11,1);
        lcd.print("SOIL");
         digitalWrite(13, HIGH);
         lcd.setCursor(0,1);
         lcd.print("PUMP:ON");
  }
 
     if (Moisture>= 300 && Moisture<=700) //for Moist Soil
    { 
      lcd.setCursor(11,0);
     lcd.print("MOIST");
     lcd.setCursor(11,1);
     lcd.print("SOIL");
     digitalWrite(13,LOW);
     lcd.setCursor(0,1);
     lcd.print("PUMP:OFF");    
  }
 
  if (Moisture < 300)  // For Soggy soil
  { 
    lcd.setCursor(11,0);
     lcd.print("SOGGY");
     lcd.setCursor(11,1);
     lcd.print("SOIL");
     digitalWrite(13,LOW);
     lcd.setCursor(0,1);
     lcd.print("PUMP:OFF");
  }
 delay(500);    
}  
