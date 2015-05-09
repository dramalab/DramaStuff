#include <TinyGPS++.h>
#include <AltSoftSerial.h>
#include "U8glib.h"

/*
* DramaLab_GeoCaching
* Guides you to a predefined place by varying the pitch of a tone.
* Higher pitch indicates that you are near to your goal.
*
* Same idea as the Reverse Geocache Puzzle by Arduiniana
* Based on the TinyGPS++ example code
*
* http://dramalab.unibz.it/
* Max Stricker, 09.05.2015 
*
*/
// GPS settings
static const int RXPin = 8, TXPin = 9;
static const uint32_t GPSBaud = 9600;

TinyGPSPlus gps;
AltSoftSerial ss(RXPin, TXPin); //SoftSerial has problem with the tone library, use AltSoftSerial

U8GLIB_ST7920_128X64 u8g(12, 11, 10, U8G_PIN_NONE); // glcd 128x64

// the place to find, keep it secret
float HIDDEN_PLACE_LAT = 46.498591; // change this, coordinates are for UniBZ place
float HIDDEN_PLACE_LON = 11.350038;

boolean found = false;
void setup()
{
  Serial.begin(115200);
  pinMode(13, OUTPUT);
  ss.begin(GPSBaud);
  u8g.setFont(u8g_font_5x7);

  digitalWrite(13, LOW);
  Serial.println(F("DramaLab_GeoCaching"));
  Serial.println(F("Sats HDOP Latitude   Longitude   Fix  Date       Time     Date Alt    Course Speed Card  Distance Course Card  Chars Sentences Checksum"));
  Serial.println(F("          (deg)      (deg)       Age                      Age  (m)    --- from GPS ----  ---- to London  ----  RX    RX        Fail"));
  Serial.println(F("---------------------------------------------------------------------------------------------------------------------------------------"));
  
  u8g.firstPage(); 
  do {
    u8g.setPrintPos(10,10);
    u8g.print("No GPS available!");
  }while(u8g.nextPage());

}

void loop()
{
  // fetch new NMEA Strings
  while (ss.available())
      gps.encode(ss.read());
  
  // printing debug information on serial monitor
  printInt(gps.satellites.value(), gps.satellites.isValid(), 5);
  printInt(gps.hdop.value(), gps.hdop.isValid(), 5);
  printFloat(gps.location.lat(), gps.location.isValid(), 11, 6);
  printFloat(gps.location.lng(), gps.location.isValid(), 12, 6);
  printInt(gps.location.age(), gps.location.isValid(), 5);
  printDateTime(gps.date, gps.time);
  printFloat(gps.altitude.meters(), gps.altitude.isValid(), 7, 2);
  printFloat(gps.course.deg(), gps.course.isValid(), 7, 2);
  printFloat(gps.speed.kmph(), gps.speed.isValid(), 6, 2);
  printStr(gps.course.isValid() ? TinyGPSPlus::cardinal(gps.course.value()) : "*** ", 6);
  unsigned long distance = (unsigned long)TinyGPSPlus::distanceBetween(gps.location.lat(), gps.location.lng(), HIDDEN_PLACE_LAT, HIDDEN_PLACE_LON);
  printInt(distance, gps.location.isValid(), 9);
  double course = TinyGPSPlus::courseTo(gps.location.lat(), gps.location.lng(), HIDDEN_PLACE_LAT, HIDDEN_PLACE_LON);
  printFloat(course, gps.location.isValid(), 7, 2);
  const char *cardinal = TinyGPSPlus::cardinal(course);
  printStr(gps.location.isValid() ? cardinal : "*** ", 6);
  printInt(gps.charsProcessed(), true, 6);
  printInt(gps.sentencesWithFix(), true, 10);
  printInt(gps.failedChecksum(), true, 9);
  Serial.println();

  if(gps.location.isValid()){
    digitalWrite(13, HIGH); // indicate gps fix
    // display debug output on tft
    displayInfo(gps.location.lat(), gps.location.lng(),course, distance, gps.satellites.value());
    if(distance<500){
      if(!found){
        playTone(distance); //indicate remaining distance by pitch
      }
      if(distance<20){ // if within 20 meters of desired place
        displayFound(); //display a message
      }
    }
  }
}


static void playTone(int distance){
  int pitch = map(distance, 1, 500, 4978, 33); // tones are from B0 to DS8
  tone(7, pitch, 1000);
  delay(1500);
}

static void displayFound(){
  found = true;
  u8g.firstPage(); 
  do {
    u8g.setFont(u8g_font_5x7);
    u8g.setPrintPos(10,10);
    u8g.print("Wow, you found it!");
  }while(u8g.nextPage());
}

/* all methods below are just for printing out debug information */

static void printFloat(float val, bool valid, int len, int prec)
{
  if (!valid)
  {
    while (len-- > 1)
      Serial.print('*');
    Serial.print(' ');
  }
  else
  {
    Serial.print(val, prec);
    int vi = abs((int)val);
    int flen = prec + (val < 0.0 ? 2 : 1); // . and -
    flen += vi >= 1000 ? 4 : vi >= 100 ? 3 : vi >= 10 ? 2 : 1;
    for (int i=flen; i<len; ++i)
      Serial.print(' ');
  }
}

static void printInt(unsigned long val, bool valid, int len)
{
  char sz[32] = "*****************";
  if (valid)
    sprintf(sz, "%ld", val);
  sz[len] = 0;
  for (int i=strlen(sz); i<len; ++i)
    sz[i] = ' ';
  if (len > 0) 
    sz[len-1] = ' ';
  Serial.print(sz);
}

static void printDateTime(TinyGPSDate &d, TinyGPSTime &t)
{
  if (!d.isValid())
  {
    Serial.print(F("********** "));
  }
  else
  {
    char sz[32];
    sprintf(sz, "%02d/%02d/%02d ", d.month(), d.day(), d.year());
    Serial.print(sz);
  }
  
  if (!t.isValid())
  {
    Serial.print(F("******** "));
  }
  else
  {
    char sz[32];
    sprintf(sz, "%02d:%02d:%02d ", t.hour(), t.minute(), t.second());
    Serial.print(sz);
  }

  printInt(d.age(), d.isValid(), 5);
}

static void printStr(const char *str, int len)
{
  int slen = strlen(str);
  for (int i=0; i<len; ++i)
    Serial.print(i<slen ? str[i] : ' ');
}

static void displayInfo(float lt, float ln, double cour, long dist, int satellites){
  if(!found){
    static const char* directions[] = {"N", "NNE", "NE", "ENE", "E", "ESE", "SE", "SSE", "S", "SSW", "SW", "WSW", "W", "WNW", "NW", "NNW"};
    int direction = (int)((cour + 11.25f) / 22.5f);
    const char* toDisplay =  directions[direction % 16];
    u8g.firstPage(); 
    do {
      u8g.setPrintPos(0,7);
      u8g.print("Latitude");
      u8g.setPrintPos(60,7);
      u8g.print(lt,6);
      u8g.setPrintPos(0,15);
      u8g.print("Longitude");
      u8g.setPrintPos(60,15);
      u8g.print(ln,6);
      u8g.setPrintPos(0,23);
      u8g.print("Direction");
      u8g.setPrintPos(60,23);
      u8g.print(toDisplay);
      u8g.setPrintPos(0,30);
      u8g.print("Distance");
      u8g.setPrintPos(60,30);
      u8g.print(dist);
      u8g.setPrintPos(0,37);
      u8g.print("Satellites");
      u8g.setPrintPos(60,37);
      u8g.print(satellites);
    }while(u8g.nextPage());
  }
}



