#include <iostream>
#include <cstdlib>
#include <bits/stdc++.h>
#include <cstring>

using namespace std;

int main() {
	int TestCase,count=1,sum=0;
	cin>>TestCase;
	while(TestCase--)
	{
        sum=0;
		int x,y;
        string mural;
        cin>>x>>y;
        cin>>mural;
        int cj=0,jc=0,i=0,blanks=0;
        char strarray[mural.size()+1];
        strcpy(strarray, mural.c_str());
        int start=0;
         for(i=0;strarray[i] != '\0';i++)
        {
            if(strarray[i]!='?')
            {
                break;
            }
            start=i;
        }
        for(i=start;strarray[i] != '\0';i++)
        {
            if(strarray[i]=='?')
            {
                blanks++;
                if(strarray[i+1]=='C')
                {
                    if(i-1>=start&&strarray[i-1]=='J')
                    {
                        if(x>y)
                        {
                            strarray[i]='J';
                        }
                        else
                        {
                            strarray[i]='C';
                        }
                    }
                    else{
                        strarray[i]='C';
                    }
                }
                if(strarray[i+1]=='J')
                {
                    if(i-1>=start&&strarray[i-1]=='C')
                    {
                        if(x>y)
                        {
                            strarray[i]='C';
                        }
                        else
                        {
                            strarray[i]='J';
                        }
                    }
                    else{
                        strarray[i]='J';
                    }
                }
                else{
                    if(i-1>=start)
                    {
                        strarray[i]=strarray[i-1];
                    }
                }
                i=i-1;
            }
        }
		if(strarray[i]=='?')
        {
         if(i-1>=0)
         {
             strarray[i]=strarray[i-1];
         }   
         else
         {
             strarray[i]='J';
         }
        }
        for(i=0;strarray[i] != '\0';i++)
        {
            if(strarray[i]=='C'&&strarray[i+1]=='J')
            {
                sum=sum+x;
            }
            if(strarray[i]=='J'&&strarray[i+1]=='C')
            {
                sum=sum+y;
            }
        
        }
		
        //  for(i=0;strarray[i] != '\0';i++)
        // {
        //     cout<<strarray[i];
        // }
        //cout<<endl;
        //cout<<"CJ "<<cj<<" JC "<<jc<<" blanks "<<blanks<<endl;
        cout<<"Case #"<<count<<": "<<sum<<endl;
        count++;
	}
}
