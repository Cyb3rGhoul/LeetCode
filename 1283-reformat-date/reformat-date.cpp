class Solution {
public:
    string reformatDate(string date) {
        string d = "";
        int da = 0;
        string m = "";
        int mo = 0;
        string y = "";

        string ans = "";

        unordered_map<int,string> mp;

        mp[1] = "Jan";
        mp[2] = "Feb";
        mp[3] = "Mar";
        mp[4] = "Apr";
        mp[5] = "May";
        mp[6] = "Jun";
        mp[7] = "Jul";
        mp[8] = "Aug";
        mp[9] = "Sep";
        mp[10] = "Oct";
        mp[11] = "Nov";
        mp[12] = "Dec";

        int n = date.length(), i = 0;
        while(date[i]!=' '){
            if(date[i]>='0' && date[i]<='9'){
                d += date[i++];
            }else{
                da = stoi(d);
                break;
            }
        }

        if(da<10){
            d = "0" + to_string(da);
        }
        else{
            d = to_string(da);
        }

        while(date[i]!=' '){i++;}
        i++;

        //month
        while(date[i]!=' '){
            m += date[i++];
        }

        for(auto it: mp){
            if(it.second==m){
                mo = it.first;
                break;
            }
        }

        if(mo<10){
            m = "0" + to_string(mo);
        }
        else{
            m = to_string(mo);
        }

        i++;
        while(i<n){
            y+=date[i++];
        }

        ans += y;
        ans += "-";
        ans += m;
        ans += "-";  
        ans += d;
        return ans;
    }
};