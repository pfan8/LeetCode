class Solution {
    public String reverseWords(String s) {
        // 时间复杂度O(n)
        // 空间复杂度O(n)
        if (s == null || s.length() == 0) {
            return "";
        }
        String[] arr = s.split(" ");
        StringBuilder res = new StringBuilder();
        
        for (int i = arr.length - 1; i >= 0; i--) {
            String word = arr[i];
            
            if (!word.equals("")) {
                if (res.length() > 0) {
                    res.append(" ");
                }
                res.append(word);
            } 
        }
        return res.toString();
    }
}