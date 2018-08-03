/*
Given a roman numeral, convert it to an integer.

Input is guaranteed to be within the range from 1 to 3999.

Read more details about roman numerals at Roman Numeric System

Example :

Input : "XIV"
Return : 14
Input : "XX"
Output : 20

LINK: https://www.interviewbit.com/problems/roman-to-integer/
*/

int val(char c)
{
    if(c=='I')
        return 1;
    if(c=='V')
        return 5;
    if(c=='X')
        return 10;
    if(c=='L')
        return 50;
    if(c=='C')
        return 100;
    if(c=='D')
        return 500;
    if(c=='M')
        return 1000;
}
 
int Solution::romanToInt(string s)
{
    int res = 0;
    int len = s.length();
 
    for(int i=0;i<len;i++)
    {
        int v1 = val(s[i]);
        if(i<len-1)
        {
            int v2 = val(s[i+1]);
            if(v2>v1)
            {
                res += v2-v1;
                i++;
            }
            else
                res += v1;
        }
        else
            res += v1;
    }
    return res;
}