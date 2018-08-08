/*
Find shortest unique prefix to represent each word in the list.

Example:

Input: [zebra, dog, duck, dove]
Output: {z, dog, du, dov}
where we can see that
zebra = z
dog = dog
duck = du
dove = dov
 NOTE : Assume that no word is prefix of another. In other words, the representation is always possible. 

LINK: https://www.interviewbit.com/problems/shortest-unique-prefix/
*/

struct TrieNode
{
    TrieNode* children[26];
    int unq_wrd_cnt;
    TrieNode()
    {
        for(int i=0;i<26;i++)
            children[i]=NULL;
        unq_wrd_cnt = 0;
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
        pCrawl->unq_wrd_cnt++;
    }
}
 
string findPre(TrieNode* root, string s)
{
    TrieNode *pCrawl = root->children[s[0]-'a'];
    string pre = "";
    pre += s[0];
 
    for(int i=1;i<s.length();i++)
    {
        if(pCrawl->unq_wrd_cnt==1)
            return pre;
        pCrawl = pCrawl->children[s[i]-'a'];
        pre += s[i];
    }
    return pre;
}
 
vector<string> Solution::prefix(vector<string> &A)
{
    vector<string> res;
 
    if(A.empty())
        return res;
 
    int n = A.size();
 
    TrieNode* root = new TrieNode();
 
    for(int i=0;i<n;i++)
        insert(root,A[i]);
 
    for(int i=0;i<n;i++)
        res.push_back(findPre(root,A[i]));
 
    return res;
}