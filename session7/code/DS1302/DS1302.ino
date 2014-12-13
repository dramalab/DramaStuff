#include <stdio.h>
#include <string.h>
#include <DS1302.h>

uint8_t CE_PIN   = 5;
uint8_t IO_PIN   = 3;
uint8_t SCLK_PIN = 4;

/* Create buffers */
char buf[50];
char day[10];

/* Create a DS1302 object */
DS1302 rtc(CE_PIN, IO_PIN, SCLK_PIN);


void print_time()
{
  /* Get the current time and date from the chip */
  Time t = rtc.time();

  /* Format the time and date and insert into the temporary buffer */
  snprintf(buf, sizeof(buf), "%04d-%02d-%02d %02d:%02d:%02d",
           t.yr, t.mon, t.date,
           t.hr, t.min, t.sec);

  /* Print the formatted string to serial so we can see the time */
  Serial.println(buf);
}

void setup(){
  delay(2000);
  Serial.begin(9600);

  /* Make a new time object to set the date and time */
  Time t(2012, 12, 9, 10, 15, 37, 7);

  /* Set the time and date on the chip */
  rtc.time(t);
}

void loop(){
  print_time();
  delay(1000);
}
