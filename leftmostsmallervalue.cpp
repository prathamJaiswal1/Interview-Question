// Problem statement:
// You are given an array of integers you have to find 
// the leftmost smaller value than the current value 
// for every index.
// Example:
// input:
// arr[]={2,1,3,2,1,3};
// output:
// ans[]={-1,-1,2,1,-1,2};

// Constraints:
// 1<=n<=1e5
// 0<=arr[i]<=1e9;

#include <bits/stdc++.h>
using namespace std;
class segmentTree
{
public:
    vector<int> seg;
    segmentTree(int n)
    {
        seg.resize(4 * n);
    }
    void build(int node, int low, int high, vector<int> &arr)
    {
        if (low == high)
        {
            seg[node] = arr[low];
            return;
        }
        int mid = (low + high) >> 1;
        build(2 * node + 1, low, mid, arr);
        build(2 * node + 2, mid + 1, high, arr);
        seg[node] = min(seg[2 * node + 1], seg[2 * node + 2]);
    }
    int query(int node, int low, int high, int qs, int qe, int val)
    {
        if (low == high)
        {
            if (seg[low] < val)
                return seg[node];
            return INT_MAX;
        }
        int mid = (low + high) >> 1;
        if (qs <= low && high <= qe)
        {
            int mid = (low + high) >> 1;
            if (seg[2 * node + 1] < val)
            {
                return query(2 * node + 1, low, mid, qs, qe, val);
            }
            return query(2 * node + 2, mid + 1, high, qs, qe, val);
        }
        return min(query(2 * node + 1, low, mid, qs, qe, val), query(2 * node + 2, mid + 1, high, qs, qe, val));
    }
};
void solve()
{
    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }
    segmentTree st(n);
    st.build(0, 0, n - 1, v);
    vector<int> ans(n, -1);
    if (v[1] > v[0])
    {
        ans[1] = v[0];
    }
    for (int i = 2; i < n; i++)
    {
        int temp = st.query(0, 0, n - 1, 0, i - 1, v[i]);
        ans[i] = (temp != INT_MAX ? temp : -1);
    }
    for (auto i : ans)
    {
        cout << i << " ";
    }
}
int main()
{
    solve();
    return 0;
}