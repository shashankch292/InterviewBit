/*
Given a string s and a dictionary of words dict, add spaces in s to construct a sentence where each word is a valid dictionary word.

Return all such possible sentences.

For example, given

s = "catsanddog",
dict = ["cat", "cats", "and", "sand", "dog"].
A solution is

[
  "cat sand dog", 
  "cats and dog"
]
Make sure the strings are sorted in your result.

LINK: https://www.interviewbit.com/problems/word-break-ii/
*/

vector<int> dp;
unordered_set<string> st;
vector<string> ans;
 
int check(int ind, int n, string &s, string str)
{
    if(ind>=n)
    {
        ans.push_back(str);
        return 1;
    }
 
    if(dp[ind]!=-1 && dp[ind]==0)
        return dp[ind];
 
    bool res = false;
    string temp = "";
 
    for(int i=ind;i<n;i++)
    {
        temp.push_back(s[i]);
        if(st.find(temp)!=st.end())
        {
            if(str=="")
                res |= check(i+1,n,s, str + temp);
            else
                res |= check(i+1,n,s, str + " " + temp);
        }
    }
    return dp[ind] = res;
}
 
vector<string> Solution::wordBreak(string A, vector<string> &B)
{
    ans.clear();
    int n = A.length();
    if(n==0)
        return ans;
 
    dp.clear();
    dp.resize(n,-1);
    st.clear();
 
    for(int i=0;i<B.size();i++)
        st.insert(B[i]);
 
    check(0,n,A,"");
 
    return ans;
}