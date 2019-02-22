#pragma once

#include "CControl.h"
#include "opencv.hpp"
#include <thread>
using namespace std;

/**
*
* @brief C++ object used to hold common code used in all of the following labs for this course
*
* This class has a CControl object and an Open cv object
* which are used in CSketch class.There will also be three public methods
* which implement the two of which are overloaded in CSketch.
*
*
* @author Balkaran Sidhu
*
*/
class CBase4618
{
public:
	CControl control;
	cv::Mat _canvas;
	CBase4618();
	~CBase4618();

	/** @brief Overloaded in CSketch updates the coordinates.
	*
	*
	* @param None.
	* @return nothing to return
	*/
	virtual void update();

	/** @brief Overloaded in CSketch to draw.
	*
	*
	* @param NONE.
	* @return nothing to return
	*/
	virtual void draw();

	/** @brief runs update and draw in an infinite loop until a button is pressed.
	*
	*
	* @param NONE.
	* @return Nothing to return
	*/
	virtual void run();	
	static void update_thread(CBase4618* ptr);
	static void draw_thread(CBase4618* ptr);
	bool _thread_exit=false;
};

