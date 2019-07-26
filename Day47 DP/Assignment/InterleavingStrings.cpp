/* Using recursion
bool solve(string &A,int la,int ha,string &B,int lb,int hb,string &C,int lc,int hc){
    if(lc>hc) return true;
    if(la>ha){
        if(B[hb]==C[hc]) return solve(A,la,ha,B,lb,hb-1,C,lc,hc-1);
        else return false;
    }
    if(lb>hc){
        if(A[ha]==C[hc]) return solve(B,la,ha-1,B,lb,hb-1,C,lc,hc-1);
        else return false;
    }
    bool q1 = false;
    bool q2 = false;
    if(A[ha]==C[hc]) q1 = solve(A,la,ha-1,B,lb,hb,C,lc,hc-1);

    if(B[hb]==C[hc]) q2 = solve(A,la,ha,B,lb,hb-1,C,lc,hc-1);

    return q1||q2;
}
int Solution::isInterleave(string A, string B, string C) {
    int la = A.length();
    int lb = B.length();
    int lc = C.length();
    if(solve(A,0,la-1,B,0,lb-1,C,0,lc-1)){
        return 1;
    }
    else return 0;

}
*/
//dp
