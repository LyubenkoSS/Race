#include "stdafx.h"

#include <Windows.h>
#include <conio.h>
#include <ctime>
#include <iostream>

#include "Trace.h"
#include "Car.h"
#include "Obstacles.h"
using namespace std;

void clearscreen();

int main(int argc, char* argv[])
{	
  Trace t(20, 15);
  t.getTrace();
  Car car(t);
  car.drawCar();	
  Obstacles obstacle(t);
  obstacle.drawObstacles();
	
  int speed = 1;
  int distance = 0;
  unsigned int time = 0;	

  unsigned int start_time = clock();

  bool crashedCar = false;
  bool exit = true;
  bool pause = true;

  while (exit){
	if (GetAsyncKeyState(VK_RETURN)) {
	  pause = !pause;				
	}
	if (GetAsyncKeyState(VK_ESCAPE)) {
	  exit = false;
	}
	if (GetAsyncKeyState(VK_LEFT)) {
	  car.turnLeft();
	}
	if (GetAsyncKeyState(VK_RIGHT)) {
	  car.turnRight();
	}
	if (GetAsyncKeyState(VK_UP)) {
	  if (speed < 19) speed++;
	}
	if (GetAsyncKeyState(VK_DOWN)) {
	  if (speed != 1) speed--;
	}
	if (pause) {			
	  obstacle.next();
	  if (car.isCarCrashed()) {
		exit = false;
	  }
	  t.displayTrace();
	  unsigned int end_time = clock();
	  time = end_time - start_time;
      distance++;
	  cout << "distance: " << distance << "m" << endl;
      cout << "speed: " << speed << endl;
	  cout << "time: " << time / 1000 << "c" << endl;
	  Sleep(400 - speed * 20);
      clearscreen();
	}
	else {
	  clearscreen();
	  cout << "Pause";
	  clearscreen();
	  Sleep(500);				
    }
  }
  if (car.isCarCrashed()) {
    cout << "Car Crash" << endl;
	cout << "Game Over" << endl;
  }
  else {
  cout << "OUT" << endl;
  }	
  system("pause");
  return 0;
}

void clearscreen()
{
  HANDLE hOut;
  COORD Position;
  hOut = GetStdHandle(STD_OUTPUT_HANDLE);
  Position.X = 0;
  Position.Y = 0;
  SetConsoleCursorPosition(hOut, Position);
}