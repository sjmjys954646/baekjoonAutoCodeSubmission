#include <string>
#include <vector>
#include <bits/stdc++.h>

using namespace std;

int solution(vector<vector<int>> sizes) {
    int answer = 0;
    
    for(int i = 0;i< sizes.size();i++)
    {
        if(sizes[i][0] < sizes[i][1])
            swap(sizes[i][0],sizes[i][1]);
    }
    
    int maxiR = -1;
    int maxiC = -1;
    
    for(int i = 0;i< sizes.size();i++)
    {
        maxiR = max(maxiR, sizes[i][0]);
        maxiC = max(maxiC, sizes[i][1]);
    }
    
    answer = maxiR * maxiC;
    
    return answer;
}