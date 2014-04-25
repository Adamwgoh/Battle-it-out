//
//  File.cpp
//  coursework
//
//  Created by Adam on 4/25/14.
//  Copyright (c) 2014 Adam. All rights reserved.
//

#include "Game.h"
#define STR_TITLE 1
#define STR_MAIN  2

using namespace std;

Game::Game(void)
: BaseEngine( 50 )
, g_state(stateInit),write_str(STR_TITLE)

{
    cout<< "constructor ran" << endl;
}

Game::~Game(void){}

void Game::SetupBackgroundBuffer(){
    
    //State switch
    switch (g_state){
        case stateInit:{
            
            DrawStrings();
            FillBackground( 0xF0F0F0 );
            
            // Draw an image loaded from a file.
            ImageData im, im2;
            
            im.LoadImage( "lib/city.jpg" );
           // im2.ShrinkFrom( &im2, 2 );
            if(im.IsLoaded()){
                //im.ResizeTo(&im2, 600, 600, false);
                cout << "Image loaded" << endl;
            }
            //Draw Image
            im.RenderImage( this->GetBackground(),
                                    0, 0,
                                    0, 0,
                                    im.GetWidth(), im.GetHeight() );
    
            break;
        }
            
        case stateMain:
            FillBackground( 0 );
            break;
            
        case statePaused:
            FillBackground( 0xFFFFFF );
            break;
    }
    cout << "painting background black" << endl;
    //Paintbackground
   // FillBackground( 0xFFFFFF );

}

void Game::DrawStrings()
{
    switch (write_str) {
        case STR_TITLE:{
            CopyBackgroundPixels(0, 0, GetScreenWidth(), 30);
            g_pMainFont = m_oFontManager.GetFont( "lib/alphbeta.ttf", 40 );
            DrawScreenString(200, 100, "Battle It Out!", 0x0000000, NULL);
            
            
            g_pMainFont = m_oFontManager.GetFont( "lib/alphbeta.ttf", 20 );
            DrawScreenString(200, 350, "PRESS ENTER TO START", 0xFFFFFF, NULL);
            SetNextUpdateRect(0, 0, GetScreenWidth(), 30);
            
            //set Font back
            g_pMainFont = m_oFontManager.GetFont( "lib/alphbeta.ttf", 16 );
            
            break;
        }
        case STR_MAIN:{
            CopyBackgroundPixels(0, 0, GetScreenWidth(), 30);
            DrawScreenString(150, 10, "Main placement example", 0x0FFFFFF, NULL);
            SetNextUpdateRect(0, 0, GetScreenWidth(), 30);
            break;
        }
        default:
            break;
    }
}

void Game::KeyDown(int iKeyCode)
{
    switch (iKeyCode)
    {
        case SDLK_ESCAPE:
            SetExitWithCode(0);
            exit(9);
            break;
        case SDLK_SPACE:
            cout << "JUMP" << endl;
            switch (g_state) {
                case stateInit:
                    cout << "Initial state" << endl;
                    g_state = stateMain;
                    write_str = STR_MAIN;
                    cout << "In Main state now" << endl;
                    SetupBackgroundBuffer();
                    Redraw(true);
                    break;
                case stateMain:
                    cout << "Main state" << endl;
                    g_state = stateInit;
                    write_str = STR_TITLE;
                    cout << "In initial state now" << endl;
                    SetupBackgroundBuffer();
                    Redraw(true);
                    break;
                default:
                    break;
            }
            break;
        case SDLK_RETURN:
            {
                cout<< "Enter pressed" << endl;
                switch (g_state){
                    case stateInit:
                        g_state = stateMain;
                        write_str = STR_MAIN;
                        SetupBackgroundBuffer();
                        Redraw(true);
                        break;
                    default:
                        break;
                }
            }
            break;
    }
}

//drawing objects on screen
void Game::DrawScreen()
{
    //getBackground
    CopyAllBackgroundBuffer();
    
    DrawStrings();
    
    if( g_state == stateInit)   return;
    
    //draw changing objects
    DrawChangingObjects();
}

