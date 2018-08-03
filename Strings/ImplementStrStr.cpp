/*
Implement strStr().

 strstr - locate a substring ( needle ) in a string ( haystack ). 
Try not to use standard library string functions for this question.

Returns the index of the first occurrence of needle in haystack, or -1 if needle is not part of haystack.

 NOTE: Good clarification questions:
What should be the return value if the needle is empty?
What if both haystack and needle are empty?
For the purpose of this problem, assume that the return value should be -1 in both cases. 

LINK: https://www.interviewbit.com/problems/implement-strstr/
*/

void complps(const string B, int m, int lps[])
{
    int len = 0, i = 1;
    lps[0]=0;
 
    while(i<m)
    {
        if(B[i]==B[len])
        {
            len++;
            lps[i] = len;
            i++;
        }
        else
        {
            if(len!=0)
                len = lps[len-1];
            else
            {
                lps[i]=0;
                i++;
            }
        }
    }
}
 
int Solution::strStr(const string A, const string B)
{
    int n = A.length();
    int m = B.length();
 
    int lps[m];
    complps(B,m,lps);
 
    int i=0,j=0;
 
    while(i<n)
    {
        if(A[i]==B[j])
        {
            i++;
            j++;
        }
 
        if(j==m)
        {
            return i-j;
        }
        else
        if(i<n && A[i]!=B[j])
        {
            if(j!=0)
                j=lps[j-1];
            else
                i++;
        }
    }
    return -1;
}