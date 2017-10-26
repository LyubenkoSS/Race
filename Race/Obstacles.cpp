#include "stdafx.h"

#include <vector>
#include <iostream>
#include <map>
#include <time.h>

#include "Trace.h"
#include "Obstacles.h"

Obstacles::Obstacles(Trace& t)
{
  srand(time(0));
  trace = &t;
  yCoordinate = 0;
  xCoordinate = rand() % (trace->getWidth() - 3) + 1;
}

void Obstacles::drawObstacles()
{
  trace->getTrace()[yCoordinate][xCoordinate] = obstacleBody;  
  trace->getTrace()[yCoordinate + 1][xCoordinate] = obstacleBody;
  trace->getTrace()[yCoordinate + 1][xCoordinate + 1] = obstacleBody;
  trace->getTrace()[yCoordinate][xCoordinate + 1] = obstacleBody;
}

void Obstacles::clearArea() 
{
  trace->getTrace()[yCoordinate][xCoordinate] = area;
  trace->getTrace()[yCoordinate + 1][xCoordinate] = area;
  trace->getTrace()[yCoordinate + 1][xCoordinate + 1] = area;
  trace->getTrace()[yCoordinate][xCoordinate + 1] = area;
}

void Obstacles::next()
{
  clearArea();
  yCoordinate++;
  if (yCoordinate < trace->getLength() - 2) {
    yCoordinate++;
  }
  else {
    yCoordinate = 0;
	xCoordinate = rand() % (trace->getWidth() - 3) + 1;
  }
  drawObstacles();
}