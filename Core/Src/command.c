/*
 * command.c
 *
 *  Created on: Oct 6, 2023
 *      Author: ottav
 */
#include "command.h"

uint8_t processCommand(const char* t_code_str,uint8_t t_code_index){
    // Check if t_code_str is not NULL to avoid potential issues
    if (t_code_str == NULL) {
        return 0; // Indicate failure or error as needed
    }

    if (strncmp(t_code_str, "T00", 3) == 0) {
        // Handle T00 code
        return 1;
    } else if (strncmp(t_code_str, "T01", 3) == 0) {
        // Handle T01 code
        return 2;
    } else if (strncmp(t_code_str, "T02", 3) == 0) {
        // Handle T02 code
        return 3;
    } else if (strncmp(t_code_str, "M03", 3) == 0) {
        // Handle M03 code
        return 4;
    } else if (strncmp(t_code_str, "M04", 3) == 0) {
        // Handle M04 code
        return 5;
    } else if (strncmp(t_code_str, "M05", 3) == 0) {
        // Handle M05 code
        return 6;
    } else if (strncmp(t_code_str, "M06", 3) == 0) {
        // Handle M06 code
        return 7;
    } else if (strncmp(t_code_str, "M07", 3) == 0) {
        // Handle M07 code
        return 8;
    } else if (strncmp(t_code_str, "M08", 3) == 0) {
        // Handle M08 code
        return 9;
    } else if (strncmp(t_code_str, "T09", 3) == 0) {
        // Handle T09 code
        return 10;
    } else if (strncmp(t_code_str, "M10", 3) == 0) {
        // Handle M10 code
        return 11;
    } else if (strncmp(t_code_str, "M11", 3) == 0) {
        // Handle M11 code
        return 12;
    } else if (strncmp(t_code_str, "M12", 3) == 0) {
        // Handle M12 code
        return 13;
    } else {
        // Handle the case when t_code_str doesn't match any of the specified codes
        return 0; // Indicate failure or error as needed
    }
}
