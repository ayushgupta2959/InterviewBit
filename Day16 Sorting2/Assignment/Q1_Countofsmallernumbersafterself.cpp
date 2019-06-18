#include<bits/stdc++.h>
using namespace std;
void merge(vector<int> &A,int l,int m,int h,vector<int> &B){
    int i = l;int j = m+1;
    vector<int> t;
    while(i<=m && j<=h){
        if(A[i]>A[j]){
            B[i]+=1;
            B[m+1]-=1;
            t.emplace_back(A[j]);
            j++;
        }
        else{
            t.emplace_back(A[i]);
            i++;
        }
    }
    while(i<=m) t.emplace_back(A[i++]);
    while(j<=h) t.emplace_back(A[j++]);
    for(i=l;i<=h;++i) A[i] = t[i-l];
    return;
}
void mergesort(vector<int> &A,int l,int h,vector<int> &B){
    if(l>=h) return;
    int m = (l+h)/2;
    mergesort(A,l,m,B);
    mergesort(A,m+1,h,B);
    merge(A,l,m,h,B);
    return;
}
vector<int> solve(vector<int> &A){
    int n = A.size();
    vector<int> B(n,0);
    mergesort(A,0,n-1,B);
    for(int i=1;i<n;++i){
        B[i]+=B[i-1];
    }
    return B;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int n;
    cin>>n;
    vector<int> A(n);
    for(int i=0;i<n;++i) cin>>A[i];
    vector<int> B = solve(A);
    for(auto x:B) cout<<x<<" ";
    return 0;
}
