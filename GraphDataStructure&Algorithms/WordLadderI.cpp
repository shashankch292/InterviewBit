/*
Given two words (start and end), and a dictionary, find the length of shortest transformation sequence from start to end, such that:

You must change exactly one character in every transformation
Each intermediate word must exist in the dictionary
Example :

Given:

start = "hit"
end = "cog"
dict = ["hot","dot","dog","lot","log"]
As one shortest transformation is "hit" -> "hot" -> "dot" -> "dog" -> "cog",
return its length 5.

Note that we account for the length of the transformation path instead of the number of transformation itself.

 Note:
Return 0 if there is no such transformation sequence.
All words have the same length.
All words contain only lowercase alphabetic characters.

LINK: https://www.interviewbit.com/problems/word-ladder-i/
*/

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
 
    return true;
}
 
int Solution::ladderLength(string start, string end, vector<string> &dictV)
{
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
 
    int n = dictV.size();
    bool vis[n];
    memset(vis,false,sizeof(vis));
 
    queue<pair<string,int> > q;
 
    q.push({start, 1});
 
    while(!q.empty())
    {
        string temp = q.front().first;
        int lev = q.front().second;
        q.pop();
 
        if(temp==end)
            return lev;
 
        if(isAdj(temp, end))
            return lev+1;
 
        for(int i=0;i<n;i++)
        {
            if(vis[i]==false && isAdj(temp, dictV[i]))
            {
                vis[i] = true;
                q.push({dictV[i],lev+1});
            }
        }
    }
 
    return 0;
}