/**
 * 题目描述：
 * 字符串的右旋转操作是把字符串尾部的若干个字符转移到字符串的前面。
 * 给定一个字符串 s 和一个正整数 k，请编写一个函数，
 * 将字符串中的后面 k 个字符移到字符串的前面，实现字符串的右旋转操作。
 *
 * 输入描述：
 * 输入共包含两行：
 * 第一行为一个正整数 k，代表右旋转的位数。
 * 第二行为字符串 s，代表需要旋转的字符串。
 *
 * 输出描述：
 * 输出共一行，为进行了右旋转操作后的字符串。
 *
 * 输入示例：
 * 2
 * abcdefg
 *
 * 输出示例：
 * fgabcde
 */

#include <iostream>
#include <string>
using namespace std;

// 反转字符串中 [left, right] 区间内的字符
void reverse(string& s, int left, int right) {
    while (left < right) {
        char temp = s[left];
        s[left] = s[right];
        s[right] = temp;
        left++;
        right--;
    }
}

int main(void) {
    string s;
    int k = 0;

    // 读取输入
    cin >> k >> s;

    int n = s.size();
    k = k % n;  // 防止 k 大于字符串长度

    // 三步翻转法（经典解法）：
    // Step 1：整体反转
    reverse(s, 0, n - 1);

    // Step 2：反转前 k 个字符（原先的尾部）
    reverse(s, 0, k - 1);

    // Step 3：反转剩下的部分（原先的头部）
    reverse(s, k, n - 1);

    // 输出结果
    cout << s << endl;

    return 0;
}