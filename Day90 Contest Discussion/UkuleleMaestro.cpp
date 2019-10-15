/*
Ukulele Maestro
Rishik has a very special Ukulele with A frets. He can use atmost 4 fingers to play a chord. Find total number of different chords Rishik can play mod 1000000007. Two chords are different if one of the fret that is pressed in one of the chord is not pressed in other chord. Note: 1 finger can press atmost 1 fret at a time. 
Input Format:
    First argument contains single integer A.
Output Format:
    Return a single integer containing total number of chords mod 1000000007.
Constraints:
    1 <= A <= 10^9  
For Example:
Input 1:
    A = 2
Output 1:
    4
Explanation 1:
    Chords are = [{}, {1}, {1,2}, {2}]
Input 2:
    A = 6
Output 2:
    57
*/
#define ll long long
int mod = 1e9+7;
int mod_pow(ll a,ll b,ll p){
    ll result = 1;
    while(b){
        if(b&1) result = (result*a)%p;
        a = (a*a)%p;
        b>>=1;
    }
    return result;
}
int nCr(ll n,ll r){
    r = min(r,n-r);
    ll num=1,denom=1;
    for(int i=0;i<r;++i){
        num = (num*(n-i))%mod;
        denom = (denom*(i+1))%mod;
    }
    ll result = (num*mod_pow(denom,mod-2,mod))%mod;
    return result;
}
int Solution::solve(int A) {
    ll result=1;
    for(int c=1;c<=4 && c<=A ;c++){
        result += nCr(A,c);
        result %= mod;
    }
    return result;
}
