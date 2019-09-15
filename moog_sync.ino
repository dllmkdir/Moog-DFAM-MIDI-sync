//important NOTE:
// This program has been crerated for the Arduino DUE.
// Even so, The Arduino Leonardo, Zero and Micro can support this program for native USB implementation
// I HIGHLY recommend to use a microcontroller with Native USB Port
//inspired from the buzzer example in :
//https://github.com/arduino-libraries/MIDIUSB/blob/master/examples/MIDIUSB_buzzer/MIDIUSB_buzzer.ino
//include the MIDIUSb library
#include "MIDIUSB.h"
//include the pitch to note library
#include "PitchToNote.h"
//config the initial project
void setup() {
    //We use just the PIN 13 to visualize the information through the built in LED
  pinMode(13, OUTPUT);
  //recommended Serial Baud Rate
   Serial.begin(115200);
}

void loop() {
    //Recieve information through the MIDI USB port
  midiEventPacket_t rx = MidiUSB.read();
  //check for the rx header information
  switch (rx.header) {
    case 0:
    //avoid empty event loop
      break; 
    case 0x9:
      digitalWrite(13, LOW);
      break;
      
    case 0x8:
      digitalWrite(13, HIGH);
      break;
     default:
     
      Serial.print("Unhadled message");
    //   Serial.print(rx.header, HEX);
    //   Serial.print("-");
    //   Serial.print(rx.byte1, HEX);
    //   Serial.print("-");
    //   Serial.print(rx.byte2, HEX);
    //   Serial.print("-");
    //   Serial.println(rx.byte3, HEX);
  }
}
//not used in this project, but important if you want to communicate date to the Computer...
//control change registrer pitch bends and different potentiometer events that can be mapped into MIDI range
void controlChange(byte channel, byte control, byte value) {
  midiEventPacket_t event = {0x0B, 0xB0 | channel, control, value};
  MidiUSB.sendMIDI(event);
  MidiUSB.flush();
}

//note on TX function
void noteOn(byte channel, byte pitch, byte velocity) {
  midiEventPacket_t noteOn = {0x09, 0x90 | channel, pitch, velocity};
  MidiUSB.sendMIDI(noteOn);
   MidiUSB.flush();//remember flushing!
}
//note off TX function
void noteOff(byte channel, byte pitch, byte velocity) {
  midiEventPacket_t noteOff = {0x08, 0x80 | channel, pitch, velocity};
  MidiUSB.sendMIDI(noteOff);
   MidiUSB.flush();//remember flushing!
}