/*
Given an array of integers, every element appears thrice except for one which occurs once.

Find that element which does not appear thrice.

Note: Your algorithm should have a linear runtime complexity.

Could you implement it without using extra memory?

Example :

Input : [1, 2, 4, 3, 3, 2, 2, 3, 1, 1]
Output : 4

LINK: https://www.interviewbit.com/problems/single-number-ii/
*/

int Solution::singleNumber(const vector<int> &A)
{
    int res = 0;
    int x, n = A.size();
    for(int i=0;i<32;i++)
    {
        int cnt = 0;
        x = (1<<i);
        for(int j=0;j<n;j++)
            if(A[j]&x)
                cnt++;
        if(cnt%3)
            res |= x;
    }
    return res;
}