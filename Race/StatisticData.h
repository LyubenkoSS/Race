#ifndef STATISTIC_DATA_H
#define STATISTIC_DATA_H

#include "stdafx.h"

class StatisticData {
  public:
    StatisticData();
	int getSpeed() const;
	void setSpeed(int);
	int getDistance() const;
	void setDistance(int) ;
	int getStartTime() const;
	void setStartTime(int);
	void increaseDistance();
	void increaseSpeed();
	void decreaseSpeed();
  private:
    int speed_;
	int distance_;
	unsigned int startTime_;

};
#endif // !STATISTIC_DATA_H

