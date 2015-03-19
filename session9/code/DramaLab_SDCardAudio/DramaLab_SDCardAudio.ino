/* DramaLab_SDCardAudio: 
 * Plays a wav file found on a SD card using an LM386-based amplifier circuit
 *
 * http://dramalab.unibz.it/
 * Max Stricker, 21.03.2015
 */

#include <SD.h>
#include <TMRpcm.h>
 
#define SDPIN 4

File myFile;
TMRpcm tmrpcm;
 
char mychar;
 
void setup(){
  Serial.begin(9600);
  tmrpcm.speakerPin = 9; //11 on Mega, 9 on Uno, Nano, etc
  tmrpcm.setVolume(4);
  if (!SD.begin(SDPIN)) {
    Serial.println("initialization failed!");
    return;
  }
  Serial.println("Type 'a' to play a song.");
}
 
void loop(){
    if(Serial.available()){
      mychar = Serial.read();
      if(mychar == 'a'){ //send the letter a over the serial monitor to start playback
      Serial.println("1 wav");
        tmrpcm.play("1.wav");
        /*available commands:
        tmrpcm.play("filename");    plays a file
        tmrpcm.play("filename",30); plays a file starting at 30 seconds into the track
        tmrpcm.speakerPin = 11;     set to 5,6,11 or 46 for Mega, 9 for Uno, Nano, etc.
        tmrpcm.disable();           disables the timer on output pin and stops the music
        tmrpcm.stopPlayback();      stops the music, but leaves the timer running
        tmrpcm.isPlaying();         returns 1 if music playing, 0 if not
        tmrpcm.pause();             pauses/unpauses playback
        tmrpcm.quality(1);          Set 1 for 2x oversampling
        tmrpcm.volume(0);           1(up) or 0(down) to control volume
        tmrpcm.setVolume(0);        0 to 7. Set volume level
        tmrpcm.loop(1);             0 or 1. Can be changed during playback for full control of looping.
        */
      }
    }
}
 
void playSound(char *file){
 tmrpcm.play(file);
 return;
}
