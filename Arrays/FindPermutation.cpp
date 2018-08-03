/*
Given a positive integer n and a string s consisting only of letters D or I, you have to find any permutation of first n positive integer that satisfy the given input string.

D means the next number is smaller, while I means the next number is greater.

Notes

Length of given string s will always equal to n - 1
Your solution should run in linear time and space.
Example :

Input 1:

n = 3

s = ID

Return: [1, 3, 2]

LINK: https://www.interviewbit.com/problems/find-permutation/
*/

vector<int> Solution::findPerm(const string s, int n)
{
    vector<int> v(n);
    int len = s.length();
 
    int k=1;
 
    for(int i=0;i<len;i++)
    {
        if(s[i]=='I')
        {
            v[i] = k;
            k++;
        }
    }
 
    v[n-1] = k++;
 
    for(int i=len-1;i>=0;i--)
    {
        if(s[i]=='D')
        {
            v[i] = k;
            k++;
        }
    }
 
    return v;
}