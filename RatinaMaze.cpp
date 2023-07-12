class Solution{
    public:
    
    bool isSafe(int i,int j,int row,int col,vector<vector<int>>&arr,vector<vector<bool> >&visited){
    if((i>=0 && i<row) && (j>= 0 && j<col) && (arr[i][j]==1) &&(visited[i][j]==false))
        return true;
    else 
        return false;
}


void solvemaze(vector<vector<int>>&arr,int row,int col,int i,int j,vector<vector<bool> >&visited,vector<string>&path,string output){
    //base case
    if(i==row-1 && j== col-1){
        path.push_back(output);
        return;
    }
    //down i+1,j
    if(isSafe(i+1,j,row,col,arr,visited)){
        visited[i+1][j]=true;
        solvemaze(arr,row,col,i+1,j,visited,path,output+'D');
        //backtrack
        visited[i+1][j]=false;
    }
         
    //left i,j-1
    if(isSafe(i,j-1,row,col,arr,visited)){
        visited[i][j-1]=true;
        solvemaze(arr,row,col,i,j-1,visited,path,output+'L');
        //backtrack
        visited[i][j-1]=false;
    }
    //right i,j+1
    if(isSafe(i,j+1,row,col,arr,visited)){
        visited[i][j+1]=true;
        solvemaze(arr,row,col,i,j+1,visited,path,output+'R');
        //backtrack
        visited[i][j+1]=false;
    }
    //up i-1,j
    if(isSafe(i-1,j,row,col,arr,visited)){
        visited[i-1][j]=true;
        solvemaze(arr,row,col,i-1,j,visited,path,output+'U');
        //backtrack
        visited[i-1][j]=false;
    }
}
    
    
    
    
    vector<string> findPath(vector<vector<int>> &m, int n) {
        // Your code goes here
        int row=n;
        int col=n;
        vector<string>path;
        string output="";
        vector<vector<bool>>visited(row,vector<bool>(col,false));
        visited[0][0]=true;
        if (m[0][0]==0){
            return path;
        }
        solvemaze(m,row,col,0,0,visited,path,output);
        return path;
    }
};
