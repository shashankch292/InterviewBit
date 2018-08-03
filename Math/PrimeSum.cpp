/*
Given an even number ( greater than 2 ), return two prime numbers whose sum will be equal to given number.

NOTE A solution will always exist. read Goldbach’s conjecture

Example:


Input : 4
Output: 2 + 2 = 4

If there are more than one solutions possible, return the lexicographically smaller solution.

If [a, b] is one solution with a <= b,
and [c,d] is another solution with c <= d, then

[a, b] < [c, d] 

If a < c OR a==c AND b < d. 

LINK: https://www.interviewbit.com/problems/prime-sum/
*/

vector<int> Solution::primesum(int A) 
{
    vector<bool> v(A+1,0);
    v[0]=v[1]=1;
    
    for(int i=2;i*i<=A;i++)
    {
        if(v[i]==0)
        {
            for(int j=i*i;j<=A;j+=i)
                v[j]=1;
        }
    }
    
    vector<int> prime;
    
    for(int i=0;i<=A;i++)
    {
        if(v[i]==0 && v[A-i]==0)
        {
            vector<int> ans = {i, A-i};
            return ans;
        }
    }
}