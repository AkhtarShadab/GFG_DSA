#include <bits/stdc++.h>
#include <string.h>
#define endl '\n'
typedef long long ll;
using ld = long double;
using namespace std;

ll binary_exponentiation(ll a, ll b, ll m) {
  ll ans = 1;
  while (b) {
    if (b % 2 == 1) {
      ans = (ans * a) % m;
    }
    a = (a * a) % m;
    b /= 2;
  }
  return ans;
}

int gcd(int a, int b) {
  if (a == 0 || b == 0)
    return a ^ b;
  return __gcd(a, b);
}

int solve(ll n) {
  int count=0;
  while (n > 0) {
    count++;
    n/=10;
  }
  return count;
}

int main() {
  // int t;cin>>t;while(t--){}
  ll n;
  cin>>n;
  cout<<solve(n);
  return 0;
}
