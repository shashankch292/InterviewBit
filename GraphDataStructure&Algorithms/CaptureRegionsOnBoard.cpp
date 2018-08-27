/*
Given a 2D board containing 'X' and 'O', capture all regions surrounded by 'X'.

A region is captured by flipping all 'O's into 'X's in that surrounded region.

For example,

X X X X
X O O X
X X O X
X O X X
After running your function, the board should be:

X X X X
X X X X
X X X X
X O X X

LINK: https://www.interviewbit.com/problems/capture-regions-on-board/
*/

int m,n;
vector<vector<bool> > vis;
 
int X[] = {0, 0, 1, -1};
int Y[] = {1, -1, 0, 0};
 
void dfs(int x, int y, vector<vector<char> > &A)
{
    vis[x][y] = true;
 
    for(int i=0;i<4;i++)
    {
        int newx = x + X[i];
        int newy = y + Y[i];
 
        if(newx>=0 && newx<m && newy>=0 && newy<n && vis[newx][newy]==false && A[newx][newy]=='O')
            dfs(newx,newy,A);
    }
}
 
void Solution::solve(vector<vector<char> > &A)
{
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
 
    m = A.size();
    n = A[0].size();
 
    vis.clear();
    vis.resize(m, vector<bool>(n, false));
 
    for(int i=0;i<m;i++)
    {
        if(A[i][0] == 'O' && vis[i][0] == false)
            dfs(i,0,A);
        if(A[i][n-1] == 'O' && vis[i][n-1] == false)
            dfs(i,n-1,A);
    }
 
    for(int j=0;j<n;j++)
    {
        if(A[0][j] == 'O' && vis[0][j]==false)
            dfs(0,j,A);
        if(A[m-1][j] == 'O' && vis[m-1][j]==false)
            dfs(m-1,j,A);
    }
 
    for(int i=0;i<m;i++)
        for(int j=0;j<n;j++)
            if(A[i][j] == 'O' && !vis[i][j])
                A[i][j] = 'X';
}