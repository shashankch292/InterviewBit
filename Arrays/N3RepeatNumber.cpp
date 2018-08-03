/*
You’re given a read only array of n integers. Find out if any integer occurs more than n/3 times in the array in linear time and constant additional space.

If so, return the integer. If not, return -1.

If there are multiple solutions, return any one.

Example :

Input : [1 2 3 1 1]
Output : 1 
1 occurs 3 times which is more than 5/3 times. 

LINK: https://www.interviewbit.com/problems/n3-repeat-number/
*/

struct ele
{
    int e,c;    
};
 
int Solution::repeatedNumber(const vector<int> &A)
{
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
 
    int n = A.size(), k=3;
 
    ele temp[k-1];
    for(int i=0;i<k-1;i++)
        temp[i].c=0;
 
    for(int i=0;i<n;i++)
    {
        int j;
        for(j=0;j<k-1;j++)
        {    
            if(temp[j].e==A[i])
            {
                temp[j].c++;
                break;
            }
        }
 
        if(j==k-1)
        {
            for(j=0;j<k-1;j++)
            {    
                if(temp[j].c==0)
                {
                    temp[j].e = A[i];
                    temp[j].c = 1;
                    break;
                }
            }
 
            if(j==k-1)
                for(j=0;j<k-1;j++)
                    temp[j].c--;
        }
    }
 
    for(int i=0;i<k-1;i++)
    {
        int cnt=0;
        for(int j=0;j<n;j++)
            if(temp[i].e == A[j])
                cnt++;
 
        if(cnt > n/k)
            return temp[i].e;
    }
 
    return -1;
}