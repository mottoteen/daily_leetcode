/*

给定一个未排序的整数数组 nums ，找出数字连续的最长序列（不要求序列元素在原数组中连续）的长度。

进阶：你可以设计并实现时间复杂度为 O(n) 的解决方案吗？

示例 1：

	输入：nums = [100,4,200,1,3,2]

	输出：4

	解释：最长数字连续序列是 [1, 2, 3, 4]。它的长度为 4。

示例 2：

	输入：nums = [0,3,7,2,5,8,4,6,0,1]

	输出：9

提示：

	0 <= nums.length <= 10 ^ 4

	-10 ^ 9 <= nums[i] <= 10 ^ 9

*/
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> hash;
        for (int& num : nums) {
            hash.insert(num);
        }
        int ret = 0;
        for (int& num : nums) {
            int cur = num;
            if (!hash.count(cur - 1)) {
                while (hash.count(cur + 1)) cur++;
                ret = max(ret, cur - num + 1);
            }
        }
        return ret;
    }
};