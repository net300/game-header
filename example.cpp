#include "gameheader.hpp"
using namespace gstd;
int main()
{
    Game ng;
    ng.air = '-';
    ng.maxX = 10;
    ng.maxY = 10;
    Entity e1={2,2,1,'#'};
    Entity e2={0,0,2,'@'};
    Entity e3={3,3,3,'!'};
    while(!keypress(27))
    {
        Entity list[]={e1,e2,e3};
        refresh(list,ng,3);
        wait(2);
        clear();
        if(keypress(down))
        {
            e1.x+=1;
            e1.y+=1;
        }
    }
}