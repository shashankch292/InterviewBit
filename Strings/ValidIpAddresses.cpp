/*
Given a string containing only digits, restore it by returning all possible valid IP address combinations.

A valid IP address must be in the form of A.B.C.D, where A,B,C and D are numbers from 0-255. The numbers cannot be 0 prefixed unless they are 0.

Example:

Given “25525511135”,

return [“255.255.11.135”, “255.255.111.35”]. (Make sure the returned strings are sorted in order)

LINK: https://www.interviewbit.com/problems/valid-ip-addresses/
*/

vector<string> split(const string &s, char delim) 
{
    vector<string> result;
    stringstream ss(s);
    string item;
    while (getline(ss, item, delim)) {
        result.push_back(item);
    }
    return result;
}
 
bool isValid(string s)
{
    vector<string> v = split(s,'.');
    for(int i=0;i<v.size();i++)
    {
        int n = v[i].length();
        if(n==0)
            return false;
        int num = stoi(v[i]);
 
        if(n>3 || num<0 || num>255)
            return false;
        if(n>1 && num==0)
            return false;
        if(n>1 && num!=0 && v[i][0]=='0')
            return false;
    }
    return true;
}
 
bool compare(string a,string b)
{
    vector<string> v1 = split(a,'.');
    vector<string> v2 = split(b,'.');
    for(int i=0;i<4;i++)
    {
        int num1 = stoi(v1[i]);
        int num2 = stoi(v2[i]);
        if(num1>num2)
            return false;
    }
    return true;
}
 
vector<string> Solution::restoreIpAddresses(string s)
{
    vector<string> res;
 
    int n = s.length();
    if(n<4 && n>12)
        return res;
 
    string temp = s;
 
    for(int i=1;i<n-2;i++)
    {
        for(int j=i+1;j<n-1;j++)
        {
            for(int k=j+1;k<n;k++)
            {
                temp = temp.substr(0,k) + "." + temp.substr(k);
                temp = temp.substr(0,j) + "." + temp.substr(j);
                temp = temp.substr(0,i) + "." + temp.substr(i);
 
                if(isValid(temp))
                    res.push_back(temp);
                temp = s;
            }
        }
    }
 
    sort(res.begin(), res.end(), compare);
    return res;
}
