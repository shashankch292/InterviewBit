/*
Given two integers representing the numerator and denominator of a fraction, return the fraction in string format.

If the fractional part is repeating, enclose the repeating part in parentheses.

Example :

Given numerator = 1, denominator = 2, return "0.5"
Given numerator = 2, denominator = 1, return "2"
Given numerator = 2, denominator = 3, return "0.(6)"

LINK: https://www.interviewbit.com/problems/fraction/
*/

string Solution::fractionToDecimal(int A, int B)
{
    if(A==0)
        return "0";
    long long int a = A;
    long long int b = B;
    string res = "";
    if((a<0)^(b<0))
        res+='-';
    a = abs(a);
    b = abs(b);
    res += to_string(a/b);
 
    long long int rem = a%b;
 
    if(rem==0)
        return res;
 
    res += '.';
 
    unordered_map<int,int> mp;
 
    while(rem)
    {
        if(mp.find(rem)!=mp.end())
        {
            res.insert(mp[rem],"(");
            res.push_back(')');
            break;
        }
 
        mp[rem] = res.length();
        rem *= 10;
        res.push_back(rem/b+'0');
        rem %= b;
    }
    return res;
}