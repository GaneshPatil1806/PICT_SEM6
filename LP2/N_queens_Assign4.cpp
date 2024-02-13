#include <bits/stdc++.h>
using namespace std;

bool valid(vector<vector<int>> &matrix,int i, int j){
    
    int N = matrix.size();

    // check in row
    for(int k=0;k<N;k++){
        if(matrix[i][k]){
            return false;
        }
    }
    
    // check for diagonal
    int r=i;
    for(int k=j;k>=0;k--){
        if(r>=0)
        if(matrix[r][k]){
            return false;
        }
        r--;
    }

    for(int k=j;k>=0;k--){
        if(i<N)
        if(matrix[i][k]){
            return false;
        }
        i++;
    }

    return true;

}

bool n_queens(vector<vector<int>> &matrix,int col_num){
    
    int N = matrix.size();

    // base case
    if(col_num >= N){
        return true;
    }

    for(int i=0;i<N;i++){
        // explore all rows in that col

        if(valid(matrix,i,col_num)){

            matrix[i][col_num] = 1;

            int is_val =  n_queens(matrix,col_num+1);

            if(is_val)
            {
                return true;
            }
            else
            {
                matrix[i][col_num] = 0;
            }
        }
    }

    return false;
}

int main()
{
    int n;
    cout<<"Enter the n for the matrix"<<endl;
    cin>>n;

    vector<vector<int>> matrix(n,vector<int>(n,0));

    if(n_queens(matrix,0)){
        for(auto i:matrix){
            for(auto j:i){
                cout<<j<<' ';
            }
            cout<<endl;
        }
    }
    else{
        cout<<"No solution found!"<<endl;
    }

}