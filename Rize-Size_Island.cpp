#include <vector>
#include <iostream>
using namespace std;

int traverseNode(int i,int j, vector<vector<int>> &matrix, 
vector<vector<int>> &visited, int &size);

void printmatrix(vector<vector<int>> matrix, vector<vector<int>> visited)
{
    for(int i=0;i<matrix.size();i++)
    {
        for(int j=0;j<matrix[0].size();j++)
        {
            cout<<matrix[i][j]<<"  ";
        }
        cout<<endl;
        for(int j=0;j<matrix[0].size();j++)
        {
            if(visited[i][j]==0)
            {
                cout<<"F"<<"  ";
            }
            else
            {
                cout<<"T"<<"  ";
            }
        }
        cout<<endl;
    }
}


vector<int> riverSizes(vector<vector<int>> matrix) {
  
	vector<vector <int>> visited (matrix.size(),vector<int>(matrix[0].size(),false));
	vector<int> sizes;
	int row= matrix.size();
	int col= matrix[0].size();
	int size=1;
	for(int i=0;i<row;i++)
	{
		for(int j=0;j<col;j++)
		{
			if(matrix[i][j]==1 & visited[i][j]==false)
			{
				size=1;
				visited[i][j]=true;
				size=traverseNode(i,j,matrix,visited,size);
                cout<<"____For ELEMENT___i="<<i<<" j= "<<j<<" value "<<matrix[i][j]<<endl;
				printmatrix(matrix,visited);
				if(size>0)
				{
					sizes.push_back(size);
				}
			}
		}
	}

  cout<<sizes.size();
}

int traverseNode(int i,int j, vector<vector<int>> &matrix, 
vector<vector<int>> &visited, int &size){
	
	int dir[4][4] = {{1,0},{0,1},{-1,0},{0,-1}};
	for(int k=0;k<4;k++)
	{
		if(i+dir[k][0]>=0 && i+dir[k][0] < matrix.size() && j+dir[k][1]>=0 && j+dir[k][1] < matrix[0].size())
			{
				if(matrix[i+dir[k][0]][j+dir[k][1]]==1 && visited[i+dir[k][0]][j+dir[k][1]]== false)
				{
					visited[i+dir[k][0]][j+dir[k][1]]= true;
					size++;
					size= traverseNode(i+dir[k][0],j+dir[k][1],matrix,visited,size);
				}
			}
	}
	return size;
}




int main()
{
    vector<vector<int>> geo= {
    {1, 0, 0, 1, 0, 1, 0, 0, 1, 1, 1, 0},
    {1, 0, 1, 0, 0, 1, 1, 1, 1, 0, 1, 0},
    {0, 0, 1, 0, 1, 1, 0, 1, 0, 1, 1, 1},
    {1, 0, 1, 0, 1, 1, 0, 0, 0, 1, 0, 0},
    {1, 0, 1, 1, 0, 0, 0, 1, 1, 1, 0, 1}
    };
    riverSizes(geo);
}