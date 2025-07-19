class Solution {
public: 
    bool startsWith(const std::string& str, const std::string& prefix) {
        return str.rfind(prefix + "/", 0) == 0;
    }
    vector<string> removeSubfolders(vector<string>& folder) {
        sort(folder.begin(),folder.end());
        vector<string> res;
        string root = folder[0];
        res.push_back(root);
        int n = folder.size();
        for(int i = 1; i<n; i++){
            if(startsWith(folder[i],root)) {
                continue;
            }else{
                root = folder[i];
                res.push_back(folder[i]);
            }
        }

        return res;
    }
};