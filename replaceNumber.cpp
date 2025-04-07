/** 
Question:

给定一个字符串 s，它包含小写字母和数字字符，请编写一个函数，将字符串中的字母字符保持不变，而将每个数字字符替换为number。 例如，对于输入字符串 "a1b2c3"，函数应该将其转换为 "anumberbnumbercnumber"。

Given a string s, which contains lowercase letters and numeric characters, write a function that leaves the alphabetic characters in the string unchanged and replaces each numeric character with number. For example, given the input string "a1b2c3", the function should convert it to "anumberbnumbercnumber".

**/


#include <iostream>
#include <string>
using namespace std;

int main(void)
{
    string s;
    while (cin >> s)
    {
        int numbersOfNumber = 0; // record the numbers of integer
        for (int i = 0; i < s.size(); i++)
        {
            if ( s[i] >= '0' && s[i] <= '9' )
            {
                numbersOfNumber++;
            }
        }

        int oldLastIndex = s.size() - 1; // record the original last char of string

        // Extend the memory for string
        s.resize( s.size() + numbersOfNumber * 5 );


        int newLastIndex = s.size() - 1; // record the latest last char


        // Replace numbers with "number" from back to front
        while (oldLastIndex >= 0)
        {
            if (s[oldLastIndex] >= '0' && s[oldLastIndex] <= '9')
            {
                s[newLastIndex--] = 'r';
                s[newLastIndex--] = 'e';
                s[newLastIndex--] = 'b';
                s[newLastIndex--] = 'm';
                s[newLastIndex--] = 'u';
                s[newLastIndex--] = 'n';
            } 
            else
            {
                s[newLastIndex--] = s[oldLastIndex];
            }

            oldLastIndex--;
        }

        cout << s << endl;
 
    }


    return 0;
}