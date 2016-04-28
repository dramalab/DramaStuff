import processing.serial.*;
import processing.video.*;


Movie myMovie;
Serial myPort;  // Create object from Serial class
String val;     // Data received from the serial port
boolean isVideoStarted = false;
boolean isVideoPause = false;

void setup(){
 size(2560, 1440, P2D);
//fullScreen();
  
  println(Serial.list());
  String portName = Serial.list()[2]; //change the 0 to a 1 or 2 etc. to match your port
  myPort = new Serial(this, portName, 9600);
  background(0);
  //frameRate(25);
  myMovie = new Movie(this, "mpquattro.mp4");
  myMovie.loop();
}


void draw()
{
   image(myMovie, 0,0,width,height);


  if ( myPort.available() > 0) 
  {  // If data is available,
  val = myPort.readStringUntil('\n');         // read it and store it in val
  }
  if(val!=null){
    val = trim(val);
    println(val);
    if(!"".equals(val)){
      int speedValue = Integer.parseInt(val);
      float videoSpeed = 0.0;
      if(speedValue>50) videoSpeed = 0.5;
      if(speedValue>100) videoSpeed = 0.7;
      if(speedValue>150) videoSpeed = 1.0;
      if(videoSpeed==0.0){
        myMovie.pause();
        isVideoPause = true;
      }else{
        if(!isVideoPause){
        myMovie.speed(videoSpeed);
        }else{
          myMovie.speed(videoSpeed);
          myMovie.loop();
          isVideoPause = false;
      }
      }
      
    }
  }

  val = null;  

   
}

void movieEvent(Movie m) {
  m.read();
}