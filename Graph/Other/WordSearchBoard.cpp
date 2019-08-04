/*
#define pi pair<int,int>
#define ppi pair<int,pi>
#define f first
#define s second
bool is_valid(vector<string> &A, string &B,int index,int x,int y){
    if(x<0||y<0||x>=A.size()||y>=A[0].length()) return false;
    if(B[index]==A[x][y]) return true;
    else return false;
}
int Solution::exist(vector<string> &A, string B) {
    queue<ppi> q;
    int n = A.size();
    int m = A[0].length();
    int l = B.length();
    //checks
    if(l==0) return 1;
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
        unordered_map<int,int> dp;
        while(q.front().f==index){
            t = q.front();
            q.pop();
            x = t.s.f;
            y = t.s.s;
            if(is_valid(A,B,index+1,x+1,y)){
                if((index+1)==(l-1)) return 1;
                if(dp.count((x+1)*m + y)==0){
                    dp[(x+1)*m + y] = 1;
                    q.push({index+1,{x+1,y}});
                }
            }
            if(is_valid(A,B,index+1,x-1,y)){
                if((index+1)==(l-1)) return 1;
                if(dp.count((x-1)*m + y)==0){
                    dp[(x-1)*m + y]=1;
                    q.push({index+1,{x-1,y}});
                }
            }
            if(is_valid(A,B,index+1,x,y+1)){
                if((index+1)==(l-1)) return 1;
                if(dp.count((x)*m + y+1)==0){
                    dp[(x)*m + y+1]=1;                    
                    q.push({index+1,{x,y+1}});
                }        
            }
            if(is_valid(A,B,index+1,x,y-1)){
                if((index+1)==(l-1)) return 1;
                if(dp.count((x)*m + y-1)==0){
                    dp[(x)*m + y-1]=1; 
                    q.push({index+1,{x,y-1}});
                }
            }
        }
        index++;
    }
    return 0;
}
*/
bool is_valid(vector<string> &A, string &B,int index,int x,int y,vector<vector<vector<int>>> &memo){
    if(x<0||y<0||x>=A.size()||y>=A[0].length()) return false;
    if(memo[x][y][index]==0) return false;
    if(B[index]==A[x][y]) return true;
    else return false;
}
int dfs(vector<string> &A, string &B,int x,int y,int i,vector<vector<vector<int>>> &memo){
    if(i+1==B.length()) return 1;
    if(memo[x][y][i]!=-1) return memo[x][y][i];
    memo[x][y][i] = 1;
    if(is_valid(A,B,i+1,x+1,y,memo) && dfs(A,B,x+1,y,i+1,memo)) return 1;
    if(is_valid(A,B,i+1,x-1,y,memo) && dfs(A,B,x-1,y,i+1,memo)) return 1;
    if(is_valid(A,B,i+1,x,y+1,memo) && dfs(A,B,x,y+1,i+1,memo)) return 1;
    if(is_valid(A,B,i+1,x,y-1,memo) && dfs(A,B,x,y-1,i+1,memo)) return 1;
    memo[x][y][i] = 0;
    return 0;
}
int Solution::exist(vector<string> &A, string B) {
    int n = A.size();
    int m = A[0].length();
    int l = B.length();
    vector<vector<vector<int>>> memo(n,vector<vector<int>>(m,vector<int>(l,-1)));
    //checks
    if(l==0) return 0;
    for(int i=0;i<n;++i){
        for(int j=0;j<m;++j){
            if(A[i][j]==B[0]){
                if(dfs(A,B,i,j,0,memo)==1) return 1;
            }
        }
    }
    return 0;
}
