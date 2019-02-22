#include "stdafx.h"
#include "CBase4618.h"

CBase4618::CBase4618()
{

}
void CBase4618::draw()
{

}
void CBase4618::run()
{
	
	thread t1(&CBase4618::update_thread, this);
	thread t2(&CBase4618::draw_thread, this);
	t1.join();
	t2.join();
	//t1.detach();
	//t2.detach();
	//if (cv::waitKey(1) != 'q');
	cv::waitKey(1);
//do
//{
//update();
//draw();


//} while (cv::waitKey(1) !='q');
}
void CBase4618::update()
{

}
CBase4618::~CBase4618()
{
}
void CBase4618::update_thread(CBase4618* ptr)
{
	while (ptr->_thread_exit == false)
	{
		cout << "T1\n";
		ptr->update();

	}
	
	//return 0;
}
void CBase4618::draw_thread(CBase4618* ptr)
{
	while (ptr->_thread_exit == false)
	{
		
		ptr->draw();
	}
	//return 0;
}