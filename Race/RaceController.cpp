#include "stdafx.h"

#include <Windows.h>
#include <ctime>
#include <iostream>

#include "RaceController.h"
#include "Trace.h"
#include "Car.h"
#include "Obstacles.h"
#include "Constants.h"


RaceController::RaceController(AbstractTrace& t, AbstractCar& c, AbstractObstacle& o) : trace_(t),
                                                                                        car_(c),
	                                                                                    obstacle(o)
{
}

void RaceController::startGame()
{
	int speed = 1;
	int distance = 0;
	unsigned int time = 0;

	unsigned int start_time = clock();
	StatisticData data;
	RaceView view(trace_, obstacle, data);

	bool crashedCar = false;
	bool enter = true;
	bool pause = true;

	while (enter) {
		if (GetAsyncKeyState(VK_RETURN)) {
			pause = !pause;
		}
		if (GetAsyncKeyState(VK_ESCAPE)) {
			enter = false;
		}
		if (GetAsyncKeyState(VK_LEFT)) {
			car_.turnLeft();
		}
		if (GetAsyncKeyState(VK_RIGHT)) {
			car_.turnRight();
		}
		if (GetAsyncKeyState(VK_UP)) {
			bool isSpeedLessMax = speed < N::MAXIMAL_SPEED_OF_CAR;
			if (isSpeedLessMax) {
				speed++;
			}
		}
		if (GetAsyncKeyState(VK_DOWN)) {
			if (speed != 1) {
				speed--;
			}
		}

		view.render(pause, speed);

		if (car_.isCarCrashed()) {
			enter = false;
		}
	}
	if (car_.isCarCrashed()) {
		std::cout << "Car Crash" << std::endl;
		std::cout << "Game Over" << std::endl;
	}
	else {
		std::cout << "OUT" << std::endl;
	}
}