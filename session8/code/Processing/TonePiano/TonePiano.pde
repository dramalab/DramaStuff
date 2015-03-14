import processing.serial.*;

Serial myPort;
String val;

void setup(){
  println(Serial.list());
  String portName = Serial.list()[0];
  myPort = new Serial(this, "/dev/cu.usbmodem14111", 9600);
  size(180, 100);
}


void draw()
{
  rect(0, 0, 20, 100);
  rect(20, 0, 20, 100);
  rect(40, 0, 20, 100);
  rect(60, 0, 20, 100);
  rect(80, 0, 20, 100);
  rect(100, 0, 20, 100);
  rect(120, 0, 20, 100);
  rect(140, 0, 20, 100);
  rect(160, 0, 20, 100);
}

void mousePressed() {
  if(mouseX>=0 && mouseX<20){
    myPort.write("450");
  }else if(mouseX>=20 && mouseX<40){
    myPort.write("400");
  }else if(mouseX>=40 && mouseX<60){
    myPort.write("350");
  }else if(mouseX>=60 && mouseX<80){
    myPort.write("300");
  }else if(mouseX>=80 && mouseX<100){
    myPort.write("250");
  }else if(mouseX>=100 && mouseX<120){
    myPort.write("200");
  }else if(mouseX>=120 && mouseX<140){
    myPort.write("150");
  }else if(mouseX>=140 && mouseX<160){
    myPort.write("100");
  }else if(mouseX>=160 && mouseX<180){
    myPort.write("50");
  }
}
