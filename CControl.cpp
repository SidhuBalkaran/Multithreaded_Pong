#include "stdafx.h"
#include "CControl.h"
CControl::CControl()
{
}

void CControl::init_com(int com)
{
	_com.open("COM"+to_string(com));
}
bool CControl::get_data(string mode, string type, string channel, int &result)
{
	
	std::string tx_str=mode+" "+type+" "+channel+"\n";
	std::string rx_str;
	string t;

	char buff[2];
		// Send TX string
		_com.write(tx_str.c_str(), tx_str.length());
		//Sleep(10); // wait for ADC conversion, etc. May not be needed?

		rx_str = "";
		// start timeout count

		double start_time = cv::getTickCount();

		buff[0] = 0;
		// Read 1 byte and if an End Of Line then exit loop
	// Timeout after 1 second, if debugging step by step this will cause you to exit the loop
		while (buff[0] != '\n' && (cv::getTickCount() - start_time) / cv::getTickFrequency() < 1.0)
		{
			if (_com.read(buff, 1) > 0)
			{
				rx_str = rx_str + buff[0];
			}
		}
	
		//printf("RX: %s", rx_str.c_str());
			 t = rx_str.c_str();
			 string result_1 = t.erase(0, 6); //TAKE last characters
			 result = stoi(result_1); //conert to int
}
bool CControl::set_data(string type, string channel, string val)
{
	std::string tx_str='S'+type+" "+channel+" "+val+'\n';
	std::string rx_str;
	string t;

	char buff[2];

		// Send TX string
		_com.write(tx_str.c_str(), tx_str.length());
		//Sleep(10); // wait for ADC conversion, etc. May not be needed?

		rx_str = "";
		// start timeout count
		double start_time = cv::getTickCount();
		buff[0] = 0;
		// Read 1 byte and if an End Of Line then exit loop
	// Timeout after 1 second, if debugging step by step this will cause you to exit the loop
		while (buff[0] != '\n' && (cv::getTickCount() - start_time) / cv::getTickFrequency() < 1.0)
		{
			if (_com.read(buff, 1) > 0)
			{
				rx_str = rx_str + buff[0];
			}
		}
		return TRUE;
}

CControl::~CControl()
{
}

int CControl::get_analog(int value)
{
	int analog= (value*100) / 1022;
	return analog;
}

void CControl::servo()
{
	while (1) {
		for (int i = 0; i <= 165; i+=3)
		{
			set_data("2", "19", to_string(i));
			cout << "\nServo position: " << i;
			Sleep(200);
		}
	}
}
int CControl::get_button()
{
	
	string channel;
	int count = 0;
	int lastd=1;
	int d;
	int p;
		get_data("G", "0", "32", d);
		//Sleep(10);
		if (d != lastd)
		{
			//if (d == 0)
			//{
				//count++;
			//}
				return d;
		}
	
		lastd = d;
		
		//}			
		}

