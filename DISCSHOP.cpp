#include <iostream>
using namespace std;

int main() {
	int testcase;
	string n; int min=99999,count=0,num=0;
    cin>>testcase;
	while(testcase>0)
	{
	    cin>>n;
	    min=99999;
        for(int i=0; i<n.size();i++)
        {
            num=stoi(n.substr(0,i)+n.substr(i+1,n.size()));
           // cout<<" Inside "<<num<<endl;
            if(min>num)
            {
                min=num;
            }
        }
	    cout<<min<<"\n";
	    testcase--;
	}
	return 0;
}
