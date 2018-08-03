/*
Given an array A of integers and another non negative integer k, find if there exists 2 indices i and j such that A[i] - A[j] = k, i != j.

Example :

Input :

A : [1 5 3]
k : 2
Output :

1
as 3 - 1 = 2

Return 0 / 1 for this problem.

LINK: https://www.interviewbit.com/problems/diffk-ii/
*/

int Solution::diffPossible(const vector<int> &A, int B)
{
    unordered_map<int,bool> hash;
 
    int n=A.size();
 
    for(int i=0;i<n;i++)
    {
        if(hash.find(A[i]-B)!=hash.end() || hash.find(A[i]+B)!=hash.end())
            return 1;
 
        hash[A[i]]=true;
    }
    return 0;
}
