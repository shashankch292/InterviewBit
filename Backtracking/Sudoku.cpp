/*
Write a program to solve a Sudoku puzzle by filling the empty cells.
Empty cells are indicated by the character '.' 
You may assume that there will be only one unique solution.



A sudoku puzzle,



and its solution numbers marked in red.

Example :

For the above given diagrams, the corresponding input to your program will be

[[53..7....], [6..195...], [.98....6.], [8...6...3], [4..8.3..1], [7...2...6], [.6....28.], [...419..5], [....8..79]]
and we would expect your program to modify the above array of array of characters to

[[534678912], [672195348], [198342567], [859761423], [426853791], [713924856], [961537284], [287419635], [345286179]]

LINK: https://www.interviewbit.com/problems/sudoku/
*/

bool check(vector<vector<char> > &A, int row, int col)
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
 
bool solve(vector<vector<char> > &A, int row, int col)
{
    if(col==9)
    {
        row++;
        col=0;
    }
 
    if(row==9)
        return true;
 
    if(A[row][col]!='.')
    {
        bool flag = solve(A, row, col+1);
        if(flag)
            return true;
    }
    else
    {
        for(int i=1;i<=9;i++)
        {
            A[row][col] = (i+'0');
            if(check(A, row, col))
            {
                bool flag = solve(A, row, col+1);
                if(flag)
                    return true;
            }
            A[row][col] = '.';
        }
    }
    return false;
}
 
void Solution::solveSudoku(vector<vector<char> > &A)
{
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
 
    bool flag = solve(A, 0, 0);
}