#ifndef TRACE_H
#define TRACE_H

#include "stdafx.h"

#include <vector>

class Trace {
public:
  Trace(int length, int width);
  
  std::vector <std::vector <char>>& const getTrace();	
  void displayTrace() const;
  int getWidth() const;
  int getLength() const;

private:	  
  void createTrace(int width);

  int length_;
  int width_;
  std::vector<std::vector <char>> traceForRace_;    
};
#endif // !TRACE_H

