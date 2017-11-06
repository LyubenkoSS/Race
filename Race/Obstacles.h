#ifndef OBSTACLES_H
#define OBSTACLES_H

#include "stdafx.h"

#include "AbstractTrace.h"
#include "AbstractObstacle.h"

class Obstacles : public AbstractObstacle{
public:
  Obstacles(AbstractTrace& t);
  void drawObstacles();
  //void next();

private:
  //void clearArea();	

  //AbstractTrace& trace_;
  //int xCoordinate_;
  //int yCoordinate_;
};
#endif // !OBSTACLES_H

