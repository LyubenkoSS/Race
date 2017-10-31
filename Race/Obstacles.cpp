#include "stdafx.h"

#include <time.h>

#include "Trace.h"
#include "Obstacles.h"
#include "Constants.h"

Obstacles::Obstacles(Trace& t) : trace_(t)
{
  srand(time(0));  
  yCoordinate_ = 0;
  xCoordinate_ = rand() % (trace_.getWidth() - INT_CONST::OBSTACL_RIGHT_MARGIN) + 1;
}

void Obstacles::drawObstacles()
{
  trace_.getTrace()[yCoordinate_][xCoordinate_] = PIXEL::OBSTACLE_BODY_PIXEL;
  trace_.getTrace()[yCoordinate_ + 1][xCoordinate_] = PIXEL::OBSTACLE_BODY_PIXEL;
  trace_.getTrace()[yCoordinate_ + 1][xCoordinate_ + 1] = PIXEL::OBSTACLE_BODY_PIXEL;
  trace_.getTrace()[yCoordinate_][xCoordinate_ + 1] = PIXEL::OBSTACLE_BODY_PIXEL;
}

void Obstacles::clearArea() 
{
  trace_.getTrace()[yCoordinate_][xCoordinate_] = PIXEL::TRACE_SPACE_PIXEL;
  trace_.getTrace()[yCoordinate_ + 1][xCoordinate_] = PIXEL::TRACE_SPACE_PIXEL;
  trace_.getTrace()[yCoordinate_ + 1][xCoordinate_ + 1] = PIXEL::TRACE_SPACE_PIXEL;
  trace_.getTrace()[yCoordinate_][xCoordinate_ + 1] = PIXEL::TRACE_SPACE_PIXEL;
}

void Obstacles::next()
{
  clearArea();
  yCoordinate_++;
  bool isEndOfTrace = yCoordinate_ < trace_.getLength() - INT_CONST::OBSTACL_BOTTOM_MARGIN;
  if (isEndOfTrace) {
    yCoordinate_++;
  }
  else {
    yCoordinate_ = 0;
	xCoordinate_ = rand() % (trace_.getWidth() - INT_CONST::OBSTACL_RIGHT_MARGIN) + 1;
  }
  drawObstacles();
}