# 🎵 Pocket Concert: OLED Music Visualizer

A cozy, kinetic physical computing project that transforms an **Arduino UNO R4** and an **SSD1306 OLED Display** into a pocket-sized music visualizer. 

This project demonstrates how to build an animated hardware UI with independent asset timelines—including large kinetic typography, a dancing stick figure, and floating particle effects—running simultaneously **without** using any blocking `delay()` functions. 

---

## 🛠️ Hardware Requirements

* **Microcontroller:** Arduino UNO R4 (Minima or WiFi)
* **Display:** 0.96-inch SSD1306 OLED Screen (128x64 pixels, I2C interface)
* **Jumpers:** 4x Male-to-Male (or Male-to-Female depending on your display module) breadboard wires

---


## 🔌 Circuit & Wiring Guide

Connecting the display is incredibly simple! We are using the classic I2C analog pins on the Arduino UNO R4.

| OLED Display Pin | Arduino UNO R4 Pin | Wire Color (Diagram Reference) |
| :--- | :--- | :--- |
| **VCC** | **3.3V** | Red |
| **GND** | **GND** | Brown/Black |
| **SCL** (Clock) | **A5** | Green |
| **SDA** (Data) | **A4** | Blue |


<img width="512" height="341" alt="connection_guide" src="https://github.com/user-attachments/assets/301f3888-65f2-4edb-bcb7-d4df4b23d937" />


*(See the `connection_guide.jpeg` included in this repository for a visual wiring layout!)*

---

## 💻 Software & Libraries

Before flashing the code, open your **Arduino IDE**, navigate to the **Library Manager**, and install these two required dependencies:

1. **Adafruit SSD1306** (The hardware driver for the screen)
2. **Adafruit GFX Library** (The core graphics engine for drawing shapes and text)

---
## 💻 Online Sources if u dont have Hardware :
## https://wokwi.com/projects/467528374050755585
## https://www.tinkercad.com/things/iR0SCeiSxOJ-pocket-concert-lcd-music-visualizer 
(The connection with tinkercad might differ as it uses lcd insted of oled)
