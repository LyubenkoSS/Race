#ifndef RACE_VIEW_H
#define RACE_VIEW_H

#include "stdafx.h"

#include <Windows.h>
#include <conio.h>
#include <ctime>
#include <iostream>

#include "Trace.h"
#include "Car.h"
#include "Obstacles.h"
#include "StatisticData.h"

class RaceView{
  public:
	RaceView(Trace& t, Car& c, Obstacles& o, StatisticData& s);
	void render(bool,int);

  private:
    Trace& trace_;
	Car& car_;
	Obstacles& obstacle_;
	StatisticData& data_;

	void clearscreen();
};
#endif // !RACE_VIEW_H
