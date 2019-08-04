#define pi pair<int,int>
#define ppi pair<int,pi>
#define f first
#define s second
bool is_valid(vector<string> &A, string &B,int index,int x,int y){
    if(x<0||y<0||x>=A.size()||y>=A[0].length()) return false;
    if(B[index+1]==A[x][y]) return true;
    else return false;
}
int Solution::exist(vector<string> &A, string B) {
    queue<ppi> q;
    int n = A.size();
    int m = A[0].length();
    int l = B.length();
    //checks
    if(l==0) return 0;
    for(int i=0;i<n;++i){
        for(int j=0;j<m;++j){
            if(A[i][j]==B[0]) q.push({0,{i,j}});
        }
    }
    if(l==1){
        if(q.empty()) return 0;
        else return 1;
    }
    int index=0;
    ppi t;
    int x,y;
    while(!q.empty()){
        unordered_map<int,int> m;
        while(q.front().f==index){
            t = q.front();
            q.pop();
            x = t.s.f;
            y = t.s.s;
            if(is_valid(A,B,index,x+1,y)){
                if(index+1==l-1) return 1;
                if(m.count((x+1)*n + y)==0){
                    m[(x+1)*n + y] = 1;
                    q.push({index+1,{x+1,y}});
                }
            }
            if(is_valid(A,B,index,x-1,y)){
                if(index+1==l-1) return 1;
                if(m.count((x-1)*n + y)==0){
                    m[(x-1)*n + y]=1;
                    q.push({index+1,{x-1,y}});
                }
            }
            if(is_valid(A,B,index,x,y+1)){
                if(index+1==l-1) return 1;
                if(m.count((x)*n + y+1)==0){
                    m[(x)*n + y+1]=1;                    
                    q.push({index+1,{x,y+1}});
                }        
            }
            if(is_valid(A,B,index,x,y-1)){
                if(index+1==l-1) return 1;
                if(m.count((x)*n + y-1)==0){
                    m[(x)*n + y-1]=1; 
                    q.push({index+1,{x,y-1}});
                }
            }
        }
        index++;
    }
    return 0;
}
