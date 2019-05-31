#include<bits/stdc++.h>
using namespace std;
#define P 1000000007
int MOD(int x){
    return (x%P + P)%P;
}
vector<int> solve(vector<vector<int> > &A, vector<int> &B, vector<int> &C, vector<int> &D, vector<int> &E) {
    int n = A.size();
    int m = A[0].size();
    int q = B.size();
    vector<int> result;
    for(int i=0;i<n;++i){
        for(int j=0;j<m;++j){
            if((i-1)>=0) A[i][j] = MOD(A[i][j] + A[i-1][j]);
            if((j-1)>=0) A[i][j] = MOD(A[i][j] + A[i][j-1]);
            if((i-1)>=0&&(j-1)>=0) A[i][j] = MOD(A[i][j] - A[i-1][j-1]);
        }
    }
    int sum;
    for(int i=0;i<q;++i){
        sum = 0;
        sum = MOD(sum + A[D[i]-1][E[i]-1]);
        if((B[i]-2)>=0) sum = MOD(sum - A[B[i]-2][E[i]-1]);
        if((C[i]-2)>=0) sum = MOD(sum - A[D[i]-1][C[i]-2]);
        if((B[i]-2)>=0 && (C[i]-2)>=0) sum = MOD(sum + A[B[i]-2][C[i]-2]);
        result.emplace_back(sum);
    }
    return result;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int r,c,q;
    cin>>r>>c>>q;
    vector<vector<int>> A(r,vector<int>(c));
    vector<int> B(q);
    vector<int> C(q);
    vector<int> D(q);
    vector<int> E(q);
    for(int i=0;i<r;++i)
        for(int j=0;j<c;++j)
            cin>>A[i][j];
    for(int i=0;i<q;++i) cin>>B[i];
    for(int i=0;i<q;++i) cin>>C[i];
    for(int i=0;i<q;++i) cin>>D[i];
    for(int i=0;i<q;++i) cin>>E[i];
    vector<int> result = solve(A,B,C,D,E);
    for(auto x:result) cout<<x<<" ";
    return 0;
}
