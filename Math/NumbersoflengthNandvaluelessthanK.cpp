/*
Given a set of digits (A) in sorted order, find how many numbers of length B are possible whose value is less than number C.

 NOTE: All numbers can only have digits from the given set. 
Examples:

	Input:
	  0 1 5  
	  1  
	  2  
	Output:  
	  2 (0 and 1 are possible)  

	Input:
	  0 1 2 5  
	  2  
	  21  
	Output:
	  5 (10, 11, 12, 15, 20 are possible)
Constraints:

    1 <= B <= 9, 0 <= C <= 1e9 & 0 <= A[i] <= 9

LINK: https://www.interviewbit.com/problems/numbers-of-length-n-and-value-less-than-k/
*/

vector<int> ntv(int n)
{
    vector<int> v;
    while(n)
    {
        v.push_back(n%10);
        n/=10;
    }
    if(v.size()==0)
        v.push_back(0);
 
    reverse(v.begin(), v.end());
    return v;
}
 
int Solution::solve(vector<int> &A, int B, int C)
{
    vector<int> cvec = ntv(C);
    int n=A.size();
 
    if(B>cvec.size() || n==0)
        return 0;
    else
    if(B<cvec.size())
    {
        if(A[0]==0 && B!=1)
            return (n-1)*pow(n,B-1);
        else
            return pow(n,B);
    }
    else
    {
        int dp[B+1], larr[11];
        memset(dp,0,sizeof(dp));
        memset(larr,0,sizeof(larr));
 
        for(int i=0;i<n;i++)
            larr[A[i]+1] = 1;
        for(int i=1;i<11;i++)
            larr[i] += larr[i-1];
 
        bool flag = true;
 
        for(int i=1;i<=B;i++)
        {
            int lnum = larr[cvec[i-1]];
            dp[i] = dp[i-1]*n;
 
            if(i==1 && A[0]==0 && B!=1)
                lnum--;
 
            if(flag)
                dp[i] += lnum;
 
            flag = flag & (larr[cvec[i-1]+1] == larr[cvec[i-1]]+1);
        }
        return dp[B];
    }
}