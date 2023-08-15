#include <bits/stdc++.h>
#include <climits>
#define endl '\n'
typedef long long ll;
typedef long double ld;
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define mod 1000000007
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
void findcomb(vector<char> keypad[], int input[], string res, int index, int n, vector<string> &ans)
{
    if (index == n)
    {
        ans.push_back(res);
        return ;
    }
    int digit = input[index];
    int len = keypad[digit].size();
    for (int i = 0; i < len; ++i)
    {
        findcomb(keypad, input, res + keypad[digit][i], index + 1, n, ans);
    }

}
vector<string> possibleNords(int arr[], int N)
{
    vector<char> keypad[] = {
        {}, {},
        {'a', 'b', 'c'},
        {'d', 'e', 'f'},
        {'g', 'h', 'i'},
        {'j', 'k', 'l'},
        {'m', 'n', 'o'},
        {'p', 'q', 'r', 's'},
        {'t', 'u', 'v'},
        {'w', 'x', 'y', 'z'}
    };
    vector<string> ans;
    string x = "";
    findcomb(keypad, arr, x, 0, N, ans);
    return ans;
}

void solve()
{
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; ++i)
    {
        cin >> arr[i];
    }
    vector<string> ans = possibleNords(arr, n);
    for (int i = 0; i < ans.size(); ++i)
    {
        cout << ans[i] << endl;
    }
}
int main()
{
#ifndef ONLINE_JUDGE
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);
#endif
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}
