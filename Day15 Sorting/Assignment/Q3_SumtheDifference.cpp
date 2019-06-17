typedef long long ll;
int p = 1000000007;
void calc_powers(vector<ll> &two_powers,int n){
    ll two = 2;
    two_powers[0] = 1;
    for(int i=1;i<n;++i){
        two_powers[i] = two;
        two = (two*2)%p;
    }
}

int Solution::solve(vector<int> &A) {
    // logic is instead of forming all subsets find how many times would a pair difference contribute to the sum
    // so if we sort the array then
    // x1 <= x2 <= x3 <= x4 (let)
    // then (x2-x1) would contribute 2^(0) times ; (x3-x2) would contribute 2^(0) times ; (x3-x2) would contribute 2^(1) times
    // so in general any two pair difference would contribute 2^(no of elements between them -1) times
    sort(A.begin(),A.end());
    int n = A.size();
    vector<ll> two_powers(n);
    calc_powers(two_powers,n);
    //for(auto x:two_powers) cout<<x<<" ";
    //cout<<"\n";
    long long result = 0;
    for(int i=0;i<n;++i){
        for(int j=i+1;j<n;++j){
            //cout<<A[j]<<" "<<A[i]<<" "<<two_powers[j-i-1]<<"\n";
            result = (result + (((A[j]-A[i])%p)*two_powers[j-i-1])%p)%p;
        }
    }
    return result;
}

