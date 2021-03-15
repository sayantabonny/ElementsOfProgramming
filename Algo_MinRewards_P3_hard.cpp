#include <vector>
#include <iostream>
#include <numeric>


int minRewards(std::vector<int> scores) {
 std::vector <int> rewards= std::vector <int> (scores.size(),1);
	for(int i=1;i<scores.size();i++)
	{
		if(scores[i]>scores[i-1])
		{
			rewards[i]=rewards[i-1]+1;
		}
	}
	for(int i=scores.size()-2;i>=0;i--)
	{
		if(scores[i]>scores[i+1])
		{
			rewards[i]=std::max(rewards[i+1]+1,rewards[i]);
		}
	}
  return accumulate(rewards.begin(),rewards.end(),0);
}

int main()
{
    std::vector<int> scores{ 8, 4, 2, 1, 3, 6, 7, 9, 5 };
    std::cout<<std::endl<<minRewards(scores);

}

