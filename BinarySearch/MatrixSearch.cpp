/*
Write an efficient algorithm that searches for a value in an m x n matrix.

This matrix has the following properties:

Integers in each row are sorted from left to right.
The first integer of each row is greater than or equal to the last integer of the previous row.
Example:

Consider the following matrix:

[
  [1,   3,  5,  7],
  [10, 11, 16, 20],
  [23, 30, 34, 50]
]
Given target = 3, return 1 ( 1 corresponds to true )

Return 0 / 1 ( 0 if the element is not present, 1 if the element is present ) for this problem

LINK: https://www.interviewbit.com/problems/matrix-search/
*/

int b_search(vector<int> v, int x)
{
    int low = 0, high = v.size();
 
    while(low <= high)
    {
        int mid = low + (high - low)/2;
 
        if(x == v[mid])
            return 1;
        if(x > v[mid])
            low = mid+1;
        else
            high = mid-1;
    }
    return 0;
}
 
int Solution::searchMatrix(vector<vector<int> > &A, int B)
{
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
 
    int low = 0, high = A.size();
 
    while(low < high)
    {
        int mid = low + (high - low)/2;
 
        int x = A[mid][0];
 
        if(x == B)
            return 1;
 
        if(x < B)
            low = mid+1;
        else
            high = mid;
    }
 
    if(low==0)
        return 0;
 
    return b_search(A[low-1], B);
}