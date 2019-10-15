/*
segment tree?
Given an array A of size N and Q queries. Perform following queries:
1 V 0 append V in the back of array.
2 X V set A[X] = V.
3 X 0 delete A[X]. Note: All element at back of X move forward to occupy void.
4 X Y find sum in range [X, Y].
Input Format:
    First argument contains an integer array A
    Second argument contains a Q x 3 Matrix B
Output Format:
    return an integer array containing answer to all 4 query in chronological order.
Constraints:
    1 <= N,Q <= 100000
    1 <= A[i],V <=10000
    1 <= X,Y <= N' Where, N' is current size of array.
For Example:
Input 1:
    A = [1, 2, 5, 3, 4] B = [[4, 2, 4], [3, 3, 0], [1, 6, 0], [4, 3, 5]]
Output 1:
    [10, 13]
Explanation:
    First Query find sum(A[2],A[3],A[4])
    Second Query make A = [1, 2, 3, 4]
    Third Query make A = [1, 2, 3, 4, 6]
    Fourth Query find sum(A[3],A[4],A[5])
*/

vector<int> stv; // segment tree of values
vector<int> stc; // segment tree storing the count of elements

int lc(int p){return (p<<1);}

int rc(int p){return (p<<1)|1;}

void build(int p,int tl,int tr,vector<int> A){
    if(tl>A.size()) return;
    if(tl==tr){
        stv[p] = A[tl-1];
        stc[p] = 1;
        return;
    }
    int tm = (tl+tr)/2;
    build(lc(p),tl,tm,A);
    if(tm < A.size()) build(rc(p),tm+1,tr,A); //can remove this if condition but its ok
    stv[p] = stv[lc(p)] + stv[rc(p)];
    stc[p] = stc[lc(p)] + stc[rc(p)];
}
int find_index(int p,int tl,int tr,int k){
    if(k>stc[p]){
        cout<<"less number of elements than expected";
        return -1;
    }
    if(tl==tr){
        return tl;
    }
    int tm = (tl+tr)/2;
    if(stc[lc(p)]<k) return find_index(rc(p),tm+1,tr,k-stc[lc(p)]);
    else return find_index(lc(p),tl,tm,k);
}
void update_index_val(int p,int tl,int tr,int &i,int &val){
    if(tl==tr){
        stv[p] = val;
        stc[p]=1;
        return;
    }
    int tm = (tl+tr)/2;
    if(i<=tm){
        update_index_val(lc(p),tl,tm,i,val);
    }
    else{
        update_index_val(rc(p),tm+1,tr,i,val);
    }
    stv[p] = stv[lc(p)] + stv[rc(p)];
    stc[p] = stc[lc(p)] + stc[rc(p)];
}
void delete_index(int p,int tl,int tr,int &i){
    if(tl==tr){
        stv[p]=0;
        stc[p]=0;
        return;
    }
    int tm = (tl+tr)/2;
    if(i<=tm){
        delete_index(lc(p),tl,tm,i);
    }
    else{
        delete_index(rc(p),tm+1,tr,i);
    }
    stv[p] = stv[lc(p)] + stv[rc(p)];
    stc[p] = stc[lc(p)] + stc[rc(p)];
}
int sum_query(int p,int tl,int tr,int ql,int qr){
    if(qr<tl || tr<ql) return 0;
    if(tl>=ql && tr<=qr) return stv[p];
    int tm = (tl+tr)/2;
    int left_result=0,right_result=0;
    if(tm>=ql) left_result = sum_query(lc(p),tl,tm,ql,qr);
    if(tm<qr) right_result = sum_query(rc(p),tm+1,tr,ql,qr);
    return left_result + right_result;
}
vector<int> Solution::solve(vector<int> &A, vector<vector<int> > &B) {
    int n = A.size();
    stv.clear();
    stc.clear();
    stv.resize(1e6,0);
    stc.resize(1e6,0);
    int right_index = 2e5+100; // taken it as more than max possible value even after queries
    build(1,1,right_index,A);
    vector<int> result;
    
    
    for(auto& q:B){
        if(q[0]==1){
            int index = find_index(1,1,right_index,stc[1]) + 1;
            //cout<<index<<"\n";
            update_index_val(1,1,right_index,index,q[1]);
            
        }
        else if(q[0]==2){
            int index = find_index(1,1,right_index,q[1]);
            update_index_val(1,1,right_index,index,q[2]);
        }
        else if(q[0]==3){
            int index = find_index(1,1,right_index,q[1]);
            delete_index(1,1,right_index,index);
        }
        else{
            int li = find_index(1,1,right_index,q[1]);
            int ri = find_index(1,1,right_index,q[2]);
            //cout<<li<<" "<<ri<<"\n";
            result.emplace_back(sum_query(1,1,right_index,li,ri));
        }
    }

    return result;
}
