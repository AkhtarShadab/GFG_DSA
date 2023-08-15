#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int getMid(int s, int e) {
    return s + (e - s) / 2;
}

ll constructSTUtil(int *arr, int ss, int se, ll *st, int si) {
    if (ss == se) {
        st[si] = arr[ss];
        return arr[ss];
    }
    int mid = getMid(ss, se);
    st[si] = constructSTUtil(arr, ss, mid, st, si * 2 + 1) +
             constructSTUtil(arr, mid + 1, se, st, si * 2 + 2);
    return st[si];
}

ll *constructST(int *arr, int n) {
    int x = (int)(ceil(log2(n)));
    int max_size = 2 * (int)pow(2, x) - 1;
    ll *st = new ll[max_size];
    constructSTUtil(arr, 0, n - 1, st, 0);
    return st;
}

ll getsum(ll *st, int n, int l, int r);
void updateValue(int *, ll *, int, int, int);


// } Driver Code Ends
// User function template for C++

// arr : given array
// n : size of arr
// index : need to update
// new_val : given value to which we need to update index
// st : constructed segment-tree

//Function to update a value in input array and segment tree.
void update(int ss, int se, int si, int index, int diff, ll *st)
{
    if (index<ss or index>se) return;
    if (ss == se)
    {
        st[si] += diff;
        return;
    }

    int mid = getMid(ss, se);
    update(ss, mid, 2 * si + 1, index, diff, st);
    update(mid + 1, se, 2 * si + 2, index, diff, st);
    st[si] += diff;
}
void updateValue(int *arr, ll *st, int n, int index, int new_val)
{
    // add code here
    if (index<0 or index>n - 1) return ;
    int diff = new_val - arr[index];
    arr[index] = new_val;
    update(0, n - 1, 0, index, diff, st);
}

//Function to return sum of elements in range from index qs (query start)
//to qe (query end).
ll RangeSUM(int l, int r, int ss, int se, int si, ll *st)
{
    if (r<ss or l>se) return 0;
    if (l <= ss and r >= se) return st[si];

    int mid = getMid(ss, se);
    return RangeSUM(l, r, ss, mid, 2 * si + 1, st) + RangeSUM(l, r, mid + 1, se, 2 * si + 2, st);
}
ll getsum(ll *st, int n, int l, int r)
{
    // add code here
    if (r<0 or l>n - 1) return 0;
    return RangeSUM(l, r, 0, n - 1, 0, st);
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
            cin.ignore(INT_MAX, '\n');
            cin >> type;
            if (type == 'G') {
                cin >> L >> R;
                cout << getsum(st, num, L, R) << endl;
            } else {
                cin >> index >> val;
                updateValue(arr, st, num, index, val);
            }
        }
    }

    return 0;
}