#include<iostream>
#include <cstdlib>
int main()
{
    int x1,x2,y1,y2;
    std::cin>>x1>>y1;
    std::cin>>x2>>y2;

    if(x2==x1 && y1==y2)
    {
        std::cout<<"SECOND";
    }
    else
    {
        if(x1==x2)
        {
            if(abs(y1-y2)==1)
            {
                std::cout<<"FIRST";
            }
            else
            {
                std::cout<<"DRAW";
            }
        }
        else{
            if(abs(x1-x2)==1)
            {
                std::cout<<"FIRST";
            }
             else
            {
                std::cout<<"DRAW";
            }
        }
    }
}