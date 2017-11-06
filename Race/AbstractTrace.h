#ifndef ABSTRACT_TRACE_H
#define ABSTRACT_TRACE_H

#include "stdafx.h"

#include <vector>

class AbstractTrace {
public:
  AbstractTrace(int length, int width);
  virtual std::vector <std::vector <char>>& const getTrace();
  virtual void displayTrace() const;
  virtual int getWidth() const;
  virtual int getLength() const;
  virtual ~AbstractTrace();

protected:
  virtual void createTrace(int width) = 0;	
  int length_;
  int width_;
  std::vector<std::vector <char>> traceForRace_;
private:
  
};
#endif // !ABSTRACT_TRACE_H
