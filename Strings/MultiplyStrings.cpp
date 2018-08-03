/*
Given two numbers represented as strings, return multiplication of the numbers as a string.

 Note: The numbers can be arbitrarily large and are non-negative.
Note2: Your answer should not have leading zeroes. For example, 00 is not a valid answer. 
For example, 
given strings "12", "10", your answer should be “120”.

NOTE : DO NOT USE BIG INTEGER LIBRARIES ( WHICH ARE AVAILABLE IN JAVA / PYTHON ). 
We will retroactively disqualify such submissions and the submissions will incur penalties.

LINK: https://www.interviewbit.com/problems/multiply-strings/
*/

string Solution::multiply(string A, string B)
{
    int na = A.length(), nb = B.length();
 
    vector<int> v(na+nb, 0);
 
    int ina = 0, inb = 0;
 
    for(int i=na-1;i>=0;i--)
    {
        int carry = 0;
        int num1 = A[i]-'0';
 
        inb = 0;
 
        for(int j=nb-1;j>=0;j--)
        {
            int num2 = B[j]-'0';
            int sum = (num1*num2) + v[ina+inb] + carry;
            carry = sum/10;
            v[ina+inb] = sum%10;
            inb++;
        }
        if(carry>0)
            v[ina+inb]+=carry;
        ina++;
    }
 
    int i =v.size()-1;
    while(i>=0 && v[i]==0)
        i--;
 
    if(i==-1)
        return "0";
 
    string ans = "";
 
    while(i>=0)
        ans.push_back(v[i--]+'0');
 
    return ans;
}