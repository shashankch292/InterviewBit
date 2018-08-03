/*
You are in an infinite 2D grid where you can move in any of the 8 directions :

 (x,y) to 
    (x+1, y), 
    (x - 1, y), 
    (x, y+1), 
    (x, y-1), 
    (x-1, y-1), 
    (x+1,y+1), 
    (x-1,y+1), 
    (x+1,y-1) 
You are given a sequence of points and the order in which you need to cover the points. Give the minimum number of steps in which you can achieve it. You start from the first point.

Input :

Given two integer arrays A and B, where A[i] is x coordinate and B[i] is y coordinate of ith point respectively.
Output :

Return an Integer, i.e minimum number of steps.
Example :

Input : [(0, 0), (1, 1), (1, 2)]
Output : 2
It takes 1 step to move from (0, 0) to (1, 1). It takes one more step to move from (1, 1) to (1, 2).

This question is intentionally left slightly vague. Clarify the question by trying out a few cases in the “See Expected Output” section.

LINK: https://www.interviewbit.com/problems/min-steps-in-infinite-grid/
*/

int Solution::coverPoints(vector<int> &A, vector<int> &B) 
{
    int x=A[0], y=B[0];
    int cnt = 0;
    for(int i=1;i<A.size();i++)
    {
        int xt = abs(A[i]-x);
        int yt = abs(B[i]-y);
        cnt += min(xt,yt) + abs(xt-yt);
        x=A[i];
        y=B[i];
    }
    return cnt;
}
