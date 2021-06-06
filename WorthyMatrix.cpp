#include <iostream>
using namespace std;

int main() {
    
    int testcase;
    cin>>testcase;
    while(testcase--)
    {
        int n,m,k;
        cin>>n>>m>>k;
        int arr[n][m];
        int sum_arr[n+1][m+1]={};
        int sum=0;
        int count=0;
        int i,j;
        for(i=0;i<n;i++)
        {
            sum=0;
            for(j=0;j<m;j++)
            {
                cin>>arr[i][j];
                if(arr[i][j]>=k)
                {
                    count++;
                }
            }
        }
         cout<<endl;
        for( i=1;i<=n;i++)
        {
            for( j=1;j<=m;j++)
            {
                sum_arr[i][j]=sum_arr[i-1][j]+sum_arr[i][j-1]+arr[i-1][j-1]-sum_arr[i-1][j-1];
                cout<<sum_arr[i][j]<<" ";
            }
           cout<<endl;
        }

        int min_val=m>n?n:m;

        for(int s=0;s<min_val;s++)
        {
            for(i=0;i<n;i++)
            {
                for(int i_1=i;i_1<=i+s && i+s<=n;i_1++)
                {
                    cout<<sum_arr[1][i_1]<<" ";
                }
                 cout<<endl;
            }
            
        }

        cout<<count<<endl;
    }
}
