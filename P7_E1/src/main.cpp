#include <Arduino.h>

#include "AudioGeneratorAAC.h" 
#include "AudioOutputI2S.h" 
#include "AudioFileSourcePROGMEM.h" 
#include "sampleaac.h" 

AudioFileSourcePROGMEM *in; 
AudioGeneratorAAC *aac; 
AudioOutputI2S *out; 
void setup(){ 
Serial.begin(115200); 
in = new AudioFileSourcePROGMEM(sampleaac, sizeof(sampleaac)); 
aac = new AudioGeneratorAAC(); 
out = new AudioOutputI2S(); 
out -> SetGain(0.125); 
out -> SetPinout(20,21,47);

aac->begin(in, out); 
} 
void loop(){ 
if (aac->isRunning()) { 
aac->loop(); 
} else { 
aac -> stop(); 
Serial.printf("Sound Generator\n"); 
delay(1000); 
} 
} 