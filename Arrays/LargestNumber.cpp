/*
Given a list of non negative integers, arrange them such that they form the largest number.

For example:

Given [3, 30, 34, 5, 9], the largest formed number is 9534330.

Note: The result may be very large, so you need to return a string instead of an integer.

LINK: https://www.interviewbit.com/problems/largest-number/
*/

bool comp(int ai,int bi)
{
    string a,b;
    a = to_string(ai);
    b = to_string(bi);
    string t1,t2;
    t1 = a+b;
    t2 = b+a;
    return t1<t2;
}
 
string Solution::largestNumber(const vector<int> &A) 
{
    int len = A.size();
    vector<int> v(len);
    
    for(int i=0;i<A.size();i++)
    {
        v[i] = A[i];
    }
    sort(v.begin(), v.end(), comp);
    string s="";
    
    int cnt=0;
    
    for(int i=len-1;i>=0;i--)
    {
        s+=to_string(v[i]);
        if(v[i]==0)
            cnt++;
    }
    
    if(cnt==len)
        s="0";
    
    return s;
}