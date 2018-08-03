/*
Given a positive integer which fits in a 32 bit signed integer, find if it can be expressed as A^P where P > 1 and A > 0. A and P both should be integers.

Example

Input : 4
Output : True  
as 2^2 = 4. 

LINK: https://www.interviewbit.com/problems/power-of-two-integers/
*/

typedef long long int ll;
 
int Solution::isPower(int A)
{
    if(A==1)
        return 1;
 
    for(ll i=2;i*i<=A;i++)
    {
        for(ll j=i*i;j<=A;j*=i)
        {
            if(j==A)
                return 1;
        }
    }
    return 0;
}
