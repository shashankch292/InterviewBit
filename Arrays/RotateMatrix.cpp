/*
You are given an n x n 2D matrix representing an image.

Rotate the image by 90 degrees (clockwise).

You need to do this in place.

Note that if you end up using an additional array, you will only receive partial score.

Example:

If the array is

[
    [1, 2],
    [3, 4]
]
Then the rotated array becomes:

[
    [3, 1],
    [4, 2]
]

LINK: https://www.interviewbit.com/problems/rotate-matrix/
*/

void Solution::rotate(vector<vector<int> > &A)
{
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
 
    int n=A.size();
 
    int l=0,h=n-1;
 
    while(l<h)
    {
        for(int k=l;k<h;k++)
        {
            int a,b,c,d;
            a = A[l][k];
            b = A[k][h];
            c = A[h][h-k+l];
            d = A[h-k+l][l];
 
            A[l][k] = d;
            A[k][h] = a;
            A[h][h-k+l] = b;
            A[h-k+l][l] = c;
        }
        l++;
        h--;
    }
}