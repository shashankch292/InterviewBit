/*
Give a N*N square matrix, return an array of its anti-diagonals. Look at the example for more details.

Example:

		
Input: 	

1 2 3
4 5 6
7 8 9

Return the following :

[ 
  [1],
  [2, 4],
  [3, 5, 7],
  [6, 8],
  [9]
]


Input : 
1 2
3 4

Return the following  : 

[
  [1],
  [2, 3],
  [4]
]

LINK: https://www.interviewbit.com/problems/anti-diagonals/
*/

vector<vector<int> > Solution::diagonal(vector<vector<int> > &A) 
{
    vector<vector<int>> v;
    
    int n = A.size();
    
    for(int i=0;i<n;i++)
    {
        vector<int> vv;
        for(int j=i,k=0;k<=i;j--,k++)
            vv.push_back(A[k][j]);
        v.push_back(vv);
    }
    
    for(int i=1;i<n;i++)
    {
        vector<int> vv;
        for(int j=n-1,k=i;k<n;j--,k++)
            vv.push_back(A[k][j]);
        v.push_back(vv);
    }
    
    return v;
}