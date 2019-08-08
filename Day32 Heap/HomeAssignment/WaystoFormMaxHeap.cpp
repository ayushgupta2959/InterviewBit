#define ull unsigned long long
int p = 1000000007;
int count_helper(int i,int n,vector<int> &count){
    if(i>n) return 0;
    count[i] += (count_helper(2*i,n,count) + count_helper(2*i+1,n,count));
    return count[i];
}
int mod_pow(int a,int b){
    ull result = 1;
    ull x = a;
    while(b){
        if(b&1) result = (result*x)%p;
        x = (x*x)%p;
        b>>=1;
    }
    return result;
}
int inverse_mod(int n){
    return mod_pow(n,p-2);
}
int nCr(int n,int r){
    r = min(r,n-r);
    ull num=1;
    ull denom=1;
    for(int i=1;i<=r;++i){
        num = (num*(n-r+i))%p;
        denom = (denom*i)%p;
    }
    return (num*inverse_mod(denom))%p;
}
void find_count(int n,vector<int> &count){
    count[1] += (count_helper(2,n,count) + count_helper(3,n,count));
}
int Solution::solve(int A) {
    vector<ull> dp(A+1);
    dp[0] = 1;
    dp[1] = 1;
    dp[2] = 1;
    for(int i=3;i<=A;++i){
        vector<int> count(i+1,1);
        find_count(i,count);
        
        //cout<<i<<": ";
        //for(auto x:count) cout<<x<<" ";
        //cout<<"\n";
        dp[i] = nCr(i-1,count[2]);
        dp[i] = (dp[i]*dp[count[2]])%p;
        dp[i] = (dp[i]*dp[count[3]])%p;
        
    }
    return dp[A];
}
