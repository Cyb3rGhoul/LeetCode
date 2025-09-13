class Solution {
public:
    string reformatDate(string date) {
        string d = "";
        int da = 0;
        string m = "";
        string y = "";

        string ans = "";

        unordered_map<string,string> mp;

        mp["01"] = "Jan";
        mp["02"] = "Feb";
        mp["03"] = "Mar";
        mp["04"] = "Apr";
        mp["05"] = "May";
        mp["06"] = "Jun";
        mp["07"] = "Jul";
        mp["08"] = "Aug";
        mp["09"] = "Sep";
        mp["10"] = "Oct";
        mp["11"] = "Nov";
        mp["12"] = "Dec";

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
                m = it.first;
                break;
            }
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