class Solution {


            
            
private:
void Find(vector<string>& ans, string& path, int n,int opening,int closing) {
        // base case
        if (opening ==0 && closing==0) {
            ans.push_back(path);
            return;
        }

        //include "("
        if(opening>0){
            path.push_back('(');
            Find(ans,path,n,opening-1,closing);
            path.pop_back();
        }
        //include ")"
        if(closing>opening){
            path.push_back(')');
            Find(ans,path,n,opening,closing-1);
            path.pop_back();
        }
}
    
    

public:
    vector<string> generateParenthesis(int n) {
        string path="";
        vector<string> ans;
        int opening=n;
        int closing=n;
        
        Find(ans, path, n,opening,closing);
        return ans;
    }
};
