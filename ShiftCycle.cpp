#include<iostream>
#include<math.h>
int main()
{
    int t,n,k;
    std::cin>>t;
    while(t--)
    {
        std::cin>>n;
        std::cin>>k;
        int ar[n];
        for(int i=0;i<n;i++)
        {
            std::cin.get()>>ar[i];
        }
        
        int count,max_val=0,max_pos=0,pos,value,start,index=0;bool flag=false;;
        int ar1[n];
        for(int i=0;i<n;i++)
        {
            count=n;
            start=pos=i; value=0;
            while(count--)
            {
                if(pos>=n)
                {
                    pos=0;
                }
                //std::cout<<"Pos "<<pos<< " value "<<value<< " start "<<start<<" coount "<<count<< "\n";
                value=value+(ar[pos]*pow(2,count));
               // std::cout<<"Pos "<<pos<< " ar [ ]"<<ar[pos]<<" value "<<value<< " start "<<start<<" coount "<<count<< "\n";
                pos++;
            }
            //std::cout<<value<<"\n ";
            if(value>=max_val)
            {
                if(value==max_val)
                {
                    ar1[index]=start;
                    index++;
                    //std::cout<<"yoooooooo"<<index;
                    flag=true;
                }
                max_val=value;
                max_pos=start;
            }
        }
        std::cout<<" -------------- \n"<<"max pos "<<max_pos<<" index "<<index<<"\n";
        int result;
        if(flag==false)
        {
            result=max_pos+((k-1)*n);
        }
        else
        {
            result=(k/index+1)+ar[(k-1%index)];
        }
         
        std::cout<<result<<"\n";
    }
}