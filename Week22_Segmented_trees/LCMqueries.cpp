#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

void updateValue(int *, ll *, int, int, int);
ll getLCM(ll *, int *, int, int, int);

int getMid(int s, int e) {
    return s + (e - s) / 2;
}

ll LCM(ll a, ll b) {
    return (a * b) / __gcd(a, b);
}

ll constructSTUtil(int *arr, int ss, int se, ll *st, int si) {
    if (ss == se) {
        st[si] = arr[ss];
        return st[si];
    }
    int mid = getMid(ss, se);
    constructSTUtil(arr, ss, mid, st, si * 2 + 1);
    constructSTUtil(arr, mid + 1, se, st, si * 2 + 2);

    st[si] = LCM(st[si * 2 + 1], st[si * 2 + 2]);
    return st[si];
}
ll *constructST(int *arr, int n) {
    int x = (int)(ceil(log2(n)));
    int max_size = 2 * (int)pow(2, x) - 1;
    ll *st = new ll[max_size];
    constructSTUtil(arr, 0, n - 1, st, 0);
    return st;
}


// } Driver Code Ends
// User function template in C++

// arr : given array
// n : size of the array
// qs and qe are L and R respectively given in the problem to denotes range
// st : segment tree of the array arr

ll RangeLCM(int ss, int se, int si, int qs, int qe, ll *st)
{
    if (qs > se or qe < ss) return 1;
    if (qs <= ss and se <= qe) return st[si];

    int mid = getMid(ss, se);
    ll left = RangeLCM(ss, mid, 2 * si + 1, qs, qe, st);
    ll right = RangeLCM(mid + 1, se, 2 * si + 2, qs, qe, st);
    return LCM(left, right);
}

//Function to find LCM of given range.
ll getLCM(ll *st, int *arr, int n, int qs, int qe)
{
    // Code here
    if (qs > n - 1 or qe < 0) return 0;
    return RangeLCM(0, n - 1, 0, qs, qe, st);
}

void update(int ss, int se , int si, int index, int *arr, ll *st)
{
    if (index<ss or index>se) return;
    if (ss == se)
    {
        st[si] = arr[index];
        return;
    }

    int mid = getMid(ss, se);
    update(ss, mid, 2 * si + 1, index, arr, st);
    update(mid + 1, se, 2 * si + 2, index, arr, st);

    st[si] = LCM(st[2 * si + 1], st[2 * si + 2]);

}
//Function to update a value in input array and segment tree.
void updateValue(int *arr, ll *st, int n, int index, int new_val)
{
    // Code here
    if (index<0 or index>n - 1) return;
    arr[index] = new_val;
    update(0, n - 1, 0, index, arr, st);
}

//{ Driver Code Starts.

int main() {
#ifndef ONLINE_JUDGE
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);
#endif
    int t;
    cin >> t;
    while (t--) {
        int num, query;
        cin >> num >> query;
        int arr[num];
        for (int i = 0; i < num; i++) cin >> arr[i];

        ll *st = constructST(arr, num);
        int L, R, index, val;
        char type;
        while (query--) {
            //  cin.ignore(INT_MAX, '\n');
            cin >> type;
            if (type == 'G') {
                cin >> L >> R;
                cout << getLCM(st, arr, num, L, R) << endl;
            } else if (type == 'U') {
                cin >> index >> val;
                updateValue(arr, st, num, index, val);
            }
        }
    }
}