/*
Given a string s and a dictionary of words dict, determine if s can be segmented into a space-separated sequence of one or more dictionary words.

For example, given

s = "myinterviewtrainer",
dict = ["trainer", "my", "interview"].
Return 1 ( corresponding to true ) because "myinterviewtrainer" can be segmented as "my interview trainer".

Return 0 / 1 ( 0 for false, 1 for true ) for this problem

LINK: https://www.interviewbit.com/problems/word-break/
*/

vector<int> dp;
unordered_set<string> st;
 
int check(int ind, int n, string &s)
{
    if(ind>=n)
        return 1;
 
    if(dp[ind]!=-1)
        return dp[ind];
 
    bool res = false;
    string temp = "";
 
    for(int i=ind;i<n && !res;i++)
    {
        temp.push_back(s[i]);
        if(st.find(temp)!=st.end())
            res |= check(i+1,n,s);
    }
    return dp[ind] = res;
}
 
int Solution::wordBreak(string A, vector<string> &B)
{
    int n = A.length();
    if(n==0)
        return 0;
 
    dp.clear();
    dp.resize(n,-1);
    st.clear();
 
    for(int i=0;i<B.size();i++)
        st.insert(B[i]);
 
    return check(0,n,A);
}