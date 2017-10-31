#include "stdafx.h"

#include <Windows.h>
#include <conio.h>
#include <ctime>
#include <iostream>

#include "RaceView.h"
#include "Trace.h"
#include "Car.h"
#include "Obstacles.h"
#include "StatisticData.h"
#include "Constants.h"

RaceView::RaceView(Trace& t, Car& c, Obstacles& o, StatisticData& s) : trace_(t), car_(c), obstacle_(o), data_(s)
{

};

void RaceView::render(bool pause, int speed)
{
	if (pause) {
	  data_.setSpeed(speed);
	  obstacle_.next();		
	  trace_.displayTrace();
	  unsigned int end_time = clock();
	  int time = end_time - data_.getStartTime();
	  data_.increaseDistance();		
	  std::cout << "distance: " << data_.getDistance() << "m" << std::endl;
	  std::cout << "speed: " << data_.getSpeed() << std::endl;
	  std::cout << "time: " << time / 1000 << "c" << std::endl;
	  Sleep(INT_CONST::FLOW_DELAY - data_.getSpeed() * INT_CONST::STEP_CHANGE_OF_FLOW_DELAy);
	  clearscreen();
	}
	else {
	  clearscreen();
	  std::cout << "Pause";
	  clearscreen();
	  Sleep(INT_CONST::FLOW_DELAY);
	}
}

void RaceView::clearscreen()
{
	HANDLE hOut;
	COORD Position;
	hOut = GetStdHandle(STD_OUTPUT_HANDLE);
	Position.X = 0;
	Position.Y = 0;
	SetConsoleCursorPosition(hOut, Position);
}