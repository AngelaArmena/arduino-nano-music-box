#include <Arduino.h>
#include <EEPROM.h>

// Define the passive buzzer pin
int buzzerPin = 4;
int ledPin = 10;
int groundPin = 7;

// Define the notes
#define NOTE_C2 65
#define NOTE_CS2 69
#define NOTE_D2 73
#define NOTE_DS2 78
#define NOTE_E2 82
#define NOTE_F2 87
#define NOTE_FS2 93
#define NOTE_G2 98
#define NOTE_GS2 104
#define NOTE_A2 110
#define NOTE_AS2 117
#define NOTE_B2 123
#define NOTE_C3 131
#define NOTE_CS3 139
#define NOTE_D3 147
#define NOTE_DS3 156
#define NOTE_E3 165
#define NOTE_F3 175
#define NOTE_FS3 185
#define NOTE_G3 196
#define NOTE_GS3 208
#define NOTE_A3 220
#define NOTE_AS3 233
#define NOTE_B3 247
#define NOTE_C4 262
#define NOTE_CS4 277
#define NOTE_D4 294
#define NOTE_DS4 311
#define NOTE_E4 330
#define NOTE_F4 349
#define NOTE_FS4 370
#define NOTE_G4 392
#define NOTE_GS4 415
#define NOTE_A4 440
#define NOTE_AS4 466
#define NOTE_B4 494
#define NOTE_C5 523
#define NOTE_CS5 554
#define NOTE_D5 587
#define NOTE_DS5 622
#define NOTE_E5 659
#define NOTE_F5 698
#define NOTE_FS5 740
#define NOTE_G5 784
#define NOTE_GS5 831
#define NOTE_A5 880
#define NOTE_AS5 932
#define NOTE_B5 988
#define NOTE_C6 1047
#define NOTE_CS6 1109
#define NOTE_D6 1175
#define NOTE_DS6 1245
#define NOTE_E6 1319
#define NOTE_F6 1397
#define NOTE_FS6 1480
#define NOTE_G6 1568
#define NOTE_GS6 1661
#define NOTE_A6 1760
#define NOTE_AS6 1865
#define NOTE_B6 1976

// Define a struct to hold melody and note duration
struct MelodyData {
  const int *melody;
  const int *noteDurations;
  int size;
};

