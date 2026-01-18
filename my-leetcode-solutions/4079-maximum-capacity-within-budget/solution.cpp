class Solution {
public:
    int maxCapacity(vector<int>& costs, vector<int>& capacity, int budget) {
    if(costs.size() != capacity.size()) return 0;
    int n = costs.size();
    if(n==0) return 0;

    vector<pair<int, int>> items;
    for(int i=0; i<n; i++){
        items.push_back({costs[i], capacity[i]});
    }

    sort(items.begin(), items.end());

    vector<int> best(n);

    best[0] = items[0].second;

    for(int i=1; i<n; i++){
        best[i] = max(best[i-1], items[i].second);
    }

    int ans = 0;

    for(int i=0; i<n; i++){
        int remaining = budget - items[i].first - 1;
        if(remaining < 0) break;

        ans = max(ans, items[i].second);

        int idx = upper_bound(
            items.begin(), items.end(),
            make_pair(remaining, INT_MAX)
        ) - items.begin() - 1;

        int partnerIdx = min(idx, i - 1);
            if (partnerIdx >= 0) {
                ans = max(ans, items[i].second + best[partnerIdx]);
            }

    }

        return ans;

}
};
