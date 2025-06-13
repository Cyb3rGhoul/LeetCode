class Solution {
public:

    void merge(vector<int> &arr, int low, int mid, int high){
        vector<int> temp; // temporary arr
        int left = low; // starting point of left sub array
        int right = mid+1; //starting point of right sub array

        //storing in the temporary array in sorted manner
        while(left<=mid && right<=high){
            if(arr[left]<=arr[right]){
                temp.push_back(arr[left]);
                left++;
            }else{
                temp.push_back(arr[right]);
                right++;
            }
        }

        while(left<=mid){
            temp.push_back(arr[left]);
            left++;
        }
        while(right<=high){
            temp.push_back(arr[right]);
            right++;
        }

        for(int i = low; i<=high; i++){
            arr[i] = temp[i-low];
        }
    }

    int countPair(vector<int> &arr, int low, int mid, int high){
        int ctn = 0;
        int right = mid + 1;
        for(int i = low; i<=mid; i++){
            while(right<=high && (long long)arr[i] > (long long)arr[right]*2){
                right++;
            }
            ctn += (right - (mid+1));
        }
        return ctn;
    }

    int mergeSort(vector<int> &arr, int low, int high){
        if(low>=high) return 0;
        int ctn = 0;
        int mid = (low+high)/2;
        ctn += mergeSort(arr,low,mid);
        ctn += mergeSort(arr,mid+1,high);
        ctn += countPair(arr,low,mid,high);
        merge(arr,low,mid,high);
        return ctn;

    }
    int reversePairs(vector<int>& nums) {
        return mergeSort(nums,0,nums.size()-1);
    }
};