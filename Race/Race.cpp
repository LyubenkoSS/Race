#include "stdafx.h"

#include <Windows.h>
#include <conio.h>
#include <ctime>
#include <iostream>

#include "Trace.h"
#include "Car.h"
#include "Obstacles.h"
#include "StatisticData.h"
#include "RaceController.h"
#include "Constants.h"
#include "RaceView.h"

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