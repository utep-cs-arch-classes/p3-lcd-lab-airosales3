/** \file lcddraw.h
 *  \brief Adapted from RobG's EduKit
 */

#ifndef lcddraw_included
#define lcddraw_included

/** Draw single pixel at col, row 
 *
 *  \param col Column to draw to
 *  \param row Row to draw to
 *  \param colorBGR Color of pixel in BGR
 */
void drawPixel(u_char col, u_char row, u_int colorBGR);


/** Fill rectangle
 *
 *  \param colMin Column start
 *  \param rowMin Row start
 *  \param width Width of rectangle
 *  \param height height of rectangle
 *  \param colorBGR Color of rectangle in BGR
 */
void fillRectangle(u_char colMin, u_char rowMin, u_char width, u_char height, u_int colorBGR);

/** Clear screen (fill with color)
 *  
 *  \param colorBGR The color to fill screen
 */
void clearScreen(u_int colorBGR);

/** Draw ralsei from Deltarune
 * \param x Where to start from the x axis
 * \param y Where to start from the y axis
 * \param width The width of the sprite
 * \param height The height of the sprite
 * \param color_1 One of the color from the color palette
 * 
 */
//void drawRalsei(u_char width, u_char height, u_int color_1);

void drawHorLine(u_char x, u_char y, u_int color);
void drawVerLine(u_char x, u_char y, u_int color);
//void drawRalseiIdle(u_char height, u_char width, u_int c);
/** Draw string at col,row
 *  Type:
 *  FONT_SM - small (5x8,) FONT_MD - medium (8x12,) FONT_LG - large (11x16)
 *  FONT_SM_BKG, FONT_MD_BKG, FONT_LG_BKG - as above, but with background color
 *  Adapted from RobG's EduKit
 *
 *  \param col Column to start drawing string
 *  \param row Row to start drawing string
 *  \param string The string
 *  \param fgColorBGR Foreground color in BGR
 *  \param bgColorBGR Background color in BGR
 */
void drawString5x7(u_char col, u_char row, char *string, 
		   u_int fgColorBGR, u_int bgColorBGR);

/** 5x7 font - this function draws background pixels
 *  Adapted from RobG's EduKit
 */
void drawChar5x7(u_char col, u_char row, char c, 
		 u_int fgColorBGR, u_int bgColorBGR);

/** Draw rectangle outline
 *  
 *  \param colMin Column start
 *  \param rowMin Row start 
 *  \param width Width of rectangle
 *  \param height Height of rectangle
 *  \param colorBGR Color of rectangle in BGR
 */
void drawRectOutline(u_char colMin, u_char rowMin, u_char width, u_char height,
		     u_int colorBGR);
#endif // included


