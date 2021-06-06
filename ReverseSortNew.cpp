// C++ program to display all permutations
// of an array using STL in C++

#include <bits/stdc++.h>
#include <algorithm>

using namespace std;

// Function to find the permutations
void findPermutations(int a[], int n, int count, int cost)
{

	// Sort the given array
	sort(a, a + n);
    int flag=0;
	// Find all possible permutations
	//cout << "Possible permutations are:\n";
	do {
		// if(!Reverse(a, n,count,cost))
        // {
        //     flag=1;
        //     break;
        // }
        //Reverse(a, n,count,cost);
        int i=0,j=0,sum=0; int p[n]; int p_location[n];
    for ( i = 0; i < n; i++) {
        //cout << a[i] << "  ";
        p[i]=a[i];
        p_location[p[i]-1]=i;

    }
    cout<<"P values"<<endl;
     for ( i = 0; i < n; i++) {
        cout << p[i] << "  ";

    }
    cout<<endl<<"Next min element location"<<endl;
     for ( i = 0; i < n; i++) {
        cout << p_location[i] << "  ";
    }
    cout<<endl;
    cout << endl;
    for(i=0;i<=n-2;i++)
    {  
                    int min=p[i];int pos=i;
                    // for(j=i;j<n;j++)
                    // {
                    //     if(p[j]<min)
                    //     {
                    //         min=p[j];
                    //         pos=j;
                    //     // cout<<"Found "<<p[j];
                    //     }
                    // }
                   // cout<<p[i]<<" "<<p_location[i]<<endl;
                    pos=p_location[i];
                // cout<<"j="<<pos+1<<endl;
                    j=i;
                    sum=sum+(pos-i+1);
                    cout<<"sum "<<sum<<" i "<<i<<" pos "<<pos<<endl;
                    while(j<pos)
                    {
                        int temp=p[j];
                        p[j]=p[pos];
                        p[pos]=temp;
                        temp=p_location[i];
                        p_location[i];
                        j++;
                        pos--;
                    }

    }
    cout<<"Outside "<<sum<<" cost "<<cost<<endl;
    if(sum==cost)
    {
        cout<<"Case #"<<count<<": ";
        for ( i = 0; i < n; i++) {
        cout << a[i] << "  ";
        }
        cout<<endl;
        flag=1;
        break;
    }
	} while (next_permutation(a, a + n));
    if(flag==0)
    {
        cout<<"Case #"<<count<<": IMPOSSIBLE"<<endl;
    }
}

// Driver code
int main()
{

    int TestCase,count=1,n,cost;
	cin>>TestCase;
	while(TestCase--)
	{
		cin>>n;
        cin>>cost;
        int a[n];
        for(int i=0;i<n;i++)
        {
            a[i]=i+1;
        }
        findPermutations(a, n,count,cost);
        count++;
    }

	

	return 0;
}
