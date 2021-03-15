#include<iostream>
#include<string>

std::string Palindrome(int i, int j, std::string s)
{
           int len=j-i+1;
           std::cout<<"len "<<len<<" i "<<i<<" j "<<j<<std::endl;
           while(true)
           {
               i--;
               j++;
               if(i<0 || j > s.length()-1 )
               {
                   i++;
                   break;
               }
                if(s[i]!=s[j])
               {
                   i++;
                   break;
               }
               if(s[i]==s[j])
               {
                   len=len+2;;
               }
           }
           std::cout<<"  "<<len<<" i "<<i<<std::endl;
           return s.substr(i,len);
       
}
int main()
{
    std::string s;
    std::cin>>s;
    /*int start=0;
    int end=s.length()-1;
    while(start<=end)
    {
        if(s[start]!=s[end])
        {
            break;
        }
        start++;
        end--;
    }
    if(start>end)
    {
        std::cout<<"Palindrome";
    }
    else
    {
        std::cout<<"Not Palindrome";
    }
    */

   int s1=0; int i=1,j=0,len=0,max_len=0; std::string str,str1="\0",str2="\0"; int flag=0,flag1=0;
   int s2=0;
   for(int c=0;c<s.length()-1;c++)
   {
       if(s[c]!=s[c+1])
       {
           flag1=1;
           break;
       }
   }
   for(int c=0;((c+1)<s.length() ||(c+2)<s.length())&&flag1==1;c++)
   {
       if(s[c]==s[c+1])
       {
           str1=Palindrome(c,c+1,s);
           flag=1;
       }
      // std::cout<<"hoho ";
       if(c+2<s.length() && s[c]==s[c+2])
       {
           str2=Palindrome(c,c+2,s);
           flag=1;
       }
       std::cout<<"str1  "<<str1<<"str2  "<<str2<<" len1 "<<str1.length()<<" len2 "<<str2.length()<<std::endl;
       str1=(str1.length()>str2.length())?str1:str2;
       if(max_len<str1.length())
       {
           max_len=str1.length();
           str=str1;
           
       }
       str1="\0";
       str2="\0";
   }
 if(flag==0)
    {
        str=s.substr(0,1);
    }
  if(flag1==0)
    {
        str=s;
    }
        
   std::cout<<str;
}