/*
Given a set of strings. Find the length of smallest string which
has all the strings in the set as substring

Constraints:
1) 1 <= Number of strings <= 18
2) Length of any string in the set will not exceed 100.

Example:
Input: [“abcd”, “cdef”, “fgh”, “de”]
Output: 8 (Shortest string: “abcdefgh”)

LINK: https://www.interviewbit.com/problems/shortest-common-superstring/
*/

bool contains(string s1, string s2)
{
    if(s1.length() < s2.length())
        return false;
    if(s2.length()==0)
        return true;
 
    int n1 = s1.length();
    int n2 = s2.length();
 
    for(int i=0;i<n1-n2;i++)
    {
        string temp = s1.substr(i,n2);
        if(s2.compare(temp) == 0)
            return true;
    }
    return false;
}
 
int longestCommanSuffix1Prefix2(string s1, string s2)
{
    int n1 = s1.length();
    int n2 = s2.length();
    int len = min(n1, n2);
    while(len)
    {
        string suff = s1.substr(n1 - len);
        string pref = s2.substr(0, len);
        if(suff.compare(pref) == 0)
            break;
        len--;
    }
    return len;
}
 
int findSuperString(string s1, string s2, vector<string> &superString)
{
    if(contains(s1, s2))
    {
        superString.push_back(s1);
        return s2.length();
    }
    if(contains(s2, s1))
    {
        superString.push_back(s2);
        return s1.length();
    }
 
    int l1 = longestCommanSuffix1Prefix2(s1, s2);
    int l2 = longestCommanSuffix1Prefix2(s2, s1);
 
    if(l1>l2)
    {
        superString.push_back(s1 + s2.substr(l1));
        return l1;
    }
    if(l2>l1)
    {
        superString.push_back(s2 + s1.substr(l2));
        return l2;
    }
 
    superString.push_back(s1 + s2.substr(l1));
    superString.push_back(s2 + s1.substr(l2));
    return l1;
}
 
int Solution::solve(vector<string> &A)
{
    int superStringSize = INT_MAX;
 
    int n = A.size();
    if(n==0)
        return 0;
    if(n==1)
        return A[0].length();
 
    vector<string> maxSuperStringPair;
    int maxOverlap = -1;
 
    int a,b;
 
    for(int i=0;i<n;i++)
    {
        for(int j=i+1;j<n;j++)
        {
            vector<string> currSuperStringPair;
 
            int currOverlap = findSuperString(A[i], A[j], currSuperStringPair);
 
            if(currOverlap > maxOverlap)
            {
                maxOverlap = currOverlap;
                maxSuperStringPair = currSuperStringPair;
                a = i;
                b = j;
            }
        }
    }
 
    int m = maxSuperStringPair.size();
 
    for(int i=0;i<m;i++)
    {
        A[a] = maxSuperStringPair[i];
        A[b] = maxSuperStringPair[i];
 
        vector<string> temp = A;
        swap(temp[b], temp[n-1]);
        temp.pop_back();
 
        int currSuperStringSize = solve(temp);
 
        if(currSuperStringSize < superStringSize)
            superStringSize = currSuperStringSize;
 
    }
 
    return superStringSize;
}