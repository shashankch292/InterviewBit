/*
There are N children standing in a line. Each child is assigned a rating value.

 You are giving candies to these children subjected to the following requirements:
Each child must have at least one candy.
Children with a higher rating get more candies than their neighbors.
What is the minimum candies you must give?

Sample Input :

Ratings : [1 2]
Sample Output :

3
The candidate with 1 rating gets 1 candy and candidate with rating cannot get 1 candy as 1 is its neighbor. So rating 2 candidate gets 2 candies. In total, 2+1 = 3 candies need to be given out.

LINK: https://www.interviewbit.com/problems/distribute-candy/
*/

int Solution::candy(vector<int> &A)
{
    int n = A.size();
 
    vector<int> l(n,1), r(n,1);
 
    for(int i=1;i<n;i++)
        if(A[i] > A[i-1])
            l[i] = l[i-1] + 1;
 
    for(int i=n-2;i>=0;i--)
        if(A[i] > A[i+1])
            r[i] = r[i+1] + 1;
 
    int ans = 0;
 
    for(int i=0;i<n;i++)
        ans += max(l[i], r[i]);
 
    return ans;
}