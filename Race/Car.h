#ifndef CAR_H
#define CAR_H

#include "stdafx.h"

#include "Trace.h"
#include <map>

using namespace std;

class Car {
public:
  Car(Trace& t);	
  void drawCar();
  void turnLeft();
  void turnRight();
  bool isCarCrashed() const;
	
private:
  void clearArea();
  bool canMuveLeft() const;
  bool canMuveRight() const;

  Trace* trace;
  int xCoordinate;
  int yCoordinate;
  vector <char*> car;
  static const char carBody = 219;
  static const char area = 32;
  static const char obstacle = 176;  
};
#endif // !CAR_H

