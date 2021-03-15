#include<iostream>


int countMinSquares(int A)
{
    //std::cout<<"A   "<<A<<std::endl;
    int sum=0,i=2,count=1;
    while(true)
    {
        if(i*i>A)
        {
            break;
        }
        i++;
        
    }
    //std::cout<<count<<" ___  "<<(A-((i-1)*(i-1)))<<std::endl;
    if((A-((i-1)*(i-1)))>3)
    {
        count+=countMinSquares((A-((i-1)*(i-1))));
    }
    else
    {
        
        count+=(A-((i-1)*(i-1)));
    }
    
    return count;
}


int main()
{
    int i;
    std::cin>>i;

   std::cout<<countMinSquares(i);
}

