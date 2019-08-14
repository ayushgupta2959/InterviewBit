int first_occurence(int s,int e,int val,vector<int> &A){
    int x = upper_bound(A.begin()+s,A.begin()+e,val-1) - A.begin();
    return x;
}
int last_occurence(int s,int e,int val,vector<int> &A){
    int x = upper_bound(A.begin()+s,A.begin()+e,val)-A.begin();
    return x-1;
}
int Solution::solve(vector<int> &A, int B) {
    int n = A.size();
    int c =0;
    /*
    //O(n*log(n))
    for(int i=0;i<n;++i){
        if(binary_search(A.begin()+i+1,A.end(),B-A[i])){
            //to handle cases when elements are not distint
            int f = first_occurence(i+1,n,B-A[i],A);
            int l = last_occurence(i+1,n,B-A[i],A);
            //cout<<B-A[i]<<" "<<f<<" "<<l<<"\n";
            c+=(l-f+1);
        }
    }
    */
    //O(n)
    int i=0;
    int j = n-1;
    int t;
    while(i<j){
        t = A[i]+A[j];
        if(t==B) {//since all elements are distinct
            i++;
            j--;
            c++;
        }
        else if(t>B){
            j--;
        }
        else{
            i++;
        }
    }
    return c;
}
