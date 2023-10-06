/*
 * command.c
 *
 *  Created on: Oct 6, 2023
 *      Author: ottav
 */
#include <pnpdrivers.h>
#include "command.h"
#include <string.h>
#include <stdio.h>
#include <stdint.h>
#include "stm32f4xx_hal.h" // Replace 'xxx' with your STM32 family


uint8_t checkForStart(const char* t_code_str){
	 if (strncmp(t_code_str, "M12", 3) == 0) {
	        // Handle M12 code
	    	//M12	0xc	Start of program	M12	No parameters. Indicates that the program is started
	        return 1;
	    }else{
	    	return 0;
	    }
}

uint8_t SCRAM(){
	return 1;
}

uint8_t move_to_xyzr(uint16_t x, uint16_t y, uint16_t z,uint16_t r){
	return 1;
}

uint8_t vacuum_on(){
	return 1;
}

uint8_t vacuum_off(){
	return 1;
}

uint8_t reel_feeder(uint8_t feeder_num){
	return 1;
}

uint8_t check_feeder_load(uint8_t feeder_num){
	return 1;
}

uint8_t check_feeder_fed(uint8_t feeder_num){
	return 1;
}

uint8_t calibrate(){
	return 1;
}

uint8_t processCommand(const char* t_code_str){
    // Check if t_code_str is not NULL to avoid potential issues
    if (t_code_str == NULL) {
        return 0; // Indicate failure or error as needed
    }

    if (strncmp(t_code_str, "T00", 3) == 0) {
        // Handle T00 code
    	//Move to coordinate	T00 X123 Y456 Z789 R90
    	int16_t x, y, z, r;
    	sscanf(t_code_str, "T%*2d X%hd Y%hd Z%hd R%hd", &x, &y, &z, &r);
    	return (move_to_xyzr(x,y,z,r));


    } else if (strncmp(t_code_str, "T01", 3) == 0) {
        // Handle T01 code
    	//Move certain distance	T01 X0 Y0 Z-15 R0	The head moves down 15 units
    	int16_t x, y, z, r;
		sscanf(t_code_str, "T%*2d X%hd Y%hd Z%hd R%hd", &x, &y, &z, &r);
		return (move_to_xyzr(x,y,z,r));

    } else if (strncmp(t_code_str, "T02", 3) == 0) {
        // Handle T02 code
    	//Go to origin (0, 0, 0, 0)	T02	No parameters
    	return (move_to_xyzr(0,0,0,0));

    } else if (strncmp(t_code_str, "M03", 3) == 0) {
        // Handle M03 code
    	//Turn on vacuum	M03	No parameters

        return vacuum_on();
    } else if (strncmp(t_code_str, "M04", 3) == 0) {
        // Handle M04 code
    	//Turn off vacuum	M04	No parameters
    	return vacuum_off();
    } else if (strncmp(t_code_str, "M05", 3) == 0) {
        // Handle M05 code
    	uint8_t reel;
    	//Feed reel	M05 P15 (read)	Feeds reel with part number 15
    	sscanf(t_code_str, "M05 P%hhu", &reel);
    	return reel_feeder(reel);
    } else if (strncmp(t_code_str, "M06", 3) == 0) {
    	uint8_t reel;
    	sscanf(t_code_str, "M06 P%hhu", &reel);
    	while(!check_feeder_load(reel)){
    		//wait
    	}

        // Handle M06 code
    	//Wait for reel	M06 P20 (read)	Waits until reel with part number 20 is loaded. Continues once it is loaded. If part already loaded, the it just continues
        return 7;
    } else if (strncmp(t_code_str, "M07", 3) == 0) {
        // Handle M07 code
    	//Wait some time	M07 M550	Waits 550ms to continue
    	uint8_t time;
		sscanf(t_code_str, "M07 P%hhu", &time);
		HAL_Delay(time);

        return 8;
    } else if (strncmp(t_code_str, "M08", 3) == 0) {
    	uint8_t reel;
		sscanf(t_code_str, "M08 P%hhu", &reel);
		while(!check_feeder_fed(reel)){
		    		//wait
		    	}
        // Handle M08 code
    	//Wait for feed	M08 P17	Waits until reel with part 17 finishes feeding

        return 9;
    } else if (strncmp(t_code_str, "T09", 3) == 0) {
        // Handle T09 code
    	//Calibrate	T09	No parameters. Will move in all directions until the limit switches are hit to determine the origin
    	calibrate();
        return 10;
    } else if (strncmp(t_code_str, "M10", 3) == 0) {
        // Handle M10 code
    	//M10	0xa	End of program	M10	No parameters. Indicates that the program is finished
        return 11;
    } else if (strncmp(t_code_str, "M11", 3) == 0) {
        // Handle M11 code
    	//M11	0xb	Emergency stop	M11	No parameters. Shuts down power to the motors
    	SCRAM();
        return 12;
    } else {
        // Handle the case when t_code_str doesn't match any of the specified codes
        return 0; // Indicate failure or error as needed
    }
}