//CHRISTMAS IN OUR HEARTS
const int melody_ChristmasInOurHearts[] PROGMEM = {
  NOTE_C5, NOTE_F5, NOTE_F5, NOTE_G5, NOTE_G5, NOTE_A5,
  NOTE_A4, NOTE_C5, NOTE_AS4, NOTE_D5, NOTE_G5, NOTE_A5, NOTE_AS5, 0,
  NOTE_D4, NOTE_E4, NOTE_F4, NOTE_D4, NOTE_E4, NOTE_F4, NOTE_D4, NOTE_E4, NOTE_F4, NOTE_G4, NOTE_F4, NOTE_E4, NOTE_F4, 
  NOTE_D4, NOTE_E4, NOTE_F4, NOTE_D4, NOTE_E4, NOTE_F4, NOTE_D4, NOTE_E4, NOTE_F4, NOTE_G4, NOTE_F4, NOTE_E4, NOTE_F4,
  NOTE_D4, NOTE_A4, NOTE_AS4, NOTE_A4, NOTE_G4, NOTE_F4, NOTE_G4, NOTE_A4, NOTE_G4, NOTE_A4, NOTE_AS4, NOTE_A4, NOTE_G4, NOTE_F4, NOTE_E4,
  NOTE_E4, NOTE_F4, NOTE_G4, NOTE_G4, NOTE_A4, NOTE_G4, 0,
  NOTE_A4, NOTE_AS4, NOTE_A4, NOTE_G4, NOTE_F4, NOTE_G4, NOTE_A4, 0, 
  NOTE_D4, NOTE_A4, NOTE_A4, NOTE_A4, NOTE_F4, NOTE_AS4, NOTE_A4, 0,
  NOTE_AS4, NOTE_A4, NOTE_D5, NOTE_D5, NOTE_A4, NOTE_C5, NOTE_AS4,
  NOTE_G4, NOTE_A4, NOTE_AS4, NOTE_C5, NOTE_AS4, NOTE_A4, 0,
  NOTE_E4, NOTE_A4, NOTE_G4, NOTE_F4, NOTE_E4, NOTE_D4, 0,
  NOTE_D4, NOTE_C4, NOTE_E4, NOTE_F4, NOTE_G4, NOTE_A4, 
  NOTE_E4, NOTE_F4, NOTE_G4, NOTE_C4, NOTE_AS4, NOTE_A4, 0,
  NOTE_D4, NOTE_C4, NOTE_E4, NOTE_F4, NOTE_G4, NOTE_A4, 
  NOTE_A4, NOTE_GS4, NOTE_A4, NOTE_B4, 0, NOTE_C5, NOTE_C5, 0,
  NOTE_C4, NOTE_A3, NOTE_C4, NOTE_F4, NOTE_G4, NOTE_A4, 0,
  NOTE_A3, NOTE_C4, NOTE_AS3, NOTE_D4, NOTE_G4, NOTE_A4, NOTE_AS4,
  NOTE_F4, NOTE_E4, NOTE_D4, NOTE_E4, NOTE_F4, NOTE_G4, NOTE_G4, NOTE_A4, NOTE_G4, 0, 
  NOTE_F4, NOTE_E4, NOTE_F4, NOTE_E4, NOTE_D4, NOTE_D4, NOTE_C4, 0, 
  NOTE_C4, NOTE_AS3, NOTE_A3, NOTE_C4, NOTE_F4, NOTE_G4, NOTE_G4, NOTE_A4, 0,
  NOTE_A3, NOTE_C4, NOTE_AS3, NOTE_D4, NOTE_G4, NOTE_A4, NOTE_AS4,
  NOTE_F4, NOTE_E4, NOTE_D4, NOTE_E4, NOTE_E4, NOTE_F4, NOTE_G4, NOTE_C4, 0,
  NOTE_C4, NOTE_AS4, NOTE_AS4, NOTE_A4, NOTE_G4, NOTE_F4, 0,
  NOTE_C4, NOTE_AS4, NOTE_AS4, NOTE_A4, 0, NOTE_G4, NOTE_F4
};
const int noteDurations_ChristmasInOurHearts[] PROGMEM = {
  3, 3, 3, 3, 3, 1,
  5, 5, 3, 3, 3, 3, 1, 3,
  3, 6, 6, 3, 6, 6, 3, 6, 6, 6, 6, 6, 6,
  3, 6, 6, 3, 6, 6, 3, 6, 6, 6, 6, 6, 6,
  3, 2, 5, 3, 3, 3, 3, 3, 6, 6, 3, 3, 2, 5, 1,
  5, 5, 2, 2, 5, 2, 2,
  5, 5, 3, 3, 3, 3, 2, 3,
  3, 3, 3, 3, 3, 3, 2, 8,
  5, 5, 3, 3, 3, 3, 1,
  5, 5, 1, 3, 3, 3, 4,
  3, 3, 3, 3, 3, 2, 4,
  3, 3, 3, 3, 3, 1, 
  5, 5, 1, 3, 3, 2, 5,
  3, 3, 3, 3, 3, 1, 
  3, 3, 3, 1, 3, 2, 1, 2, 
  3, 3, 1, 3, 3, 3, 4, 
  5, 5, 3, 3, 3, 3, 1,
  3, 3, 3, 3, 3, 3, 5, 5, 3, 5,
  5, 2, 5, 3, 3, 3, 3, 3,
  5, 5, 3, 3, 3, 3, 3, 2, 5,
  5, 5, 3, 3, 3, 3, 1,
  3, 3, 3, 5, 5, 3, 3, 2, 3,
  3, 3, 3, 3, 3, 1, 2,
  2, 2, 2, 1, 3, 2, 1
};
//HOWL'S MOVING CASTLE THEME
const int melody_HowlsMovingCastleTheme[] PROGMEM = {
  NOTE_D5, NOTE_D5, NOTE_D5, NOTE_C5, NOTE_C5, NOTE_C5, NOTE_AS4, NOTE_AS4, NOTE_AS4, NOTE_A4, NOTE_G4, NOTE_FS4,
  NOTE_D2, NOTE_A2, NOTE_D3, NOTE_FS3, NOTE_A3, NOTE_D4,
  NOTE_D4, NOTE_G4, NOTE_AS4, NOTE_D5,
  NOTE_D5, NOTE_C5, NOTE_AS4, NOTE_A4, NOTE_AS4, 
  NOTE_G4, NOTE_AS4, NOTE_D5, NOTE_G5,
  NOTE_G5, NOTE_G5, NOTE_F5, NOTE_DS5, NOTE_F5,
  NOTE_A4, NOTE_D5, NOTE_F5, NOTE_A5, 
  NOTE_G5, NOTE_F5, NOTE_E5, NOTE_F5, NOTE_G5, NOTE_F5, NOTE_E5,
  NOTE_D5, NOTE_C5, NOTE_AS4, NOTE_C5, NOTE_D5, NOTE_C5, NOTE_G4, NOTE_A4,
  NOTE_D4, NOTE_G4, NOTE_AS4, NOTE_D5,
  NOTE_D5, NOTE_C5, NOTE_AS4, NOTE_A4, NOTE_AS4, 
  NOTE_G4, NOTE_AS4, NOTE_D5, NOTE_G5,
  NOTE_G5, NOTE_G5, NOTE_F5, NOTE_DS5, NOTE_F5,
  NOTE_A4, NOTE_D5, NOTE_F5, NOTE_A5,
  NOTE_G5, NOTE_F5, NOTE_E5, NOTE_DS5, NOTE_E5, NOTE_G5, NOTE_F5, 
  NOTE_E5, NOTE_D5, NOTE_CS5, NOTE_D5, NOTE_D5, NOTE_C5, NOTE_AS4, NOTE_A4, NOTE_C5, NOTE_CS5, NOTE_D5,
};
const int noteDurations_HowlsMovingCastleTheme[] PROGMEM = {
  3, 3, 3, 3, 3, 3, 3, 3, 3, 5, 5, 1,
  3, 3, 3, 3, 3, 1, 
  3, 3, 3, 1,
  3, 3, 3, 3, 1,
  3, 3, 3, 1, 
  3, 3, 3, 3, 1,
  3, 3, 3, 1, 
  3, 3, 3, 3, 1, 3, 1,
  3, 3, 3, 3, 3, 3, 3, 1,
  3, 3, 3, 1,
  3, 3, 3, 3, 1,
  3, 3, 3, 1, 
  3, 3, 3, 3, 1,
  3, 3, 3, 1, 
  1, 5, 5, 5, 5, 1, 1, 
  5, 5, 5, 5, 2, 5, 4, 2, 5, 4, 1,
};
//I SEE THE LIGHT
const int melody_iSeeTheLight[] PROGMEM = {
  NOTE_G4, NOTE_F4, NOTE_E4, NOTE_D4, NOTE_E4, NOTE_D4, NOTE_B3, NOTE_C4, NOTE_G3,
  NOTE_G4, NOTE_F4, NOTE_E4, NOTE_D4, NOTE_E4, NOTE_D4, NOTE_B3, NOTE_C4,
  NOTE_A4, NOTE_G4, NOTE_F4, NOTE_G4, NOTE_C5, NOTE_G4, NOTE_C4, NOTE_E4, NOTE_D4,
  NOTE_G4, NOTE_F4, NOTE_E4, NOTE_C4, NOTE_D4, 0,
  NOTE_G4, NOTE_F4, NOTE_E4, NOTE_D4, NOTE_E4, NOTE_D4, NOTE_B3, NOTE_C4, NOTE_G3,
  NOTE_G4, NOTE_F4, NOTE_E4, NOTE_D4, NOTE_E4, NOTE_D4, NOTE_B3, NOTE_C4,
  NOTE_A4, NOTE_G4, NOTE_F4, NOTE_G4, NOTE_C5, NOTE_G4, NOTE_C4, NOTE_E4, NOTE_D4,
  NOTE_G4, NOTE_F4, NOTE_E4, NOTE_C4, NOTE_D4,
  NOTE_B3,
  NOTE_A4, NOTE_G4, NOTE_F4, NOTE_C4, NOTE_B4, NOTE_A4, NOTE_G4,
  NOTE_C4, NOTE_C5, NOTE_B4, NOTE_A4, NOTE_E4, NOTE_G4,
  NOTE_A3, NOTE_B3,
  NOTE_A4, NOTE_B4, NOTE_C5, NOTE_F4, NOTE_F4, NOTE_E4, NOTE_G4,
  NOTE_C4, NOTE_D4, NOTE_D4, NOTE_D4, NOTE_G4, NOTE_F4, NOTE_F4, NOTE_E4,
  NOTE_A4, NOTE_B4, NOTE_C5, NOTE_F4, NOTE_F4, NOTE_E4, NOTE_G4,
  NOTE_C4, NOTE_D4, NOTE_E4, NOTE_F4, NOTE_E4, NOTE_D4, NOTE_C4,
  NOTE_A4, NOTE_B4, NOTE_C5, NOTE_F4, NOTE_F4, NOTE_E4, NOTE_G4,
  NOTE_C4, NOTE_D4, NOTE_E4, NOTE_F4, NOTE_E4, NOTE_D4, NOTE_D4, NOTE_C4,
};
const int noteDurations_iSeeTheLight[] PROGMEM = {
  2, 2, 1, 5, 3, 6, 6, 5, 1,
  2, 2, 1, 5, 3, 6, 6, 1,
  2, 2, 1, 4, 4, 4, 4, 2, 2,
  2, 3, 2, 2, 1, 1,
  2, 2, 1, 5, 3, 6, 6, 5, 1,
  2, 2, 1, 5, 3, 6, 6, 1,
  2, 2, 1, 4, 4, 4, 4, 2, 2,
  2, 3, 2, 2, 1,
  1,
  2, 2, 1, 4, 2, 2, 1,
  4, 1, 4, 1, 4, 1,
  2, 2,
  4, 4, 2, 2, 1, 3, 1,
  4, 4, 1, 4, 1, 4, 3, 1,
  4, 4, 2, 2, 1, 3, 1,
  4, 4, 1, 4, 2, 2, 1,
  4, 4, 2, 2, 1, 3, 1,
  4, 4, 1, 4, 2, 2, 2, 1,
};
//YELLOW
const int melody_Yellow[] PROGMEM = {
  NOTE_D5, NOTE_E5, NOTE_D5, NOTE_E5,
  NOTE_D5, NOTE_E5, NOTE_D5, NOTE_E5, NOTE_G5, NOTE_D5, 0, 
  NOTE_D5, NOTE_C5, NOTE_D5, 0, NOTE_G5, NOTE_C5, 0,
  NOTE_A4, NOTE_C5, NOTE_A4, NOTE_C5, NOTE_C5, NOTE_G4, 0,
  NOTE_G4, NOTE_E5, NOTE_D5, NOTE_E5,
  NOTE_D5, NOTE_E5, NOTE_D5, NOTE_E5, NOTE_G5, NOTE_D5, 0, 
  NOTE_C5, NOTE_D5, NOTE_C5, NOTE_D5, NOTE_G5, NOTE_C5, 0,
  NOTE_A4, NOTE_C5, NOTE_A4, NOTE_C5, NOTE_C5, NOTE_G4, 0,
  NOTE_D5, NOTE_E5, NOTE_D5, NOTE_E5, NOTE_G5, NOTE_D5, 0,
  NOTE_C5, NOTE_D5, NOTE_C5, NOTE_D5, NOTE_G5, NOTE_C5, 0,
  NOTE_A4, NOTE_C5, NOTE_A4, NOTE_C5, NOTE_C5, NOTE_G4,
  0, 0, 0,
  NOTE_C5, NOTE_A5, NOTE_G5, NOTE_C5, NOTE_C5, NOTE_G5, NOTE_G5, NOTE_E5, NOTE_E5, 0,
  NOTE_C5, NOTE_A5, NOTE_G5, NOTE_C5, NOTE_C5, NOTE_G5, NOTE_G5, NOTE_E5, NOTE_E5, 0,
  NOTE_C5, NOTE_A5, NOTE_G5, NOTE_C5, NOTE_C5, NOTE_G5, NOTE_G5, NOTE_E5, NOTE_E5, NOTE_C5, NOTE_A4, 0,
  NOTE_C5, NOTE_C5, NOTE_G5, NOTE_G5, NOTE_E5, NOTE_E5, NOTE_C5, NOTE_A4
};
const int noteDurations_Yellow[] PROGMEM = {
  4, 4, 4, 1,
  4, 4, 4, 3, 2, 1, 3,
  4, 4, 4, 8, 3, 1, 3,
  7, 7, 7, 3, 5, 2, 6,
  4, 4, 4, 1, 
  4, 4, 4, 3, 2, 1, 3,
  4, 4, 4, 4, 4, 1, 2,
  7, 7, 7, 3, 5, 2, 1,
  4, 4, 4, 4, 2, 1, 6,
  4, 4, 4, 4, 4, 1, 2,
  7, 7, 7, 3, 5, 3,
  1, 1, 3,
  3, 1, 2, 4, 4, 4, 4, 4, 3, 3,
  3, 1, 2, 4, 4, 4, 4, 4, 3, 3,
  3, 1, 2, 4, 4, 4, 4, 4, 3, 5, 1, 4,
  4, 4, 4, 4, 4, 4, 4, 1
};
//MARRIED LIFE
const int melody_MarriedLife[] PROGMEM = {
  NOTE_F4, NOTE_A4, NOTE_F4, NOTE_E4, 0,
  NOTE_F4, NOTE_A4, NOTE_E4, NOTE_D4, 0,
  NOTE_D4, NOTE_F4, NOTE_D4, NOTE_C4, 0,
  NOTE_D4, NOTE_A4, NOTE_G4, NOTE_D4, NOTE_A4, NOTE_G4, NOTE_F4, NOTE_D4, 0,
  NOTE_F4, NOTE_G4, NOTE_F4, NOTE_E4,
  NOTE_E4, NOTE_G4, NOTE_E4, NOTE_C4,
  NOTE_C4, NOTE_E4, NOTE_C4, NOTE_AS3, 0,
  NOTE_AS3, NOTE_C4, NOTE_AS3, 0,
  NOTE_A3, NOTE_AS3, NOTE_C4, NOTE_D4, NOTE_E4,
  NOTE_C4, NOTE_D4, NOTE_E4, 0,
  NOTE_F5, NOTE_A5, NOTE_F5, NOTE_E5, 0,
  NOTE_F5, NOTE_A5, NOTE_E5, NOTE_D5, 0,
  NOTE_F5, NOTE_A5, NOTE_D6, NOTE_E6, 0,
  NOTE_D6, NOTE_F6, NOTE_E6, 0, NOTE_D6, NOTE_A5, NOTE_B5, NOTE_D6, NOTE_F6, 0,
  NOTE_E6, NOTE_DS6, NOTE_D6, 0, 
  NOTE_F6, 0, NOTE_G6, 0, NOTE_F6, 0, NOTE_E6, 0,
  NOTE_E6, NOTE_G6, NOTE_E6, NOTE_C6, 0,
  NOTE_C6, NOTE_E6, NOTE_C6, NOTE_AS5, 0,
  NOTE_AS5, NOTE_C6, NOTE_AS5, NOTE_A5, NOTE_AS5, 0,
  NOTE_C6, 0, NOTE_D6, NOTE_E6, NOTE_C6, NOTE_D6, NOTE_E6, 0, NOTE_F6, NOTE_G6, NOTE_F6
};
const int noteDurations_MarriedLife[] PROGMEM = {
  3, 3, 3, 1, 2, 
  3, 3, 3, 2, 4, 
  3, 3, 3, 1, 1, 
  3, 3, 2, 3, 3, 2, 3, 1, 2,
  3, 3, 3, 1,
  3, 3, 3, 2, 
  3, 3, 3, 2, 3,
  4, 4, 3, 3,
  3, 3, 2, 4, 2,
  3, 3, 1, 2,
  4, 4, 4, 1, 1, 
  4, 4, 4, 2, 5,
  6, 5, 4, 1, 2,
  4, 3, 3, 7, 4, 3, 2, 4, 1, 2,
  15, 15, 2, 1,
  4, 12, 4, 12, 4, 8, 1, 4, 
  4, 4, 4, 2, 4,
  4, 3, 6, 3, 3,
  4, 4, 4, 2, 4, 6, 
  2, 5, 3, 2, 3, 3, 2, 8, 3, 2, 1
};
const int melody_AlmostThere[] PROGMEM = {
  NOTE_E5, NOTE_DS5, NOTE_E5, NOTE_A5, NOTE_G5, NOTE_E5, NOTE_C5,
  NOTE_DS4, NOTE_D4, NOTE_C4, NOTE_A3, NOTE_C4, NOTE_A3, NOTE_D4, NOTE_A3, NOTE_A3, NOTE_G3,
  NOTE_DS5, NOTE_E5, 0,
  NOTE_E4, NOTE_G4, NOTE_C5, NOTE_A4, NOTE_G4, NOTE_G4, NOTE_G4, NOTE_E4, 0,
  NOTE_E3, NOTE_A3, NOTE_C4, NOTE_C4, NOTE_E4, NOTE_D4,
  NOTE_A4, NOTE_G4, NOTE_G4, NOTE_G4, NOTE_A4, NOTE_G4, NOTE_E4, NOTE_D4, NOTE_C4, NOTE_C4, NOTE_A3, NOTE_C4, NOTE_C4, NOTE_A3, NOTE_E4, NOTE_C4, NOTE_D4, 0,
  NOTE_C4, NOTE_A4, NOTE_G4, NOTE_G4, NOTE_E4, NOTE_A4, NOTE_G4, NOTE_E4, NOTE_D4, NOTE_C4, NOTE_C4, NOTE_A3, 0,
  NOTE_A4, NOTE_A4, NOTE_A4, NOTE_A4, NOTE_A4, NOTE_G4, NOTE_G4,
  NOTE_E5, NOTE_G5, NOTE_E5, NOTE_A5, 0, NOTE_A5, NOTE_A5,
  NOTE_A4, NOTE_C5, NOTE_C5, NOTE_E5, NOTE_D5, NOTE_C5, NOTE_A4,
  NOTE_A5, NOTE_G5, NOTE_A5, NOTE_A5, NOTE_G5, NOTE_A5, NOTE_E5, NOTE_C5,
  NOTE_A4, NOTE_C5, 0, NOTE_E5, NOTE_D5,
  NOTE_A5, NOTE_G5, NOTE_A5, NOTE_G5, NOTE_A5, NOTE_A5, 0,
  NOTE_A4, NOTE_C5, NOTE_E5, NOTE_D5,
  NOTE_A5, NOTE_G5, NOTE_G5, NOTE_A5, NOTE_G5, NOTE_A5, NOTE_G5, NOTE_E5, NOTE_D5, NOTE_C5,
  NOTE_C5, NOTE_A4, NOTE_C5, 0, NOTE_C5, NOTE_C5
};
const int noteDurations_AlmostThere[] PROGMEM = {
  2, 2, 2, 8, 8, 8, 2,
  5, 3, 10, 10, 5, 5, 3, 10, 5, 2,
  5, 2, 3,
  3, 3, 2, 5, 5, 5, 5, 2, 3,
  5, 5, 3, 5, 3, 1,
  5, 3, 2, 5, 2, 5, 10, 10, 5, 5, 5, 5, 5, 5, 2, 5, 1, 2, 
  5, 3, 5, 2, 5, 3, 3, 10, 10, 3, 5, 5, 5,
  3, 5, 3, 3, 3, 5, 3, 
  6, 6, 6, 2, 5, 2, 1,
  6, 3, 3, 2, 3, 6, 1,
  6, 6, 3, 3, 6, 3, 3, 2,
  6, 2, 8, 3, 1, 
  1, 6, 6, 6, 2, 1, 3,
  3, 3, 6, 1,
  7, 7, 3, 3, 7, 3, 7, 7, 7, 3, 
  7, 6, 2, 8, 2, 1
};

