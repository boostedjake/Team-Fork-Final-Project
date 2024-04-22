// note durations: 4 = quarter note, 8 = eighth note, etc.:
int noteDurations[] = {
  4, 8, 8, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4
};

#include "pitches.h"

// Define the pins
#define PIEZO_PIN 8

// Define the frequencies of the notes
#define NOTE_D4  294
#define NOTE_C4  262
#define NOTE_F3  175
#define NOTE_G3  196

// Define the durations of the notes
#define NOTE_DURATION 200

void setup() {
  // Set the piezo pin as an output
  pinMode(PIEZO_PIN, OUTPUT);
}

void loop() {
  // Play the sequence of notes
  playNote(NOTE_D4);
  playNote(NOTE_D4);
  playNote(NOTE_D4);
  playNote(NOTE_C4);
  playNote(NOTE_D4);
  playNote(NOTE_F3);
  playNote(NOTE_F3);
  playNote(NOTE_G3);
  playNote(NOTE_F3);
  playNote(NOTE_G3);
  playNote(NOTE_F3);
}

// Function to play a note
void playNote(int note) {
  tone(PIEZO_PIN, note, NOTE_DURATION);
  delay(NOTE_DURATION * 1.3); // add a delay between notes for spacing
}
