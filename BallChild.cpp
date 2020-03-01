// Module:	BallChild.cpp
// Author:  Miguel Antonio Logarta
// Date:    February 28, 2020
// Purpose: Implementation file for child class BallChild

#include "CIS023_S2020_HW11 Miguel Antonio Logarta.h"

bool BallChild::Move(HWND hWnd)
{
	RECT rClient;								// Main window
	GetClientRect(hWnd, &rClient);				// Get Window size

	// Move the object
	rDim.left += pSpeed.x;
	rDim.top += pSpeed.y;
	rDim.right += pSpeed.x;
	rDim.bottom += pSpeed.y;

	// Bounce off the walls
	if (rDim.left <= 0)							// Did it hit the left wall?
		pSpeed.x *= -1;							// Change direction to the right
	if (rDim.top <= 0)							// Did it hit the top?
		pSpeed.y *= -1;							// Change the direction to down
	if (rDim.bottom >= rClient.bottom)			// Did it hit the bottom?
		pSpeed.y *= -1;							// Change the direction to up
	if (rDim.right >= rClient.right)			// Did it hit the right wall?
		pSpeed.x *= -1;							// Change the direction to left

	return TRUE;								// Continue moving
}
