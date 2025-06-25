#include <Arduino.h>

#include "Audio.h" 
#include "SD.h" 
#include "FS.h" 
// Digital I/O used 
#define SD_CS        10  
#define SPI_MOSI     11
#define SPI_MISO     13  
#define SPI_SCK      12 
#define I2S_DOUT     47
#define I2S_BCLK     20
#define I2S_LRC      21
Audio audio; 

void setup(){ 
pinMode(SD_CS, OUTPUT); 
digitalWrite(SD_CS, HIGH); 
SPI.begin(SPI_SCK, SPI_MISO, SPI_MOSI); 
Serial.begin(115200); 
SD.begin(SD_CS); 
audio.setPinout(I2S_BCLK, I2S_LRC, I2S_DOUT); 
audio.setVolume(10); // 0...21 

audio.connecttoFS(SD, "bass-wiggle-297877.wav"); 
} 
 
void loop(){ 
    audio.loop(); 
} 
 
