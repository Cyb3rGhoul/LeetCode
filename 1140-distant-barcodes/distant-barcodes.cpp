class Solution {
public:
    vector<int> rearrangeBarcodes(vector<int>& barcodes) {
        int n=barcodes.size();

        unordered_map<int,int> mp;

        for(int i = 0; i<n; i++){
            mp[barcodes[i]]++;
        }

        priority_queue<pair<int,int>> pq;

        for(auto& it: mp){
            pq.push({it.second,it.first});
        }

        vector<int> res;
        while(!pq.empty()){
            int ele = pq.top().second;
            int occ = pq.top().first;
            pq.pop();
            res.push_back(ele);
            occ--;
            while(!pq.empty()){
                int ele2 = pq.top().second;
                int occ2 = pq.top().first;
                pq.pop();
                res.push_back(ele2);
                occ2--;
                if(occ2!=0) pq.push({occ2,ele2});
                break;
            }
            if(occ!=0) pq.push({occ,ele});

        }


        return res;
    }
};