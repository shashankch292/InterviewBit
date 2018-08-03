/*
Reverse bits of an 32 bit unsigned integer

Example 1:

x = 0,

          00000000000000000000000000000000  
=>        00000000000000000000000000000000
return 0

Example 2:

x = 3,

          00000000000000000000000000000011 
=>        11000000000000000000000000000000
return 3221225472

Since java does not have unsigned int, use long

LINK: https://www.interviewbit.com/problems/reverse-bits/
*/

unsigned int Solution::reverse(unsigned int A)
{
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
 
    int cnt=32, rev = 0;
    while(A)
    {
        rev <<= 1;
        rev |= (A&1);
        A >>= 1;
        cnt--;
    }
    rev <<= cnt;
    return rev;
}