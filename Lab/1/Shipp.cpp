//Note for Press
#include<bits/stdc++.h>
#include<conio.h>
#include<windows.h>
#include<time.h>
using namespace std;

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

void xy(int x, int y)
{
COORD c = { x, y };
SetConsoleCursorPosition( GetStdHandle(STD_OUTPUT_HANDLE) , c);
}

void draw(int x,int y)
{
    xy(x,y);
    setcolor (2,4);
    cout<<"<-0->";
}

void draw_b(int x,int y)
{
    xy(x,y);
    setcolor (0,15);
    cout<<"^";
}

void erase_ship(int x,int y)
{
    xy(x,y);
    setcolor (0,0);
    cout<<"     ";
}
void erase_b(int x,int y)
{
    xy(x,y);
    setcolor (0,0);
    cout<<" ";
}
char cursor(int x, int y)
{
    HANDLE hStd = GetStdHandle(STD_OUTPUT_HANDLE);
    char buf[2]; COORD c = {x,y}; DWORD num_read;
    if(!ReadConsoleOutputCharacter(hStd,(LPTSTR)buf,1,c,(LPDWORD)&num_read) )
        return '\0';
    else
        return buf[0];

}

int main()
{
    int x=38,y=20;
    vector<int> bx,by;
    setcursor(0);
    char ch='s';
    int LR = 3;
    int score = 0;
    printf("score :%d",score);
    srand(time(NULL));
    xy(rand()%74+2,rand()%10+1);
    cout<<"*";
    char se;
    se='A';

    draw(x,y);
    do 
    {
        if (_kbhit())
        {
            ch=_getch();
            if(ch=='a' && x-1>=0) {erase_ship(x,y); draw(--x,y);}
            if(ch=='d' && x+1<79) {erase_ship(x,y); draw(++x,y);}
            if(ch=='e')
            {
                if(bx.size()>4)
                {
                    for(int j=0;j<bx.size();j++)
                        erase_b(bx[j],by[j]);
                    bx.clear();
                    by.clear();
                }
                by.push_back(y-1);
                bx.push_back(x+2);
            }
            /*if(ch=='a') LR=0;
            if(ch=='d') LR=1;
            if(ch=='s') LR=3;*/
            fflush(stdin);
        }
        if(LR!=3)
        {
            if(LR==0&&x-1>0) { erase_ship(x,y);draw(--x,y); }
            if(LR==1&&x+1<79) { erase_ship(x,y);draw(++x,y); }
        }
        if(bx.size()!=0)
        {
            for(int j=0;j<bx.size();j++)
            {
                if(by[j]==0)
                {
                    erase_b(bx[j],by[j]);
                    bx.erase(bx.begin());
                    by.erase(by.begin());
                    j--;
                }
                else
                {
                    if(cursor(bx[j],by[j]-1)=='*')
                    {
                        erase_b(bx[j],by[j]-1);
                        erase_b(bx[j],by[j]);
                        bx.erase(bx.begin()+j);
                        by.erase(by.begin()+j);

                        Beep(100,200);
                        score++;
                        j--;

                        setcolor (7,0);
                        xy(rand()%74+2,rand()%10+1);
                        cout<<"*";
                        xy(0,0);
                        printf("score :%d",score);
                    }
                    else
                    {
                        erase_b(bx[j],by[j]);draw_b(bx[j],--by[j]);
                    }
                        
                }
            }
        }
        Sleep(100);
    }while (ch!='x');
return 0;
}