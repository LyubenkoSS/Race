#ifndef RACE_CONTROLLER_H
#define RACE_CONTROLLER_H

#include "stdafx.h"

#include <Windows.h>
#include <conio.h>
#include <ctime>
#include <iostream>

#include "Trace.h"
#include "Car.h"
#include "Obstacles.h"
#include "StatisticData.h"
#include "RaceView.h"

using namespace std;

class RaceController {
  public:
    RaceController(Trace& t, Car& c, Obstacles& o);
	void startGame();

  private:	
	Trace& trace_;
	Car& car_;
	Obstacles& obstacle;	
};




#endif // !RACE_CONTROLLER_H

