/*

给定两个句子 A 和 B 。 （句子是一串由空格分隔的单词。每个单词仅由小写字母组成。）

如果一个单词在其中一个句子中只出现一次，在另一个句子中却没有出现，那么这个单词就是不常见的。

返回所有不常用单词的列表。

您可以按任何顺序返回列表。

示例 1：

	输入：A = "this apple is sweet", B = "this apple is sour"

	输出：["sweet","sour"]

示例 2：

	输入：A = "apple apple", B = "banana"

	输出：["banana"]

提示：

	0 <= A.length <= 200
	
	0 <= B.length <= 200
	
	A 和 B 都只包含空格和小写字母。

*/
class Solution {
public:
    vector<string> split(const string& str, char deli) {
        int beginPos = str.find_first_not_of(deli);
        int endPos = str.find_first_of(deli, beginPos);
        vector<string> strs;
        while (beginPos != string::npos) {
            strs.push_back(str.substr(beginPos, endPos - beginPos));
            beginPos = str.find_first_not_of(deli, endPos);
            endPos = str.find_first_of(deli, beginPos);
        }
        return strs;
    }
    vector<string> uncommonFromSentences(string A, string B) {
        vector<string> As = split(A, ' ');
        vector<string> Bs = split(B, ' ');
        vector<string> ret;
        unordered_map<string, int> hash;
        for (string& str : As)
            ++hash[str];
        for (string& str : Bs)
            ++hash[str];
        for (auto& item : hash) {
            if (item.second == 1)
                ret.push_back(item.first);
        }
        return ret;
    }
};