#ifndef CAR_H
#define CAR_H

#include "stdafx.h"

#include "Trace.h"

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

  Trace& trace_;
  int xCoordinate_;
  int yCoordinate_;
  std::vector <char*> _car;  
};
#endif // !CAR_H

