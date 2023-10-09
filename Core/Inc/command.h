/*
 * command.h
 *
 *  Created on: Oct 6, 2023
 *      Author: ottav
 */

#ifndef INC_COMMAND_H_
#define INC_COMMAND_H_

#include <stdint.h>


uint8_t processCommand(const char* t_code_str);

uint8_t checkForStart(const char* t_code_str);


uint8_t SCRAM();

uint8_t move_to_xyzr(uint16_t x, uint16_t y, uint16_t z,uint16_t r);

uint8_t vacuum_on();

uint8_t vacuum_off();

uint8_t reel_feeder(uint8_t feeder_num);

uint8_t check_feeder_load(uint8_t feeder_num);

uint8_t check_feeder_fed(uint8_t feeder_num);

uint8_t calibrate();

#endif /* INC_COMMAND_H_ */
