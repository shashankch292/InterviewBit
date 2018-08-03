/*
Implement atoi to convert a string to an integer.

Example :

Input : "9 2704"
Output : 9
Note: There might be multiple corner cases here. Clarify all your doubts using “See Expected Output”.

 Questions: Q1. Does string contain whitespace characters before the number?
A. Yes Q2. Can the string have garbage characters after the number?
A. Yes. Ignore it. Q3. If no numeric character is found before encountering garbage characters, what should I do?
A. Return 0. Q4. What if the integer overflows?
A. Return INT_MAX if the number is positive, INT_MIN otherwise. 
Warning : DO NOT USE LIBRARY FUNCTION FOR ATOI.
If you do, we will disqualify your submission retroactively and give you penalty points.

LINK: https://www.interviewbit.com/problems/atoi/
*/

int Solution::atoi(const string A)
{
    int n = A.length();
    int i=0, neg=0;
 
    while(i<n && A[i]==' ')
        i++;
    if(i<n && A[i]=='-')
    {
        neg=1;
        i++;
    }
    if(i<n && A[i]=='+')
        i++;
 
    long long int res=0;
 
    while(i<n)
    {
        if(!isdigit(A[i]))
            break;
 
        res = res*10 + (A[i]-'0');
 
        if(neg==0 && res>=INT_MAX)
            return INT_MAX;
        if(neg==1 && (-1*res)<=INT_MIN)
            return INT_MIN;
        i++;
    }
 
    if(neg)
        res*=-1;
    return (int)res;
}