/* tab:4
 *
 * text.h - font data and text to mode X conversion utility header file
 *
 * "Copyright (c) 2004-2009 by Steven S. Lumetta."
 *
 * Permission to use, copy, modify, and distribute this software and its
 * documentation for any purpose, without fee, and without written agreement is
 * hereby granted, provided that the above copyright notice and the following
 * two paragraphs appear in all copies of this software.
 *
 * IN NO EVENT SHALL THE AUTHOR OR THE UNIVERSITY OF ILLINOIS BE LIABLE TO
 * ANY PARTY FOR DIRECT, INDIRECT, SPECIAL, INCIDENTAL, OR CONSEQUENTIAL
 * DAMAGES ARISING OUT  OF THE USE OF THIS SOFTWARE AND ITS DOCUMENTATION,
 * EVEN IF THE AUTHOR AND/OR THE UNIVERSITY OF ILLINOIS HAS BEEN ADVISED
 * OF THE POSSIBILITY OF SUCH DAMAGE.
 *
 * THE AUTHOR AND THE UNIVERSITY OF ILLINOIS SPECIFICALLY DISCLAIM ANY
 * WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF
 * MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE.  THE SOFTWARE
 * PROVIDED HEREUNDER IS ON AN "AS IS" BASIS, AND NEITHER THE AUTHOR NOR
 * THE UNIVERSITY OF ILLINOIS HAS ANY OBLIGATION TO PROVIDE MAINTENANCE,
 * SUPPORT, UPDATES, ENHANCEMENTS, OR MODIFICATIONS."
 *
 * Author:        Steve Lumetta
 * Version:       2
 * Creation Date: Thu Sep 9 22:08:16 2004
 * Filename:      text.h
 * History:
 *    SL    1    Thu Sep 9 22:08:16 2004
 *        First written.
 *    SL    2    Sat Sep 12 13:40:11 2009
 *        Integrated original release back into main code base.
 */

#ifndef TEXT_H
#define TEXT_H

/* The default VGA text mode font is 8x16 pixels. */
#define FONT_WIDTH   8
#define FONT_HEIGHT 16

/* Text buffer should fill the size of the status bar. */
#define STATUS_BAR_WIDTH 320
#define STATUS_BAR_HEIGHT 18

/* Number of planes to put text into and starting index in buffer for each plane. */
#define NUM_OF_PLANES 4
#define PLANE_ONE 1440
#define PLANE_TWO 2880
#define PLANE_THREE 4320
#define PLANE_SIZE STATUS_BAR_WIDTH * STATUS_BAR_HEIGHT / NUM_OF_PLANES

/* Max number of letters allowed in the status bar. */
#define MAX_NUMBER_OF_CHARS 40

/* Define colors to be used for status bar and text. */
#define STATUS_BAR_COLOR 7
#define TEXT_COLOR 15

/* Transfer input strings to a text buffer.*/
void text_to_graphics(const char* left_string, const char* center_string, const char* right_string);

/* get the appropriate text buffer based on offset (should be 0-3). */
unsigned char* get_textBuffer(int offset);

/* Standard VGA text font. */
extern unsigned char font_data[256][16];

#endif /* TEXT_H */
