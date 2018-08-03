/*
Find if Given number is power of 2 or not. 
More specifically, find if given number can be expressed as 2^k where k >= 1.

Input:

number length can be more than 64, which mean number can be greater than 2 ^ 64 (out of long long range)
Output:

return 1 if the number is a power of 2 else return 0

Example:

Input : 128
Output : 1

LINK: https://www.interviewbit.com/problems/power-of-2/
*/

string div2(string s)
{
    string res;
 
    int n=s.length();
    int carry=0,i=0;
    while(i<n)
    {
        int num = s[i]-'0';
        num = num + (carry*10);
        carry = num%2;
        res.push_back((num/2)+'0');
        i++;
    }
 
    if(carry)
        return "1";
 
    while(res.length()>0 && res[0]=='0')
        res.erase(res.begin());
 
    return res;
}
 
int Solution::power(string s)
{
    if(s.length()==1 && s[0]=='1')
        return 0;
 
    while(s.length()>0)
    {
        if(s.length()==1 && s[0]=='1')
            break;
 
        if((s[s.length()-1]-'0')%2)
            return 0;
 
        s = div2(s);
    }
    return 1;
}