# Moog-DFAM-MIDI-sync
Moog DFAM MIDI synchronization using Arduino.
You can configure your own **MOOG DFAM** to synchronize with your computer, using just an Arduino.

## Advice and Findings
Read carefully the Voltage Input Specs before implementing this solution.

We HIGHLY ENCOURAGE using an **Arduino Due** or Native USB Port options (Due, Leonardo, Zero, Micro) to recieve MIDI information.

Most of the non-USB-native microcontrollers need to use the Serial Port with [Hairless](https://projectgus.github.io/hairless-midiserial/).

Hairless is a program to communicate MIDI information, but it is not a robust solution to implement.

Hairless crashes, has multiple errors and can even freeze computers. In action, Hairless is more like a testing toy than a good way to mantain 

MIDI communication. Also, it creates huge lag gaps.

Current is not a big problem for the DFAM, because the input and output work with buffers to decouple impedance.

## Instructions
Using the libraries provided by the Arduino Team: 

[https://github.com/arduino-libraries/MIDIUSB](https://github.com/arduino-libraries/MIDIUSB)


First, download the MIDUSB library available on Arduino. (version 1.0.3 is recommended)

We added the main src folder of this library just for reference. These are the most important files on the library.

Open The Arduino App and copy the code from the **"moog_sync.ino"** file.

Compile the Program, Upload it and you are good to go.

The Eagle Board is also included.

You can observe how the circuit needs to be configured in order to operate.

![Eagle Circuit](https://raw.githubusercontent.com/dllmkdir/Moog-DFAM-MIDI-sync/master/diagram.png)

Connect the Arduino to the Native USB Port and configure the MIDI output in your Favorite DAW.

The device must appear as `Arduino Due`.

After this, the MIDI trigger signal must be there. Check out if the Built-in LED reacts to the incoming MIDI Impulse.

I HIGHLY ENCOURAGE also to measure output voltage before connecting to the **Moog DFAM**. At least, it is incredibly expensive to just crash the whole device.

You must be getting voltages across 0.1 and 5 V.

Finally, Create a MIDI Track and send any note to trigger the MOOG DFAM.

Observe that the incoming note must be in a short duration to avoid multiple false triggers.





