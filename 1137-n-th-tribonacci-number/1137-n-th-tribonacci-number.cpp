class Solution {
public:
    int tribonacci(int n) {
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);
        
        if(n<3) {
            if(n==0) return 0;
            else return 1;
        }
        int arr[n+1];
        arr[0] = 0;
        arr[1] = 1;
        arr[2] = 1;
        for(int i=3; i<=n; i++) arr[i] = arr[i-1]+arr[i-2]+arr[i-3];

        return arr[n];
    }
};