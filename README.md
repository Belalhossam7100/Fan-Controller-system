![image](https://github.com/Belalhossam7100/Fan-Controller-system/assets/141184780/75c59a8b-5289-4184-af94-a68eff9b4f4f)
Overview: This project aims to design a temperature-controlled fan system using the ATmega32 microcontroller. The fan automatically adjusts its speed based on the temperature sensed by the LM35 temperature sensor. The microcontroller continuously monitors the temperature, performs necessary calculations, displays the temperature on an LCD, and controls the fan speed accordingly.
Specifications:
1.	Microcontroller: ATmega32 running at a frequency of 1MHz.
2.	Temperature Sensing: LM35 temperature sensor provides continuous analog output, converted to digital values using ADC.
3.	Temperature Calculation: Microcontroller performs calculations to determine temperature from ADC values.
4.	Fan Control:
    •	Below 30°C: Fan turned off.

    •	30-59°C: Fan operates at 25% speed.

    •	60-89°C: Fan operates at 50% speed.

    •	90-119°C: Fan operates at 75% speed.

    •	120°C and above: Fan operates at 100% speed.

6.	Circuit Principle: Fan connected to DC motor switches on/off based on temperature. Motor rotates clockwise or stops based on fan state.
7.	LCD Display: Continuous display of temperature and fan state.
8.	Motor Speed Control: PWM signal generated from Timer0 controls DC motor speed.


Instructions:
1.	Connect LM35 temperature sensor, LCD, DC motor, and ATmega32 microcontroller as per the provided schematics.
2.	Upload the provided code to the microcontroller.
3.	Power on the system.
4.	Monitor the LCD display for temperature readings and fan status.
5.	Observe fan speed adjustments based on temperature changes.
