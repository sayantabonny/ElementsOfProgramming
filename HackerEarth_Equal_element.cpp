
#include <iostream>
#include <cstdlib>
#include <bits/stdc++.h>


using namespace std;

int main() {
	int TestCase;
	int n=0,i=0,temp,min=INT_MAX,sum=0,diff;
	cin>>TestCase;
	while(TestCase--)
	{
		cin>>n;
		int *p=new int[n];
		set<int, greater<int> > s1;
		for(int i=0;i<n;i++)
		{
			cin>>temp;
			p[i]=temp;
			s1.insert(temp);
		}
		set<int, greater<int> >::iterator itr;
    		
		for (itr = s1.begin(); itr != s1.end(); itr++) 
		{
			sum=0;
			for(i=0;i<n;i++)
			{
				diff=abs(*itr-p[i]);
				if(p[i]-3 <1 && *itr < p[i] && diff==1)
				{
					sum=min;
					cout<<" 1st "<<p[i]<<" "<<*itr<<endl;
					break;
				}
				if(p[i]+3 >100000 && *itr > p[i] && diff==1)
				{
					sum=min;
					cout<<" 2nd "<<p[i];
					break;
				}
				diff=diff%2;
				sum=sum+diff;
			}
			if(sum<min)
			{
				min=sum;
			}
			cout<<sum<<" "<<*itr<<endl;
		}
	   cout <<min<<endl;
	}

   
}


