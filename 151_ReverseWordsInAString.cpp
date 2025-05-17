class Solution {
public:
    // 主函数：反转句子中的单词顺序，去除多余空格
    string reverseWords(string s) {
        
        // 第一步：去除多余空格（开头/结尾空格 + 单词间多个空格）
        removeExtraSpaces(s);

        // 第二步：整体字符串反转，例如 "the sky is blue" → "eulb si yks eht"
        reverse(s, 0, s.size() - 1);

        // 第三步：逐个单词反转，使每个单词本身恢复正常顺序
        // 最终结果变为 "blue is sky the"
        int left = 0;
        for (int right = 0; right <= s.size(); right++) {
            // 遇到空格或字符串末尾，说明找到了一个完整单词的区间
            if (right == s.size() || s[right] == ' ') {
                reverse(s, left, right - 1); // 反转这个单词
                left = right + 1;            // 移动到下一个单词起点
            }
        }

        return s;
    }

    // 工具函数1：去除多余空格（压缩空格 + 去首尾）
    void removeExtraSpaces(string & s) {
        int slowPtr = 0;  // 写入位置
        int fastPtr = 0;  // 读取位置

        while (fastPtr < s.size()) {
            if (s[fastPtr] != ' ') {
                // 如果 slowPtr 不是起点，需要补一个空格（表示前面已有单词）
                if (slowPtr != 0) s[slowPtr++] = ' ';

                // 拷贝当前单词的所有字符
                while (fastPtr < s.size() && s[fastPtr] != ' ') {
                    s[slowPtr++] = s[fastPtr++];
                }
            } else {
                // 如果是空格，fastPtr 跳过
                fastPtr++;
            }
        }

        // 最终 resize 字符串，裁剪尾部未使用字符
        s.resize(slowPtr);
    }

    // 工具函数2：反转字符串中指定区间 [left, right]
    void reverse(string & s, int left, int right) {
        while (left < right) {
            char temp = s[left];
            s[left] = s[right];
            s[right] = temp;
            left++;
            right--;
        }
    }
};
