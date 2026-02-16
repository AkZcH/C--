#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int longestSubarray(vector<int>& nums, int k) {
    int n = nums.size();

    vector<long long> prefix(n + 1, 0);
    for (int i = 0; i < n; i++)
        prefix[i + 1] = prefix[i] + nums[i];

    // mins[i] = minimum prefix sum from i to end
    vector<long long> mins(n + 1);
    mins[n] = prefix[n];

    for (int i = n - 1; i >= 0; i--)
        mins[i] = min(prefix[i], mins[i + 1]);

    int ans = 0;

    for (int i = 0; i <= n; i++) {
        long long target = prefix[i] + k;

        // Find farthest j where mins[j] <= target
        int j = upper_bound(mins.begin(), mins.end(), target) - mins.begin() - 1;

        if (j >= i)
            ans = max(ans, j - i);
    }

    return ans;
}
