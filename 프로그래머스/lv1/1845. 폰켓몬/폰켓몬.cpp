#include <bits/stdc++.h>

using namespace std;

int solution(vector<int> nums)
{
    int answer = 0;
    
    map<int,int> m;
    for(int i = 0;i < nums.size();i++)
    {
        if(!m.count(nums[i]))
            m[nums[i]] = 1;
        else
            m[nums[i]]++;
    }
    
    answer = min(m.size(), nums.size() / 2);
    
    return answer;
}