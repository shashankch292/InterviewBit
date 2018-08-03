/*
Given numRows, generate the first numRows of Pascal’s triangle.

Pascal’s triangle : To generate A[C] in row R, sum up A’[C] and A’[C-1] from previous row R - 1.

Example:

Given numRows = 5,

Return

[
     [1],
     [1,1],
     [1,2,1],
     [1,3,3,1],
     [1,4,6,4,1]
]

LINK: https://www.interviewbit.com/problems/pascal-triangle/
*/

vector<vector<int> > Solution::generate(int n) 
{
    vector<vector<int>> v;
    
    for(int i=0;i<n;i++)
    {
        vector<int> vv;
        for(int j=0;j<=i;j++)
        {
            if(j==0 || j==i)
                vv.push_back(1);
            else
                vv.push_back(v[i-1][j] + v[i-1][j-1]);
        }
        v.push_back(vv);
    }
    return v;
}