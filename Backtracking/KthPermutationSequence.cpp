/*
The set [1,2,3,…,n] contains a total of n! unique permutations.

By listing and labeling all of the permutations in order,
We get the following sequence (ie, for n = 3 ) :

1. "123"
2. "132"
3. "213"
4. "231"
5. "312"
6. "321"
Given n and k, return the kth permutation sequence.

For example, given n = 3, k = 4, ans = "231"

 Good questions to ask the interviewer :
What if n is greater than 10. How should multiple digit numbers be represented in string?
 In this case, just concatenate the number to the answer.
so if n = 11, k = 1, ans = "1234567891011" 
Whats the maximum value of n and k?
 In this case, k will be a positive integer thats less than INT_MAX.
n is reasonable enough to make sure the answer does not bloat up a lot.

LINK: https://www.interviewbit.com/problems/kth-permutation-sequence/
*/

int fact(int n)
{
    if(n>12)
        return INT_MAX;
    int f = 1;
    for(int i=1;i<=n;i++)
        f *= i;
    return f;
}
 
string getPer(int k, vector<int> v)
{
    int n = v.size();
 
    if(n==0 || k>fact(n))
        return "";
 
    int f = fact(n-1);
    int pos = k/f;
    k %= f;
    string ch = to_string(v[pos]);
    v.erase(v.begin()+pos);
    return ch + getPer(k, v);
}
 
string Solution::getPermutation(int A, int B)
{
    vector<int> v;
    for(int i=1;i<=A;i++)
        v.push_back(i);
 
    return getPer(B-1, v);
}
