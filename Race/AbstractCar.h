#ifndef ABSTRACT_CAR_H
#define ABSTRACT_CAR_H

#include "stdafx.h"

#include <memory>

#include "AbstractTrace.h"

class AbstractCar {
public:
  AbstractCar(AbstractTrace& t);
  virtual ~AbstractCar();
  virtual void drawCar() = 0;
  virtual void turnLeft();
  virtual void turnRight();
  virtual bool isCarCrashed() const = 0;

protected:
  AbstractTrace& trace_;
  int xCoordinate_;
  int yCoordinate_;
  std::vector <std::unique_ptr<char>> car_;

private:
  virtual void clearArea();
  virtual bool canMuveLeft() const;
  virtual bool canMuveRight() const;  
};
#endif // !ABSTRACT_CAR_H
