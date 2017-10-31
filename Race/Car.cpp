#include "stdafx.h"

#include "Trace.h"
#include "Car.h"
#include "Constants.h"

Car::Car(Trace& t) : trace_(t)
{
  xCoordinate_ = trace_.getWidth() / 2;
  yCoordinate_ = trace_.getLength() - INT_CONST::CAR_BOTTOM_MARGIN;
  _car.reserve(INT_CONST::CAR_BODY_COUNT_PIXELS);
};

void Car::drawCar() {	
  trace_.getTrace()[yCoordinate_][xCoordinate_] = PIXEL::CAR_BODY_PIXEL;
  _car.push_back(&trace_.getTrace()[yCoordinate_][xCoordinate_]);

  trace_.getTrace()[yCoordinate_ + 1][xCoordinate_] = PIXEL::CAR_BODY_PIXEL;
  _car.push_back(&trace_.getTrace()[yCoordinate_ + 1][xCoordinate_]);

  trace_.getTrace()[yCoordinate_ + 2][xCoordinate_] = PIXEL::CAR_BODY_PIXEL;
  _car.push_back(&trace_.getTrace()[yCoordinate_ + 2][xCoordinate_]);

  trace_.getTrace()[yCoordinate_ + 3][xCoordinate_] = PIXEL::CAR_BODY_PIXEL;
  _car.push_back(&trace_.getTrace()[yCoordinate_ + 3][xCoordinate_]);

  trace_.getTrace()[yCoordinate_ + 1][xCoordinate_ - 1] = PIXEL::CAR_BODY_PIXEL;
  _car.push_back(&trace_.getTrace()[yCoordinate_ + 1][xCoordinate_ - 1]);

  trace_.getTrace()[yCoordinate_ + 1][xCoordinate_ + 1] = PIXEL::CAR_BODY_PIXEL;
  _car.push_back(&trace_.getTrace()[yCoordinate_ + 1][xCoordinate_ + 1]);

  trace_.getTrace()[yCoordinate_ + 3][xCoordinate_ - 1] = PIXEL::CAR_BODY_PIXEL;
  _car.push_back(&trace_.getTrace()[yCoordinate_ + 3][xCoordinate_ - 1]);

  trace_.getTrace()[yCoordinate_ + 3][xCoordinate_ + 1] = PIXEL::CAR_BODY_PIXEL;
  _car.push_back(&trace_.getTrace()[yCoordinate_ + 3][xCoordinate_ + 1]);
}

void Car::clearArea() 
{	
  for (auto it = _car.begin(); it < _car.end(); ++it) {
    *(*it) = PIXEL::TRACE_SPACE_PIXEL;
  }
  _car.clear();
}


void Car::turnLeft()
{
  clearArea();
  if (canMuveLeft()) {
    xCoordinate_--;
  }	
  drawCar();
}

void Car::turnRight() 
{
  clearArea();
  if (canMuveRight()) {
    xCoordinate_++;
  }	
  drawCar();
}

bool Car::canMuveLeft() const 
{
  bool isLeftEndOfTrace = xCoordinate_ >= INT_CONST::CAR_LEFT_MARGIN;
  if (isLeftEndOfTrace) {
	return true;
  }
  return false;
}

bool Car::canMuveRight() const 
{
  bool isRightEndOfTrace = xCoordinate_ <= trace_.getWidth() - INT_CONST::CAR_RIGHT_MARGIN;
  if (isRightEndOfTrace) {
	return true;
  }
  return false;
}

bool Car::isCarCrashed() const 
{
  for (auto it = _car.begin(); it < _car.end(); ++it) {	
	bool isCrash = *(*it) == PIXEL::TRACE_SPACE_PIXEL ||
		           *(*it) == PIXEL::OBSTACLE_BODY_PIXEL;
	if (isCrash) {
	  return true;
	}
  }
  return false;
 }