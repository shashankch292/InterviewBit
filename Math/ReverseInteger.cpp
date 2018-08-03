/*
Reverse digits of an integer.

Example1:

x = 123,

return 321
Example2:

x = -123,

return -321

Return 0 if the result overflows and does not fit in a 32 bit signed integer

LINK: https://www.interviewbit.com/problems/reverse-integer/
*/

int Solution::reverse(int A)
{
    int flag = 0;
 
    if(A<0)
    {
        flag=1;
        A=A*-1;
    }
 
    int s = 0;
 
    while(A)
    {
        if(s >= INT_MAX/10)
            return 0;
        s = s*10 + (A%10);
        A /= 10;
    }
 
    if(flag)
        s=s*-1;
    return s;
}