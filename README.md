# Binary-Converter
Using Arduino R3 to convert decimal to binary

## Circuit Board Preview
<img width="814" alt="Screenshot 2025-01-13 at 7 21 21 PM" src="https://github.com/user-attachments/assets/84032d58-600a-4129-ac72-399f05b4ea79" />
https://www.tinkercad.com/things/fOvaAfKz7kY-final-project-v21

## Following Items Required are:
- Keypad 4x4 - 1x
- LCD 16x2 - 1x
- Resistors - 2x 
- Arduino R3 - 1x
- Breadboard Small - 1x
- Red wires - 8x
- Blue wires - 8x
- Green Wires - 3x

## Functions
When the program starts, user can choose a mode either DtoB or BtoD using the keypad.
### DtoB(Decimal to Binary)
- Convert decimal number into binary number.
- User can enter a decimal number from 0(0000000000000000) to 65535(1111111111111111) using the keypad. Press "*" to see the result.
- When user enter a number greater than 65535, the LCD monitor says "Num is too big!".
- After monitor showing the result, press any key on the keypad to return to the menu.
### BtoD(Binary to Decimal)
- Convert binary number into decimal number.
- User can enter a binary number from 0000000000000000(0) to 1111111111111111(65535) using the keypad. All keys on the keypad except 0 and 1 are disabled. Press "*" to see the result.
- After monitor showing the result, press any key on the keypad to return to the menu.
