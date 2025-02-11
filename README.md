# Standing Desk 

## Overview  
The **Standing Desk** is an electrically adjustable desk designed for ergonomic comfort, allowing users to transition between sitting and standing positions with ease. The desk features a motorized lifting mechanism controlled by a custom PCB and firmware.  

This repository contains all the necessary files to build and assemble the desk, including mechanical parts, electronic schematics, PCB design, and firmware.  

## Features  
- **Electric Height Adjustment** – Smooth motorized movement for seamless transitions between sitting and standing positions.  
- **Memory Presets** – Store preferred height positions for quick adjustments.
- **Button Control** – User-friendly interface for height adjustment.
- **Supports up to 20kg Load** – Sturdy design capable of handling up to **20kg** of weight.  
---

## Key Components List  
### 🔩 Mechanical Components  
- **MDF Laser-Cut Parts** – Custom-designed structural parts for the desk frame.  
- **Metal Profiles** – design is open for modefications and does not affect the operation.  
- **Lead Screws & Guide Rails** – Ensures precise height adjustment.  
- **Motor Brackets & Couplings** – Secure motor attachment and efficient power transfer.  

### ⚡ Electrical Components  
- **High Torque DC Motor with Gearbox** – Powers the height adjustment mechanism.  
- **Custom PCB** – Controls motor movements and user interactions.  
- **Motor Driver L298N** – Regulates power delivery to motors.  
- **Power Supply  (24V 5A or based on motor requirements)** – Provides sufficient power for motors and electronics.  
- **Optical Endstop & normal Endstop** – Detects desk height limits for safety.  
- **Microcontroller (ATmega328P)** – Handles desk automation and user input.  
- **Buttons** – User interface for manual adjustments.  
---

## Hardware Overview  
1. **Inputs**:  
   - **Power Supply**: 12V or 24V (Depends on DC motor model) and GND.  
   - **Control Switches**:  
     - 2 switches for UP and DOWN.  
     - 1 switch for Homing To the Min Position .  
     - 1 switch to select the Mode (Saved Position).
     - 1 Endstop to detects the Min Position when Homing.
     - 1 Optical Endstop to calculate the travel from the Min position to the current position.
2. **Outputs**:  
   - 1 High torque DC motor.
3. **PCB Design**:  
   - Single-layer for easy DIY manufacturing.  
   - THT components for straightforward soldering.  
   - Compact layout with labeled connections.  

---

## Firmware  
The firmware is written on the **Arduino platform** and requires the ATmega328P chip to be bootloaded.  
### Setup:  
1. Burn the **Arduino bootloader** onto the ATmega328P chip.  
2. Open the provided Arduino code in the repository.  
3. Compile and upload the code to the ATmega328P using an **Arduino-compatible programmer**.  

---

## Operation  
### Control Switches  
1. **Number of LEDs (4 switches)**:  
   - Use binary values (e.g., `0000` for 0 LEDs, `0001` for 1 LED, up to `1100` for 12 LEDs).  
2. **Operation Modes (2 switches)**:  
   - `00`: Dynamic Mode 1 (e.g., Sequential Lighting).  
   - `01`: Dynamic Mode 2 (e.g., Blinking All LEDs).  
   - `10`: Dynamic Mode 3 (e.g., Alternate Pairs Lighting).  
   - `11`: Dynamic Mode 4 (e.g., Random LED Lighting).
     
---

### Testing  
After assembling the board:  
1. Set all switches to the maximum values.  
2. Vary the operation mode and delay settings.  
3. Observe LED indicator behavior on each output channel.  

---

## Repository Structure  
- **Hardware:** PCB design files, schematics, KiCad Files, and BOM
- **Firmware:** Arduino firmware and bootloader setup
- **Documentation:** User guides, truth table, and setup instructions
- **Real-Tests:** Images, videos, and reports of real-world tests

---

## Future Plans  
- **Wi-Fi Support** for wireless control.  
- **Mobile App** to customize patterns and delays.  
- **RGB Control** for each digit.  
- **Custom Modes** for user-defined patterns.  

---

## License  
This project is released under the **MIT License**.  

Feel free to contribute, modify, and enhance this project.
