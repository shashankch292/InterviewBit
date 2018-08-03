/*
Given a string, 
find the length of the longest substring without repeating characters.

Example:

The longest substring without repeating letters for "abcabcbb" is "abc", which the length is 3.

For "bbbbb" the longest substring is "b", with the length of 1.

LINK: https://www.interviewbit.com/problems/longest-substring-without-repeat/
*/

int Solution::lengthOfLongestSubstring(string A)
{
    unordered_map<char, int> mp;
    int res = 0, cnt = 0, i = 0;
    int n = A.size();
 
    while(i<n)
    {
        if(mp.find(A[i])==mp.end())
        {
            mp[A[i]] = i+1;
            i++;
            cnt++;
        }
        else
        {
            i = mp[A[i]];
            res = max(res,cnt);
            cnt=0;
            mp.clear();
        }
    }
    return max(res,cnt);
}
