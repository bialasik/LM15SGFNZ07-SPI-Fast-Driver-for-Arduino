#ifndef lcd_lm15 _h
#define lcd_lm15 _h

#if ARDUINO >= 100
 #include "Arduino.h"
 #include "Print.h"
#else
 #include "WProgram.h"
#endif

#define RED     0x0F00
#define GREEN   0x00F0
#define BLUE    0x000F
#define YELLOW  0x0FF0
#define MAGENTA 0x0F0F
#define CYAN    0x00FF
#define BLACK   0x0000
#define WHITE   0x0FFF
#define ORANGE  0x0F90
#define GREY    0x0777
#define PINK    0x0F0F
#define LIME    0x00F0

void initLCD_LM15(unsigned char contrast);
void setContrast_LM15(unsigned char contrast);
void window_LM15(unsigned char xstart, unsigned char ystart, unsigned char xend, unsigned char yend);
void cursor_LM15(unsigned char row, unsigned char col);
void clearLCD_LM15(void);
void testLCD_LM15(void);
void setCursorLCD_LM15(unsigned char y, unsigned char x); 
void getCursorLCD_LM15(unsigned char *y, unsigned char *x);
void rectLCD_LM15(unsigned char h, unsigned char w, unsigned char x, unsigned char y, unsigned int color); 
void textLCD_LM15(char *c, unsigned int colortext, unsigned int colorbg);
void newlineLCD_LM15(void);
void drawPixelLCD_LM15(unsigned char y, unsigned char x, unsigned int color);
void drawLineLCD_LM15(int x1, int y1, int x2, int y2, unsigned int color);
void drawCircleLCD_LM15(int x, int y, int radius, int fill, unsigned int color);

#endif