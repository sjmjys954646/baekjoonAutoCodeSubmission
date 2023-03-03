#include <bits/stdc++.h>

using namespace std;

vector<int> solution(vector<int> answers) {
    vector<int> answer;
    
    int N = answers.size();
    
    vector<int> supo1;
    vector<int> supo2;
    vector<int> supo3;
    
    int index = 1;
    for(int i = 0;i < N;i++)
    {
        supo1.push_back(index);
        index++;
        
        if(index == 6)
            index = 1;
    }
    
    int arr2[8] = {2,1,2,3,2,4,2,5};
    index = 0;
    for(int i = 0;i < N;i++)
    {
        supo2.push_back(arr2[index]);
        index++;
        
        if(index == 8)
            index = 0;
    }
    
    int arr3[10] = {3,3,1,1,2,2,4,4,5,5};
    index = 0;
    for(int i = 0;i < N;i++)
    {
        supo3.push_back(arr3[index]);
        index++;
        
        if(index == 10)
            index = 0;
    }
    
    vector<int> sum(3,0);
    
    for(int i = 0;i<N;i++)
    {
        if(answers[i] == supo1[i])
            sum[0]++;
        if(answers[i] == supo2[i])
            sum[1]++;
        if(answers[i] == supo3[i])
            sum[2]++;
    }
    for(auto i : supo1)
        cout << i << " ";
    cout<<"\n";
    for(auto i : supo2)
        cout << i << " ";
    cout<<"\n";
    for(auto i : supo3)
        cout << i << " ";
    cout<<"\n";
    
    cout<<sum[0] << sum[1] << sum[2];
    int maxi = max({sum[0],sum[1],sum[2]});
    
    for(int i = 0;i<3;i++)
    {
        if(maxi == sum[i])
            answer.push_back(i+1);
    }
    
    sort(answer.begin(),answer.end());
    
    return answer;
}