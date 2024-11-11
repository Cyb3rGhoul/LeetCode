class Solution {
public:
    bool isPrime[1000];

    void sieve(){ //O(loglogn) normally
        fill(isPrime, isPrime+1000, true);

        isPrime[0] = false;
        isPrime[1] = false;

        for(int i = 2; i * i < 1000; i++){
            if(isPrime[i]==true){
                for(int j = i*i; j<1000; j+=i){
                    isPrime[j] = false;
                }
            }
        }

    }

    bool primeSubOperation(vector<int>& nums) {

        int n = nums.size();
        

        sieve(); //it will populate my isPrime number
        //if isPrime[i] == true , means i is prime else not


        for(int i = n-2; i>=0; i--){
            if(nums[i]<nums[i+1]) continue;
            // nums[i] >= nums[i+1]
            // decreasae nums[i] atleast be less then nums[i+1]

            //check prime

            for(int j = 2; j < nums[i]; j++){
                if(!isPrime[j]) continue;
                if(nums[i] - j < nums[i+1]){
                    nums[i] -= j;
                    break;
                }
            }

            if(nums[i]>=nums[i+1]) return false;
        }

        return true;
    }
};