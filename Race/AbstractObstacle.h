#ifndef ABSTRACT_OBSTACLES_H
#define ABSTRACT_OBSTACLES_H

#include "stdafx.h"

#include "Trace.h"
#include "AbstractTrace.h"

class AbstractObstacle {
public:
  AbstractObstacle(AbstractTrace& t);
  virtual void drawObstacles() = 0;
  virtual void next();

protected:
  AbstractTrace& trace_;
  int xCoordinate_;
  int yCoordinate_;
	
  virtual void clearArea();	
};
#endif // !ABSTRACT_OBSTACLES_H
