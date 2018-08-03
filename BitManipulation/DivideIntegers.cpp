/*
Divide two integers without using multiplication, division and mod operator.

Return the floor of the result of the division.

Example:

5 / 2 = 2
Also, consider if there can be overflow cases. For overflow case, return INT_MAX.

LINK: https://www.interviewbit.com/problems/divide-integers/
*/

int Solution::divide(int A, int B)
{
    int sign = ((A<0)^(B<0))?-1:1;
    long long int x=abs(1LL*A), y=abs(1LL*B), q=0, temp=0;
 
    for(int i=31;i>=0;i--)
    {
        if(temp+(y<<i) <= x)
        {
            temp += (y<<i);
            q |= (1LL<<i);
        }
    }
    if(q>=INT_MAX && sign==-1)
        return INT_MIN;
    if(q>=INT_MAX)
        return INT_MAX;
    return int(sign*q);
}
