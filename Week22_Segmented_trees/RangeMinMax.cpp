#include<bits/stdc++.h>
using namespace std;
typedef pair<int, int> PII;

int getMid(int s, int e) {  return s + (e - s) / 2;  }

void constructSTUtil(int *arr, int ss, int se, PII *st, int si)
{
    if (ss == se)
    {
        st[si].first = st[si].second = arr[ss];
        return;
    }
    int mid = getMid(ss, se);
    constructSTUtil(arr, ss, mid, st, si * 2 + 1);
    constructSTUtil(arr, mid + 1, se, st, si * 2 + 2);

    st[si].first = min(st[si * 2 + 1].first, st[si * 2 + 2].first);
    st[si].second = max(st[si * 2 + 1].second, st[si * 2 + 2].second);

    return;
}

PII *constructST(int *arr, int n)
{
    int x = (int)(ceil(log2(n)));
    int max_size = 2 * (int)pow(2, x) - 1;
    PII *st = new PII[max_size];
    constructSTUtil(arr, 0, n - 1, st, 0);
    return st;
}

void updateValue(int *, PII *, int, int, int);
PII getMinMax(PII *, int *, int, int, int);


// } Driver Code Ends
//User function template for C++

// arr : given array arr
// st : segment tree of the given array arr
// n :  size of arr array
// qs and qe : index range to find Min and Max value between these indexes.
// PII :  return pair denoting min,max respectively.
// index : given index to update with new_val


//Function to update a value in input array and segment tree.
PII getAns(PII *st, int qs, int qe, int ss, int se, int si)
{
    if (qs > se || ss > qe) return {INT_MAX, INT_MIN};
    if (qs <= ss and qe >= se) return st[si];

    int mid = getMid(ss, se);

    PII left = getAns(st, qs, qe, ss, mid, 2 * si + 1);
    PII right = getAns(st, qs, qe, mid + 1, se, 2 * si + 2);
    return {min(left.first, right.first), max(left.second, right.second)};
}

PII getMinMax(PII *st, int *arr, int n, int qs, int qe)
{
    //add code here
    return getAns(st, qs, qe, 0, n - 1, 0);

}

//Function to return minimum and maximum of elements in range from index
//qs (quey start) to qe (query end).
void update(int ss, int se, int index, PII *st, int si, int *arr)
{
    if (ss > index or se < index) return;
    if (ss == se)
    {
        st[si].first = st[si].second = arr[index];
        return;
    }


    int mid = getMid(ss, se);
    update(ss, mid, index, st, 2 * si + 1, arr);
    update(mid + 1, se, index, st, 2 * si + 2, arr);

    st[si].first = min(st[2 * si + 1].first, st[2 * si + 2].first);
    st[si].second = max(st[2 * si + 1].second, st[2 * si + 2].second);

    return;
}
void updateValue(int *arr, PII *st, int n, int index, int new_val)
{
    // add code here
    if (index<0 or index > n - 1) return;
    arr[index] = new_val;
    update(0 , n - 1, index, st, 0, arr);
}

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
        for (int i = 0; i < num; i++)
            cin >> arr[i];

        PII *st = constructST(arr, num);
        int L, R, index , val;
        char type;
        while (query--) {
            cin.ignore(INT_MAX, '\n');
            cin >> type;
            if (type == 'G') {
                cin >> L >> R;
                PII ans = getMinMax(st, arr, num, L, R);
                cout << ans.first << " " << ans.second << endl;
            }
            else {
                cin >> index >> val;
                updateValue(arr, st, num, index, val);
            }

        }
    }
    return 0;
}