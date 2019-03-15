#include <Adafruit_NeoPixel.h>
#ifdef __AVR__
  #include <avr/power.h>
#endif

// Which pin on the Arduino is connected to the NeoPixels?
// On a Trinket or Gemma we suggest changing this to 1
#define PIN1            0
#define PIN2            1

// How many NeoPixels are attached to the Arduino?
#define NUMPIXELS      12

// When we setup the NeoPixel library, we tell it how many pixels, and which pin to use to send signals.
// Note that for older NeoPixel strips you might need to change the third parameter--see the strandtest
// example for more information on possible values.
Adafruit_NeoPixel pixels1 = Adafruit_NeoPixel(NUMPIXELS, PIN1, NEO_GRB + NEO_KHZ800);
Adafruit_NeoPixel pixels2 = Adafruit_NeoPixel(NUMPIXELS, PIN2, NEO_GRB + NEO_KHZ800);

void setup() {
  pixels1.begin(); // This initializes the NeoPixel library.
  pixels2.begin(); // This initializes the NeoPixel library.
  for(int i=0;i<NUMPIXELS;i++){

    pixels1.setPixelColor(i, pixels1.Color(0,0,0)); // RGB
    pixels2.setPixelColor(i, pixels2.Color(0,0,0)); // RGB
    pixels1.show();
    pixels2.show();
  }
  pinMode(21, INPUT);
}

void loop() {
  bool logic = digitalRead(21);
  int pot1Val = analogRead(23);
  int pot2Val = analogRead(22);
  pot1Val = 530 - pot1Val;
  pot2Val = 530 - pot2Val;
  if(logic == 1){
    for(int i=0;i<NUMPIXELS;i++){
      if (i <= pot1Val/46 + 1 && i != 0){
        pixels1.setPixelColor(i, pixels1.Color(0,30,0)); // RGB
        pixels1.show();
      }
      else{
        pixels1.setPixelColor(i, pixels1.Color(0,0,0)); // RGB
        pixels1.show();
      }
    }
    for(int i=0;i<NUMPIXELS;i++){
      if (i <= pot2Val/46 + 1 && i != 0){
        pixels2.setPixelColor(i, pixels2.Color(0,0,30)); // RGB
        pixels2.show();
      }
      else{
        pixels2.setPixelColor(i, pixels2.Color(0,0,0)); // RGB
        pixels2.show();
      }
    }
    delay(10); // Delay for a period of time (in milliseconds).
    
  }
  if(logic == 0){
    for(int i=0;i<=NUMPIXELS;i++){
        pixels1.setPixelColor(12 - i, pixels1.Color(30,0,0)); // RGB
        pixels2.setPixelColor(12 - i, pixels2.Color(30,0,0)); // RGB
        pixels1.show();
        pixels2.show();
    }
    delay(1000);
    for(int i=0;i<=NUMPIXELS;i++){
        pixels1.setPixelColor(12 - i, pixels1.Color(0,0,0)); // RGB
        pixels2.setPixelColor(12 - i, pixels2.Color(0,0,0)); // RGB
        pixels1.show();
        pixels2.show();
    }
    delay(1000);
  }
}
