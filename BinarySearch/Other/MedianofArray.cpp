double Solution::findMedianSortedArrays(const vector<int> &A, const vector<int> &B) {
    int na = A.size();
    int nb = B.size();
    int total = na+nb;
    int median = (na+nb+1)/2;
    int pa,pb;
    int l=1,r=na;
    int la,lb,ra,rb;
    if(na==0 && nb==0) return 0;
    else if(na==0){
        if(total&1) return B[total/2];
        else return (1.0*B[total/2] + 1.0*B[(total/2)-1])/2.0;
    }
    else if(nb==0){
        if(total&1) return A[total/2];
        else return (1.0*A[total/2] + 1.0*A[(total/2)-1])/2.0;
    }
    while(true){
        pa = (l+r)/2;
        if(pa<0) pa=0;
        if(nb<median-pa){
            l = pa+1;
            continue;
        }
        pb = median-pa;
        //cout<<pa<<" "<<pb<<"\n";
        la = pa>0?A[pa-1]:INT_MIN;
        lb = pb>0?B[pb-1]:INT_MIN;
        ra = pa<na?A[pa]:INT_MAX;
        rb = pb<nb?B[pb]:INT_MAX;
        if(la<=rb && lb<=ra){
            if(total&1) return max(la,lb);
            else return ((1.0)*max(la,lb)+(1.0)*min(ra,rb))/2.0;
        }
        else if(la>rb){
            r = pa-1;
        }
        else{
            l = pa+1;
        }
    }
}
