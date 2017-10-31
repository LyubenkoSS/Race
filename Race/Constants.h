#ifndef CONSTANTS_H
#define CONSTANTS_H

#include "stdafx.h"

namespace INT_CONST { 
  static const int STEP_CHANGE_OF_FLOW_DELAy = 20;
  static const int MAXIMAL_SPEED_OF_CAR = 19;
  static const int FLOW_DELAY = 400;

  static const int MIN_LENGTH_OF_TRACE = 10;
  static const int MIN_WIDTH_OF_TRACE = 10;
   
  static const int OBSTACL_RIGHT_MARGIN = 3;
  static const int OBSTACL_BOTTOM_MARGIN = 2;
   
  static const int CAR_BODY_COUNT_PIXELS = 8;
  static const int CAR_BOTTOM_MARGIN = 5;
  static const int CAR_LEFT_MARGIN = 3;
  static const int CAR_RIGHT_MARGIN = 4;
}

namespace PIXEL {
  //Pixel for trace
  static const char TRACE_WALL_PIXEL = 222;
  static const char TRACE_SPACE_PIXEL = 32;

  //Pixel for car
  static const char CAR_BODY_PIXEL = 219;
  
  //Pixel for obstacles
  static const char OBSTACLE_BODY_PIXEL = 176;
}
#endif // !CONSTANTS_H

