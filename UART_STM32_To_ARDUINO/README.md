/In this mini-project, I have made a UART communication between STM32F407-VG and an ARDUINO UNO to transmit a message from one direction (STM --> ARDUINO).
/The LED will blink if the transmitted message contains a certain character or string.
/
/
/****WIRING****/
  PIN7 (ARDUINO) ====> LED 
  Rx   (ARDUINO) ====> PA2 (STM32)
  GND  (ARDUINO) ====> GND (STM32)
