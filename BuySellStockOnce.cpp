#include<iostream>
#include<vector>
#include<limits>

double BuySellStockOnce(const std::vector<double>& prices)
{
  double min_price_so_far= std::numeric_limits<double>::max(), max_profit=0,max_profit_sell_today;
  for(const double& price : prices)
  {
      std::cout<<min_price_so_far<<"  "<<max_profit_sell_today<<" "<<price<<" "<<max_profit<<"\n";
      max_profit_sell_today = price -min_price_so_far;
      max_profit = std::max(max_profit,max_profit_sell_today);
      min_price_so_far=std::min(min_price_so_far,price);
  }
  return max_profit;
}

int main()
{
    std::vector<double> vect;
    int n;
    std::cin>>n;int val;
    for (int i=0;i<n;i++)
    {
        std::cin>>val;
        vect.push_back(val);
    }
    double ans=BuySellStockOnce(vect);
    std::cout<<"\n"<<ans<<"\n";
}

//9 310 315 275 295 260 270 290 230 255 250