class Solution {
public:
    #define P pair<double,int>
    double maxAverageRatio(vector<vector<int>>& classes, int extraStudents) {
        int n = classes.size();

        priority_queue<P> pq;

        for(int i = 0; i<n; i++){
            double curr = (double)classes[i][0]/classes[i][1];
            double upp = (double)(classes[i][0]+1)/(classes[i][1]+1);
            double delta = upp - curr;
            pq.push({delta, i});
        }

        while(extraStudents--){
            auto crr = pq.top();
            pq.pop();

            double delta = crr.first;
            int idx = crr.second;

            classes[idx][0]++;
            classes[idx][1]++;
            
            double curr = (double)classes[idx][0]/classes[idx][1];
            double upp = (double)(classes[idx][0]+1)/(classes[idx][1]+1);
            delta = upp - curr;
            pq.push({delta, idx});

        }

        double res = 0.0;

        for(int i = 0; i<n; i++){
            res+=(double)classes[i][0]/classes[i][1];
        }

        return res/n;
    }
};