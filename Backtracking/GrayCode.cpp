/*
The gray code is a binary numeral system where two successive values differ in only one bit.

Given a non-negative integer n representing the total number of bits in the code, print the sequence of gray code. A gray code sequence must begin with 0.

For example, given n = 2, return [0,1,3,2]. Its gray code sequence is:

00 - 0
01 - 1
11 - 3
10 - 2
There might be multiple gray code sequences possible for a given n.
Return any such sequence.

LINK: https://www.interviewbit.com/problems/gray-code/
*/

vector<int> Solution::grayCode(int A)
{
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
 
    int n = pow(2,A);
    vector<int> ans(n);
 
    if(n>1)
    {
        int mxb = pow(2,A-1);
        vector<int> temp = grayCode(A-1);
 
        for(int i=0;i<n;i++)
        {
            if(i<n/2)
                ans[i] = temp[i];
            else
                ans[i] = mxb + temp[n-i-1];
        }
    }
    else
    if(n==1)
    {
        ans[0]=0;
        ans[1]=1;
    }
 
    return ans;
}