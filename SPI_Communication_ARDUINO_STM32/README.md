/In this mini-project, I have made a simplex communication between STM32F407-VG and ARDUINO UNO to transmit one character (ARDUINO --> STM32).
<br>/The orange LED will blink if the message has been received succefully.
<br>/
<br>/
<br>/****WIRING****/
<br>  PD13 (STM32) ====> LED 
<br>  SS    PIN10 (ARDUINO) ====> PA4(STM32)
<br>  SCK   PIN13 (ARDUINO) ====> PA5 (STM32)
<br>  MISO  PIN12 (ARDUINO) ====> PA6 (STM32)
<br>  MOSI  PIN11 (ARDUINO) ====> PA7 (STM32)
