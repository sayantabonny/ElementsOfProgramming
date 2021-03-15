#include<iostream>
#include<vector>
#include<string>
#include<algorithm> 
void ApplyPermutation(std::vector<int>* perm_ptr, std::vector<std::string>* A_ptr)
{
    std::vector<int> &perm=*perm_ptr;
    std::vector<std::string> &A=*A_ptr;
    for(int i=0;i<A.size();i++)
    {
        int next=i;
        std::cout<<perm[i]<<"\n";
        std::cout<<A[i]<<"\n";
        while(perm[i]>=0)
        {
            std::swap(A[i],A[perm[next]]);
            int temp=perm[next];
            perm[next]-=perm.size();
            next=temp;
            std::cout<<"\n i  "<<i<<" perm[i] "<<perm[i]<<" next "<<next<<"\n ";
            for(auto j: perm)
            {
                std::cout<<j<< " ";
            }
            std::cout<<"\n";
            for(auto j: A)
            {
                std::cout<<j<<" ";
            }
            std::cout<<"\n";
        }

    }

    std::for_each(perm.begin(),perm.end(),[&](int& x){x+=perm.size(); });

}

int main()
{
    std::vector<int> vect {2,3,0,1};
    std::vector<std::string> vect1{"a","b","c","d"};

    ApplyPermutation(&vect,&vect1);
}