#include <Wire.h>;
 
void setup(){
  Wire.begin();
  Serial.begin(9600);
  while (!Serial);
  Serial.println("\nI2C Scanner");
}
 
void loop(){
  byte error, address;
  int nDevices;
  Serial.println("Scanning...");
   
  nDevices = 0;
  for(address = 1; address < 127; address++ ){
    Wire.beginTransmission(address);
    error = Wire.endTransmission();
     
    if (error == 0){
      Serial.print("ditemukan Perangkat i2C pada alamat 0x");
      if (address<16)
      Serial.print("0");
      Serial.print(address,HEX);
      Serial.println(" !");
       
      nDevices++;
    }
    else if (error==4){
      Serial.print("tidak ditemukan alamat 0x");
      if (address<16)
      Serial.print("0");
      Serial.println(address,HEX);
    }
  }
  if (nDevices == 0)
    Serial.println("Tidak Ditemukan Alamat i2c\n");
    else
    Serial.println("selesai\n");
     
    delay(5000);
}
