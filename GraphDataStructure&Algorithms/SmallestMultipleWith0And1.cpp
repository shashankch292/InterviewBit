/*
You are given an integer N. You have to find smallest multiple of N which consists of digits 0 and 1 only. Since this multiple could be large, return it in form of a string.

Note:

Returned string should not contain leading zeroes.
For example,

For N = 55, 110 is smallest multiple consisting of digits 0 and 1.
For N = 2, 10 is the answer.

LINK: https://www.interviewbit.com/problems/smallest-multiple-with-0-and-1/
*/

string Solution::multiple(int A)
{
    if(A==0)
        return "0";
 
    int val[A+1], par[A+1], flag[A+1];
    memset(val,-1,sizeof(val));
    memset(par,-1,sizeof(par));
    memset(flag,0,sizeof(flag));
 
    queue<int> q;
 
    q.push(1%A);
    par[1%A] = -1;
    val[1%A] = 1;
    flag[1%A] = 1;
 
    while(!q.empty())
    {
        int num = q.front();
        q.pop();
 
        if(num == 0)
        {
            string s = "";
 
            while(num!=-1)
            {
                s.push_back(val[num] + '0');
                num = par[num];
            }
 
            reverse(s.begin(), s.end());
 
            return s;
        }
 
        int num0 = (num*10)%A;
        int num1 = (num*10 + 1)%A;
 
        if(flag[num0]==0)
        {
            flag[num0] = 1;
            par[num0] = num;
            val[num0] = 0;
            q.push(num0);
        }
 
        if(flag[num1] == 0)
        {
            flag[num1] = 1;
            par[num1] = num;
            val[num1] = 1;
            q.push(num1);
        }
 
    }
}