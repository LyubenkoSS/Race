#include "stdafx.h"

#include "AbstractCar.h"
#include "Constants.h"

AbstractCar::AbstractCar(AbstractTrace& t) : trace_(t),
                                             xCoordinate_(trace_.getWidth() / 2),
                                             yCoordinate_(trace_.getLength() - N::CAR_BOTTOM_MARGIN)
{
  car_.reserve(N::CAR_BODY_COUNT_PIXELS);
};
AbstractCar::~AbstractCar()
{}

void AbstractCar::clearArea()
{
  for (auto it = car_.begin(); it < car_.end(); ++it) {
	*(*it) = P::TRACE_SPACE_PIXEL;
  }
  car_.clear();
}


void AbstractCar::turnLeft()
{
  clearArea();
  if (canMuveLeft()) {
	xCoordinate_--;
  }
  drawCar();
}

void AbstractCar::turnRight()
{
  clearArea();
  if (canMuveRight()) {
	xCoordinate_++;
  }
  drawCar();
}

bool AbstractCar::canMuveLeft() const
{
  bool isLeftEndOfTrace = xCoordinate_ >= N::CAR_LEFT_MARGIN;
  if (isLeftEndOfTrace) {
	return true;
  }
  return false;
}

bool AbstractCar::canMuveRight() const
{
  bool isRightEndOfTrace = xCoordinate_ <= trace_.getWidth() - N::CAR_RIGHT_MARGIN;
  if (isRightEndOfTrace) {
	return true;
  }
  return false;
}