/*
Given a triangle, find the minimum path sum from top to bottom. Each step you may move to adjacent numbers on the row below.

For example, given the following triangle

[
     [2],
    [3,4],
   [6,5,7],
  [4,1,8,3]
]
The minimum path sum from top to bottom is 11 (i.e., 2 + 3 + 5 + 1 = 11).

 Note:
Bonus point if you are able to do this using only O(n) extra space, where n is the total number of rows in the triangle. 

LINK: https://www.interviewbit.com/problems/min-sum-path-in-triangle/
*/

int Solution::minimumTotal(vector<vector<int> > &A)
{
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
 
    int n = A.size();
 
    for(int i=1;i<n;i++)
    {
        int c = A[i].size();
        int k = 0;
 
        A[i][0] += A[i-1][k];
 
        for(int j=1;j<c-1;j++)
        {
            A[i][j] += min(A[i-1][k], A[i-1][k+1]);
            k++;
        }
 
        A[i][c-1] += A[i-1][k];
    }
 
    int ans = INT_MAX;
 
    for(int i=0;i<A[n-1].size();i++)
        ans = min(ans, A[n-1][i]);
    return ans;
}