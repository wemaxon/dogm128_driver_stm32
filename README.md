# dogm128_driver_stm32
This is a driver library to control the Electronics Assembly DOGM128 monochrome display with an STM32##

## Class diagram of the driver
![class diagram](/documentation/class_diagram.png)

## How to use

```cpp
//includes library header
#include "Monochrome_Display.hpp"

//creates Display Object
Monochrome_Display MyDisplay;

//Initializes Display, pass SPI Handler and Ports and Pins of Chip Select, A0  and RESET
MyDisplay.init(&hspi1, CS_GPIO_Port, CS_Pin, A0_GPIO_Port, A0_Pin, OERST_GPIO_Port, OERST_Pin);

//draws Image at Position 0,0
MyDisplay.drawImage(&camaro, 0, 0);

//writes Pixels from Buffer to Display
MyDisplay.updateBuffer();

//clears Display
MyDisplay.clear();

//writes String to Display at position 0,0
MyDisplay.writeString("HELLO WORLD", &smallFT, 0, 0);

//writes Pixels from Buffer to Display again
MyDisplay.updateBuffer();

```




## Copyright & copyright

Copyright © 2019,2020  Maximilian Anton Weber

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <https://www.gnu.org/licenses/>.
