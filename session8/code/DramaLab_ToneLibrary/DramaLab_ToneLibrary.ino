/* DramaLab_ToneLibrary: 
 * Generate sounds with the tone-itead library
 * https://code.google.com/p/tone-itead/downloads/list
 *
 * http://dramalab.unibz.it/
 * Max Stricker, 14.03.2015
 *
 */
#include <Tone_Itead.h>
int speakerPin = 1;
Tone makeTone;

// notes to play; see Tone_Itead.h for frequencies; 
int notes[] = { 
 NOTE_C4, NOTE_C4, NOTE_D4, NOTE_C4, NOTE_F4, NOTE_E4, 
 NOTE_C4, NOTE_C4, NOTE_D4, NOTE_C4, NOTE_G4, NOTE_F4,
 NOTE_C4, NOTE_C4, NOTE_C5, NOTE_A4, NOTE_F4, NOTE_E4, NOTE_D4,
 NOTE_AS4, NOTE_AS4, NOTE_A4, NOTE_F4, NOTE_G4, NOTE_F4}; 

// number of beats for each note
int beats[] = { 
 1, 1, 2, 2, 2, 4, 
 1, 1, 2, 2, 2, 4, 
 1, 1, 2, 2, 2, 2, 2, 
 1, 1, 2, 2, 2, 4}; 

// Calculate song length
int songLength = sizeof(notes) / sizeof(int); 
int tempo = 220; // in milliseconds

void playNote(int note, int beat){
 makeTone.stop(); // speaker reset
 makeTone.play(note); // play tone 
 delay(tempo * beat); // for specified number of beats
 makeTone.stop(); // speaker reset
 delay(tempo / 4); // pause between notes
}

void setup() {
 pinMode(speakerPin,OUTPUT);
 makeTone.begin(speakerPin); // set up piezo speaker
}

void loop() {
  for (int i = 0; i < songLength; i++) 
  {
    playNote(notes[i],beats[i]); // make sound
  }
}
