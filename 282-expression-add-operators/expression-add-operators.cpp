class Solution {
public:
    vector<string> res;

    void solve(string& num, int target, int idx, string path, long current_sum, long prev_val) {
        // Base Case: We've used up the whole number string
        if (idx == num.length()) {
            if (current_sum == target) {
                res.push_back(path);
            }
            return;
        }

        // Loop to form multi-digit numbers
        for (int j = idx; j < num.length(); ++j) {
            // Edge Case: Numbers can't have leading zeros unless it's the number 0 itself
            if (j > idx && num[idx] == '0') {
                break;
            }

            string current_num_str = num.substr(idx, j - idx + 1);
            long current_num = stol(current_num_str);

            if (idx == 0) {
                // This is the first number, so no operator before it
                solve(num, target, j + 1, current_num_str, current_num, current_num);
            } else {
                // Add '+' operator
                solve(num, target, j + 1, path + "+" + current_num_str, current_sum + current_num, current_num);

                // Add '-' operator
                solve(num, target, j + 1, path + "-" + current_num_str, current_sum - current_num, -current_num);

                // Add '*' operator (the tricky one)
                long new_sum = (current_sum - prev_val) + (prev_val * current_num);
                long new_prev_val = prev_val * current_num;
                solve(num, target, j + 1, path + "*" + current_num_str, new_sum, new_prev_val);
            }
        }
    }

    vector<string> addOperators(string num, int target) {
        // Start the recursion from index 0
        solve(num, target, 0, "", 0, 0);
        return res;
    }
};