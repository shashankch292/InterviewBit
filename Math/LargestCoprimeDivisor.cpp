/*
You are given two positive numbers A and B. You need to find the maximum valued integer X such that:

X divides A i.e. A % X = 0
X and B are co-prime i.e. gcd(X, B) = 1
For example,

A = 30
B = 12
We return
X = 5

LINK: https://www.interviewbit.com/problems/largest-coprime-divisor/
*/

int gcd(int a,int b)
{
    if(b==0)
        return a;
    else
        return gcd(b,a%b);
}
 
int Solution::cpFact(int A, int B)
{
    while(gcd(A,B)!=1)
        A /= gcd(A,B);
    return A;
}