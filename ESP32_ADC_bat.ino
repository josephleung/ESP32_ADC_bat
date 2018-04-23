// ESP32 ADC config to get correct battery voltage for Adafruit-HUZZAH32-ESP32-Feather
// In order to read desired ADC values we need to set the attenuation.
// For more info please read https://esp-idf.readthedocs.io/en/v2.0/api/peripherals/adc.html


#include <driver/adc.h>

#define VBATPIN A13

void setup()
{
  Serial.begin(115200);

  adc1_config_width(ADC_WIDTH_12Bit);  // 12bit, so the range is 0-4095
  adc1_config_channel_atten(ADC1_CHANNEL_7, ADC_ATTEN_11db);  //11db attenation to get good linearity
}

void loop()
{
  float batVolt = getBatVolt();
  Serial.println(batVolt);
}


float getBatVolt()
{
  float resule = analogRead(VBATPIN);

  resule *= 2;  // there's a 1/2 voltage devid hardware
  resule *= 3.3;
  resule /= 4096;
  return resule;
}
