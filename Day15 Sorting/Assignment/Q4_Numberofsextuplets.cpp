int p = 1000000007;
int first_occurence(vector<int> &X,int ele){
    int l = 0;
    int h = X.size()-1;
    int m;
    int index=INT_MAX;
    while(l<=h){
        m = (l+h)/2;
        if(X[m]==ele){
            index = min(index,m);
            h = m-1;
        }
        else if(X[m]<ele){
            l = m+1;
        }
        else{
            h = m-1;
        }
    }
    return index;
}
int last_occurence(vector<int> &X,int ele){
    int l = 0;
    int h = X.size()-1;
    int m;
    int index=INT_MIN;
    while(l<=h){
        m = (l+h)/2;
        if(X[m]==ele){
            index = max(index,m);
            l = m+1;
        }
        else if(X[m]<ele){
            l = m+1;
        }
        else{
            h = m-1;
        }
    }
    return index;
}
int Solution::solve(vector<int> &A) {
    //equation can be simplified to (a*b +c) = d*(e+f) condition is d != 0
    // logic is to generate all ans for lhs in n^3 time by selecting all combinations in A
    // similarly  generate all ans for rhs in n^3 time by selecting all combinations in A
    // sort lhs array and rhs array
    // iterate lhs array and search for first and last occurence of each element of lhs array in rhs array.
    // this can be done in O(n^3 log2(n^3))
    // ans += last-first +1

    vector<int> lhs;
    vector<int> rhs;
    int n = A.size();
    for(int i=0;i<n;++i){
        for(int j=0;j<n;++j){
            for(int k=0;k<n;++k){
                lhs.emplace_back(A[i]*A[j]+A[k]);
                if(A[i]) rhs.emplace_back(A[i]*(A[j]+A[k]));
            }
        }
    }
    sort(lhs.begin(),lhs.end());
    sort(rhs.begin(),rhs.end());
    int fo,lo,result=0;
    int nlhs = lhs.size();
    for(auto x:lhs){
        fo = first_occurence(rhs,x);
        lo = last_occurence(rhs,x);
        if(fo<nlhs) result = (result + (lo-fo)+1)%p;
    }
    return result;
}

