#include <vector>
#include <iostream>
#include <numeric>

int minRewards(std::vector<int> scores)  {
	std::vector <int> rewards= std::vector<int>(scores.size(),0);
	if(scores.size()<2)
	{
		return accumulate(scores.begin(),scores.end(),0);
	}
  for (int i=1;i<scores.size();i++)
	{
		if(i==1 )
		{
			if(scores[i-1]<scores[i])
			{
				rewards[i-1]=1;
			}
			
		}
		if(i==scores.size()-1)
		{
			if(scores[i]<scores[i-1])
			{
				rewards[i]=1;
			}
		}
		else if(scores[i]<scores[i-1]&&scores[i]<scores[i+1])
		{
			rewards[i]=1;
		}
	}
// 	  for(int i=0;i<rewards.size();i++)
//   {
//      std::cout<<rewards[i]<<" "<<scores[i]<<endl;
//  }
// std::cout<<std::endl;
	
	for(int i=0;i<rewards.size();i++)
	{
		int right=0,left=0;
		if(rewards[i]==1)
		{
			right=i+1;
			left=i-1;
			while(right<rewards.size() && rewards[right]!=1 && scores[right]>scores[right-1])
			{
				rewards[right]=std::max(rewards[right-1]+1,rewards[right]);
				right++;
				
			}
			while(left>=0 && rewards[left]!=1 && scores[left]>scores[left+1])
			{
				rewards[left]=std::max(rewards[left+1]+1,rewards[left]);
				left--;
			}
		}
	}
// 	  for(int i=0;i<rewards.size();i++)
//   {
//      std::cout<<rewards[i]<<" "<<scores[i]<<endl;
//  }
// std::cout<<std::endl;
  return accumulate(rewards.begin(),rewards.end(),0);
 }
int main()
{
    std::vector<int> scores{ 8, 4, 2, 1, 3, 6, 7, 9, 5 };
    std::cout<<std::endl<<minRewards(scores);

}
