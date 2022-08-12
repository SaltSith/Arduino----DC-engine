/*
 Name:		Arduino____DC_engine.ino
 Created:	8/12/2022 10:24:04 PM
 Author:	marcin
*/

#include "dc_engine.h"

dc_engine engine_single_direction(1);
dc_engine engine_bi_direction(2, 3);


// the setup function runs once when you press reset or power the board
void setup() {
	engine_single_direction.init();
	engine_bi_direction.init();
}

// the loop function runs over and over again until power down or reset
void loop() {
	engine_single_direction.start();
	engine_bi_direction.start(DC_ENGINE_FORWARD);
	delay(1000);

	engine_single_direction.stop();
	engine_bi_direction.stop();
	delay(1000);

	engine_single_direction.start();
	engine_bi_direction.start(DC_ENGINE_BACKWARD);
	delay(1000);

	engine_single_direction.stop();
	engine_bi_direction.stop();
	delay(1000);
}
