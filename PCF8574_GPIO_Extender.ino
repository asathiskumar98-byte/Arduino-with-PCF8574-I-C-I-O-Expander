#include<Wire.h>

void WriteToPCF8574(unsigned char data)
{
  Wire.beginTransmission(0x20);
  Wire.write(data);
  Wire.endTransmission();
}
void setup()
{
  Wire.begin();
}

void loop()
{
  WriteToPCF8574(0x01);
  delay(1000);
  WriteToPCF8574(0x02);
  delay(1000);
  WriteToPCF8574(0x04);
  delay(1000);
  WriteToPCF8574(0x08);
  delay(1000);
  WriteToPCF8574(0x10);
  delay(1000);
  WriteToPCF8574(0x20);
  delay(1000);
  WriteToPCF8574(0x40);
  delay(1000);
  WriteToPCF8574(0x80);
  delay(1000);
}
