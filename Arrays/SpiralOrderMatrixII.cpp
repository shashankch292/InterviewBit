/*
Given an integer n, generate a square matrix filled with elements from 1 to n2 in spiral order.

Example:

Given n = 3,

You should return the following matrix:

[
  [ 1, 2, 3 ],
  [ 8, 9, 4 ],
  [ 7, 6, 5 ]
]

LINK: https://www.interviewbit.com/problems/spiral-order-matrix-ii/
*/

vector<vector<int> > Solution::generateMatrix(int A) 
{
    vector<vector<int>> v(A, vector<int>(A));
    
    int t=0,b=A-1,l=0,r=A-1,dir=0;
    
    int num = 1;
    
    while(l<=r && t<=b)
    {
        if(dir==0)
        {
            for(int i=l;i<=r;i++)
            {
                v[t][i] = num;
                num++;
            }
            t++;
        }
        else
        if(dir==1)
        {
            for(int i=t;i<=b;i++)
            {
                v[i][r] = num;
                num++;
            }
            r--;
        }
        else
        if(dir==2)
        {
            for(int i=r;i>=l;i--)
            {
                v[b][i] = num;
                num++;
            }
            b--;
        }
        else
        if(dir==3)
        {
            for(int i=b;i>=t;i--)
            {
                v[i][l] = num;
                num++;
            }
            l++;
        }
        dir = (dir+1)%4;
    }
    return v;
}