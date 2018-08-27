/*
Given two words (start and end), and a dictionary, find the shortest transformation sequence from start to end, such that:

Only one letter can be changed at a time
Each intermediate word must exist in the dictionary
If there are multiple such sequence of shortest length, return all of them. Refer to the example for more details.

Example :

Given:

start = "hit"
end = "cog"
dict = ["hot","dot","dog","lot","log"]
Return

  [
    ["hit","hot","dot","dog","cog"],
    ["hit","hot","lot","log","cog"]
  ]
 Note:
All words have the same length.
All words contain only lowercase alphabetic characters.

LINK: https://www.interviewbit.com/problems/word-ladder-ii/
*/

vector<vector<string> > res;
int nd, minL;
string en;
 
bool isAdj(string a, string b)
{
    int n = a.length();
    int cnt = 0;
 
    for(int i=0;i<n;i++)
    {
        if(a[i]!=b[i])
            cnt++;
        if(cnt>1)
            return false;
    }
 
    return cnt==1? true : false;
}
 
void dfs(vector<string> &dict, vector<string> &temp, bool vis[], int len)
{
    if(len>minL)
        return;
 
    if(temp[len-1] == en)
    {
        if(minL > len)
        {
            minL = len;
            res.clear();
        }
        res.push_back(temp);
        return;
    }
 
    string s = temp[len-1];
 
    for(int i=0;i<nd;i++)
    {
        if(vis[i] == false && isAdj(s,dict[i]))
        {
            vis[i] = true;
            temp.push_back(dict[i]);
            dfs(dict,temp,vis,len+1);
            temp.pop_back();
            vis[i] = false;
        }
    }
}
 
vector<vector<string> > Solution::findLadders(string start, string end, vector<string> &dict)
{
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
 
    res.clear();
 
    dict.push_back(end);
 
    unordered_set<string> st;
    for(auto x : dict)
        st.insert(x);
    dict.assign(st.begin(), st.end());
    sort(dict.begin(), dict.end());
 
    nd = dict.size();
    minL = INT_MAX;
 
    en = end;
 
    vector<string> temp;
    bool vis[nd];
    memset(vis,false,sizeof(vis));
 
    temp.push_back(start);
    dfs(dict,temp,vis,1);
 
    return res;
}