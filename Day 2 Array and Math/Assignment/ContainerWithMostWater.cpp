int Solution::maxArea(vector<int> &A) {
    int n = A.size();
    int ma = 0;
    int i = 0;
    int j = n-1;
    while(i<j){
        ma = max(ma,(j-i)*(min(A[i],A[j])));
        if(A[i]<A[j]) i++;
        else j--;
    }
    return ma;
}
