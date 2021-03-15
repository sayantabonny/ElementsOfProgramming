#include<iostream>


int main()
{
    int n,t;
    std::cin>>t;
    while(t--)
    {
            std::cin>>n;
    int ar[n][n];
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            std::cin>>ar[i][j];
        }
    }

    int count=0;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
           for (int x = i; x < n; ++x) {
					for (int y = j; y < n; ++y) {
						if (ar[x][y] < ar[i][j]) count++;
					}
           }
        }
    }
    std::cout<<count<<"\n";
    }

}