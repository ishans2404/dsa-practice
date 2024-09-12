class Solution {
    public int countConsistentStrings(String allowed, String[] words) {
        boolean[] arr = new boolean[26];
        for(int i=0; i<allowed.length(); i++) {
            arr[allowed.charAt(i) - 'a'] = true;
        }

        int res = 0;
        for(String w : words) {
            boolean[] newarr = new boolean[26];
            int temp = 26;
            for(int i=0; i<w.length(); i++) {
                newarr[w.charAt(i) - 'a'] = true;
            }
            for(int i=0; i<26; i++) {
                if(arr[i] == false && newarr[i] == true) temp--;
            }
            if(temp == 26) res++;
        }
        return res;
    }
}