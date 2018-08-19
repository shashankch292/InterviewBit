/*
As it is Tushar’s Birthday on March 1st, he decided to throw a party to all his friends at TGI Fridays in Pune.
Given are the eating capacity of each friend, filling capacity of each dish and cost of each dish. A friend is satisfied if the sum of the filling capacity of dishes he ate is equal to his capacity. Find the minimum cost such that all of Tushar’s friends are satisfied (reached their eating capacity).

NOTE:

Each dish is supposed to be eaten by only one person. Sharing is not allowed.
Each friend can take any dish unlimited number of times.
There always exists a dish with filling capacity 1 so that a solution always exists.
Input Format

Friends : List of integers denoting eating capacity of friends separated by space.
Capacity: List of integers denoting filling capacity of each type of dish.
Cost :    List of integers denoting cost of each type of dish.
Constraints:
1 <= Capacity of friend <= 1000
1 <= No. of friends <= 1000
1 <= No. of dishes <= 1000

Example:

Input:
    2 4 6
    2 1 3
    2 5 3

Output:
    14

Explanation: 
    First friend will take 1st and 2nd dish, second friend will take 2nd dish twice.  Thus, total cost = (5+3)+(3*2)= 14

LINK: https://www.interviewbit.com/problems/tushars-birthday-party/
*/

int Solution::solve(const vector<int> &A, const vector<int> &B, const vector<int> &C)
{
    int nf = A.size();
    int nd = B.size();
 
    if(nf==0)
        return 0;
 
    int maxCap = A[0];
 
    for(int i=1;i<nf;i++)
        maxCap = max(maxCap, A[i]);
 
    long long int dp[maxCap+1][nd+1];
    memset(dp,0,sizeof(dp));
 
    for(int i=1;i<=maxCap;i++)
        dp[i][0] = INT_MAX;
 
    for(int i=1;i<=maxCap;i++)
    {
        for(int j=1;j<=nd;j++)
        {
            if(i>=B[j-1])
                dp[i][j] = min(dp[i][j-1], C[j-1] + dp[i-B[j-1]][j]);
            else
                dp[i][j] = dp[i][j-1];
        }
    }
 
    int ans = 0;
 
    for(int i=0;i<nf;i++)
        ans += dp[A[i]][nd];
 
    return ans;
}