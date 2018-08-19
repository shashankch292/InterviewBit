/*
On a N * M chessboard, where rows are numbered from 1 to N and columns from 1 to M, there are queens at some cells. Return a N * M array A, where A[i][j] is number of queens that can attack cell (i, j). While calculating answer for cell (i, j), assume there is no queen at that cell.

Notes:

Queen is able to move any number of squares vertically, horizontally or diagonally on a chessboard. A queen cannot jump over another queen to attack a position.
You are given an array of N strings, each of size M. Each character is either a 1 or 0 denoting if there is a queen at that position or not, respectively.
Expected time complexity is worst case O(N*M).
For example,

Let chessboard be,
[0 1 0]
[1 0 0]
[0 0 1]

where a 1 denotes a queen at that position.

Cell (1, 1) is attacked by queens at (2, 1), (1,2) and (3,3).
Cell (1, 2) is attacked by queen at (2, 1). Note that while calculating this, we assume that there is no queen at (1, 2).
Cell (1, 3) is attacked by queens at (3, 3) and (1, 2).
and so on...

Finally, we return matrix
[3, 1, 2]
[1, 3, 3]
[2, 3, 0]

LINK: https://www.interviewbit.com/problems/queen-attack/
*/

int XU[] = {0, -1, -1, -1};
int YU[] = {-1, -1, 0, 1};
int XD[] = {0, 1, 1, 1};
int YD[] = {1, 1, 0, -1};
 
vector<vector<int> > Solution::queenAttack(vector<string> &A)
{
    int n = A.size();
    int m = A[0].size();
 
    int dpUP[n][m][4] , dpDOWN[n][m][4];
 
    memset(dpUP,0,sizeof(dpUP));
    memset(dpDOWN,0,sizeof(dpDOWN));
 
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            for(int k=0;k<4;k++)
            {
                int x = i + XU[k];
                int y = j + YU[k];
 
                if(x>=0 && x<n && y>=0 && y<m)
                {
                    if(A[x][y]=='1')
                        dpUP[i][j][k] = 1;
                    else
                        dpUP[i][j][k] = dpUP[x][y][k];
                }
            }
        }
    }
 
    for(int i=n-1;i>=0;i--)
    {
        for(int j=m-1;j>=0;j--)
        {
            for(int k=0;k<4;k++)
            {
                int x = i + XD[k];
                int y = j + YD[k];
 
                if(x>=0 && x<n && y>=0 && y<m)
                {
                    if(A[x][y]=='1')
                        dpDOWN[i][j][k] = 1;
                    else
                        dpDOWN[i][j][k] = dpDOWN[x][y][k];
                }
            }
        }
    }
 
    vector<vector<int> > res(n, vector<int>(m, 0));
 
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            for(int k=0;k<4;k++)
            {
                res[i][j] += dpUP[i][j][k];
                res[i][j] += dpDOWN[i][j][k];
            }
        }
    }
 
    return res;
}