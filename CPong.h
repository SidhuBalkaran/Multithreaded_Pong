#pragma once
#include <string>
#include <iostream>
#include <thread>
#include <conio.h>
#include <istream>
#include "Client.h"
#include "Server.h"
#include "Serial.h"
#include "opencv.hpp"
#include "CBase4618.h"

/**
*
* @brief C++ object used to create a Pong;
*
* This class drwas and updates the paddles on the screen
* Y axis input comes from the joystck.

*
*
* @author Balkaran Sidhu
*
*/
class CPong:public CBase4618 {
public:
	CPong();
	~CPong();

	/** @brief GETS JOYSTICK INPUT.
	*
	* @param NONE.
	* @return nothing to return
	*/
	void update() override;

	/** @brief renders all the graphics on the screen.
	*
	* @param NONE.
	* @return nothing to return
	*/
	void draw() override;
	
	/** @brief resets the position velocity to default.
	*
	* @param NONE
	* @return nothing to return
	*/
	void reset();
	std::mutex show_mutex;
	
	int y_pos;///< Y value JoYSTICK
	const int frameDelay = 1000 / 30;///< 33ms delay
	uint32_t frameStart;///< start time.
	double last;///< previous time
	int score;///< score of player
	int press;///<button output value
};

