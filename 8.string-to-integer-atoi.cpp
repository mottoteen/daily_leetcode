class Solution {
public:
    int myAtoi(string s) {
        long ret = 0;
        int state = 0;
        for(char i : s)
        {
            if(state == 0 && i == ' ') continue;
            else if(state == 0 && i == '+') state = 1;
            else if(state == 0 && i == '-') state = 2;
            else if(i >= '0' && i <= '9')  {
                if(state == 0) state = 1;
                ret = ret * 10 + i - '0';
                if(ret > INT_MAX) break;
            }
            else break;
        }
        if(state == 1 && ret > INT_MAX) ret = INT_MAX;
        else if(state == 2) {
            ret = -ret;
            if(ret < INT_MIN) ret = INT_MIN;
        }
        return ret;
    }
};