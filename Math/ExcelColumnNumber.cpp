/*
Given a column title as appears in an Excel sheet, return its corresponding column number.

Example:

    A -> 1
    
    B -> 2
    
    C -> 3
    
    ...
    
    Z -> 26
    
    AA -> 27
    
    AB -> 28 

LINK: https://www.interviewbit.com/problems/excel-column-number/
*/

int Solution::titleToNumber(string A)
{
    int n=A.length();
 
    int ans=0;
 
    for(int i=0;i<n;i++)
    {
        ans = (ans*26) + (A[i]-'A'+1);
    }
 
    return ans;
}