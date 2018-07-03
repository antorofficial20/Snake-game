#include<stdio.h>
#include<conio.h>
#include<windows.h>
bool gameover;
const int width=20;
const int height=20;
int x,y,fruitx,fruity,score;
enum eDirection { stop=0,left,right,up,down};
eDirection dir;
void setup()
{
    gameover=false;
    dir=stop;
    x=height/2;
    y=width/2;
    fruitx=rand() % width;
    fruity=rand() % height;
    score=0;
}
void draw()
{
    system("cls");
  int i,j;
    for(i=0;i<width+2;i++)
    printf( "#");
    printf("\n");
    for(i=0;i<height;i++)
    {
        for(j=0;j<width;j++)
        {
            if(j==0)
             printf("#");
            if(i==y && j==x)
            printf("O");
           else if(i == fruity && j == fruitx)
            printf("F");
             else
             printf(" ");
             if(j==width-1)
             printf("#");
        }
        printf("\n");
    }
    for(i=0;i<width+2;i++)
        printf( "#");
        printf("\n");
        printf("Score:%d",score);
}
void input()
{
    if(_kbhit())
    {
        switch(_getch())
        {
        case 'a':
            dir=left;
            break;
        case 'd':
            dir=right;
            break;
        case 's':
            dir=down;
            break;
        case 'w':
            dir=up;
            break;
        case 'x':
            gameover =true;
            break;
        }
    }
}
void logic()
{
 switch(dir)
 {
 case left:
    x--;
    break;
 case right:
    x++;
    break;
 case up:
    y--;
    break;
 case down:
    y++;
    break;
    default:
        break;
 }
        if(x>width || x<0 ||y>height ||y<0)
            gameover=true;
            if(x==fruitx && y==fruity)
            {
                score+=10;
              fruitx=rand() % width;
              fruity=rand() % height;
            }
}
int main()
{
    setup();
    while(!gameover)
    {
        draw();
        input();
        logic();
        Sleep(100);
    }
    //system("pause");
    return 0;
}
