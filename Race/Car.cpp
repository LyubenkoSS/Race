#include "stdafx.h"

#include <vector>
#include <algorithm>
#include <iostream>
#include <map>

#include "Trace.h"
#include "Car.h"

Car::Car(Trace& t) {
  trace = &t;
  xCoordinate = trace->getWidth() / 2;
  yCoordinate = trace->getLength() - 5;
  car.reserve(8);
};

void Car::drawCar() {	
  trace->getTrace()[yCoordinate][xCoordinate] = carBody;
  car.push_back(&trace->getTrace()[yCoordinate][xCoordinate]);

  trace->getTrace()[yCoordinate + 1][xCoordinate] = carBody;
  car.push_back(&trace->getTrace()[yCoordinate + 1][xCoordinate]);

  trace->getTrace()[yCoordinate + 2][xCoordinate] = carBody;
  car.push_back(&trace->getTrace()[yCoordinate + 2][xCoordinate]);

  trace->getTrace()[yCoordinate + 3][xCoordinate] = carBody;
  car.push_back(&trace->getTrace()[yCoordinate + 3][xCoordinate]);

  trace->getTrace()[yCoordinate + 1][xCoordinate - 1] = carBody;
  car.push_back(&trace->getTrace()[yCoordinate + 1][xCoordinate - 1]);

  trace->getTrace()[yCoordinate + 1][xCoordinate + 1] = carBody;
  car.push_back(&trace->getTrace()[yCoordinate + 1][xCoordinate + 1]);

  trace->getTrace()[yCoordinate + 3][xCoordinate - 1] = carBody;
  car.push_back(&trace->getTrace()[yCoordinate + 3][xCoordinate - 1]);

  trace->getTrace()[yCoordinate + 3][xCoordinate + 1] = carBody;
  car.push_back(&trace->getTrace()[yCoordinate + 3][xCoordinate + 1]);
}

void Car::clearArea() 
{	
  for (auto it = car.begin(); it < car.end(); ++it) {
    *(*it) = ' ';
  }
  car.clear();
}


void Car::turnLeft()
{
  clearArea();
  if (canMuveLeft()) {
    xCoordinate--;
  }	
  drawCar();
}

void Car::turnRight() 
{
  clearArea();
  if (canMuveRight()) {
    xCoordinate++;
  }	
  drawCar();
}

bool Car::canMuveLeft() const 
{
  if (xCoordinate >= 3) {
	return true;
  }
  return false;
}

bool Car::canMuveRight() const 
{
  if (xCoordinate <= trace->getWidth() - 4) {
	return true;
  }
  return false;
}

bool Car::isCarCrashed() const 
{
  for (auto it = car.begin(); it < car.end(); ++it) {		
	if (*(*it) == area || *(*it) == obstacle) {
	  return true;
	}
  }
  return false;
 }