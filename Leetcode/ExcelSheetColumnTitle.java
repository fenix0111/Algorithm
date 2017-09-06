// Leetcode 168. Excel Sheet Column Title
// https://leetcode.com/problems/excel-sheet-column-title/description/
// Runtime: 0ms

class Solution {
    public String convertToTitle(int n) {
        StringBuilder sb = new StringBuilder();
        String[] table = {  "0",
                            "A","B","C","D","E","F","G","H","I","J",
                            "K","L","M","N","O","P","Q","R","S","T",
                            "U","V","W","X","Y","Z" };
        int number = n;
        int quotient = 0;
        int mod = 0;

        while (number > 0) {
            mod = number % 26;
            if (mod == 0) {
                sb.insert(0, "Z");
                number = number - 26;
            } else {
                sb.insert(0, table[mod]);
            }
            number = number / 26;
        }
        return sb.toString();
    }
    
    // 其他参考解法
    public String convertToTitle(int n) {
        StringBuilder sb = new StringBuilder();
        while (n != 0) {
            n--;
            sb.insert(0, (char)('A' + （n % 26)));
            n = n/26;
        }
        return sb.toString();
    }
}
