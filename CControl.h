
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

using namespace std;

/**
*
* @brief C++ object used for communication with the embedded system
*
* This class has a serial port object and an init_com method
* which initializes the serial port to the com port passed as
* a parameter to the method.There will also be two public methods
* which implement the serial communication protocol
*
*
* @author Balkaran Sidhu
*
*/
class CControl{
private:
	Serial _com;

public:

	CControl();
	~CControl();

	int x; ///< X value JoYSTICK
	int y; ///< Y  vakue JOYSTICK

 /** @brief Sets the desired COM port.
	*
	* @param COM port string.
	* @return nothing to return
 */
	void init_com(int com);//string comport);

 /** @brief Gets data on a digital or analog channel.
 *
 * @param strings of Mode used to select GET or SET.
 * @param strings of type used to select Digital,Analog or Servo.
 *@param strings of channel used select the the channel to read from.
 *@param strings of result passed by referance.
 * @return returns TRUE or FALSE
 */
	bool get_data(string mode,string type, string channel, int &result);

	/** @brief SETs data on a digital channel.
 *
 *
 * @param strings of type used to select Digital,Analog or Servo.
 *@param strings of channel used select the the channel to write to.
 *@param strings of valued on a channel used select the the channel to write to.
 * @return returns TRUE or FALSE
*/
	bool set_data(string type, string channel, string val);

	/** @brief Returns a percent scale value of the joystick position.
*
* @param integer value:raw value of joystick.
*
* @return returns percent scale value.
*/
	int get_analog(int value);

	/** @brief Debounces the puch button.
*
* @param none.
*
* @return nothing to return.
*/
	int get_button();

	/** @brief Displayes servo position.
*
* @param none.
*
* @return nothing to return.
*/
	void servo();
};
