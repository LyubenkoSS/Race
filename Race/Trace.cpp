#include "stdafx.h"

#include <vector>
#include <iostream>

#include "Trace.h"

Trace::Trace(int length, int width) : 
	length(length = (length > minLengthOfTrace ? length : minLengthOfTrace)),
	width(width = (width > minWidthOfTrace ? width : minWidthOfTrace)),
	traceForRace(length) 
{}	

vector<vector <char>>&  Trace::getTrace()
{
  if (traceForRace[0].empty()) {		
    createTrace(width);
  }
  return traceForRace;
}

void Trace::displayTrace() const 
{	
  for (auto i = traceForRace.begin(); i < traceForRace.end(); ++i) {		
    for (auto j = i->begin(); j < i->end(); ++j) {			
	  cout << *j;
	}
	cout << endl;
  }
}

void Trace::createTrace(int width) 
{	
  for (auto i = traceForRace.begin(); i < traceForRace.end(); ++i) {		
    vector<char> widthOfTrace(width);
	for (auto j = widthOfTrace.begin(); j < widthOfTrace.end(); ++j){
	  if (j == widthOfTrace.begin() || j == (widthOfTrace.end() - 1)) {
	    *j = static_cast<char> (WALL);
	  }
	  else {
	    *j = static_cast<char> (SPACE);
	  }
	}
	*i = widthOfTrace;
  }
}

int Trace::getLength() const 
{
  return length;
}

int Trace::getWidth() const 
{
  return width;
}