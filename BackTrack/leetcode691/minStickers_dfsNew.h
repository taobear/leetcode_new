#include <string>
#include <vector>

using namespace std;

class Solution
{
public:
    int ans = INT_MAX;
    bool is_zero(vector<int> &tar)
    {
        for (auto x : tar)
            if (x)
                return 0;
        return 1;
    }
    void dfs(vector<int> &tar, vector<vector<int>> &p, int curr)
    {
        if (curr >= ans)
            return; //当前深度大于ans,返回
        if (is_zero(tar))
        {
            ans = min(ans, curr);
            return;
        }
        int loc;
        for (int i = 0; i < 26; i++)
        {
            if (tar[i])
            {
                loc = i;
                break;
            }
        }
        for (auto &x : p)
        {
            if (!x[loc])
                continue; //从左边第一个未出现字符开始，避免重复
            vector<int> tmp(26);
            for (int i = 0; i < 26; i++)
                tmp[i] = max(0, tar[i] - x[i]);
            dfs(tmp, p, curr + 1);
        }
        return;
    }
    bool bigger(vector<int> &a, vector<int> &b)
    {
        for (int i = 0; i < 26; i++)
        {
            if (a[i] < b[i])
                return 0;
        }
        return 1;
    }
    int minStickers(vector<string> &stickers, string target)
    {
        int n = stickers.size();
        vector<int> tar(26, 0);
        for (auto x : target)
            tar[x - 'a']++;
        vector<vector<int>> p;
        vector<bool> ext(26, 0);
        for (int i = 0; i < n; i++)
        {
            vector<int> curr(26, 0);
            for (int j = 0; j < stickers[i].size(); j++)
            {
                if (tar[stickers[i][j] - 'a'])
                    curr[stickers[i][j] - 'a']++;
                ext[stickers[i][j] - 'a'] = 1;
            }
            bool tag = 1;
            for (int i = 0; i < p.size(); i++)
            {
                //某个字符串如果完全包含另一个字符串，删除另一个字符串
                if (bigger(curr, p[i]))
                {
                    p.erase(p.begin() + i);
                    i--;
                }
                else if (bigger(p[i], curr))
                {
                    tag = 0;
                    break;
                }
            }
            if (tag)
                p.push_back(curr);
        }
        //有某个字符所有单词都没有,不能成功
        for (int i = 0; i < 26; i++)
        {
            if (tar[i] && !ext[i])
                return -1;
        }
        dfs(tar, p, 0);
        return ans == INT_MAX ? -1 : ans;
    }
};

