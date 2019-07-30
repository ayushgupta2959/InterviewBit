#define pi pair<int,int>
#define ppi pair<int,pi>
bool is_valid(vector<vector<int> > &A,int x,int y){
    if(x<0||y<0||x>=A.size()||y>=A[0].size()) return false;
    if(A[x][y]==-1) return true;
    else return false;
}
vector<vector<int> > Solution::solve(vector<vector<int> > &A) {
    queue<ppi> q;
    pi temp;
    int x,y;
    int n = A.size();
    int m = A[0].size();
    for(int i=0;i<n;++i){
        for(int j=0;j<m;++j){
            if(A[i][j]==1){
                A[i][j]=0;
                q.push({0,{i,j}});
            }
            else A[i][j]=-1;
        }
    }
    int d = 0;
    while(!q.empty()){
        while(q.front().first==d){
            temp = q.front().second;
            q.pop();
            x = temp.first;
            y = temp.second;
            if(is_valid(A,x+1,y)){
                A[x+1][y]=d+1;
                q.push({d+1,{x+1,y}});
            }
            if(is_valid(A,x-1,y)){
                A[x-1][y]=d+1;
                q.push({d+1,{x-1,y}});
            }
            if(is_valid(A,x,y+1)){
                A[x][y+1]=d+1;
                q.push({d+1,{x,y+1}});
            }
            if(is_valid(A,x,y-1)){
                A[x][y-1]=d+1;
                q.push({d+1,{x,y-1}});
            }
        }
        d++;
    }
    return A;
}