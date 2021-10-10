#include <windows.h>
#include <time.h>
#include <bits/stdc++.h>
#define screen_x 80
#define screen_y 25
#define scount 80
using namespace std;
HANDLE wHnd;
int color=7;
int Xx,Yy;
int crash=10;
char ship[6]= "<-0->";
bool CStar;
CHAR_INFO consoleBuffer[screen_x * screen_y];
COORD bufferSize = { screen_x,screen_y };
COORD characterPos = { 0,0 };
SMALL_RECT windowSize = { 0,0,screen_x-1,screen_y-1 };
COORD star[scount];
COORD Star;
HANDLE rHnd;
DWORD fdwMode;
int setConsole(int x, int y)
{
wHnd = GetStdHandle(STD_OUTPUT_HANDLE);
SetConsoleWindowInfo(wHnd, TRUE, &windowSize);
SetConsoleScreenBufferSize(wHnd, bufferSize);
return 0;
}

void fill_star_to_buffer()
{
    int j=0;
    /*while(i<80)
    {
        consoleBuffer[star[i].X + screen_x * star[i].Y].Char.AsciiChar = '*';
        consoleBuffer[star[i].X + screen_x * star[i].Y].Attributes = 7;
        i++;
        for(int k=Xx-2;k<=Xx+2;k++)
        {
            if(star[i].X==k&&star[i].Y==Yy)
             crash--;
        }
    }*/
    //For Only One Star
    for(int i=Xx-2;i<=Xx+2;i++,j++)
    {
        consoleBuffer[i + screen_x * Yy].Char.AsciiChar = ship[j];
        consoleBuffer[i + screen_x * Yy].Attributes = color;
        consoleBuffer[Star.X + screen_x * Star.Y].Char.AsciiChar = '*';
        consoleBuffer[Star.X + screen_x * Star.Y].Attributes = 7;
        if(i==Star.X&&Yy==Star.Y)
        {
            crash--; CStar=true;
        }
    } 
}

void clear_buffer()
{
    for (int y = 0; y < screen_y; ++y) 
    {
        for (int x = 0; x < screen_x; ++x) 
        {
        consoleBuffer[x + screen_x * y].Char.AsciiChar = ' ';
        consoleBuffer[x + screen_x * y].Attributes = 0;
        }
    }
}

void init_star()
{
    for(int i=0;i<scount;i++)
    {
        star[i].X=rand()%80;
        star[i].Y=rand()%25;
    }
}

void setStar()
{
    Star.X=rand()%80;
    Star.Y=rand()%25;
    CStar = false;
}

void star_fall()
{
    int i;
    for (i = 0; i < scount; i++) 
    {
        if (star[i].Y >= screen_y-1) {
            star[i] = { short((rand() % screen_x)),1 };
        }
        else {
            star[i] = { star[i].X, short(star[i].Y+1) };
        }
    }
}

void fill_buffer_to_console()
{
WriteConsoleOutputA(wHnd, consoleBuffer, bufferSize, characterPos,
&windowSize);
}

int setMode()
{
    rHnd = GetStdHandle(STD_INPUT_HANDLE);
    fdwMode = ENABLE_EXTENDED_FLAGS | ENABLE_WINDOW_INPUT |
    ENABLE_MOUSE_INPUT;
    SetConsoleMode(rHnd, fdwMode);
    return 0;
}

//main
/*int main()
{
    int i;
    srand(time(NULL));
    setConsole(screen_x, screen_y);
    init_star();
    i = 0;
    while (i < 1000)
    {
        star_fall();
        clear_buffer();
        fill_star_to_buffer();
        fill_buffer_to_console();
        Sleep(200);
        i++;
    }
    return 0;
}*/
int main()
{
    bool play = true;
    srand(time(NULL));
    DWORD numEvents = 0;
    DWORD numEventsRead = 0;
    setConsole(screen_x, screen_y);
    setMode();
    setStar();
    while (play)
    {
        GetNumberOfConsoleInputEvents(rHnd, &numEvents);
        if (numEvents != 0) {
            INPUT_RECORD* eventBuffer = new INPUT_RECORD[numEvents];
            ReadConsoleInput(rHnd, eventBuffer, numEvents, &numEventsRead);
            for (DWORD i = 0; i < numEventsRead; ++i) 
            {
                if (eventBuffer[i].EventType == KEY_EVENT && eventBuffer[i].Event.KeyEvent.bKeyDown == true ) {
                    if (eventBuffer[i].Event.KeyEvent.wVirtualKeyCode == VK_ESCAPE) {
                        play = false;
                    }
                    if (eventBuffer[i].Event.KeyEvent.uChar.AsciiChar == 'c'){
                        color = rand()%16;
                    }
                }
                else if (eventBuffer[i].EventType == MOUSE_EVENT) {

                    int posx = eventBuffer[i].Event.MouseEvent.dwMousePosition.X;
                    int posy = eventBuffer[i].Event.MouseEvent.dwMousePosition.Y;

                    if (eventBuffer[i].Event.MouseEvent.dwButtonState & FROM_LEFT_1ST_BUTTON_PRESSED) {
                        color = rand()%16;
                    }
                    else if (eventBuffer[i].Event.MouseEvent.dwEventFlags & MOUSE_MOVED) {
                        Xx=posx;
                        Yy=posy;
                    }
                }
            }
            delete[] eventBuffer;
        }
        //star_fall();
        clear_buffer();
        fill_star_to_buffer();
        fill_buffer_to_console();
        
        if(crash<=0)
            play=false;
        if(CStar)
            setStar();
        Sleep(200);
    }
    return 0;
}