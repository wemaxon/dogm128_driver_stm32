# dogm128_driver_stm32
This is a C++ driver library to control the Electronics Assembly DOGM128 monochrome display with an STM32.

## Class diagram of the driver
![class diagram](/documentation/class_diagram.png)

## How to use

```cpp
//includes library header
#include "Monochrome_Display.hpp"

//creates display object
Monochrome_Display MyDisplay;

//Initializes display, passes SPI handler and ports and pins of chip celect, A0 and RESET
MyDisplay.init(&hspi1, CS_GPIO_Port, CS_Pin, A0_GPIO_Port, A0_Pin, OERST_GPIO_Port, OERST_Pin);

//draws image at position 0,0
MyDisplay.drawImage(&camaro, 0, 0);

//writes pixels from buffer to display
MyDisplay.updateBuffer();

//clears display
MyDisplay.clear();

//writes String with smallFT font to display at position 0,0
MyDisplay.writeString("HELLO WORLD", &smallFT, 0, 0);

//writes pixels from buffer to display again
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
