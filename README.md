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
     - 2 Switches for UP and DOWN.  
     - 1 Switch for Homing To the Min Position .
     - 1 Switch to save the current position. 
     - 1 Switch to select the Mode (Saved Position).
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

### Powering On  
1. Connect the **24V/12V power supply** to the PCB.  
2. Ensure all connections (motors, endstops, buttons) are properly secured.  

### Manual Height Adjustment  
- Use the **UP** and **DOWN** buttons to control the desk height.  
- The **motorized mechanism** moves the desk smoothly between sitting and standing positions.  
- The **optical endstop** continuously tracks position changes to ensure precise height adjustments.  

### Homing Process  
- When first powered on, the system requires **homing** to calibrate its position.  
- Press the **Homing button**, and the desk will move to the **minimum position**.  
- The **mechanical endstop** will detect the lower limit and stop movement.  
- Once homing is complete, the system is ready for normal operation.  

### Memory Presets (Saved Position)  
- The desk allows storing one specific height positions for quick recall.  
- Press the **Mode button** to switch to **Saved Position Mode**.  
- Adjust the desk to a preferred height and **save it** using save button.  
- When  pressing **MODE** the disk will move to the stored positions.  

### Safety Features  
- **Limit Switches:** Prevents movement beyond mechanical constraints.  

### Shutdown Procedure  
- Lower the desk to the minimum position (recommended).  
- Disconnect the **power supply** if the desk won’t be used for an extended period.  

     
---


## Repository Structure  
- **Hardware:** PCB design files, schematics, KiCad Files, and BOM
- **Firmware:** Arduino firmware and bootloader setup
- **Documentation:** User guides, truth table, and setup instructions
- **Real-Tests:** Images, videos, and reports of real-world tests

---

## Feature Improvements  
- **Stronger Frame & Higher Load Capacity** – Reinforce the structure to support heavier loads beyond 20kg.  
- **Dual-Motor System** – Enhance stability and lifting efficiency with synchronized motors.  
- **LCD Display** – Display real-time height, system status, and saved presets.  
- **Soft Start & Stop Motion** – Implement acceleration control for smoother transitions.  
 

---

## License  
This project is released under the **MIT License**.  

Feel free to contribute, modify, and enhance this project.
