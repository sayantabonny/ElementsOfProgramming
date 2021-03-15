#include <vector>
#include <iostream>
#include <numeric>

int minRewards(std::vector<int> scores) {
 std::vector<int> rewards= std::vector<int>(scores.size(),1);
 for(int i=1;i<scores.size();i++)
 {
     int j=i-1;
     if(scores[j]<scores[i])
     {
         rewards[i]=rewards[j]+1;
     }
     else{
         for(int k=i-1;k>=0 && scores[k]>scores[k+1];k--)
         {
             rewards[k]=std::max(rewards[k],rewards[k+1]+1);
         }
     }
 }
//  for(int i=0;i<rewards.size();i++)
//  {
//      std::cout<<rewards[i]<<" ";
//  }
// std::cout<<std::endl;
  return accumulate(rewards.begin(),rewards.end(),0);
}

int main()
{
    std::vector<int> scores{ 8, 4, 2, 1, 3, 6, 7, 9, 5 };
    std::cout<<std::endl<<minRewards(scores);

}
