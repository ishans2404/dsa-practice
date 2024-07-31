class Solution {
public:
    int n;
    int totalWidth;
    vector<vector<int>> dp;

    int helper(vector<vector<int>>& books, int idx, int remainWidth, int maxHeight) {
        if(idx >= n) return maxHeight;
        if(dp[idx][remainWidth] != -1) return dp[idx][remainWidth];

        int bookWidth = books[idx][0];
        int bookHeight = books[idx][1];


        int keep = INT_MAX;
        int skip = INT_MAX;

        // keep
        if(bookWidth <= remainWidth) keep = helper(books, idx+1, remainWidth-bookWidth, max(maxHeight, bookHeight));
        // skip
        skip = maxHeight + helper(books, idx+1, totalWidth-bookWidth, bookHeight);

        return dp[idx][remainWidth] = min(keep, skip);
    }


    int minHeightShelves(vector<vector<int>>& books, int shelfWidth) {
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(nullptr);
        std::cout.tie(nullptr);

        n = books.size();
        totalWidth = shelfWidth;
        dp = vector<vector<int>>(n+1, vector<int>(shelfWidth+1, -1));
        return helper(books, 0, shelfWidth, 0);
    }
};