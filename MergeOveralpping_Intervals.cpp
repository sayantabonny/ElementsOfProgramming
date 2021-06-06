#include <vector>
#include <iostream>

using namespace std;

vector<vector<int>> mergeOverlappingIntervals(vector<vector<int>> intervals) {
  if(intervals.size()<=1)
	{
		return intervals;
	}
	for(int i=1;i<intervals.size();i++)
	{
		int j=i;
		if(intervals[i-1][0]>intervals[i][0])
		{
			while(j>=0)
			{
				if(intervals[j][0]<intervals[j-1][0])
				{
					intervals[j+1]=intervals[j];
					cout<<intervals[i][0]<<" j "<<j;
				}
				else
				{
					intervals[j]=intervals[i];
					break;
				}
				j--;
			}
			if(intervals[0][0]>intervals[i][0])
			{
				intervals[0]=intervals[i];
			}
		}
	}
	vector<vector<int>> answer;
	int first=intervals[0][0], second=intervals[0][1]; int i;
		for(i=1;i<intervals.size();i++)
	{	
			//cout<<intervals[i-1][0]<<intervals[i][0];
			if(intervals[i-1][1]<intervals[i][0])
			{
				answer.push_back({first,second});
				first=intervals[i][0];
				second=intervals[i][1];
			}
			else
			{
				second=intervals[i][1];
			}
		}
	if(intervals[intervals.size()-2][1]>=intervals[intervals.size()-1][0])
			{
				answer.push_back({intervals[intervals.size()-2][0],intervals[intervals.size()-1][1]});
			}
	else
	{
		answer.push_back({intervals[intervals.size()-1][0],intervals[intervals.size()-1][1]});
	}
	
		
	
  return answer;
}


int main()
{
    vector<vector<int>> m={{1,2,3},{4,5,6}};
    cout<<mergeOverlappingIntervals(m)[0][0];
}