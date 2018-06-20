 /*http://www.arduino.cc/en/Tutorial/Tone
*/

#include "pitches.h"
long currenttime1,previoustime1,currenttime2,previoustime2;
boolean check1,check2;
volatile boolean state=LOW;
// notes in the melody:
int melody2[] = {
  NOTE_B4, NOTE_A4, NOTE_G4, NOTE_A4, NOTE_B4, NOTE_B4, NOTE_B4, NOTE_A4, NOTE_A4, NOTE_A4, NOTE_B4, NOTE_B4, NOTE_B4 ,NOTE_B4, NOTE_A4, NOTE_G4, NOTE_A4, NOTE_B4, NOTE_B4, NOTE_B4, NOTE_A4,NOTE_A4,NOTE_B4, NOTE_A4, NOTE_G4
};
int melody1[] = {
 NOTE_E3, NOTE_G4, NOTE_C5, NOTE_E5, NOTE_B2, NOTE_G4, NOTE_B4, NOTE_D5,  
 NOTE_C3, NOTE_E4, NOTE_A4, NOTE_C5, NOTE_G2, NOTE_E4, NOTE_G4, NOTE_B4,  
 NOTE_A2, NOTE_C4, NOTE_F4, NOTE_A4, NOTE_E1, NOTE_C4, NOTE_E4, NOTE_G4,  
 NOTE_A2, NOTE_D4, NOTE_F4, NOTE_A4, NOTE_B2, NOTE_D4, NOTE_G4, NOTE_B4,  
 NOTE_E3, NOTE_E5, NOTE_F5, NOTE_G5, NOTE_E5, NOTE_F5, NOTE_G5, NOTE_G4, NOTE_A4, NOTE_B4, NOTE_C5, NOTE_D5, NOTE_E5, NOTE_F5,   
 NOTE_E5, NOTE_C5, NOTE_D5, NOTE_E5, NOTE_E4, NOTE_F4, NOTE_G4, NOTE_A4, NOTE_G4, NOTE_F4, NOTE_G4, NOTE_F4, NOTE_F4, NOTE_G4,   
 NOTE_F4, NOTE_A4, NOTE_G4, NOTE_F4, NOTE_E4, NOTE_D4, NOTE_E4, NOTE_D4, NOTE_C4, NOTE_D4, NOTE_E4, NOTE_F4, NOTE_G4, NOTE_A4,   
 NOTE_F4, NOTE_A4, NOTE_G4, NOTE_A4, NOTE_B4, NOTE_C5, NOTE_G4, NOTE_A4, NOTE_B4, NOTE_C5, NOTE_D5, NOTE_E5, NOTE_F5, NOTE_G5,  
 NOTE_E5, NOTE_C5, NOTE_D5, NOTE_E5, NOTE_D5, NOTE_C5, NOTE_D5, NOTE_B4, NOTE_C5, NOTE_D5, NOTE_E5, NOTE_D5, NOTE_C5, NOTE_B4,  
 NOTE_C5, NOTE_A4, NOTE_B4, NOTE_C5, NOTE_C4, NOTE_D4, NOTE_E4, NOTE_F4, NOTE_E4, NOTE_D4, NOTE_E4, NOTE_C5, NOTE_B4, NOTE_C5,  
 NOTE_A4, NOTE_C5, NOTE_B4, NOTE_A4, NOTE_G4, NOTE_F4, NOTE_G4, NOTE_F4, NOTE_E4, NOTE_F4, NOTE_G4, NOTE_A4, NOTE_B4, NOTE_C5,  
 NOTE_A4, NOTE_C5, NOTE_B4, NOTE_C5, NOTE_B4, NOTE_A4, NOTE_B4, NOTE_C5, NOTE_D5, NOTE_C5, NOTE_B4, NOTE_C5, NOTE_A4, NOTE_B4,  
 NOTE_C5,0
};

// note durations: 4 = quarter note, 8 = eighth note, etc.:
int noteDurations2[] = {
  4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4,4, 4, 4, 4, 4, 4, 4, 4, 4, 4,0
};
int noteDurations1[] = {
  8, 8, 8, 8, 8, 8, 8, 8,  
 8, 8, 8, 8, 8, 8, 8, 8,   
 8, 8, 8, 8, 8, 8, 8, 8,   
 8, 8, 8, 8, 8, 8, 8, 8,   
 8,16,16,8,16,16,16,16,16,16,16,16,16, 16,  
 8,16,16,8,16,16,16,16,16,16,16,16,16, 16,  
 8,16,16,8,16,16,16,16,16,16,16,16,16, 16,  
 8,16,16,8,16,16,16,16,16,16,16,16,16, 16,  
 8,16,16,8,16,16,16,16,16,16,16,16,16, 16,  
  8,16,16,8,16,16,16,16,16,16,16,16,16, 16,  
 8,16,16,8,16,16,16,16,16,16,16,16,16, 16,  
 8,16,16,8,16,16,16,16,16,16,16,16,16, 16,  
  1 
};

void setup() {
   pinMode(13, OUTPUT);
    pinMode(2, INPUT_PULLUP);
   noTone(8);
   attachInterrupt(0,int0,LOW);
}

void loop() {
if(state==LOW){
    for (int thisNote1 = 0; thisNote1 < 27; thisNote1++) {
    int noteDuration1 = 1000 / noteDurations1[thisNote1];
    tone(8, melody1[thisNote1], noteDuration1);
    previoustime1=millis();
     digitalWrite(13,HIGH);
    check1=false;
    while(!check1){
      currenttime1=millis();
      if(currenttime1-previoustime1>500){
        digitalWrite(13,LOW);
      }
      if(currenttime1-previoustime1>550){
        check1=true;
      }
    }
    noTone(8);
  }
}
 if(state==HIGH){ 
    for (int thisNote2 = 0; thisNote2 < 11; thisNote2++) {
    int noteDuration2 = 1800 / noteDurations2[thisNote2];
    tone(8, melody2[thisNote2], noteDuration2);
    previoustime2=millis();
     digitalWrite(13,HIGH);
    check2=false;
    while(!check2){
      currenttime2=millis();
      if(currenttime2-previoustime2>500){
        digitalWrite(13,LOW);
      }
      if(currenttime2-previoustime2>550){
        check2=true;
      }
    }

    noTone(8);
  }
 }

}

void int0(){
  state=!state;
}

