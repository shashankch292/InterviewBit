/*
The count-and-say sequence is the sequence of integers beginning as follows:

1, 11, 21, 1211, 111221, ...
1 is read off as one 1 or 11.
11 is read off as two 1s or 21.

21 is read off as one 2, then one 1 or 1211.

Given an integer n, generate the nth sequence.

Note: The sequence of integers will be represented as a string.

Example:

if n = 2,
the sequence is 11.

LINK: https://www.interviewbit.com/problems/count-and-say/
*/

string Solution::countAndSay(int n) 
{
    string s="1";
    n--;
 
    while(n--)
    {
        string temp="";
        int cnt=1, len=s.size();
        for(int i=1;i<len;i++)
        {
            if(s[i]==s[i-1])
                cnt++;
            else
            {
                temp.push_back('0'+cnt);
                temp.push_back(s[i-1]);
                cnt=1;
            }
        }
        temp.push_back('0'+cnt);
        temp.push_back(s[len-1]);
        s = temp;
    }
    return s;
}