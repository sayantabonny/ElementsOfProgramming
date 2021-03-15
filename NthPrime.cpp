#include<iostream>
#include<vector>
#include <deque> 
#include<math.h>

std::vector<int> GeneratePrimes(int n)
{
    std::vector<int> primes;
    std::deque<bool> is_prime(n+1,true);
    for(bool a:is_prime)
    {
        std::cout<<a<<"\n";
    }
    is_prime[0]=is_prime[1]=false;
    for(int p=2;p<n;++p)
    {
        if(is_prime[p])
        {
            primes.emplace_back(p);

        }
        for(int i=p;i<=n;i+=p)
        {
            is_prime[i]=false;
        }
    }
    return primes;
}

std::vector<int> GeneratePrimes_1(int n)
{
    const int size=std::floor(0.5*(n-3))+1;
    std::cout<<size<<"\n";
    std::vector<int> primes;
    primes.emplace_back(2);
    std::deque<bool> is_prime(size,true);
    for(int i=0;i<size;i++)
    {
        if(is_prime[i])
        {
            
            int p=(i*2)+3;
            primes.emplace_back(p);
        }
    }

}
int main()
{
    std::vector<int> vect;

    vect=GeneratePrimes(10);
    for(int ans: vect)
    {
        std::cout<<ans<<"\n";
    }
}
