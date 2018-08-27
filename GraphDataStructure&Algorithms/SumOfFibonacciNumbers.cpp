/*
How many minimum numbers from fibonacci series are required such that sum of numbers should be equal to a given Number N?
Note : repetition of number is allowed.

Example:

N = 4
Fibonacci numbers : 1 1 2 3 5 .... so on
here 2 + 2 = 4 
so minimum numbers will be 2 

LINK: https://www.interviewbit.com/problems/sum-of-fibonacci-numbers/
*/

int Solution::fibsum(int A)
{
    if(A==0)
        return 0;
 
    vector<int> fibb = {1,2};
 
    int i = 1;
 
    while(1)
    {
        if(fibb[i] > A-fibb[i-1])
            break;
 
        fibb.push_back(fibb[i] + fibb[i-1]);
        i++;
    }
 
    int n = fibb.size();
    int cnt = 0;
    i = n-1;
 
    while(A)
    {
        cnt += A/fibb[i];
        A = A%fibb[i];
        i--;
    }
    return cnt;
}