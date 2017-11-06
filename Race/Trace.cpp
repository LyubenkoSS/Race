#include "stdafx.h"

#include "Trace.h"
#include "Constants.h"

Trace::Trace(int length, int width) : AbstractTrace(length, width) 
{
}

void Trace::createTrace(int width) 
{	
  for (auto i = traceForRace_.begin(); i < traceForRace_.end(); ++i) {		
    std::vector<char> widthOfTrace(width);
	for (auto j = widthOfTrace.begin(); j < widthOfTrace.end(); ++j){
	  bool isWallOfTrace = j == widthOfTrace.begin() || j == (widthOfTrace.end() - 1);
	  if (isWallOfTrace) {
	    *j = P::TRACE_WALL_PIXEL;
	  }
	  else {
	    *j = P::TRACE_SPACE_PIXEL;
	  }
	}
	*i = widthOfTrace;
  }
}