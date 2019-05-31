#include<bits/stdc++.h>
using namespace std;
vector<int> subUnsort(vector<int> &A) {
    int n = A.size();
    int max_so_far = A[0];
    int e;
    int s = 0;
    int i=1;
    int t;
    while(i<n){
        if(A[i]>=max_so_far) max_so_far = A[i++];
        else{
            int min_so_far = A[i];
            t = i+1;
            while(t<n){
                if(A[t]<min_so_far){
                  i = t; min_so_far = A[t];
                }
                t++;
            }
            while(s<i && A[s]<=A[i]){
                s++;
            }
            break;
        }
    }
    if(i == n) return {-1};
    e = i++;
    while(i<n){
        if(A[i]>=max_so_far) max_so_far = A[i];
        else{
            e = i;
        }
        i++;
    }
    return {s,e};
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int x;
    vector<int> A;
    while(cin>>x) A.emplace_back(x);
    vector<int> result = subUnsort(A);
    for(auto x:result) cout<<x<<" ";
    return 0;
}
