#include "stdafx.h"

#include "Car.h"
#include "Constants.h"

Car::Car(AbstractTrace& t) : AbstractCar(t)
{
}

Car::~Car()
{
}

void Car::drawCar() {	
  trace_.getTrace()[yCoordinate_][xCoordinate_] = P::CAR_BODY_PIXEL;
  car_.push_back(&trace_.getTrace()[yCoordinate_][xCoordinate_]);

  trace_.getTrace()[yCoordinate_ + 1][xCoordinate_] = P::CAR_BODY_PIXEL;
  car_.push_back(&trace_.getTrace()[yCoordinate_ + 1][xCoordinate_]);

  trace_.getTrace()[yCoordinate_ + 2][xCoordinate_] = P::CAR_BODY_PIXEL;
  car_.push_back(&trace_.getTrace()[yCoordinate_ + 2][xCoordinate_]);

  trace_.getTrace()[yCoordinate_ + 3][xCoordinate_] = P::CAR_BODY_PIXEL;
  car_.push_back(&trace_.getTrace()[yCoordinate_ + 3][xCoordinate_]);

  trace_.getTrace()[yCoordinate_ + 1][xCoordinate_ - 1] = P::CAR_BODY_PIXEL;
  car_.push_back(&trace_.getTrace()[yCoordinate_ + 1][xCoordinate_ - 1]);

  trace_.getTrace()[yCoordinate_ + 1][xCoordinate_ + 1] = P::CAR_BODY_PIXEL;
  car_.push_back(&trace_.getTrace()[yCoordinate_ + 1][xCoordinate_ + 1]);

  trace_.getTrace()[yCoordinate_ + 3][xCoordinate_ - 1] = P::CAR_BODY_PIXEL;
  car_.push_back(&trace_.getTrace()[yCoordinate_ + 3][xCoordinate_ - 1]);

  trace_.getTrace()[yCoordinate_ + 3][xCoordinate_ + 1] = P::CAR_BODY_PIXEL;
  car_.push_back(&trace_.getTrace()[yCoordinate_ + 3][xCoordinate_ + 1]);
}

bool Car::isCarCrashed() const 
{
  for (auto it = car_.begin(); it < car_.end(); ++it) {	
	bool isCrash = *(*it) == P::TRACE_SPACE_PIXEL ||
		           *(*it) == P::OBSTACLE_BODY_PIXEL;
	if (isCrash) {
	  return true;
	}
  }
  return false;
 }