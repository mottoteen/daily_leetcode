/*

给你一个按升序排序的整数数组 num（可能包含重复数字），请你将它们分割成一个或多个子序列，其中每个子序列都由连续整数组成且长度至少为 3 。

如果可以完成上述分割，则返回 true ；否则，返回 false 。

示例 1：

	输入: [1,2,3,3,4,5]

	输出: True

	解释:

		你可以分割出这样两个连续子序列 : 

			1, 2, 3

			3, 4, 5

示例 2：

	输入: [1,2,3,3,4,4,5,5]
	
	输出: True
	
	解释:
	
		你可以分割出这样两个连续子序列 : 
		
			1, 2, 3, 4, 5
			
			3, 4, 5

示例 3：

	输入: [1,2,3,4,4,5]
	
	输出: False

提示：

	输入的数组长度范围为 [1, 10000]

*/
class Solution {
public:
    bool isPossible(vector<int>& nums) {
        unordered_map<int, int> countMap;
        unordered_map<int, int> endMap;
        for (auto& x : nums)
            countMap[x]++;
        for (auto& x : nums) {
            int count = countMap[x];
            if (count > 0) {
                int prevEndCount = endMap[x - 1];
                if (prevEndCount > 0) {
                    countMap[x] = count - 1;
                    endMap[x - 1] = prevEndCount - 1;
                    endMap[x] = endMap[x] + 1;
                } else {
                    int count1 = countMap[x + 1];
                    int count2 = countMap[x + 2];
                    if (count1 > 0 && count2 > 0) {
                        countMap[x] = count - 1;
                        countMap[x + 1] = count1 - 1;
                        countMap[x + 2] = count2 - 1;
                        endMap[x + 2] = endMap[x + 2] + 1; 
                    } else
                        return false;
                }
            }
        }
        return true;
    }
};