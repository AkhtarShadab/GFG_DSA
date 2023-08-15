#include <bits/stdc++.h>
#include <string.h>
#define endl '\n'
typedef long long ll;
using ld = long double;
using namespace std;

ll binary_exponentiation(ll a, ll b, ll m)
{
    ll ans = 1;
    while (b)
    {
        if (b % 2 == 1)
        {
            ans = (ans * a) % m;
        }
        a = (a * a) % m;
        b /= 2;
    }
    return ans;
}



int gcd(int a,int b)
{
  if(a==0||b==0) return a^b;
 return __gcd(a,b);
}

bool solve(ll n)
{
    ll rev=0;
    ll temp = n;
    while(temp!=0)
    {
        int ld = temp%10;
        rev = rev*10+ld;
        temp/=10;
    }

    return (rev==n) ? true : false;

}

int main()
{
    // int t;cin>>t;while(t--){}
    ll n;
    cin>>n;
     cout<<solve(n);
    return 0;
}
