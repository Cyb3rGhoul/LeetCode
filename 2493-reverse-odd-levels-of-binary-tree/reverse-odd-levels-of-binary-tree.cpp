class Solution {
public:
    TreeNode* reverseOddLevels(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);

        int level = 0;

        while(!q.empty()){
            int n = q.size();
            vector<TreeNode*> levelNode;
            
            while(n--){
                TreeNode* temp=q.front();
                q.pop();
                levelNode.push_back(temp);

                if(temp->left){
                    q.push(temp->left);
                }
                if(temp->right){
                    q.push(temp->right);
                } 
            }
            if(level%2==1){
                int i = 0;
                int j = levelNode.size()-1;
                while(i<j){
                    int temp = levelNode[i]->val;
                    levelNode[i]->val=levelNode[j]->val;
                    levelNode[j]->val=temp;
                    i++;
                    j--;
                }
            }
            level++;
        }
        return root;
    }
};