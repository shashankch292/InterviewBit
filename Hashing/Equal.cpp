/*
Given an array A of integers, find the index of values that satisfy A + B = C + D, where A,B,C & D are integers values in the array

Note:

1) Return the indices `A1 B1 C1 D1`, so that 
  A[A1] + A[B1] = A[C1] + A[D1]
  A1 < B1, C1 < D1
  A1 < C1, B1 != D1, B1 != C1 

2) If there are more than one solutions, 
   then return the tuple of values which are lexicographical smallest. 

Assume we have two solutions
S1 : A1 B1 C1 D1 ( these are values of indices int the array )  
S2 : A2 B2 C2 D2

S1 is lexicographically smaller than S2 iff
  A1 < A2 OR
  A1 = A2 AND B1 < B2 OR
  A1 = A2 AND B1 = B2 AND C1 < C2 OR 
  A1 = A2 AND B1 = B2 AND C1 = C2 AND D1 < D2
Example:

Input: [3, 4, 7, 1, 2, 9, 8]
Output: [0, 2, 3, 5] (O index)
If no solution is possible, return an empty list.

LINK: https://www.interviewbit.com/problems/equal/
*/

vector<int> Solution::equal(vector<int> &A)
{
    vector<int> res;
    unordered_map<long long int, pair<int,int> > mp;
    int n = A.size();
 
    for(int i=0;i<n;i++)
    {
        for(int j=i+1;j<n;j++)
        {
            int sum = A[i]+A[j];
 
            if(mp.find(sum)==mp.end())
                mp[sum]={i,j};
            else
            {
                int ii = mp[sum].first;
                int jj = mp[sum].second;
                if(ii==i || ii==j || jj==i || jj==j)
                    continue;
 
                vector<int> temp = {ii,jj,i,j};
 
                if(res.empty())
                    res = temp;
                else
                {
                    for(int i=0;i<4;i++)
                    {
                        if(res[i]<temp[i])
                            break;
                        else
                        if(res[i]>temp[i])
                        {
                            res = temp;
                            break;
                        }
                    }
                }
            }
        }
    }
    return res;
}