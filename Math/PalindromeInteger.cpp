/*
Determine whether an integer is a palindrome. Do this without extra space.

A palindrome integer is an integer x for which reverse(x) = x where reverse(x) is x with its digit reversed.
Negative numbers are not palindromic.

Example :

Input : 12121
Output : True

Input : 123
Output : False

LINK: https://www.interviewbit.com/problems/palindrome-integer/
*/

int Solution::isPalindrome(int A)
{
    if(A<0)
        return 0;
 
    int Ac = A, s=0;
    while(A)
    {
        s = s*10 + (A%10);
        A/=10;
    }
    if(s==Ac)
        return 1;
    else
        return 0;
}