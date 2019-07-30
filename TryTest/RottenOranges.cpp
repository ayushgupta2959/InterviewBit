#define ppi pair<int,pair<int,int>>
#define pi pair<int,int>
bool is_valid(vector<vector<int> > &A,int x,int y){
    if(x<0||y<0||x>=A.size()||y>=A[0].size()) return false;
    if(A[x][y]==0||A[x][y]==-1) return false;
    else return true;
}
int Solution::solve(vector<vector<int> > &A) {
    queue<ppi> q;
    int n = A.size();
    int m = A[0].size();
    pi temp;
    for(int i=0;i<n;++i){
        for(int j=0;j<m;++j){
            if(A[i][j]==2){
                A[i][j]=-1;
                temp = {i,j};
                q.push({0,temp});
            }
        }
    }
    
    
    int x,y;
    int t = 0;
    
    while(!q.empty()){
        while(q.front().first==t){
            temp = q.front().second;
            x = temp.first;
            y = temp.second;
            q.pop();
            if(is_valid(A,x+1,y)){
                A[x+1][y]=-1;
                q.push({t+1,{x+1,y}});
            }
            if(is_valid(A,x-1,y)){
                A[x-1][y]=-1;
                q.push({t+1,{x-1,y}});
            }
            if(is_valid(A,x,y+1)){
                A[x][y+1]=-1;
                q.push({t+1,{x,y+1}});
            }
            if(is_valid(A,x,y-1)){
                A[x][y-1]=-1;
                q.push({t+1,{x,y-1}});
            }
        }
        if(!q.empty()) t++;
    }
    /*
    for(int i=0;i<n;++i){
        for(int j=0;j<m;++j){
            cout<<A[i][j]<<" ";
        }
        cout<<"\n";
    }
    while(!q.empty()){
        cout<<q.front().first<<" "<<q.front().second.first<<" "<<q.front().second.second<<"\n";
        q.pop();
        
    }
    */
    for(int i=0;i<n;++i){
        for(int j=0;j<m;++j){
            if(A[i][j]==1){
                return -1;
            }
        }
    }
    return t;
}
