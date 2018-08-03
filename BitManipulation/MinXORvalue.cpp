/*
Given an array of N integers, find the pair of integers in the array which have minimum XOR value. Report the minimum XOR value.

Examples : 
Input 
0 2 5 7 
Output 
2 (0 XOR 2) 
Input 
0 4 7 9 
Output 
3 (4 XOR 7)

Constraints: 
2 <= N <= 100 000 
0 <= A[i] <= 1 000 000 000

LINK: https://www.interviewbit.com/problems/min-xor-value/
*/

int Solution::findMinXor(vector<int> &A)
{
    sort(A.begin(), A.end());
    int mn = INT_MAX;
 
    for(int i=1;i<A.size();i++)
    {
        mn = min(mn,A[i-1]^A[i]);
    }
    return mn;
}