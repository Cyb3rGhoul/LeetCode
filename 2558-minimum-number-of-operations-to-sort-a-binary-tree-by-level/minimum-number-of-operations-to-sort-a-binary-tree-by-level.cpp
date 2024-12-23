
class Solution {
public:
    int countMinSwaps(vector<int> ans){
        int n = ans.size();
        int res = 0;
        vector<int> sortedVec(begin(ans),end(ans));
        sort(sortedVec.begin(),sortedVec.end());

        unordered_map<int,int> mp;

        for(int i = 0; i<n; i++){
            mp[ans[i]] = i;
        }

        for(int i =0 ; i<n; i++){
            if(ans[i]==sortedVec[i]) continue;
            int curr = mp[sortedVec[i]];
            mp[ans[i]] = curr;
            mp[ans[curr]] = i;
            swap(ans[curr], ans[i]);
            res++;
        }
        return res;
    }
    int minimumOperations(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
        int result = 0;

        while(!q.empty()){
            int n = q.size();
            vector<int> ans;
            while(n--){
                TreeNode* temp = q.front();
                q.pop();
                ans.push_back(temp->val);
                if(temp->left) q.push(temp->left);
                if(temp->right) q.push(temp->right);
            }
            result += countMinSwaps(ans);
        }

        return result;

    }
};