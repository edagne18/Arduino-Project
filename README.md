# RFID Access Control System

This project involves the development of a door lock system utilizing **Radio Frequency Identification (RFID)** technology. The goal was to create a secure and efficient access control system using the **ELEGOO MEGA2560 R3** microcontroller and the **RFID-RC522** module, with a **Servo Motor SG90** managing the door lock mechanism.

## Project Description

The RFID-based door lock system facilitates seamless access control by identifying authorized RFID tags and activating a servo motor to unlock the door. The system provides auditory and visual feedback using a buzzer and LEDs, while displaying messages like "Access Granted" or "Access Denied" on the serial monitor.

### Key Components
1. **ELEGOO MEGA2560 R3 Microcontroller**
   - Powered by ATmega2560.
   - 54 Digital I/O pins, 16 analog input pins.
   - Operates at 5V, with a clock speed of 16 MHz.

2. **RFID-RC522 Module**
   - Operating frequency: 13.56 MHz.
   - Communication: SPI, I2C, UART.
   - Max reading range: 5 cm.

3. **Servo Motor SG90**
   - Operating Voltage: 5V.
   - Torque: 2.5kg/cm.
   - Rotation Range: 0-180°.

4. **Additional Components**
   - Breadboard, LEDs (green and red), Buzzer, Jumper cables, Arduino IDE.

## System Architecture

The system operates by scanning an RFID tag. If the tag's UID matches the stored UID in the microcontroller, the servo motor unlocks the door, the green LED lights up, and the buzzer sounds. If the tag does not match, the red LED is activated, and access is denied. All operations are displayed on the serial monitor.

## Setup

1. Connect the **RFID-RC522** module to the **ELEGOO MEGA2560 R3** microcontroller following this pin configuration:

   | RFID-RC522 Pin | MEGA2560 Pin |
   |----------------|--------------|
   | SDA            | 53           |
   | SCK            | 52           |
   | MOSI           | 51           |
   | MISO           | 50           |
   | GND            | GND          |
   | RST            | 5            |
   | 3.3V           | 3.3V         |

2. Additional component pin configuration:

   | Component  | Pin  |
   |------------|------|
   | Green LED  | 32   |
   | Red LED    | 28   |
   | Buzzer     | 24   |

3. Upload the provided Arduino code for the RFID system.

## Installation

- Ensure that the **Arduino IDE** is installed.
- Download and install the necessary **RFID libraries** via the Arduino Library Manager.
- Connect the components as per the circuit diagram.

## Testing

1. Upload the provided code to the **ELEGOO MEGA2560**.
2. Scan an RFID card or tag. Observe the servo motor's movement and the LED signals for access control.
3. Monitor the serial output for "Access Granted" or "Access Denied" messages.

## Support

For any issues or questions regarding the project, please contact the project contributor.

## License

This project is licensed for educational purposes only as part of the COMP 408 Web Programming course.
