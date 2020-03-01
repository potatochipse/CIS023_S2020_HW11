// Module:	BallChild.h
// Author:  Miguel Antonio Logarta
// Date:    February 28, 2020
// Purpose: Header file for BallChild.cpp
//			Responsible for controlling the movement of balls


#pragma once
class BallChild :
	public BallBase
{
public:
	bool Move(HWND);			// Calculate new location, return FALSE to start over 
};

