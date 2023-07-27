class Solution {
private:
void solve(string &digits,int n,vector<string>&ans,string &output,int index,vector<string>&mapping){
    //base case
    if(index>=n){
        ans.push_back(output);
        return ;
    }
    //recursive call
    int digit=digits[index]-'0';
    string value=mapping[digit];
    for(int i=0;i<value.length();i++){
        char ch=value[i];
        output.push_back(ch);
        solve(digits,n,ans,output,index+1,mapping);
        //backtracking
        output.pop_back();
    }
}

    
    


public:
    vector<string> letterCombinations(string digits) {
        int index=0;
        int n=digits.length();
        vector<string>ans;
        string output="";
        vector<string>empty;
        vector<string>mapping(10);
        if(digits.size()==0){
            return empty;
        }
        mapping [2]="abc";
        mapping [3]="def";
        mapping [4]="ghi";
        mapping [5]="jkl";
        mapping [6]="mno";
        mapping[7]="pqrs";
        mapping [8]="tuv";
        mapping[9]="wxyz";
        solve(digits,n,ans,output,index,mapping);
        return ans;

    }
};
