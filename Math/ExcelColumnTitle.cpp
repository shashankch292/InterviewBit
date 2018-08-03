/*
Given a positive integer, return its corresponding column title as appear in an Excel sheet.

For example:

    1 -> A
    2 -> B
    3 -> C
    ...
    26 -> Z
    27 -> AA
    28 -> AB 

LINK: https://www.interviewbit.com/problems/excel-column-title/
*/

string Solution::convertToTitle(int A)
{
    string s="";
 
    while(A)
    {
        int r = (A%26)-1;
        if(r<0)
        {
            r+=26;
            A--;
        }
        s += r +'A';
        A/=26;
    }
    reverse(s.begin(), s.end());
    return s;
}
