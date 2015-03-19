/*
 * DramaLab_ProcessingPlayerSerial
 *
 * http://dramalab.unibz.it/
 * Max Stricker, 21.03.2015   
 */
import ddf.minim.*;
import processing.serial.*;

Minim minim;
AudioPlayer player;
Serial myPort;  // Create object from Serial class
String val;     // Data received from the serial port

void setup()
{
  println(Serial.list());
  String portName = Serial.list()[5]; //change the 0 to a 1 or 2 etc. to match your port
  myPort = new Serial(this, portName, 9600);
  
  size(512, 200, P3D);
  minim = new Minim(this);
  player = minim.loadFile("Read Between The Lines.mp3");//taken from http://www.maninblack.org/demos.html
}

void draw()
{
  background(0);
  stroke(255);
  // draw the waveforms
  // the values returned by left.get() and right.get() will be between -1 and 1,
  // so we need to scale them up to see the waveform
  // note that if the file is MONO, left.get() and right.get() will return the same value
  for(int i = 0; i < player.bufferSize() - 1; i++)
  {
    float x1 = map( i, 0, player.bufferSize(), 0, width );
    float x2 = map( i+1, 0, player.bufferSize(), 0, width );
    line( x1, 50 + player.left.get(i)*50, x2, 50 + player.left.get(i+1)*50 );
    line( x1, 150 + player.right.get(i)*50, x2, 150 + player.right.get(i+1)*50 );
  }
  if ( myPort.available() > 0){  // If data is available,
    val = myPort.readStringUntil('\n');// read it and store it in val
  }
  if(val!=null){
    val = trim(val);
    if(val.equals("play")){
        player.play();
      }else{
        player.pause();
    }  
  }
  val = null;  

}
