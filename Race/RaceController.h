#ifndef RACE_CONTROLLER_H
#define RACE_CONTROLLER_H

#include "stdafx.h"

#include "AbstractTrace.h"
#include "Car.h"
#include "Obstacles.h"
#include "RaceView.h"
#include "AbstractCar.h"
#include "AbstractObstacle.h"

using namespace std;

class RaceController {
public:
  RaceController(AbstractTrace& t, AbstractCar& c, AbstractObstacle& o);
  void startGame();

private:
  AbstractTrace& trace_;
  AbstractCar& car_;
  AbstractObstacle& obstacle;
};
#endif // !RACE_CONTROLLER_H
