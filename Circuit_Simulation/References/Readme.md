## Atmega 8 --> board

### Oscillators 
- Oscillators move back and forth to generate pulses
- atmega 8 has onchip 8 MHz oscillator but some times its inaccuarate 
- hence to extend the frequency we use external oscillator 
- external oscillators require load capacitors 
	- recomended values are between <b>2 pf to 22pf</b>

### Decoupling capacitors 
- Decople the IC power pins from rest of the circuit or the supply 
- smaller loads like ICs needs from 100nF to 1000nF
- larger loads might require hundreds of microfarads 
- Def : 
	- In electronics, a decoupling capacitor is a capacitor used to decouple (i.e. prevent electrical energy from transferring to) one part of a circuit from another. <br>Noise caused by other circuit elements is shunted through the capacitor, <br>reducing its effect on the rest of the circuit.

### Terminologies 

- Floating pin : 
	- Pin with nothing connected
	- EMI causes such pins to produce noise 

- Pull-up Resistors 
	- pulls the resistor to a known state
	- A pull-up resistor is added before switch to avoid the randome switching of the switch 
	- add a 5 V supply with resistor before the switch 
	- this causes 
		- <b>HI : NOT PRESSED (1)</b>
		- <b>LO : Pressed (0)</b>
	- General values between 1Kohms to 100KOhms
