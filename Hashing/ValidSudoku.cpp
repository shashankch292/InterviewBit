/*
Determine if a Sudoku is valid, according to: http://sudoku.com.au/TheRules.aspx

The Sudoku board could be partially filled, where empty cells are filled with the character ‘.’.



The input corresponding to the above configuration :

["53..7....", "6..195...", ".98....6.", "8...6...3", "4..8.3..1", "7...2...6", ".6....28.", "...419..5", "....8..79"]
A partially filled sudoku which is valid.

 Note:
A valid Sudoku board (partially filled) is not necessarily solvable. Only the filled cells need to be validated.
Return 0 / 1 ( 0 for false, 1 for true ) for this problem

LINK: https://www.interviewbit.com/problems/valid-sudoku/
*/

bool check(const vector<string> &A, int row, int col)
{
    for(int i=0;i<9;i++)
    {
        if(row!=i && A[i][col]==A[row][col])
            return false;
        if(col!=i && A[row][i]==A[row][col])
            return false;
    }
 
    int mrow = (row/3)*3;
    int mcol = (col/3)*3;
 
    for(int i=0;i<3;i++)
    {
        for(int j=0;j<3;j++)
        {
            int newi = mrow + i;
            int newj = mcol + j;
            if(newi!=row && newj!=col && A[newi][newj]==A[row][col])
                return false;
        }
    }
 
    return true;
}
 
int Solution::isValidSudoku(const vector<string> &A)
{
    for(int i=0;i<9;i++)
    {
        for(int j=0;j<9;j++)
        {
            if(A[i][j]!='.')
            {
                if(!check(A,i,j))
                    return false;
            }
        }
    }
    return true;
}