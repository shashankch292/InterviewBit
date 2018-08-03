/*
Given two binary strings, return their sum (also a binary string).

Example:

a = "100"

b = "11"
Return a + b = “111”.

LINK: https://www.interviewbit.com/problems/add-binary-strings/
*/

string Solution::addBinary(string A, string B)
{
    reverse(A.begin(), A.end());
    reverse(B.begin(), B.end());
    int an = A.length();
    int bn = B.length();
    int i=0,j=0,carry=0;
    string s="";
 
    while(i<an && j<bn)
    {
        int x = (A[i]-'0') + (B[j]-'0') + carry;
        carry = x/2;
        x%=2;
        if(x==1)
            s+='1';
        else
            s+='0';
        i++;j++;
    }
 
    while(i<an)
    {
        int x = (A[i]-'0') + carry;
        carry = x/2;
        x%=2;
        if(x==1)
            s+='1';
        else
            s+='0';
        i++;
    }
 
    while(j<bn)
    {
        int x = (B[j]-'0') + carry;
        carry = x/2;
        x%=2;
        if(x==1)
            s+='1';
        else
            s+='0';
        j++;
    }
 
    if(carry==1)
        s+='1';
 
    reverse(s.begin(), s.end());
 
    return s;
}