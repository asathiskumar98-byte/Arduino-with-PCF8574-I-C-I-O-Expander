🔌 Arduino with PCF8574 I²C I/O Expander

📘 Overview

This project demonstrates how to interface the PCF8574 I/O Expander with an Arduino UNO using the I²C protocol.
The PCF8574 allows you to control 8 additional digital I/O pins using just two Arduino pins (SDA and SCL).
It’s perfect when you’re running out of GPIOs and need to drive LEDs, relays, or other peripherals.

🧩 Components Required

Arduino UNO

PCF8574 I/O Expander module (or IC)

8 LEDs with 220Ω resistors (optional for testing)

Jumper wires and breadboard

⚙️ Circuit Connections
PCF8574 Pin	Function	Arduino UNO Pin
VCC	Power	5V
GND	Ground	GND
SDA	I²C Data	A4
SCL	I²C Clock	A5
A0, A1, A2	I²C Address Select	GND (Address = 0x20)
P0–P7	Output Pins	LEDs or other loads

When A0, A1, and A2 are tied to GND, the device address becomes 0x20.
Multiple PCF8574 chips can share the same I²C bus by assigning different addresses (0x20–0x27).

💻 Arduino Code
```c
#include <Wire.h>

void WriteToPCF8574(unsigned char data)
{
  Wire.beginTransmission(0x20); // Address of PCF8574 (A0,A1,A2=GND)
  Wire.write(data);             // Send 8-bit data to output pins P0–P7
  Wire.endTransmission();       // Stop transmission
}

void setup()
{
  Wire.begin();                 // Initialize I²C communication
}

void loop()
{
  WriteToPCF8574(0x01); delay(1000); // P0 = HIGH
  WriteToPCF8574(0x02); delay(1000); // P1 = HIGH
  WriteToPCF8574(0x04); delay(1000); // P2 = HIGH
  WriteToPCF8574(0x08); delay(1000); // P3 = HIGH
  WriteToPCF8574(0x10); delay(1000); // P4 = HIGH
  WriteToPCF8574(0x20); delay(1000); // P5 = HIGH
  WriteToPCF8574(0x40); delay(1000); // P6 = HIGH
  WriteToPCF8574(0x80); delay(1000); // P7 = HIGH
}
```
🧠 Explanation

The PCF8574 acts as a remote 8-bit I/O port.

Each bit of the data byte corresponds to one pin (P0–P7).

Sending 0x01 turns P0 ON, while 0x80 turns P7 ON.

The example code activates each pin sequentially, creating a “running LED” effect.

📊 Expected Output

If 8 LEDs are connected to P0–P7, they will light one by one in sequence, each staying ON for one second.

Example output pattern:

LED1 → LED2 → LED3 → LED4 → LED5 → LED6 → LED7 → LED8 → repeat

⚠️ Notes

PCF8574 operates between 2.5V and 5.5V, so it’s safe with 5V Arduino boards.

Use pull-up resistors (4.7kΩ–10kΩ) on SDA and SCL if your module doesn’t already have them.

The I²C address changes based on A0–A2 pin wiring:

0x20 (A0=A1=A2=GND)

0x21 (A0=VCC)

up to 0x27 (A0=A1=A2=VCC)

🚀 Future Ideas

Interface LCD displays or keypads through PCF8574 for pin-efficient control.

Combine multiple expanders for up to 64 I/O pins using one I²C bus.

Add input reading (buttons or sensors) using Wire.requestFrom().
