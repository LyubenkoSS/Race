#include "stdafx.h"

#include <vector>
#include <iostream>
#include <map>
#include <time.h>

#include "Trace.h"
#include "Obstacles.h"
#include "PixelFiller.h"

Obstacles::Obstacles(Trace& t)
{
  srand(time(0));
  trace = &t;
  yCoordinate = 0;
  xCoordinate = rand() % (trace->getWidth() - rightMargin) + 1;
}

void Obstacles::drawObstacles()
{
  trace->getTrace()[yCoordinate][xCoordinate] = static_cast<char> (PixelFiller::OBSTACLE_BODY);
  trace->getTrace()[yCoordinate + 1][xCoordinate] = static_cast<char> (PixelFiller::OBSTACLE_BODY);
  trace->getTrace()[yCoordinate + 1][xCoordinate + 1] = static_cast<char> (PixelFiller::OBSTACLE_BODY);
  trace->getTrace()[yCoordinate][xCoordinate + 1] = static_cast<char> (PixelFiller::OBSTACLE_BODY);
}

void Obstacles::clearArea() 
{
  trace->getTrace()[yCoordinate][xCoordinate] = static_cast<char> (PixelFiller::TRACE_SPACE);
  trace->getTrace()[yCoordinate + 1][xCoordinate] = static_cast<char> (PixelFiller::TRACE_SPACE);
  trace->getTrace()[yCoordinate + 1][xCoordinate + 1] = static_cast<char> (PixelFiller::TRACE_SPACE);
  trace->getTrace()[yCoordinate][xCoordinate + 1] = static_cast<char> (PixelFiller::TRACE_SPACE);
}

void Obstacles::next()
{
  clearArea();
  yCoordinate++;
  if (yCoordinate < trace->getLength() - bottomMargin) {
    yCoordinate++;
  }
  else {
    yCoordinate = 0;
	xCoordinate = rand() % (trace->getWidth() - rightMargin) + 1;
  }
  drawObstacles();
}