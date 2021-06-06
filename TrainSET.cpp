#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main() {
	int testcases;
	cin>>testcases;
	while(testcases--)
	{
	    int n;
	    cin>>n;
	    string s;
	    int val;
	    map <string, int> true_values;
	    map <string, int> false_values;
	    unordered_set <string> stringSet ;
	    int sum=0;
	    while(n--)
	    {
	        cin>>s>>val;
	        
	        if (stringSet.find(s) == stringSet.end())
	        {
	            if(val==1)
	            {
	                true_values.insert(pair<string, int>(s, 1));
                    false_values.insert(pair<string, int>(s, 0));
	            }
	            else
	            {
	                false_values.insert(pair<string, int>(s, 1));
                    true_values.insert(pair<string, int>(s, 0));
	            }
	        }
	        else
	        {
	            if(val==1)
	            {
	                true_values[s]++;
	            }
	            else
	            {
	                false_values[s]++;
	            }
	        }
	        stringSet.insert(s);
	    }
	    unordered_set<string> :: iterator itr;
	    for (itr = stringSet.begin(); itr != stringSet.end(); itr++)
	    {
            cout<<" str "<<(*itr) << " true "<< true_values[(*itr)]<< " false " << false_values[(*itr)]<<endl;
	        if(true_values[(*itr)]>false_values[(*itr)])
	        {
	            sum=sum+true_values[(*itr)];
	        }
	        else
	        {
	            sum=sum+false_values[(*itr)];
	        }
	    }
	    cout<<sum<<"\n";
	    
	}
}
