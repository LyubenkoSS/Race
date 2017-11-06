#include "stdafx.h"

#include <iostream>

#include "Trace.h"
#include "Car.h"
#include "Obstacles.h"
#include "RaceController.h"


int main(int argc, char* argv[])
{
	Trace trace(20, 15);
	trace.getTrace();

	Car car(trace);
	car.drawCar();

	Obstacles obstacle(trace);
	obstacle.drawObstacles();

	RaceController controller(trace, car, obstacle);
	controller.startGame();
	/*int a = 5;
	std::cout << a << std::endl;
	int& b = a;
	std::cout << b << std::endl;
	int* ptr = &a;
	std::cout << *ptr << std::endl;
	ptr = &b;
	std::cout << *ptr << std::endl;
	ptr = 0;
	//int& c = *ptr;
	//c = a;
	std::cout << "/////////////////////" << std::endl;
	
	//std::cout << c << std::endl;
	std::cout << "//////////////////" << std::endl;
	ptr = &a;
	int* ptr2 = &b;
	std::cout << ptr << std::endl;
	std::cout << ptr2 << std::endl;
	int* ptr3 = 0;
	std::cout << ptr3 << std::endl;
	int* cc;*/



	system("pause");
	return 0;
}