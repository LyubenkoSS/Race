#ifndef CAR_H
#define CAR_H

#include "stdafx.h"

#include "AbstractTrace.h"
#include "AbstractCar.h"

class Car : public AbstractCar {
public:
  Car(AbstractTrace& t);
  ~Car();
  void drawCar();  
  bool isCarCrashed() const;	
};
#endif // !CAR_H

