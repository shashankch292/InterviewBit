/*
Given an absolute path for a file (Unix-style), simplify it.

Examples:

path = "/home/", => "/home"
path = "/a/./b/../../c/", => "/c"
Note that absolute path always begin with ‘/’ ( root directory )
Path will not have whitespace characters.

LINK: https://www.interviewbit.com/problems/simplify-directory-path/
*/

string Solution::simplifyPath(string s)
{
    int n = s.length();
 
    stack<string> st;
    string temp = "";
    string res = "";
 
    for(int i=0;i<n;i++)
    {
        temp = "";
 
        while(i<n && s[i]=='/')
            i++;
 
        while(i<n && s[i]!='/')
            temp.push_back(s[i++]);
 
        if(temp=="..")
        {
            if(!st.empty())
                st.pop();
        }
        else
        if(temp==".")
            continue;
        else
        if(temp.length()>0)
            st.push(temp);
    }
 
    while(!st.empty())
    {
        temp = st.top();
        st.pop();
        if(res=="")
            res = temp;
        else
            res = temp + "/" + res;
    }
    res = "/" + res;
    return res;
}