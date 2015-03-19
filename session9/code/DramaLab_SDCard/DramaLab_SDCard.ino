/*
 * DramaLab_SDCard: Shows how to work with the SD-Card shield by performing a few operations.
 * It shows the current files and directories (recursive) and creates a text file.
 * Wiring: Shield --> Arduino 
 *           MOSI --> D11
 *           MISO --> D12
 *           CLK  --> D13
 *           CS   --> D4
 * http://dramalab.unibz.it/
 * Max Stricker, 21.03.2015	 
 */
#include <SD.h>

int PIN_MOSI = 11;
int PIN_MISO = 12;
int PIN_CLK = 13;
int PIN_CS = 4;

File root;

void setup()
{
  Serial.begin(9600);
  Serial.print("Initializing SD card...");
  // Note that even if it's not used as the CS pin, the hardware SS pin 
  // (10 on most Arduino boards, 53 on the Mega) must be left as an output 
  // or the SD library functions will not work. 
  pinMode(10, OUTPUT);
  if (!SD.begin(PIN_CS)) {
    Serial.println("initialization failed!");
    return;
  }
  Serial.println("initialization done.");

  root = SD.open("/");
  Serial.println("Directory structure:");
  printDirectory(root, 0);
  
  Serial.println("Writing test file");
  File myFile = SD.open("test.txt", FILE_WRITE);
  
  // if the file opened okay, write to it:
  if (myFile) {
    Serial.print("Writing to test.txt...");
    myFile.println("testing 1, 2, 3.");
    myFile.close();
    Serial.println("done.");
  } else {
    Serial.println("error opening test.txt");
  }
  Serial.println("Reading written content");
  // re-open the file for reading:
  myFile = SD.open("test.txt");
  if (myFile) {
    Serial.println("test.txt:");
    
    // read from the file until there's nothing else in it:
    while (myFile.available()) {
    	Serial.write(myFile.read());
    }
    myFile.close();
    SD.remove("test.txt");
    Serial.println("removed test.txt");
  } else {
    Serial.println("error opening test.txt");
  }
}

void loop()
{
  // nothing happens after setup finishes.
}

void printDirectory(File dir, int numTabs) {
   while(true) {
     
     File entry =  dir.openNextFile();
     if (! entry) {
       // no more files
       break;
     }
     for (uint8_t i=0; i<numTabs; i++) {
       Serial.print('\t');
     }
     Serial.print(entry.name());
     if (entry.isDirectory()) {
       Serial.println("/");
       printDirectory(entry, numTabs+1);
     } else {
       // files have sizes, directories do not
       Serial.print("\t\t");
       Serial.println(entry.size(), DEC);
     }
     entry.close();
   }
}



