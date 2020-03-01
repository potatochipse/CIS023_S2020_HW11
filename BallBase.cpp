// Module:	BallBase.cpp
// Author:  Miguel Antonio Logarta
// Date:    February 28, 2020
// Purpose: Implementation file for base class BallBase
//			Responsible for drawing balls

#include "CIS023_S2020_HW11 Miguel Antonio Logarta.h"

void BallBase::Initialize(HWND hWnd)
{
	// Make GDI graphic a random size of 20 to 50 px
	dSize = GetRandom(20, 50);

	// Get client window dimensions
	RECT rClient;
	GetClientRect(hWnd, &rClient);						// Window

	// Start at the center of the window
	// Half of the client window - half of the size of the ball
	rDim.left = (rClient.right / 2) - (dSize / 2.0);
	rDim.top = (rClient.bottom / 2) - (dSize / 2.0);
	rDim.right = rDim.left + dSize;
	rDim.bottom = rDim.top + dSize;

	// Set a random color
	r = GetRandom(0, 255);
	g = GetRandom(0, 255);
	b = GetRandom(0, 255);

	// Set the x and y speed of the object to a random value between 1 and 20
	pSpeed.x = GetRandom(1, 20);
	pSpeed.y = GetRandom(1, 20);
}

void BallBase::Draw(HDC hdc)
{
	HBRUSH brush = CreateSolidBrush(RGB(r, g, b));
	HBRUSH oldBrush;
	oldBrush = (HBRUSH)SelectObject(hdc, brush);

	// Draw the object
	Ellipse(hdc, rDim.left, rDim.top, rDim.right, rDim.bottom);

	SelectObject(hdc, oldBrush);
	DeleteObject(brush);
}

int BallBase::GetRandom(int iMin, int iMax)
{
	random_device rd;									// Non-deterministic generator
	mt19937 gen(rd());									// To seed mersenne twister
	uniform_int_distribution<> dist(iMin, iMax);		// Distribute results inside center rect

	return dist(gen);
}

RECT BallBase::GetInvalidRect()
{
	rReturn = rDim;										// Start with current size

	// Expand to account for movement
	rReturn.left -= dSize;
	rReturn.top -= dSize;
	rReturn.right += dSize;
	rReturn.bottom += dSize;

	return rReturn;										// Return new (larger) rectangle
}
