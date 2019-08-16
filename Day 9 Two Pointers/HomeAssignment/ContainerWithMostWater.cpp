int Solution::maxArea(vector<int> &A) {
    int n = A.size();
    int ma = 0;
    int i = 0;
    int j = n-1;
    while(i<j){
        ma = max(ma,min(A[i],A[j])*(j-i));
        if(A[i]<A[j]) i++;
        else j--;
    }
    return ma;
}
