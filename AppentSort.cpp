#include<iostream>
#include <math.h> 

using namespace std;
int main()
{
    int testcases;
    cin>>testcases;
    int c=1;
    while(testcases--)
    {
        int n;
        cin>>n;
        int arr[n];
        int digit[n];
        int temp; int count=0;
        for(int i=0;i<n;i++)
        {
            cin>>arr[i];
            temp=arr[i];
            count=0;
            while(temp>0)
            {
                count++;
                temp=temp/10;
            }
            digit[i]=count;
        }
        count++; int ans=0; int temp_count=0;
        for(int i=1;i<n;i++)
        {
            temp_count=0;
            cout<<"element " <<arr[i]<<endl;
            if(arr[i-1]>=arr[i])
            {
                count=(digit[i-1]-digit[i]);
               // cout<<arr[i]<<" pow "<<pow(10*1.0,count*1.0)<<endl;
                arr[i]=arr[i]*round(pow(10*1.0,count*1.0));
                cout<<"ar[i] "<<arr[i]<<" count  "<<count<<" i-1 "<<arr[i-1]<<endl;
                digit[i]=digit[i]+count;
                if(ar[i-1]>ar[i])
                {
                    if()
                }
                
            }
            ans=ans+count;
        }

        cout<<"Case "<<c<<"#"<<ans<<endl;
        c++;

    }
}