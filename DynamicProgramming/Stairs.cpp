/*
You are climbing a stair case. It takes n steps to reach to the top.

Each time you can either climb 1 or 2 steps. In how many distinct ways can you climb to the top?

Example :

Input : 3
Return : 3

Steps : [1 1 1], [1 2], [2 1]

LINK: https://www.interviewbit.com/problems/stairs/
*/

int Solution::climbStairs(int A)
{
    if(A==0 || A==1)
        return A;
 
    int a = 1;
    int b = 2;
 
    for(int i=3;i<=A;i++)
    {
        int s = a+b;
        a = b;
        b = s;
    }
 
    return b;
}