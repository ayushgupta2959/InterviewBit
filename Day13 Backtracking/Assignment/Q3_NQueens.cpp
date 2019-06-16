#include<bits/stdc++.h>
using namespace std;
bool isPossible(vector<string> &board,int row,int col,int A){
    // check column
    for(int i = 0;i<=row;++i){
        if(board[i][col]=='Q') return false;
    }

    //check left diagonal
    int i = row-1;
    int j = col-1;
    while(i>=0 && j>=0){
        if(board[i][j]=='Q') return false;
        i--;
        j--;
    }

    //check right diagonal
    i = row-1;
    j = col+1;
    while(i>=0 && j<A){
        if(board[i][j]=='Q') return false;
        i--;
        j++;
    }

    return true;
}
void solve(vector<string> &board,int row,int A,vector<vector<string>> &result){
    if(row==A){
        /*string s = "";
        for(int i=0;i<(A-1);++i){
            s += (board[i]+",\n");
        }
        s+=board[A-1];
        */
        result.emplace_back(board);
        return;
    }
    for(int j=0;j<A;++j){

        if(isPossible(board,row,j,A)){
            board[row][j] = 'Q';
            solve(board,row+1,A,result);
            board[row][j] = '.';
        }
    }
    return;
}
vector<vector<string>> solveNQueens(int A) {
    vector<vector<string>> result;
    vector<string> board(A);
    string s = "";
    for(int i=0;i<A;++i) s+='.';
    for(int i=0;i<A;++i) board[i] = s;
    solve(board,0,A,result);
    return result;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int a;
    cin>>a;
    vector<vector<string>> result = solveNQueens(a);
    for(auto x:result){
        for(auto y:x){
            cout<<y<<"\n";
        }
        cout<<"\n\n";
    }
    return 0;
}
