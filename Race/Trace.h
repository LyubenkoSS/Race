#ifndef TRACE_H
#define TRACE_H

#include "stdafx.h"

#include "AbstractTrace.h"

class Trace : public AbstractTrace {
  public:
	  Trace(int length, int width);
  
  private:	  
    void createTrace(int width);   
};
#endif // !TRACE_H

