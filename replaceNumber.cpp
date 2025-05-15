/**
 * Question:
 * 给定一个字符串 s，它包含小写字母和数字字符，
 * 请编写一个函数，将字符串中的字母字符保持不变，
 * 而将每个数字字符替换为 "number"。
 * 例如输入: "a1b2c3"，输出应为: "anumberbnumbercnumber"
 *
 * Given a string s, which contains lowercase letters and numeric characters,
 * write a function that leaves the alphabetic characters unchanged,
 * and replaces each numeric character with the string "number".
 * For example: input "a1b2c3" → output "anumberbnumbercnumber"
 */

#include <iostream>
#include <string>
using namespace std;

int main(void) {
    string s;

    // 连续读取输入，每次处理一个字符串
    while (cin >> s) {

        // 记录原始字符串结尾位置
        int endOfOriginStringIndex = s.size() - 1;

        // 统计数字字符个数（每个数字将被替换成 "number"）
        int numberCounter = 0;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] >= '0' && s[i] <= '9') {
                numberCounter++;
            }
        }

        // 每个数字替换为 "number"，即增加 5 个字符（6-1）
        // 扩容字符串，为从后往前就地替换留足空间
        s.resize(s.size() + numberCounter * (string("number").length() - 1));

        // 设置两个指针：left 指向原始末尾，right 指向扩容后末尾
        int left = endOfOriginStringIndex;
        int right = s.size() - 1;

        // 从后往前遍历原始字符串，逐个处理字符
        for (; left >= 0; left--) {
            if (s[left] >= '0' && s[left] <= '9') {
                // 如果当前字符是数字，反向写入字符串 "number"
                string number = "number";
                int lengthOfNumber = number.size();
                while (lengthOfNumber != 0) {
                    s[right--] = number[lengthOfNumber - 1];
                    lengthOfNumber--;
                }
            } else {
                // 如果是字母，直接原样拷贝
                s[right--] = s[left];
            }
        }

        // 输出处理后的字符串结果
        cout << s << endl;
    }

    return 0;
}