class Solution {
public:
    int n;
    void solve(string& tiles, vector<bool>& used, unordered_set<string>& res, string &curr){
        res.insert(curr);
        for(int i = 0; i<n; i++){
            if(used[i]){
                continue;
            }
            used[i] = true;
            curr.push_back(tiles[i]);

            solve(tiles,used,res,curr);

            used[i] = false;
            curr.pop_back();
        }
    }
    int numTilePossibilities(string tiles) {
        n = tiles.length();
        vector<bool> used(n, false);
        unordered_set<string> res;
        string curr = "";
        solve(tiles,used,res,curr);
        return res.size()-1;
    }
};