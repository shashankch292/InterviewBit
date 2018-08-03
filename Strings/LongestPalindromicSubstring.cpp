/*
Given a string S, find the longest palindromic substring in S.

Substring of string S:

S[i...j] where 0 <= i <= j < len(S)

Palindrome string:

A string which reads the same backwards. More formally, S is palindrome if reverse(S) = S.

Incase of conflict, return the substring which occurs first ( with the least starting index ).

Example :

Input : "aaaabaaa"
Output : "aaabaaa"

LINK: https://www.interviewbit.com/problems/longest-palindromic-substring/
*/

string Solution::longestPalindrome(string s)
{
    int maxlen = 1, start = 0, low, high;
    int len = s.length();
 
    for(int i=0;i<len;i++)
    {
        low = i-1;
        high = i;
 
        while(low>=0 && high<len && s[low]==s[high])
        {
            if((high-low+1) > maxlen || ((high-low+1)==maxlen && low<start))
            {
                start = low;
                maxlen = (high-low+1);
            }
            low--;
            high++;
        }
 
        low = i-1;
        high = i+1;
 
        while(low>=0 && high<len && s[low]==s[high])
        {
            if((high-low+1) > maxlen || ((high-low+1)==maxlen && low<start))
            {
                start = low;
                maxlen = (high-low+1);
            }
            low--;
            high++;
        }
    }
 
    return s.substr(start,maxlen);    
}
