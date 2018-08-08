/*
Given a set of reviews provided by the customers for different hotels and a string containing “Good Words”, you need to sort the reviews in descending order according to their “Goodness Value” (Higher goodness value first). We define the “Goodness Value” of a string as the number of “Good Words” in that string.

Note: Sorting should be stable. If review i and review j have the same “Goodness Value” then their original order would be preserved.

 You are expected to use Trie in an Interview for such problems 

Constraints:

1.   1 <= No.of reviews <= 200
2.   1 <= No. of words in a review <= 1000
3.   1 <= Length of an individual review <= 10,000
4.   1 <= Number of Good Words <= 10,000
5.   1 <= Length of an individual Good Word <= 4
6.   All the alphabets are lower case (a - z)
Input:

S : A string S containing "Good Words" separated by  "_" character. (See example below)
R : A vector of strings containing Hotel Reviews. Review strings are also separated by "_" character.
Output:

A vector V of integer which contain the original indexes of the reviews in the sorted order of reviews. 

V[i] = k  means the review R[k] comes at i-th position in the sorted order. (See example below)
In simple words, V[i]=Original index of the review which comes at i-th position in the sorted order. (Indexing is 0 based)
Example:

Input: 
S = "cool_ice_wifi"
R = ["water_is_cool", "cold_ice_drink", "cool_wifi_speed"]

Output:
ans = [2, 0, 1]
Here, sorted reviews are ["cool_wifi_speed", "water_is_cool", "cold_ice_drink"]

LINK: https://www.interviewbit.com/problems/hotel-reviews/
*/

/////////////////////////////////////////////////////////////
// Using Trie
/////////////////////////////////////////////////////////////

bool comp(const pair<int,int> &a, const pair<int,int> &b)
{
    if(a.first!=b.first)
        return a.first>b.first;
    return a.second<b.second;
}
 
vector<string> split(string s)
{
    int n = s.length();
    string temp = "";
    vector<string> res;
 
    for(int i=0;i<n;i++)
    {
        if(s[i]=='_')
        {
            res.push_back(temp);
            temp = "";
            continue;
        }
        temp+=s[i];
    }
    res.push_back(temp);
    return res;
}
 
struct TrieNode
{
    TrieNode* children[26];
    bool isEnd;
    TrieNode()
    {
        for(int i=0;i<26;i++)
            children[i]=NULL;
        isEnd = false;
    }
};
 
void insert(TrieNode* root, string s)
{
    TrieNode *pCrawl = root;
 
    for(int i=0;i<s.length();i++)
    {
        int ind = s[i]-'a';
 
        if(!pCrawl->children[ind])
            pCrawl->children[ind] = new TrieNode();
        pCrawl = pCrawl->children[ind];
    }
    pCrawl->isEnd = true;
}
 
bool search(TrieNode* root, string s)
{
    TrieNode *pCrawl = root;
 
    for(int i=0;i<s.length();i++)
    {
        int ind = s[i]-'a';
 
        if(!pCrawl->children[ind])
            return false;
        pCrawl = pCrawl->children[ind];
    }
    return pCrawl->isEnd;
}
 
vector<int> Solution::solve(string A, vector<string> &B)
{
    TrieNode* root = new TrieNode();
 
    vector<string> good = split(A);
    int ng = good.size();
 
    for(int i=0;i<ng;i++)
        insert(root,good[i]);
 
    int nr = B.size();
    vector<pair<int,int> > v(nr);
 
 
    for(int i=0;i<nr;i++)
    {
        vector<string> rew = split(B[i]);
        int nrew = rew.size();
        int cnt=0;
        for(int j=0;j<nrew;j++)
        {
            if(search(root,rew[j]))
                cnt++;
        }
        v[i] = {cnt,i};
    }
 
    sort(v.begin(), v.end(), comp);
 
    vector<int> res;
 
    for(int i=0;i<nr;i++)
        res.push_back(v[i].second);
 
    return res;
}

/////////////////////////////////////////////////////////////
// Using Map
/////////////////////////////////////////////////////////////

bool comp(const pair<int,int> &a, const pair<int,int> &b)
{
    if(a.first!=b.first)
        return a.first>b.first;
    return a.second<b.second;
}
 
vector<string> split(string s)
{
    int n = s.length();
    string temp = "";
    vector<string> res;
 
    for(int i=0;i<n;i++)
    {
        if(s[i]=='_')
        {
            res.push_back(temp);
            temp = "";
            continue;
        }
        temp+=s[i];
    }
    res.push_back(temp);
    return res;
}
 
vector<int> Solution::solve(string A, vector<string> &B)
{
    unordered_map<string, int> mp;
    vector<string> good = split(A);
    int ng = good.size();
 
    for(int i=0;i<ng;i++)
    {
        if(mp.find(good[i])==mp.end())
            mp[good[i]] = 1;
    }
 
    int nr = B.size();
    vector<pair<int,int> > v(nr);
 
 
    for(int i=0;i<nr;i++)
    {
        vector<string> rew = split(B[i]);
        int nrew = rew.size();
        int cnt=0;
        for(int j=0;j<nrew;j++)
        {
            if(mp.find(rew[j])!=mp.end())
                cnt++;
        }
        v[i] = {cnt,i};
    }
 
    sort(v.begin(), v.end(), comp);
 
    vector<int> res;
 
    for(int i=0;i<nr;i++)
        res.push_back(v[i].second);
 
    return res;
}