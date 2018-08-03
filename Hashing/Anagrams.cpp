/*
Given an array of strings, return all groups of strings that are anagrams. Represent a group by a list of integers representing the index in the original list. Look at the sample case for clarification.

 Anagram : a word, phrase, or name formed by rearranging the letters of another, such as 'spar', formed from 'rasp' 
 Note: All inputs will be in lower-case. 
Example :

Input : cat dog god tca
Output : [[1, 4], [2, 3]]
cat and tca are anagrams which correspond to index 1 and 4. 
dog and god are another set of anagrams which correspond to index 2 and 3.
The indices are 1 based ( the first element has index 1 instead of index 0).

 Ordering of the result : You should not change the relative ordering of the words / phrases within the group. Within a group containing A[i] and A[j], A[i] comes before A[j] if i < j.

LINK: https://www.interviewbit.com/problems/anagrams/
*/

vector<vector<int> > Solution::anagrams(const vector<string> &A)
{
    vector<vector<int> > res;
    vector<string> v;
    int n = A.size();
 
    for(int i=0;i<n;i++)
    {
        string s = A[i];
        sort(s.begin(), s.end());
        v.push_back(s);
    }
 
    unordered_map<string, vector<int> > mp;
 
    for(int i=0;i<n;i++)
        mp[v[i]].push_back(i+1);
 
    for(auto it=mp.begin();it!=mp.end();it++)
        res.push_back(it->second);
    return res;
}
