/**
 * @file question_third.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2024-01-26
 * 
 * @copyright Copyright (c) 2024
 * 
 */

 /*
 执行一个 C++ 函数 findLongestIncreasingSubsequence，将整数向量作为输入，
 并返回最长递增子序列的长度。该函数不仅要找到长度，还要打印实际的子序列。

例如，给定输入向量[10, 22, 9, 33, 21, 50, 41, 60, 80]
函数应输出：
Longest Increasing Subsequence: 10, 22, 33, 50, 60, 80
Length of Longest Increasing Subsequence: 6

确保执行效率高，能处理较大的输入向量。考虑使用动态编程或其他优化算法来解决问题。

提示：最长递增子序列（LIS）问题是在给定序列中找到最长子序列的问题，
 */

#include <iostream>
#include <vector>
#include <string>
using namespace std;

class LongestIncreasingSubsequence
{
public:
    static pair<int, vector<int>> findLongestIncreasingSubsequence(const vector<int> &nums)
    {
        int len = nums.size();
        if (len == 0)
        {
            return {0, {}};
        }
        int maxLength = 0;
        vector<int> lenth(len);
        vector<int> pre(len, -1);
        int i, j;
        int end = 0;
        for (i = 0; i < len; i++)
        {
            for (j = 0; j < i; j++)
            {
                if (nums[i] > nums[j] && lenth[j] + 1 > lenth[i])
                {
                    pre[i] = j;
                    lenth[i] = lenth[j] + 1;
                    if (maxLength < lenth[i])
                    {
                        maxLength = lenth[i];
                        end = i;
                    }
                }
            }
        }
        vector<int> longestSubsequence(maxLength);
        for (i = 0; i < maxLength; i++)
        {
            longestSubsequence[maxLength - i - 1] = nums[end];
            end = pre[end];
        }
        return {maxLength, longestSubsequence};
    }
};

int main()
{
    vector<int> input = {10, 22, 9, 33, 21, 50, 41, 60, 80};

    auto result = LongestIncreasingSubsequence::findLongestIncreasingSubsequence(input);

    cout << "Longest Increasing Subsequence: ";
    for (int num : result.second)
    {
        cout << num << " ";
    }
    cout << endl;

    cout << "Length of Longest Increasing Subsequence: " << result.first << endl;

    return 0;
}
