/*
Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses of length 2*n.

For example, given n = 3, a solution set is:

"((()))", "(()())", "(())()", "()(())", "()()()"
Make sure the returned list of strings are sorted.

LINK: https://www.interviewbit.com/problems/generate-all-parentheses-ii/
*/

vector<string> res;
 
void getParenth(int n, int bal, string &temp)
{
    if(temp.length()==2*n)
    {
        if(bal==0)
            res.push_back(temp);
        return;
    }
 
    if(bal<n)
    {
        temp.push_back('(');
        getParenth(n,bal+1,temp);
        temp.pop_back();
    }
    if(bal>0)
    {
        temp.push_back(')');
        getParenth(n,bal-1,temp);
        temp.pop_back();
    }
}
 
vector<string> Solution::generateParenthesis(int A)
{
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
 
    res.clear();
    string temp = "";
 
    getParenth(A, 0, temp);
 
    return res;
}