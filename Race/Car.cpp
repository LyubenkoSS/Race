#include "stdafx.h"

#include <vector>
#include <algorithm>
#include <iostream>
#include <map>

#include "Trace.h"
#include "Car.h"
#include "PixelFiller.h"

Car::Car(Trace& t) {
  trace = &t;
  xCoordinate = trace->getWidth() / 2;
  yCoordinate = trace->getLength() - bottomMargin;
  car.reserve(carBodyCountPixels);
};

void Car::drawCar() {	
  trace->getTrace()[yCoordinate][xCoordinate] = static_cast<char>(PixelFiller::CAR_BODY);
  car.push_back(&trace->getTrace()[yCoordinate][xCoordinate]);

  trace->getTrace()[yCoordinate + 1][xCoordinate] = static_cast<char>(PixelFiller::CAR_BODY);
  car.push_back(&trace->getTrace()[yCoordinate + 1][xCoordinate]);

  trace->getTrace()[yCoordinate + 2][xCoordinate] = static_cast<char>(PixelFiller::CAR_BODY);
  car.push_back(&trace->getTrace()[yCoordinate + 2][xCoordinate]);

  trace->getTrace()[yCoordinate + 3][xCoordinate] = static_cast<char>(PixelFiller::CAR_BODY);
  car.push_back(&trace->getTrace()[yCoordinate + 3][xCoordinate]);

  trace->getTrace()[yCoordinate + 1][xCoordinate - 1] = static_cast<char>(PixelFiller::CAR_BODY);
  car.push_back(&trace->getTrace()[yCoordinate + 1][xCoordinate - 1]);

  trace->getTrace()[yCoordinate + 1][xCoordinate + 1] = static_cast<char>(PixelFiller::CAR_BODY);
  car.push_back(&trace->getTrace()[yCoordinate + 1][xCoordinate + 1]);

  trace->getTrace()[yCoordinate + 3][xCoordinate - 1] = static_cast<char>(PixelFiller::CAR_BODY);
  car.push_back(&trace->getTrace()[yCoordinate + 3][xCoordinate - 1]);

  trace->getTrace()[yCoordinate + 3][xCoordinate + 1] = static_cast<char>(PixelFiller::CAR_BODY);
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
  if (xCoordinate >= leftMargin) {
	return true;
  }
  return false;
}

bool Car::canMuveRight() const 
{
  if (xCoordinate <= trace->getWidth() - rightMargin) {
	return true;
  }
  return false;
}

bool Car::isCarCrashed() const 
{
  for (auto it = car.begin(); it < car.end(); ++it) {		
	if (*(*it) == static_cast<char>(PixelFiller::TRACE_SPACE) || *(*it) == static_cast<char>(PixelFiller::OBSTACLE_BODY)) {
	  return true;
	}
  }
  return false;
 }