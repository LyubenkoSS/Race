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
	
	system("pause");
	return 0;
}