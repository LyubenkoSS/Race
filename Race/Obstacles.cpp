#include "stdafx.h"

#include <time.h>

#include "Trace.h"
#include "Obstacles.h"
#include "Constants.h"

Obstacles::Obstacles(AbstractTrace& t) : AbstractObstacle(t)
{
}

void Obstacles::drawObstacles()
{
  trace_.getTrace()[yCoordinate_][xCoordinate_] = P::OBSTACLE_BODY_PIXEL;
  trace_.getTrace()[yCoordinate_ + 1][xCoordinate_] = P::OBSTACLE_BODY_PIXEL;
  trace_.getTrace()[yCoordinate_ + 1][xCoordinate_ + 1] = P::OBSTACLE_BODY_PIXEL;
  trace_.getTrace()[yCoordinate_][xCoordinate_ + 1] = P::OBSTACLE_BODY_PIXEL;
}