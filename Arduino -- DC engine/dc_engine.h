#pragma once

typedef enum {
	DC_ENGINE_FORWARD = 0,
	DC_ENGINE_BACKWARD,
	DC_ENGINE_DIR_LAST
} dc_engine_direction;

typedef enum {
	DC_ENGINE_SINGLE_DIRECTION = 0,
	DC_ENGINE_BI_DIRECTION,
} dc_engine_type_t;


class dc_engine {
private:
	const dc_engine_direction direction;
	const dc_engine_type_t engine_type;
	const uint8_t pin_a;
	const uint8_t pin_b;

public:
	dc_engine(const uint8_t pin_a);
	dc_engine(const uint8_t pin_a, const uint8_t pin_b);
	~dc_engine();

	void init(void);
	void start(void);
	void start(const dc_engine_direction direction);
	void stop(void);
};