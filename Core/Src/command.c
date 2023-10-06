/*
 * command.c
 *
 *  Created on: Oct 6, 2023
 *      Author: ottav
 */
#include <pnpdrivers.h>
#include "command.h"
#include <string.h>

uint8_t processCommand(const char* t_code_str,uint8_t t_code_index){
    // Check if t_code_str is not NULL to avoid potential issues
    if (t_code_str == NULL) {
        return 0; // Indicate failure or error as needed
    }

    if (strncmp(t_code_str, "T00", 3) == 0) {
        // Handle T00 code
    	//Move to coordinate	T00 X123 Y456 Z789 R90
        return 1;
    } else if (strncmp(t_code_str, "T01", 3) == 0) {
        // Handle T01 code
    	//Move certain distance	T01 X0 Y0 Z-15 R0	The head moves down 15 units
        return 2;
    } else if (strncmp(t_code_str, "T02", 3) == 0) {
        // Handle T02 code
    	//Go to origin (0, 0, 0, 0)	T02	No parameters
        return 3;
    } else if (strncmp(t_code_str, "M03", 3) == 0) {
        // Handle M03 code
    	//Turn on vacuum	M03	No parameters
        return 4;
    } else if (strncmp(t_code_str, "M04", 3) == 0) {
        // Handle M04 code
    	//Turn off vacuum	M04	No parameters
        return 5;
    } else if (strncmp(t_code_str, "M05", 3) == 0) {
        // Handle M05 code
    	//Feed reel	M05 P15 (read)	Feeds reel with part number 15
        return 6;
    } else if (strncmp(t_code_str, "M06", 3) == 0) {
        // Handle M06 code
    	//Wait for reel	M06 P20 (read)	Waits until reel with part number 20 is loaded. Continues once it is loaded. If part already loaded, the it just continues
        return 7;
    } else if (strncmp(t_code_str, "M07", 3) == 0) {
        // Handle M07 code
    	//Wait some time	M07 M550	Waits 550ms to continue
        return 8;
    } else if (strncmp(t_code_str, "M08", 3) == 0) {
        // Handle M08 code
    	//Wait for feed	M08 P17	Waits until reel with part 17 finishes feeding
        return 9;
    } else if (strncmp(t_code_str, "T09", 3) == 0) {
        // Handle T09 code
    	//Calibrate	T09	No parameters. Will move in all directions until the limit switches are hit to determine the origin
        return 10;
    } else if (strncmp(t_code_str, "M10", 3) == 0) {
        // Handle M10 code
    	//M10	0xa	End of program	M10	No parameters. Indicates that the program is finished
        return 11;
    } else if (strncmp(t_code_str, "M11", 3) == 0) {
        // Handle M11 code
    	//M11	0xb	Emergency stop	M11	No parameters. Shuts down power to the motors
        return 12;
    } else if (strncmp(t_code_str, "M12", 3) == 0) {
        // Handle M12 code
    	//M12	0xc	Start of program	M12	No parameters. Indicates that the program is started
        return 13;
    } else {
        // Handle the case when t_code_str doesn't match any of the specified codes
        return 0; // Indicate failure or error as needed
    }
}
