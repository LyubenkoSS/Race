#include "stdafx.h"

#include <iostream>

#include "Trace.h"
#include "Constants.h"

Trace::Trace(int length, int width) : 
	length_(length = (length > INT_CONST::MIN_LENGTH_OF_TRACE ? length : INT_CONST::MIN_LENGTH_OF_TRACE)),
	width_(width = (width > INT_CONST::MIN_WIDTH_OF_TRACE ? width : INT_CONST::MIN_WIDTH_OF_TRACE)),
	traceForRace_(length) 
{}	

std::vector<std::vector <char>>&  Trace::getTrace()
{
  bool empty = traceForRace_[0].empty();
  if (empty) {		
    createTrace(width_);
  }
  return traceForRace_;
}

void Trace::displayTrace() const 
{	
  for (auto i = traceForRace_.begin(); i < traceForRace_.end(); ++i) {		
    for (auto j = i->begin(); j < i->end(); ++j) {			
	  std::cout << *j;
	}
	std::cout << std::endl;
  }
}

void Trace::createTrace(int width) 
{	
  for (auto i = traceForRace_.begin(); i < traceForRace_.end(); ++i) {		
	  std::vector<char> widthOfTrace(width);
	for (auto j = widthOfTrace.begin(); j < widthOfTrace.end(); ++j){
	  bool isWallOfTrace = j == widthOfTrace.begin() || j == (widthOfTrace.end() - 1);
	  if (isWallOfTrace) {
	    *j = PIXEL::TRACE_WALL_PIXEL;
	  }
	  else {
	    *j = PIXEL::TRACE_SPACE_PIXEL;
	  }
	}
	*i = widthOfTrace;
  }
}

int Trace::getLength() const 
{
  return length_;
}

int Trace::getWidth() const 
{
  return width_;
}