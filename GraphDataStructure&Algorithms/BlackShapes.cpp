/*
Given N * M field of O's and X's, where O=white, X=black
Return the number of black shapes. A black shape consists of one or more adjacent X's (diagonals not included)

Example:

OOOXOOO
OOXXOXO
OXOOOXO

answer is 3 shapes are  :
(i)    X
     X X
(ii)
      X
 (iii)
      X
      X
Note that we are looking for connected shapes here.

For example,

XXX
XXX
XXX
is just one single connected black shape.

LINK: https://www.interviewbit.com/problems/black-shapes/
*/

int n,m;
int X[] = {0, 0, 1, -1};
int Y[] = {1, -1, 0, 0};
 
void dfs(int x, int y, vector<string> &A)
{
    A[x][y] = 'O';
 
    for(int i=0;i<4;i++)
    {
        int newx = x+X[i];
        int newy = y+Y[i];
 
        if(newx>=0 && newx<n && newy>=0 && newy<m && A[newx][newy]=='X')
            dfs(newx,newy,A);
    }
}
 
int Solution::black(vector<string> &A)
{
    n = A.size();
    m = A[0].size();
 
    int ans = 0;
 
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
            if(A[i][j] == 'X')
            {
                ans++;
                dfs(i,j,A);
            }
 
    return ans;
}