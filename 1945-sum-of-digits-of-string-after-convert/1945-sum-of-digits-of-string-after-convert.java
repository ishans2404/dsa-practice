class Solution {
    public int getLucky(String s, int k) {
        int sum = 0;
        int n = s.length();
        for(int i = 0; i < n; i++) {
            int temp = s.charAt(i) - 96;
            while(temp > 0) {
                sum += temp % 10;
                temp /= 10;
            }
        }
        k--;
        int num = sum;
        while(k > 0) {
            sum = 0;
            while(num > 0) {
                sum += num % 10;
                num /= 10;
            }
            num = sum;
            k--;
        }

        return sum;
        
    }
}