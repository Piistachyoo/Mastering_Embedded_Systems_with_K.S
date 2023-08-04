
# Smart_Car_Parking_STM32F103

[Smart Car Parking (STM32F103) - باركينج الواد حماده! - YouTube](https://www.youtube.com/watch?v=GNSE2qDyYh0)

#### Features:
 - This is an event-triggered, foreground-background system that works on a finite state machine.
 - The system has 3 slots in total.
 - Only 3 users have the privilege to access the parking system.
 - The system uses 2 LCDs to interface, one in the admin panel, and the other in the entry gate.
 - The entry gate’s RFID module accepts input if the parking is not full.
 - The exit gate’s RFID module accepts input if the parking is not empty.
 - Used PIR motion sensors to detect if the car is present before closing the gate.

TODO: Use an external EEPROM to save privileged IDs

#### Components used:

- STM32F103C6T6 
- 4x3 Keypad
- 2 x 16x4 LCD 
- 2 x servo motor 
- 2 x PIR sensor 
- Green LED 
- Red LED

#### Peripherals used:

- RCC
- NVIC
- SysTick
- Timers
- UART

#### Project design:
![project design](https://github.com/Piistachyoo/Smart_Car_Parking_STM32F103/blob/main/project_design.png?raw=true)