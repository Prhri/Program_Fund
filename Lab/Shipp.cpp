//Note for Press
#include<bits/stdc++.h>
#include<conio.h>
#include<windows.h>
using namespace std;
int x=38,y=20;
COORD old;
COORD c = {x,y};
COORD bullet[5];
bool fire=false;
void erase_ship()
{
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), old);
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0);
    cout<<"     ";
}

void setcursor(bool visible)
{
    HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_CURSOR_INFO lpCursor;
    lpCursor.bVisible = visible;
    lpCursor.dwSize = 20;
    SetConsoleCursorInfo(console,&lpCursor);
}

void setcolor(int fg,int bg)
{
HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
SetConsoleTextAttribute(hConsole, bg*16+fg);
}

void draw(int X,int Y)
{
    old = c;
    erase_ship();
    if(X>=0&&Y>=0&&X<80&&Y<80)
    {
    c.X = X;
    c.Y = Y;
    old = c;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), c);
    setcolor (2,4);
    cout<<"<-0->";
    }
    else
    {
        if(x<0)
            x=0;
        if(y<0)
            y=0;
        if(x>74)
            x=79;
        if(y>79)
            y=79;
        draw(x,y);    
    }
}

void shoot()
{
    if(fire)
    {
        for(int i=0;i<5;i++)
        {
            bullet[i].X=c.X+2;
            bullet[i].Y=c.Y+i*2-1;
        }
        while(bullet[4].Y>0)
        {
            for(int i=0;i<5;i++)
            {
                if(bullet[i].Y<c.Y&&bullet[i].Y>0)
                {
                    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), bullet[i]);
                    setcolor(0,0);
                    cout<<" ";
                    bullet[i].Y--;
                    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), bullet[i]);
                    setcolor(0,15);
                    cout<<" ";
                }
                else
                    bullet[i].Y--;
            }
            Sleep(30);
        }
        SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), bullet[4]);
        setcolor(0,0);
        cout<<" ";
        fire=false;
    }
}

int main()
{
    setcursor(0);
    char ch=' ';
    cout<<"     Press E to Shoot";
    //Additional Function
    // Use for select manual or auto
    char se;
    //cin>>se;
    se='A'; //Auto Select Auto move control
    draw(x,y);
    do 
    {
        if (_kbhit())
        {
            ch=_getch();
            if(se=='M')
            {
            //Manual Control if user enter M
            if(ch=='a') draw(--x,y);
            if(ch=='d') draw(++x,y);
            if(ch=='w') draw(x,--y);
            if(ch=='s') draw(x,++y);
            if(ch=='e') shoot();
            }
            else //else Auto Control from line 110 select Auto Move
            {
                while((ch=='a'&& x-1>=0)||(ch=='d'&& x+1<=79))
                {
                Sleep(10);
                if(ch=='a')
                    draw(--x,y);
                if(ch=='d')
                    draw(++x,y);
                }
            }
            if(ch=='e')
                fire=true;
            shoot();
            fflush(stdin);
        }
    }while (ch!='x');
return 0;
}