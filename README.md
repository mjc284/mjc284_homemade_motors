# mjc284_repurposing_stators
Building homemade AC and DC motors by repurposing old stators and rotors.

![Front](/photos/front.jpeg "Front")

### Video demonstration:
https://www.youtube.com/watch?v=WFz_ZSToyOA

### Objective:
This project consists of three motors made of a repurposed drill motor rotor, a drill motor stator, and a fan motor stator respectively. All the repurposed parts were slavaged from broken electronics. The drill rotor was driven by providing PWM pulses through an H-bridge and through the slip ring, with a strong permanent magnet under the rotor to provide the magnetic field. 

![Front](/photos/front.jpeg "Front")

The drill motor stator was driven as a 2-pole AC motor by alternating the current through the coils with an H-bridge. Although this type of motor is not practical without a starting coil, the setup still managed to demonstrate that the rotor would turn half of the time clockwise and the other half counter-clockwise.

![Front](/photos/front.jpeg "Front")

The fan stator was that of an 8-pole AC motor. However, there were three output wires consisting of two for each coil phases and one for common. Therefore, all three legs of the inverter used and the coil excitation sequence was programmed.

![Front](/photos/front.jpeg "Front")

### Project Workflow:
- All the hardware and circuit were modelled using Fusion 360.
- Some of the parts were milled from 6mm MDF using a desktop-CNC. 
- 3D-printed some of the parts with postprocessing from Ultimaker-Cura.
- PCB was manufactured from the Fusion 360 gerber file by Chinese PCB services.
- Arduino-pro mini was programmed and used to drive the circuit.