// Create an array of MelodyData structures
const MelodyData melodies[] PROGMEM = {
  {melody_ChristmasInOurHearts, noteDurations_ChristmasInOurHearts, sizeof(melody_ChristmasInOurHearts) / sizeof(melody_ChristmasInOurHearts[0])},
  {melody_HowlsMovingCastleTheme, noteDurations_HowlsMovingCastleTheme, sizeof(melody_HowlsMovingCastleTheme) / sizeof(melody_HowlsMovingCastleTheme[0])},
  {melody_iSeeTheLight, noteDurations_iSeeTheLight, sizeof(melody_iSeeTheLight) / sizeof(melody_iSeeTheLight[0])},
  {melody_Yellow, noteDurations_Yellow, sizeof(melody_Yellow) / sizeof(melody_Yellow[0])},
  {melody_MarriedLife, noteDurations_MarriedLife, sizeof(melody_MarriedLife) / sizeof(melody_MarriedLife[0])},
  {melody_AlmostThere, noteDurations_AlmostThere, sizeof(melody_AlmostThere) / sizeof(melody_AlmostThere[0])}
};

void setup() {
  // Initialize the buzzer pin as an output
  pinMode(buzzerPin, OUTPUT);
  pinMode(ledPin, OUTPUT);
  pinMode(groundPin, OUTPUT);
  digitalWrite(groundPin, LOW);

  // Read the value of the counter from EEPROM on startup
  int songCounter = EEPROM.read(0);
  songCounter = (songCounter + 1) % (sizeof(melodies) / sizeof(melodies[0]));
  EEPROM.write(0, songCounter);
}

void loop() {
  int songCounter = EEPROM.read(0);

  MelodyData melodyData;
  memcpy_P(&melodyData, &melodies[songCounter], sizeof(melodyData));

  playMelody(melodyData.melody, melodyData.noteDurations, melodyData.size);

  delay(2000); // Wait before playing the melody again
}

void playMelody(const int *melody, const int *noteDurations, int melodySize) {
  for (int i = 0; i < melodySize; i++) {
    int singingNoteDuration = 1000 / pgm_read_word(&noteDurations[i]);
    int ledLightDuration = singingNoteDuration * 0.75;

    tone(buzzerPin, pgm_read_word(&melody[i]), singingNoteDuration);

    if (pgm_read_word(&melody[i]) != 0) {
      digitalWrite(ledPin, HIGH);
    }

    unsigned long LEDStartTime = millis();
    while (millis() - LEDStartTime < ledLightDuration) {
      // Keep the LED on for half the note duration
    }

    noTone(buzzerPin);
    digitalWrite(ledPin, LOW);

    int pauseBetweenNotes = singingNoteDuration * 0.5;
    delay(pauseBetweenNotes);
  }
}
