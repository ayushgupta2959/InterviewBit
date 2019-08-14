int P = 1000000007;
typedef long long ll;
int Solution::solve(vector<int> &A, int B) {
    int n = A.size();
    int i = 0;
    int j = n-1;
    int l;
    ll result = 0;
    while(i<=j){
        if(((ll)A[i]*(ll)A[j]) < B){
            l = (j-i);
            result = (result + (2*l)%P +1)%P;
            i++;
        }
        else{
            j--;
        }
    }
    return result;
}
