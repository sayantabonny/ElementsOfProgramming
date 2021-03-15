#include <iostream>

int main()
{
	int n=0;
	std::cin >> n;
	int arr[n];
	int even=0,odd=0;
	for(int i=0;i<n;i++)
	{
		std::cin>> arr[i];
		if(arr[i]%2)
		{
			odd+=arr[i];
		}
		else
		{
			even+=arr[i];
		}
	}
	int result=(even>odd)?even:odd;
	std::cout<<result;
}
