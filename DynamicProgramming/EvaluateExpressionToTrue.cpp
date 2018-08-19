/*
Given expression with operands and operators (OR , AND , XOR) , in how many ways can you evaluate the expression to true, by grouping in different ways? Operands are only true and false.
Input:

string :  T|F&T^T
here '|' will represent or operator 
     '&' will represent and operator
     '^' will represent xor operator
     'T' will represent true operand
     'F' will false
Output:

different ways % MOD
where MOD = 1003
Example:

string : T|F
only 1 way (T|F) => T
so output will be 1 % MOD = 1

LINK: https://www.interviewbit.com/problems/evaluate-expression-to-true/
*/

typedef long long int ll;
#define MOD 1003
 
int Solution::cnttrue(string A)
{
    int n = A.length();
    int no = (n/2)+1;
    vector<vector<ll> > T(no, vector<ll>(no, 0));
    vector<vector<ll> > F(no, vector<ll>(no, 0));
 
    for(int len=1;len<=no;len++)
    {
        for(int j=len-1;j<no;j++)
        {
            int i = j-(len-1);
 
            if(len==1)
            {
                T[i][j] = A[i*2] == 'T' ? 1 : 0;
                F[i][j] = A[i*2] == 'F' ? 1 : 0;
            }
            else
            {
                for(int k=i;k<j;k++)
                {
                    char op = A[k*2+1];
 
                    ll leftT = T[i][k];
                    ll leftF = F[i][k];
                    ll rightT = T[k+1][j];
                    ll rightF = F[k+1][j];
 
                    ll totalT = 0, totalF = 0;
 
                    if(op == '&')
                    {
                        totalT = (leftT * rightT)%MOD;
                        totalF = (leftT * rightF)%MOD + (leftF * rightT)%MOD + (leftF * rightF)%MOD;
                    }
                    else
                    if(op == '|')
                    {
                        totalT = (leftT * rightF)%MOD + (leftF * rightT)%MOD + (leftT * rightT)%MOD;
                        totalF = (leftF * rightF)%MOD;
                    }
                    else
                    if(op == '^')
                    {
                        totalT = (leftT * rightF)%MOD + (leftF * rightT)%MOD;
                        totalF = (leftT * rightT)%MOD + (leftF * rightF)%MOD;
                    }
 
                    T[i][j] = (T[i][j] + totalT)%MOD;
                    F[i][j] = (F[i][j] + totalF)%MOD;
                }
            }
        }
    }
    return T[0][no-1];
}
