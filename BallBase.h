// Module:	BallBase.h
// Author:  Miguel Antonio Logarta
// Date:    February 28, 2020
// Purpose: Header file for BallBase.cpp
//			Responsible for drawing balls

#pragma once
class BallBase
{
public:
	void Initialize(HWND);
	void Draw(HDC);
	int GetRandom(int, int);
	RECT GetInvalidRect();

private:
	double dSize;					// Size of the object
	int r, g, b;					// Variables for color
	RECT rReturn;					// Return value of GetInvalidRect
	
protected:							// Protected variables so that the child classes can access it
	RECT rDim;						// Location and size of star
	POINT pSpeed;					// Speed and direction
};

