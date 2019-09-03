#pragma once

class num_t
{
public:
	/*Constructors*/
	num_t();

	~num_t();
	/* Slectors */
	uint8_t getBase();

private:
	std::string n_num;
	uint8_t n_base;
};