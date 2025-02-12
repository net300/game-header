#include <iostream>
#include <cstdlib>
#include <conio.h>
#ifdef __WIN32__
#include <windows.h>
#else
#ifdef __unix__
#include <unistd.h>
#endif
#endif
#define up 72
#define down 80
#define right 77
#define left 75
namespace gstd{
    class Game{
    public:
        int maxX;
        int maxY;
        char air;
    };
    class Entity{
    public:    
        int x;
        int y;
        int floor;
        char costume;
    };
    Entity movto(int ax,int ay,int af){
        return {ax,ay,af};
    }
    int wait(int seconds)
    {
        #ifdef __WIN32__
        Sleep(1000*seconds);
        #else
        usleep(1000000*seconds);//Maybe the macos can't run this please call me if it is
        #endif
    }
    #ifdef __WIN32__
        bool keypress(char presskey)//its only for windows user
        {
            char _ch;
            if(_kbhit)
            {
                _ch = _getch();
            }
            return (presskey == _ch);
        }
    #else
        //sorry the like-unix systems keypress() function is coding now.
        //I hope you can wait a moment please.
    #endif
    int clear()
    {
        #ifdef __WIN32__
            system("cls");
        #else
            #ifdef __unix__
                system("clear");
            #else
                #ifdef TARGET_OS_MAC
                system("clear")
                #endif
            #endif
        #endif
    }
    int refresh(Entity in[],Game game,int howmanyE)
    {
        int o=0;
        int k[howmanyE];
        for (int i = 0;i < game.maxY*2+1;i++)
        {
            for (int j = 0;j < game.maxX*2+1;j++)
            {
                for (int n = 0;n < howmanyE;n++)
                {
                    if (game.maxX+in[n].x == j&&game.maxY-in[n].y == i)
                    {
                        k[o] = n;
                        o+=1;
                    }
                    if(n == howmanyE-1&&o>0)
                    {
                        for (int a=0;a<o-1;a++)
                        {
                            if (in[k[a]].floor<in[k[a+1]].floor)
                            {
                                k[a+1]=k[a];
                            }
                            else
                            {
                                continue;
                            }
                        }
                        std::cout << in[(k[o-1])].costume;
                    }
                }
                if(o==0)
                    std::cout << game.air;
                o=0;
            }
            std::cout << std::endl;
        }
    }
}