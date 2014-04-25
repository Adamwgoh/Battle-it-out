//
//  GameObjects.cpp
//  coursework
//
//  Created by Adam on 4/25/14.
//  Copyright (c) 2014 Adam. All rights reserved.
//

#include "GameObjects.h"
#include "Game.h"

using namespace std;

GameObjects::GameObjects(Game* gEngine, int objX, int objY)
: DisplayableObject(gEngine),
gameEngine(gEngine),
objX(objX),
objY(objY),
objDir(0)
{
    
    
    // The ball coordinate will be the centre of the ball
	// Because we start drawing half the size to the top-left.
	m_iStartDrawPosX = -25;
	m_iStartDrawPosY = -25;
    
	// Record the ball size as both height and width
	m_iDrawWidth = 50;
	m_iDrawHeight = 50;
	
	// Out item at specific coordinates
	m_iPreviousScreenX = m_iCurrentScreenX = objX*50+25+25;
	m_iPreviousScreenY = m_iCurrentScreenY = objY*50+25+40;
    
	// And make it visible
	SetVisible(true);
    
}

GameObjects::~GameObjects(){}

void GameObjects::DoUpdate(int iCurrentTIme){}

void GameObjects::Draw(){
    // Do not draw if it should not be visible
	if ( !IsVisible() )
		return;
    
	int iSize = 25;
    //	int iTick = m_pMainEngine->GetTime()/20; // 1 per 20ms
    //	int iFrame = iTick % 30;
    //	int iSize = 10 + iFrame;
    //	if ( iFrame > 15 )
    //		iSize = 10 + (30-iFrame);
    
	gameEngine->DrawScreenOval(
                               m_iCurrentScreenX - iSize,
                               m_iCurrentScreenY - iSize,
                               m_iCurrentScreenX + iSize-1,
                               m_iCurrentScreenY + iSize-1,
                               0x00ffff );
    
	// Store the position at which the object was last drawn
	// You MUST do this to ensure that the screen is updated when only drawing movable objects
	// This tells the system where to 'undraw' the object from
	StoreLastScreenPositionAndUpdateRect();
}