/*
Max Heap is a special kind of complete binary tree in which for every node the 
value present in that node is greater than the value present in it’s children nodes. 
If you want to know more about Heaps, please visit this link

So now the problem statement for this question is:

How many distinct Max Heap can be made from n distinct integers

In short, you have to ensure the following properties for the max heap :

Heap has to be a complete binary tree ( A complete binary tree is a binary tree in which every level, 
except possibly the last, is completely filled, and all nodes are as far left as possible. )
Every node is greater than all its children
Let us take an example of 4 distinct integers. Without loss of generality 
let us take 1 2 3 4 as our 4 distinct integers

Following are the possible max heaps from these 4 numbers :

         4 
       /  \ 
      3   2 
     / 
    1
         4 
       /  \ 
      2   3 
     / 
    1
        4 
       /  \ 
      3   1 
     / 
    2
These are the only possible 3 distinct max heaps possible for 4 distinct elements.

Implement the below function to return the number of distinct Max Heaps that is possible from n distinct elements.

As the final answer can be very large output your answer modulo 1000000007

Input Constraints : n <= 100

 NOTE: Note that even though constraints are mentioned for this problem, for most problems on InterviewBit, 
 constraints are intentionally left out. In real interviews, the interviewer might not disclose constraints 
 and ask you to do the best you can do. 

LINK: https://www.interviewbit.com/problems/ways-to-form-max-heap/
*/

#define MOD 1000000007
 
long long int ncr[105][105], dp[105];
 
void ini()
{
    int i,j;
    ncr[0][0]=1;
    for(i=1;i<105;i++)
    {
        ncr[i][0]=1;
        for(j=1;j<=i;j++)
        {
            ncr[i][j]=(ncr[i-1][j]%MOD + ncr[i-1][j-1]%MOD)%MOD;
        }
    }
 
    for(i=0;i<105;i++)
        dp[i]=-1;
}
 
int getleft(int n)
{
    if(n==1)
        return 0;
    int k = log2(n);
    int nodes = 1<<k;
    int m = n - (nodes - 1);
    nodes/=2;
 
    return (nodes-1 + min(nodes,m));
}
 
long long int getnum(int n)
{
    if(n<=1)
        return 1;
    if(dp[n]!=-1)
        return dp[n];
 
    int left_num = getleft(n);
 
    return dp[n] = ((ncr[n-1][left_num] * getnum(left_num))%MOD * getnum(n-1-left_num))%MOD;
}
 
int Solution::solve(int A)
{
    ini();
    return int(getnum(A));
}