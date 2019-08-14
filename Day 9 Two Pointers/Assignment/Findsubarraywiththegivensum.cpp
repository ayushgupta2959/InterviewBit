/*
vector<int> Solution::solve(vector<int> &A, int B) {
    int n = A.size();
    vector<int> t = A;
    for(int i=1;i<n;++i){
        A[i] += A[i-1];
    }
    int i = 0;
    int j = 0;
    int ss;
    while(i<=j && j<n){
        ss = A[j];
        if(i>0) ss-=A[i-1];
        if(ss == B){
            return {t.begin()+i,t.begin()+j+1};
        }
        else if(ss>B){
            i++;
        }
        else{
            j++;
        }
    }
    return {-1};
}
*/
//space optimized
vector<int> Solution::solve(vector<int> &A, int B) {
    int n = A.size();
    int ss = A[0];
    int j=0;
    int i=0;
    while(j<n){
        if(ss<B){
            j++;
            if(j<n) ss+= A[j];
        }
        else if(ss>B){
            i++;
            ss-=A[i-1];
        }
        else{
            return {A.begin()+i,A.begin()+j+1};
        }
    }
    return {-1};
}
