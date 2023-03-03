#include <string>
#include <vector>
#include <algorithm>

using namespace std;

char arr[5] = {'A', 'E', 'I', 'O', 'U'};
vector<string> v;
vector<char> hubo;

void dfs(int cur, int N)
{
    if(cur == N)
    {
        string tmp = "";
        for(auto i : hubo)
        {
            tmp+=i;
        }
        v.push_back(tmp);
        return;
    }
    
    for(int i = 0;i<5;i++)
    {
        hubo.push_back(arr[i]);
        dfs(cur+1,N);
        hubo.pop_back();
    }
}

int solution(string word) {
    int answer = 0;
    for(int i = 1;i<=5;i++)
    {
        dfs(0,i);
    }
    
    sort(v.begin(),v.end());
    
    
    for(int i = 0;i<v.size();i++)
    {
        if(word == v[i])
        {
            answer = i + 1;
        }
    }
    
    return answer;
}