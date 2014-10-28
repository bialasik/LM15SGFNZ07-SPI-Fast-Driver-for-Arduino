LM15SGFNZ07 SPI Arduino Fast Library
=============

author: Marcin Selerowski (bialasik)

based on [Elektor code for AVR C](http://www.elektor-magazine.com/fileadmin/user_upload/2008/dolo/080320-11.zip) and [mindogas library for Arduino](https://bitbucket.org/mindogas/lm15sgfnz07)

help with first steps: michalko12 from elektroda.pl

"Why do you write that library for Arduino, if currently exist one?"
------
Because actual mindogas library was very slow. Cleaning LCD (filling all the pixels with same color) took about 2 seconds... I was unable to use LM15SGFNZ07-based LCD on most of my Arduino projects.

I have changed connection to hardware SPI. Also, I've found Elektor C code, which was the base. I've rewrote the mainly code and I've customised it for Arduino standards. It's simple to use it now. And it's fast! I can use this display in my projects!

Cool story bro, but where I must put files?
------
1. Create the directory in _libraries_ in Arduino main folder
2. Just put here lcd_lm15.c and lcd_lm15.h files
3. It's done!

How to wire Arduino with LM15SGFNZ07 LCD?
------
![LCD](http://i.imgur.com/jL4YGl2.png)

| PIN LCD       | PIN ARDUINO   |
|:-------------:|:-------------:|
| 1             | 10            |
| 2             | 8             |
| 3             | 6             |
| 4             | 13            |
| 5             | 11            |
| 6             | 3.3V          |
| 7             | GND           |
| 8             | 3.3V          |
| 9             | GND           |
| 10            | 3.3V          |

How to use it?
------
Simplest Arduino sketch

```cpp
#include <SPI.h>
#include <lcd_lm15.h>

void setup() 
{ 
  initLCD_LM15(32);
  textLCD_LM15("Kocham Kasie", ORANGE, BLUE);
} 
  
void loop() 
{ 

}
```
Ok, it's simple! But I want to do something more than text writing. Maybe some documentation, please?
------
All right! Here is the **list of useful avalible functions** (2014.10.27):

```cpp
initLCD_LM15(CONTRAST_NUMBER_FROM_0_TO_255_DEFAULT_IS_32);
```
Initialize the display (send init data, set contrast and clear LCD with white color).

```cpp
setContrast_LM15(CONTRAST_NUMBER_FROM_0_TO_255_DEFAULT_IS_32);
```
Set contrast. (wow such discovery).

```cpp
clearLCD_LM15();
```
Clear LCD with white color.

```cpp
testLCD_LM15();
```
Draw four strips on LCD: white, red, green and blue.

```cpp
setCursorLCD_LM15(Y_POSITION, X_POSITION);
```
Set cursor. Virtual cursor. 

```cpp
getCursorLCD_LM15(Y_POSITION, X_POSITION);
```
Get cursor. Virtual cursor. 

```cpp
rectLCD_LM15(HEIGHT, WIDTH, START_X, START_Y, COLOR); 
```
Draw rectangle.

```cpp
textLCD_LM15("TEXT", TEXT_COLOR, BACKGROUND_COLOR);
```
Write text with text color and background color. Currently there's not transparent color for background, but I will make it.

```cpp
newlineLCD_LM15();
```
Go to new line.

```cpp
drawPixelLCD_LM15(Y_POSITION, X_POSITION, COLOR);
```
Draw a single pixel on the screen.

```cpp
drawLineLCD_LM15(START_POINT_X, START_POINT_Y, END_POINT_X, END_POINT_Y, COLOR);
```
Draw a line.

```cpp
drawCircleLCD_LM15(CENTER_X, CENTER_Y, RADIUS, FILL, COLOR);
```
Draw a circle. FILL: 0 - off, 1 - on

Aaaaand... color list!
```cpp
RED
GREEN
BLUE
YELLOW
MAGENTA
CYAN
BLACK
WHITE
ORANGE
GREY
PINK
LIME
```

I love blue color!

TO DO list
------
1. ~~Drawing circles~~ Done!
2. ~~Drawing lines~~ Done!
3. Drawing frames
4. ~~More colors!~~ Done!
5. Different fonts (?)
6. Set pins on LCD init, not in code
7. Drawing ovals
8. Drawing text with transparent background
9. ???

Write to me if you want!
------
bialasikk[kitty]gmail.com