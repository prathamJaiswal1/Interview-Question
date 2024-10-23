// Problem statement:
// You are given an array of integers you have to find // the leftmost smaller value than the current value // for every index.
// Example:
// input:// arr[]={2,1,3,2,1,3};
// output:// ans[]={-1,-1,2,1,-1,2};

// Constraints:
// 1<=n<=1e5
// 0<=arr[i]<=1e9;
#include <bits/stdc++.h>
using namespace std;
void solve(){
    int n;cin>>n;
    vector<int>v(n),ans;
    for(int i=0;i<n;i++){
        cin>>v[i];
    }
    set<int>st;
    st.insert(v[0]);
    cout<<-1<<" ";
    for(int i=1;i<n;i++){
        auto it=st.lower_bound(v[i]);
        if(it==st.begin()){
            cout<<-1<<" ";
             st.insert(v[i]);
        }else{
            it--;
            cout<<*it<<" ";
        }
    }
    cout<<endl;
}
int main(){
    int t;cin>>t;
    while(t--){
       solve();
    }
    return 0;
}
