#include "stdafx.h"

#include <time.h>

#include "Trace.h"
#include "Obstacles.h"
#include "AbstractObstacle.h"
#include "Constants.h"

AbstractObstacle::AbstractObstacle(AbstractTrace& t) : trace_(t), 
                                                       yCoordinate_(0)
{
  srand(time(0));
  xCoordinate_ = rand() % (trace_.getWidth() - N::OBSTACL_RIGHT_MARGIN) + 1;
}

void AbstractObstacle::clearArea()
{
  trace_.getTrace()[yCoordinate_][xCoordinate_] = P::TRACE_SPACE_PIXEL;
  trace_.getTrace()[yCoordinate_ + 1][xCoordinate_] = P::TRACE_SPACE_PIXEL;
  trace_.getTrace()[yCoordinate_ + 1][xCoordinate_ + 1] = P::TRACE_SPACE_PIXEL;
  trace_.getTrace()[yCoordinate_][xCoordinate_ + 1] = P::TRACE_SPACE_PIXEL;
}

void AbstractObstacle::next()
{
  clearArea();
  yCoordinate_++;
  bool isEndOfTrace = yCoordinate_ < trace_.getLength() - N::OBSTACL_BOTTOM_MARGIN;
  if (isEndOfTrace) {
	yCoordinate_++;
  }
  else {
	yCoordinate_ = 0;
	xCoordinate_ = rand() % (trace_.getWidth() - N::OBSTACL_RIGHT_MARGIN) + 1;
  }
  drawObstacles();
}