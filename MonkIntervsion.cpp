/*
 * MonkIntervsion.h
 *
 *  Created on: Aug 25, 2020
 *      Author: Sayanta
 */

#include <iostream>

int main()
{
	using namespace std;
	int t,n;
	cin >> t;
	while(t)
	{
		t--;
		cin >> n;
		int ar [400];
		for(int i=0;i<n*n;i++)
		{
			cin >> ar[i];
		}
		int max=0; int flag=0; int result=0; int temp=0; int index;
		for(int i=(n*n)-1;i>=0;i--)
		{
			max=ar[i]; flag=0;
			for(int j=i-1;j>=0;j--)
			{
				//cout << " ar[i] " <<ar[i] << " ar[j]"<< ar[j] << " " <<max<<endl;
				if(ar[j]>max)
				{
					//cout<<"Hiii"<<endl;
					max=ar[j];
					index=j;
					flag=1;
				}
			}
			if(flag==1)
			{
				result++;
				temp=ar[index];
				ar[index]=ar[i];
				ar[i]=ar[index];
			}

		}
		cout << result*2 << endl;
	}
	return 0;
}
