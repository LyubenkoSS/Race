#ifndef TRACE_H
#define TRACE_H

#include <vector>

#include "stdafx.h"

using namespace std;

class Trace {
public:
  Trace(int length, int width);
  Trace& operator= (Trace&& t);
  vector <vector <char>>& const getTrace();	
  void displayTrace() const;
  int getWidth() const;
  int getLength() const;

private:	
  int length;
  int width;
  void createTrace(int width);
  vector<vector <char>> traceForRace;  
  const int minLengthOfTrace = 10;
  const int minWidthOfTrace = 10;
};
#endif // !TRACE_H

