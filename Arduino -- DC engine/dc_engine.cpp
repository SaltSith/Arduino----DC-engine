#include "dc_engine.h"

#include <Arduino.h>

dc_engine::dc_engine(const uint8_t pin_a):pin_a(pin_a), engine_type(DC_ENGINE_SINGLE_DIRECTION) {}

dc_engine::dc_engine(const uint8_t pin_a, const uint8_t pin_b): pin_a(pin_a), pin_b(pin_b), engine_type(DC_ENGINE_BI_DIRECTION) {}

dc_engine::~dc_engine() {}

void dc_engine::init(void)
{
	pinMode(this->pin_a, OUTPUT);
	if (this->engine_type == DC_ENGINE_BI_DIRECTION) {
		pinMode(this->pin_b, OUTPUT);
	}

	this->stop();
}

void dc_engine::start(void)
{
	if (this->engine_type == DC_ENGINE_BI_DIRECTION) {
		return;
	}

	digitalWrite(this->pin_a, HIGH);
}

void dc_engine::start(const dc_engine_direction direction)
{
	if (this->engine_type == DC_ENGINE_SINGLE_DIRECTION) {
		return;
	}

	switch (direction) {
	case DC_ENGINE_FORWARD:
		digitalWrite(this->pin_a, LOW);
		digitalWrite(this->pin_b, HIGH);
		break;

	case DC_ENGINE_BACKWARD:
		digitalWrite(this->pin_a, HIGH);
		digitalWrite(this->pin_b, LOW);
		break;

	default:
		break;
	}
}

void dc_engine::stop(void)
{
	digitalWrite(this->pin_a, LOW);
	if (this->engine_type == DC_ENGINE_BI_DIRECTION) {
		digitalWrite(this->pin_b, LOW);
	}
}
