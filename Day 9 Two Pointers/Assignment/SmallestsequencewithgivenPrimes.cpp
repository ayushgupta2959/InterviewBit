/*
vector<int> Solution::solve(int A, int B, int C, int D) {
    set<int> s;
    s.emplace(A);
    s.emplace(B);
    s.emplace(C);
    vector<int> r(D);
    for(int i=0;i<D;++i){
        r[i] = *(s.begin());
        s.erase(s.begin());
        s.emplace(r[i]*A);
        s.emplace(r[i]*B);
        s.emplace(r[i]*C);
    }
    return r;
}
*/
//space optimized
vector<int> Solution::solve(int A, int B, int C, int D) {
    vector<int> r(D+1);
    r[0]=1;
    int i=1;
    int ia=0,ib=0,ic=0;
    int a,b,c;
    while(i<=D){
        a = A*r[ia];
        b = B*r[ib];
        c = C*r[ic];
        if(a<=b && a<=c){
            if(a==r[i-1]) i--;
            r[i]=a;
            ia++;
        }
        else if(b<=a && b<=c){
            if(b==r[i-1]) i--;
            r[i]=b;
            ib++;
        }
        else{
            if(c==r[i-1]) i--;
            r[i]=c;
            ic++;
        }
        i++;
    }
    return {r.begin()+1,r.end()};
}
