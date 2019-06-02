#include<bits/stdc++.h>
using namespace std;
vector<int> solve(vector<int> &A) {
    int n=A.size();
    int N = 1000001;
    int x;
    vector<int> spf(N);
    for(int i=1;i<N;++i) spf[i] = i;
    for(int i=2;i<N;i+=2) spf[i] = 2;
    for(int i=3;i*i<N;i+=2){ // no need for sqrt(N) to N since after sqrt(N) only numbers which are
                             // prime would be left and spf[prime] = prime
        if(spf[i]==i){
            x = 2*i;
            for(int j=i*i;j<N;j+=x){ // adding 2*i because i is odd so i+i would be even but even has spf = 2 so add 2*i
               if(spf[j]==j) spf[j] = i;
            }
        }
    }
    for(int i=0;i<80;++i) cout<<i<<"-"<<spf[i]<<"\n";
    //cout<<spf[75]<<"\n";
    int c;
    int result;
    int cspf;
    for(int i=0;i<n;++i){
        result =1;
        x = A[i];
        cspf = spf[x];
        c = 0;
        while(x!=1){
            x/=cspf;
            c++;
            if(cspf != spf[x]){
                result = result*(c+1);
                c = 0;
                cspf = spf[x];
            }
        }
        A[i] = result;
    }
    return A;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    vector<int> A = {75};
    vector<int> r = solve(A);
    for(auto x:r){
        cout<<x<<" ";
    }
    return 0;
}
