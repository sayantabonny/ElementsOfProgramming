#include<iostream>
#include<set>
#include<vector>

using namespace std;

int main()
{
    int m[4][4] = {{1,0,0,1},{0,1,1,0},{0,1,1,1},{1,0,1,1}};
    int group=0;
     
    vector<set<int>> groups {{1,1}};
    //cout<<groups.size()<<endl;
    for(int i=0;i<4;i++)
    {
        for(int j=0;j<4;j++)
        {
            if(m[i][j]==1)
            {
                int flag=1;
                for(int k=0;k<groups.size();k++)
                {
                   cout<<" row "<<i<<" column "<<j<<endl;
                    
                    auto it2 = groups[k].find(i+1);  
                    auto it1 = groups[k].find(j+1);  
                    if(it1 == groups[k].end())
                    {
                        cout<<" NOT FOUND "<<j+1<<" at "<<k<<endl;
                    }

                    if(it2 == groups[k].end())
                    {
                        cout<<" NOT FOUND "<<i+1<<" at "<<k<<endl;
                    }
                    

                    if ( it1 != groups[k].end() || it2 != groups[k].end()) { 
                         groups[k].insert(i+1);
                         groups[k].insert(j+1);
                         flag=-1;
                    }
                    
                }
                if(flag==1)
                {
                       set<int> temp {i+1,j+1} ;
                        groups.push_back(temp); 
                }
                 
                
            }
        }
    }
    set<int>::iterator itr;
     for(int k1=0;k1<groups.size();k1++)
                    {
                        cout<<"SET "<<k1+1<<endl;
                        for (itr = groups[k1].begin(); itr != groups[k1].end(); itr++)
                        {
                            cout <<*itr<<" ";
                        }
                        cout<<endl;
                    }
    cout<<groups.size()<<endl;
}