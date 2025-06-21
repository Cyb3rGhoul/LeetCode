class Solution {
public:

    bool topo(unordered_map<int,vector<int>> adj, int n, vector<int>& indegree){
        queue<int> q;

        //kitane node maine visit kar liye
        int ctn = 0;

        for(int i = 0; i<n; i++){
            if(indegree[i]==0) {
                q.push(i);
                ctn++;
            }
        }

        while(!q.empty()){
            int u = q.front();
            q.pop();

            for(int &v: adj[u]){
                indegree[v]--;
                if(indegree[v]==0) {
                    q.push(v);
                    ctn++;
                }
            }
        }

        return (ctn==n); //I was able to visit all nodes(course)
        //i.e I was able to finish all courses
    }

    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        
        //dekho isme humko bantana hai ki hum sare course kar payenge ki nahi

        // the only constraint in doing all the course ki a--->b and b--->a matalb
        // cycle form ho ri hogi

        //topological sort dekhte hai.

        //graph banao
        unordered_map<int,vector<int>> adj;
        vector<int> indegree(numCourses,0);

        for(auto &vec: prerequisites){
            int a = vec[0];
            int b = vec[1];

            //b-->a;

            adj[b].push_back(a);

            //arrow jaa raha hai 'a' me
            indegree[a]++;
        }

        return topo(adj,numCourses,indegree);
    }
};