#ifndef TRACE_H
#define TRACE_H

#include <vector>

#include "stdafx.h"

using namespace std;

class Trace {
public:
  Trace(int length, int width);
  vector <vector <char>>& const getTrace();	
  void displayTrace() const;
  int getWidth() const;
  int getLength() const;

private:	
  int length;
  int width;
  void createTrace(int width);
  vector<vector <char>> traceForRace;
  const int WALL = 222;
  const int SPACE = 32;
  const int minLengthOfTrace = 10;
  const int minWidthOfTrace = 10;
};



#endif // !TRACE_H

