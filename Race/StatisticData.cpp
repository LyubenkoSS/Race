#include "stdafx.h"

#include <ctime>

#include "StatisticData.h"

StatisticData::StatisticData() : speed_(1), distance_(0), startTime_(clock())
{}

StatisticData::StatisticData(const StatisticData& sd) : speed_(sd.getSpeed()), distance_(sd.getDistance()), startTime_(sd.getStartTime())
{}

void StatisticData::setDistance(int distance)
{
	StatisticData::distance_ = distance;
}

int StatisticData::getDistance() const
{
	return distance_;
}

void StatisticData::setSpeed(int speed)
{
	StatisticData::speed_ = speed;
}

int StatisticData::getSpeed() const
{
	return speed_;
}

void StatisticData::setStartTime(int time)
{
	startTime_ = time;
}

int StatisticData::getStartTime() const
{
	return startTime_;
}

void StatisticData::increaseDistance()
{
	distance_++;
}

void StatisticData::increaseSpeed()
{
	speed_++;
}

void StatisticData::decreaseSpeed()
{
	speed_--;
}
