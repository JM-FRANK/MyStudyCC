#include "myFunction.h"
#include <stdio.h>
// 定义全局变量

// int GlobalInt = 10;

// 将整形数组元素倒置
void reverse_array(int *arr, int length)
{
    int *St = arr;              // 头指针
    int *Ed = arr + length - 1; // 尾指针
    int temp;
    while (St < Ed)
    {
        temp = *St;
        *St = *Ed;
        *Ed = temp;
        St++;
        Ed--;
    }
}

// 找出整形数组中的最大最小值
void find_max_min(int *arr, int length, int *max, int *min)
{
    *max = *min = arr[0];
    for (int i = 0; i < length; i++)
    {
        if (arr[i] > *max)
        {
            *max = arr[i];
        }
        if (arr[i] < *min)
        {
            *min = arr[i];
        }
    }
}

// 找出字符串中最长片段
int lengthOfLongestSubstring(char *s)
{
    if (s == NULL || *s == '\0')
    {
        return 0;
    } // 排除空字符串或错误输入影响
    int next;
    int sum = 1;
    int start = 0;
    int end = 0;
    int map[256] = {0};
    int result = 1;
    map[s[start]] = 1;
    while (s[end] != '\0')
    {                   // 向后遍历至结尾
        next = end + 1; // 设置用于对比的下一个位置
        if (s[next] == '\0')
        {
            result = result > sum ? result : sum;
        }
        if (!map[s[next]])
        { // 若下个位置不重复则记录并增加长度
            map[s[next]] = 1;
            sum++;
            end++;
        }
        else
        {
            result = result > sum ? result : sum; // 取历史最大
            while (map[s[next]])
            {                      // 清空前文直到重复的值
                map[s[start]] = 0; // 并将开始指针移至next位置
                start++;
            }
            end = next;            // 结尾后移
            map[s[end]] = 1;       // 记录尾值（next值）
            sum = end - start + 1; // 更新长度
        }
    }
    return result;
}
