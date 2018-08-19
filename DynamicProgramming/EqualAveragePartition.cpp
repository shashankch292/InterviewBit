/*
Given an array with non negative numbers, divide the array into two parts such that the average of both the parts is equal. 
Return both parts (If exist).
If there is no solution. return an empty list.

Example:


Input:
[1 7 15 29 11 9]

Output:
[9 15] [1 7 11 29]

The average of part is (15+9)/2 = 12,
average of second part elements is (1 + 7 + 11 + 29) / 4 = 12

 NOTE 1: If a solution exists, you should return a list of exactly 2 lists of integers A and B which follow the following condition :
numElements in A <= numElements in B
If numElements in A = numElements in B, then A is lexicographically smaller than B ( https://en.wikipedia.org/wiki/Lexicographical_order )
NOTE 2: If multiple solutions exist, return the solution where length(A) is minimum. If there is still a tie, return the one where A is lexicographically smallest. NOTE 3: Array will contain only non negative numbers. 

LINK: https://www.interviewbit.com/problems/equal-average-partition/
*/

int total_size;
vector<int> temp;
vector<vector<vector<bool> > > dp;
 
bool check(int ind, int sum, int sz, vector<int> &A)
{
    if(sz==0)
        return sum==0;
 
    if(ind >= total_size)
        return false;
 
    if(dp[ind][sum][sz] == false)
        return false;
 
    if(sum >= A[ind])
    {
        temp.push_back(A[ind]);
        if(check(ind+1, sum-A[ind], sz-1, A))
            return true;
        temp.pop_back();
    }
 
    if(check(ind+1, sum, sz, A))
        return true;
 
    return dp[ind][sum][sz] = false;
}
 
vector<vector<int> > Solution::avgset(vector<int> &A)
{
    temp.clear();
    dp.clear();
 
    vector<vector<int> > res;
    total_size = A.size();
 
    if(total_size == 0)
        return res;
 
    sort(A.begin(), A.end());
 
    int total_sum = 0;
    for(int i=0;i<total_size;i++)
        total_sum += A[i];
 
    dp.resize(total_size, vector<vector<bool> >(total_sum+1, vector<bool>(total_size, true)));
 
    for(int i=1;i<total_size;i++)
    {
        if((total_sum*i)%total_size != 0)
            continue;
 
        int sumSet1 = (total_sum*i)/total_size;
 
        if(check(0,sumSet1,i,A))
        {
            int ptr1 = 0;
            int ptr2 = 0;
            vector<int> s1, s2;
            s1 = temp;
 
            while(ptr1 < total_size || ptr2 < temp.size())
            {
                if(ptr2 < temp.size() && temp[ptr2] == A[ptr1])
                {
                    ptr1++;
                    ptr2++;
                    continue;
                }
                s2.push_back(A[ptr1]);
                ptr1++;
            }
            res.push_back(s1);
            res.push_back(s2);
            return res;
        }
    }
 
    return res;
}
