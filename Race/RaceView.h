#ifndef RACE_VIEW_H
#define RACE_VIEW_H

#include "stdafx.h"

#include "AbstractTrace.h"
#include "StatisticData.h"
#include "AbstractObstacle.h"

class RaceView {
public:
 RaceView(AbstractTrace& t, AbstractObstacle& o, StatisticData& s);
  void render(bool&, int&);

private:
  AbstractTrace& trace_;
  AbstractObstacle& obstacle_;
  StatisticData& data_;

  void clearscreen();
};
#endif // !RACE_VIEW_H