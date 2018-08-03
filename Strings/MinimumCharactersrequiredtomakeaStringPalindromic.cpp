/*
You are given a string. The only operation allowed is to insert characters in the beginning of the string. How many minimum characters are needed to be inserted to make the string a palindrome string

Example:
Input: ABC
Output: 2
Input: AACECAAAA
Output: 2

LINK: https://www.interviewbit.com/problems/minimum-characters-required-to-make-a-string-palindromic/
*/

bool ispalin(string s)
{
    for(int i=0,j=s.length()-1;i<=j;i++,j--)
        if(s[i]!=s[j])
            return false;
    return true;
}
 
int Solution::solve(string s)
{
    int cnt = 0;
    while(s.length()>0)
    {
        if(ispalin(s))
            break;
        else
        {
            cnt++;
            s.erase(s.end()-1);
        }
    }
    return cnt;
}