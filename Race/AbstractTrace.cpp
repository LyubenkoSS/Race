#include "stdafx.h"

#include <iostream>

#include "AbstractTrace.h"
#include "Constants.h"

AbstractTrace::AbstractTrace(int length, int width) :
	length_(length > N::MIN_LENGTH_OF_TRACE ? length : N::MIN_LENGTH_OF_TRACE),
	width_(width > N::MIN_WIDTH_OF_TRACE ? width : N::MIN_WIDTH_OF_TRACE),
	traceForRace_(length)
{}

AbstractTrace::~AbstractTrace()
{}

std::vector<std::vector <char>>&  AbstractTrace::getTrace()
{
	bool empty = traceForRace_[0].empty();
	if (empty) {
	  createTrace(width_);
	}
	return traceForRace_;
}

void AbstractTrace::displayTrace() const
{
	for (auto i = traceForRace_.begin(); i < traceForRace_.end(); ++i) {
	  for (auto j = i->begin(); j < i->end(); ++j) {
		std::cout << *j;
	  }
	  std::cout << std::endl;
	}
}

inline int AbstractTrace::getLength() const
{
	return length_;
}

inline int AbstractTrace::getWidth() const
{
	return width_;
}