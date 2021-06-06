#include <iostream>
#include <cstdlib>
#include <bits/stdc++.h>


using namespace std;

int main() {
	int TestCase,count=1,n;
	cin>>TestCase;
	while(TestCase--)
	{
		cin>>n;
		int *p=new int[n];
            for(int i=0;i<n;i++)
            {
                
                cin>>p[i];
            }
            int i=0,j=0,sum=0;
            for(i=0;i<=n-2;i++)
            {  
                int min=p[i];int pos=i;
                for(j=i;j<n;j++)
                {
                    if(p[j]<min)
                    {
                        min=p[j];
                        pos=j;
                       // cout<<"Found "<<p[j];
                    }
                }
               // cout<<"j="<<pos+1<<endl;
                j=i;
                sum=sum+(pos-i+1);
                while(j<pos)
                {
                    int temp=p[j];
                    p[j]=p[pos];
                    p[pos]=temp;
                    j++;
                    pos--;
                }
            }
            cout<<"Case #"<<count<<": "<<sum<<endl;
            count++;
	}
}
