#include <iostream> 
#include <iterator> 
#include <map> 
int main()
{
	int n=0;
	std::cin >> n;
	std::map<int, int> scores;
	std::map<int, int>::iterator it;
	std::map<int, int>::iterator it1;
	std::map<int, int>::iterator it2;
	int val=1;
	for(int i=0;i<n;i++)
	{
		int temp;
		std::cin>>temp;
		if(scores.find(temp)==scores.end())
		{
			scores.insert({temp,temp});
		}
		else
		{
			it = scores.find(temp); 
			it->second=it->second+temp;
		}

	}
	int sum=0;int result=0;
	for(it=scores.begin();it!=scores.end();it++)
	{
		sum=0;
		std::cout<<"\n"<<it->first<<" "<<it->second<<"\n";
		it1=scores.find(it->first+1);
		it2=scores.find(it->first-1);
		if(it1!=scores.end())
		{
			std::cout<<"+1 sum "<<sum<<"\n";
			sum+=it1->second;

		}
		if(it2!=scores.end())
		{
			std::cout<<"-1 sum "<<sum<<"\n";
			sum+=sum;
		}
		if(sum>it->second)
		{
			std::cout<<"assign sum "<<sum<<" it-> second "<<it->second<<"\n";
			result+=sum;
			it->second=0;
		}
		if((sum<it->second))
		{
			//result+=it->second;

			it1->second=0;
			it2->second=0;
		}
		
		std::cout<<"\n"<<"Result "<<result<<"\n";

	}
	
	std::cout<<result;
	
}
