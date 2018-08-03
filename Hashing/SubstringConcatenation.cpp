/*
You are given a string, S, and a list of words, L, that are all of the same length.

Find all starting indices of substring(s) in S that is a concatenation of each word in L exactly once and without any intervening characters.

Example :

S: "barfoothefoobarman"
L: ["foo", "bar"]
You should return the indices: [0,9].
(order does not matter).

LINK: https://www.interviewbit.com/problems/substring-concatenation/
*/

vector<int> Solution::findSubstring(string A, const vector<string> &B)
{
    int wrd_size = B[0].length();
    int B_size = B.size();
    int tlen = wrd_size*B_size;
    int n = A.length();
 
    vector<int> res;
 
    if(tlen>n)
        return res;
 
    unordered_map<string, int> mp;
 
    for(int i=0;i<B_size;i++)
        mp[B[i]]++;
 
    for(int i=0;i<=n-tlen;i++)
    {
        unordered_map<string, int> temp = mp;
        int j = i;
        while(j < i+tlen)
        {
            string s = A.substr(j,wrd_size);
 
            if(temp.find(s)==temp.end())
                break;
            else
                temp[s]--;
            j += wrd_size;
        }
 
        bool flag = true;
        for(auto it=temp.begin();it!=temp.end();it++)
            if(it->second>0)
                flag=false;
 
        if(flag)
            res.push_back(i);
    }
    return res;
}