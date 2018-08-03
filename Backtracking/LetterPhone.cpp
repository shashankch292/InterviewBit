/*
Given a digit string, return all possible letter combinations that the number could represent.

A mapping of digit to letters (just like on the telephone buttons) is given below.



The digit 0 maps to 0 itself.
The digit 1 maps to 1 itself.

Input: Digit string "23"
Output: ["ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"].
Make sure the returned strings are lexicographically sorted.

LINK: https://www.interviewbit.com/problems/letter-phone/
*/

vector<string> res;
string phone[] = {"0", "1", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
 
void getLetters(string A, int i, string temp)
{
    if(i==A.length())
    {
        res.push_back(temp);
        return;
    }
 
    int ind = A[i]-'0';
    int len = phone[ind].length();
 
    for(int j=0;j<len;j++)
    {
        temp.push_back(phone[ind][j]);
        getLetters(A, i+1, temp);
        temp.pop_back();
    }
}
 
vector<string> Solution::letterCombinations(string A)
{
    res.clear();
    string temp;
 
    getLetters(A, 0, temp);
 
    return res;
}