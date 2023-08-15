#include <bits/stdc++.h>

using namespace std;

int arr[100001];
int rank1[100001];


// } Driver Code Ends
//User function Template for C++

class Solution
{
public:
    //Function to merge two nodes a and b.
    class Solution
    {
    public:
        //Function to merge two nodes a and b.
        int find(int a, int par[], int rank[])
        {
            if (par[a] == a) return a;

            par[a] = find(par[a], par, rank);
            return par[a];
        }
        void unionNodes( int a, int b, int par[], int rank1[], int n)
        {
            //code here
            if (find(a, par, rank1) == find(b, par, rank1)) return;
            int par_a = find(a, par, rank1), par_b = find(b, par, rank1);
            if (rank1[a] < rank1[b]) par[par_a] = par_b ;
            else if (rank1[b] < rank1[a]) par[par_b] = par_a;
            else {
                par[par_b] = par_a;
                rank1[a]++;
            }
        }

        //Function to determine number of connected components.
        int findNumberOfConnectedComponents( int n, int arr[], int rank1[])
        {
            //code here
            unordered_set<int> st;
            for (int i = 1; i <= n; i++)
            {
                st.insert(find(arr[i], arr, rank1));
                // cout<<arr[i]<<" ";
            }
            // cout<<endl;
            int ans = st.size();
            return ans;
        }
    };
}

//{ Driver Code Starts.



int main() {
    int t;
    cin >> t;

    while (t--) {

        //taking number of nodes
        int n;
        cin >> n;

        //initializing parent array and
        //rank array
        for (int i = 1; i <= n; i++) {
            arr[i] = i;
            rank1[i] = 1;
        }

        //taking number of queries
        int q;
        cin >> q;
        Solution obj;
        while (q--) {
            int a, b;
            cin >> a >> b;

            //calling unionNodes() function
            obj.unionNodes(a, b, arr, rank1, n);
        }

        //calling function findNumberofConnectedComponents()
        cout << obj.findNumberOfConnectedComponents(n, arr, rank1) << endl;
    }
    return 0;
}