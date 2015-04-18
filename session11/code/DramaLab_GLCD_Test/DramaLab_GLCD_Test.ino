/*
* Control a 128x64GLCD display(with ST7920 chipset)
* using the u8glib library:
* https://code.google.com/p/u8glib/wiki/userreference
*
* http://dramalab.unibz.it/
* Max Stricker, 18.04.2015   
*
* Wiring:
* VSS -> GND
* VDD -> 5V
* RS -> D10
* RW -> D11
* E(nable) -> D13
* PSB -> GND
* BLA -> Poti -> 5V
* BLK -> GND
*/

#include "U8glib.h"


U8GLIB_ST7920_128X64 u8g(13, 11, 10, U8G_PIN_NONE);

void draw(void) {
  u8g.setFont(u8g_font_courB10);
  //u8g.setFont(u8g_font_osb21);
  u8g.drawStr( 0, 22, "Hello World!");
  u8g.drawLine(63, 64, 25, 17);
}

void drawBox(){
//u8g.drawBox(100,5,20,30);
}

void drawCircle(){
u8g.drawCircle(63,64,64,U8G_DRAW_UPPER_RIGHT);  
u8g.drawCircle(63,64,63,U8G_DRAW_UPPER_LEFT);  
u8g.drawLine(0,63,128,63);
}
void setup(void) {
  // flip screen, dependig of view
   u8g.setRot180();
  // assign default color value

}

void loop(void) {
  // picture loop
  u8g.firstPage();  
  do {
    draw();
    drawBox();
    drawCircle();
  } while( u8g.nextPage() );
  
  // rebuild the picture after some delay
  delay(500);
}

