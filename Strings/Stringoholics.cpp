/*
You are given an array A consisting of strings made up of the letters ‘a’ and ‘b’ only. 
Each string goes through a number of operations, where:
<ul>
<li>At time 1, you circularly rotate each string by 1 letter.</li>
<li>At time 2, you circularly rotate the new rotated strings by 2 letters.</li>
<li>At time 3, you circularly rotate the new rotated strings by 3 letters.</li>
<li>At time i, you circularly rotate the new rotated strings by i % length(string) letters.</li>
</ul>
Eg: String is abaa
<ul>
<li>At time 1, string is baaa, as 1 letter is circularly rotated to the back</li>
<li>At time 2, string is aaba, as 2 letters of the string baaa is circularly rotated to the back</li>
<li>At time 3, string is aaab, as 3 letters of the string aaba is circularly rotated to the back</li>
<li>At time 4, string is again aaab, as 4 letters of the string aaab is circularly rotated to the back</li>
<li>At time 5, string is aaba, as 1 letters of the string aaab is circularly rotated to the back</li>
</ul>
After some units of time, a string becomes equal to it’s original self. 
Once a string becomes equal to itself, it’s letters start to rotate from the first letter again (process resets). So, if a string takes t time to get back to the original, at time t+1 one letter will be rotated and the string will be it’s original self at 2t time. 
You have to find the minimum time, where maximum number of strings are equal to their original self. 
As this time can be very large, give the answer modulo 109+7.

Note: Your solution will run on multiple test cases so do clear global variables after using them.

Input:

A: Array of strings.
Output:

Minimum time, where maximum number of strings are equal to their original self.
Constraints:

1 <= size(A) <= 10^5
1 <= size of each string in A <= 10^5
Each string consists of only characters 'a' and 'b'
Summation of length of all strings <= 10^7
Example:

Input

A: [a,ababa,aba]
Output

4

String 'a' is it's original self at time 1, 2, 3 and 4.
String 'ababa' is it's original self only at time 4. (ababa => babaa => baaba => babaa => ababa)
String 'aba' is it's original self at time 2 and 4. (aba => baa => aba)

Hence, 3 strings are their original self at time 4.

LINK: https://www.interviewbit.com/problems/stringoholics/
*/

typedef long long int ll;
#define MOD 1000000007

ll powe(ll a, ll b, ll p=MOD)
{
    ll res = 1;

    a = a%p;

    while(b)
    {
        if(b&1)
            res = (res*a)%p;

        b = b>>1;
        a = (a*a)%p;
    }

    return res;
}

ll computeLPS(string s)
{
    int n = s.length();

    ll lps[n];
    lps[0] = 0;

    int i = 1, len = 0;

    while(i<n)
    {
        if(s[i] == s[len])
        {
            len++;
            lps[i] = len;
            i++;
        }
        else
        {
            if(len == 0)
            {
                lps[i] = 0;
                i++;
            }
            else
                len = lps[len-1];
        }
    }

    return lps[n-1];
}

ll calc(string s)
{
    ll n = s.length();
    ll x = computeLPS(s);

    if(n%(n-x) == 0)
        n -= x;

    ll i=1, sum = 1;

    while(1)
    {
        if(sum%n == 0)
            break;
        i++;
        sum += i;
    }
    return i;
}

ll findLCM(vector<ll> &v)
{
    int n = v.size();
    unordered_map<ll, ll> mp;

    for(int i=0;i<n;i++)
    {
        ll num = v[i];
        for(int j=2;j<=num;j++)
        {
            ll cnt = 0;
            while(num%j == 0)
            {
                cnt++;
                num /= j;
            }

            if(cnt == 0)
                continue;

            mp[j] = max(mp[j], cnt);
        }
    }

    ll val = 1;

    for(auto x : mp)
    {
        ll a = x.first;
        ll b = x.second;

        val = (val * powe(a,b))%MOD;
    }

    return val;
}

int Solution::solve(vector<string> &A)
{
    ll n = A.size();

    vector<ll> v;

    for(int i=0;i<n;i++)
        v.push_back(calc(A[i]));

    ll ans = findLCM(v);

    return ans;
}