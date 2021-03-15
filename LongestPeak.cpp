#include<iostream>
#include<string>
#include <vector>


int main()
{
    std::vector <int> array {1, 2, 3, 3, 4, 0, 10, 6, 5, -1, -3, 2, 3};


    for(int i=0;i<array.size();i++)
    {
        std::cout<<array[i]<<" ";
    }
    std::cout<<std::endl;
    int flag1=0;
	int flag2=0;
	int count=0,max=0;
	if(array.size()<=3)
	{
		return array.size();
	}
	for (int i=0;i<array.size()-1;i++)
	{
		if( array[i]<array[i+1] && flag2==1)
		{
			count=0;
            flag2=0;
		}
		if(array[i]<array[i+1])
		{
			flag1=1;
			count++;
            //std::cout<<" "<<array[i];
		}
		else if(array[i]>array[i+1] && flag1==1)
		{
			flag2=1;
			count++;
            //std::cout<<" "<<array[i];
			if(max<count)
			{
				max=count;
                //std::cout<<std::endl<<"count "<<count<<std::endl;
			}
		}
		else
		{
			flag1=0;
			flag2=0;
			count=0;
		}
	}
  std::cout<<std::endl<<max;

}