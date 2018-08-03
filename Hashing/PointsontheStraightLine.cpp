/*
Given n points on a 2D plane, find the maximum number of points that lie on the same straight line.

Sample Input :

(1, 1)
(2, 2)
Sample Output :

2
You will be give 2 arrays X and Y. Each point is represented by (X[i], Y[i])

LINK: https://www.interviewbit.com/problems/points-on-the-straight-line/
*/

inline size_t key(int i,int j) {return (size_t) i << 32 | (unsigned int) j;}
 
int Solution::maxPoints(vector<int> &A, vector<int> &B)
{
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
 
    unordered_map<size_t ,int> mp;
 
    int res=0, n = A.size();
    if(n<2)
        return n;
 
    for(int i=0;i<n;i++)
    {
        int crmx=0, ovrlap=0, vert=0;
 
        for(int j=i+1;j<n;j++)
        {
            if(A[i]==A[j] && B[i]==B[j])
                ovrlap++;
            else
            if(A[i]==A[j])
                vert++;
            else
            {
                int xdiff = A[j]-A[i];
                int ydiff = B[j]-B[i];
                int g = __gcd(ydiff,xdiff);
 
                xdiff/=g;
                ydiff/=g;
 
                mp[key(xdiff,ydiff)]++;
 
                crmx = max(crmx, mp[key(xdiff,ydiff)]);
            }
            crmx = max(crmx, vert);
        }
 
        res = max(res, crmx+ovrlap+1);
 
        mp.clear();
    }
    return res;
}