/*
Given a string, determine if it is a palindrome, considering only alphanumeric characters and ignoring cases.

Example:

"A man, a plan, a canal: Panama" is a palindrome.

"race a car" is not a palindrome.

Return 0 / 1 ( 0 for false, 1 for true ) for this problem

LINK: https://www.interviewbit.com/problems/palindrome-string/
*/

×
int Solution::isPalindrome(string s)
{
    int i=0,j=s.length()-1;
 
    while(i<=j)
    {
        while(!isalnum(s[i]))
            i++;
        while(!isalnum(s[j]))
            j--;
        if(i>j)
            break;
        if(tolower(s[i])!=tolower(s[j]))
            return 0;
        i++;
        j--;
    }
    return 1;
}