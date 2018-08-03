/*
Implement pow(x, n) % d.

In other words, given x, n and d,

find (xn % d)

Note that remainders on division cannot be negative. 
In other words, make sure the answer you return is non negative.

Input : x = 2, n = 3, d = 3
Output : 2

2^3 % 3 = 8 % 3 = 2.

LINK: https://www.interviewbit.com/problems/implement-power-function/
*/

int Solution::pow(int x, int n, int d)
{
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
 
    if(x==0)
        return 0;
    if(n==0)
        return 1;
 
    long long int a = x%d;
    if(a<0)
        a+=d;
    long long int res = 1;
 
 
    while(n)
    {
        if(n&1)
            res = (res*a)%d;
        a = (a*a)%d;
        if(a<0)
            a+=d;
        n = n>>1;
    }
    return int(res);
}