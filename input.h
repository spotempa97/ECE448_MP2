/* tab:4
 *
 * input.h - header file for input control to maze game
 *
 * "Copyright (c) 2004-2011 by Steven S. Lumetta."
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
 * Version:       3
 * Creation Date: Thu Sep 9 22:22:00 2004
 * Filename:      input.h
 * History:
 *    SL    1    Thu Sep 9 22:22:00 2004
 *        First written.
 *    SL    2    Sun Sep 13 04:11:44 2009
 *        Changed display interface for Tux controller.
 *    SL    3    Wed Sep 14 02:06:59 2011
 *        Updated command names and numbers for adventure game.
 */

#ifndef INPUT_H
#define INPUT_H

/* Variables needed to open tux ioctl. */
int fd; /* File descriptor used when dealing with the TUX controller input. */
int ldisc_num;
int ioctl_retVal;
int buttons;

/* possible commands from input device, whether keyboard or game controller */
typedef enum {
    CMD_NONE, CMD_RIGHT, CMD_LEFT, CMD_UP, CMD_DOWN,
    CMD_MOVE_LEFT, CMD_ENTER, CMD_MOVE_RIGHT,
    CMD_TYPED,
    CMD_QUIT,
    NUM_COMMANDS
} cmd_t;

#define MAX_TYPED_LEN 20

/* Define data for buttons pressed (used as CASES in tux_thread). */
#define TUX_RIGHT 0x7F
#define TUX_DOWN 0xBF
#define TUX_LEFT 0xCF
#define TUX_UP 0xEF
#define TUX_C 0xF7
#define TUX_B 0xFB
#define TUX_A 0xFC
#define TUX_START 0xFE

/*
#define TUX_RIGHT 0x80
#define TUX_DOWN 0x40
#define TUX_LEFT 0x20
#define TUX_UP 0x10
#define TUX_C 0x08
#define TUX_B 0x04
#define TUX_A 0x02
#define TUX_START 0x01
*/

/* Number of LEDs that exist. */
#define NUM_LEDS 4

/* Number of seconds in a minute. */
#define SEC_TO_MINUTES 60

/* Maximum number that can be displayed for minutes. */
#define MAX_MINS 99

/* Initialize the input device. */
extern int init_input();

/* Read a command from the input device. */
extern cmd_t get_command();

/* Get currently typed command string. */
extern const char* get_typed_command();

/* Reset typed command. */
extern void reset_typed_command();

/* Shut down the input device. */
extern void shutdown_input();

/*
 * Show the elapsed seconds on the Tux controller(no effect when
 * compiled for a keyboard).
 */
extern void display_time_on_tux(int num_seconds);

#endif /* INPUT_H */
