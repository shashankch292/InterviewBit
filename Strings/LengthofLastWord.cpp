/*
Given a string s consists of upper/lower-case alphabets and empty space characters ' ', return the length of last word in the string.

If the last word does not exist, return 0.

Note: A word is defined as a character sequence consists of non-space characters only.

Example:

Given s = "Hello World",

return 5 as length("World") = 5.

Please make sure you try to solve this problem without using library functions. Make sure you only traverse the string once.

LINK: https://www.interviewbit.com/problems/length-of-last-word/
*/

int Solution::lengthOfLastWord(const string s)
{
    int n = s.length(),ind = 0,flag=1;
 
 
    for(int i=0;i<n;i++)
    {
        if(s[i]!=' ' && flag==1)
        {
            ind = i;
            flag=0;
        }
        if(s[i]==' ')
            flag=1;
    }
 
    while(n>0 && s[n-1]==' ')
        n--;
 
    if(ind>=n)
        return 0;
    else
        return (n-ind);
}
