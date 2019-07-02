
int merge(vector<int> &A,int l,int m,int h){
    vector<int> t;
    int i = l;
    int j = m+1;
    int count = 0;
    while(i<=m && j<=h){
        if(A[i]>(2*A[j])){ count += (m-i+1); j++;}
        else i++;

    }
    i = l;
    j = m+1;
    while(i<=m && j<=h){
        if(A[i]<A[j]){t.emplace_back(A[i]); i++;}
        else{t.emplace_back(A[j]); j++;}
    }
    while(i<=m) {t.emplace_back(A[i]); i++;}
    while(j<=h) {t.emplace_back(A[j]); j++;}
    for(i=l;i<=h;++i){
        A[i] = t[i-l];
    }
    return count;
}
int mergesort(vector<int> &A,int l,int h){
    if(l>=h) return 0;
    int m = (l+h)/2;
    int lcount = mergesort(A,l,m);
    int rcount = mergesort(A,m+1,h);
    int currcount = merge(A,l,m,h);
    //cout<<l<<" "<<m<<" "<<h<<" "<<lcount<<" "<<rcount<<" "<<currcount<<"\n";
    //for(auto x:A) cout<<x<<" ";
    //cout<<"\n";
    return (lcount + rcount + currcount);
}
int Solution::solve(vector<int> &A) {
    int x = mergesort(A,0,A.size()-1);
    //for(auto x:A) cout<<x<<" ";
    //cout<<"\n";
    return x;

}
