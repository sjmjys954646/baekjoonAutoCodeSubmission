#include <bits/stdc++.h>

using namespace std;

bool solution(vector<string> phone_book) {
    bool answer = true;
    
    sort(phone_book.begin(),phone_book.end());
    for (auto it1 = phone_book.begin(); it1 != phone_book.end(); it1++)
    {
        for (auto it2 = it1; it2 != phone_book.end(); ++it2)
        {
            if (it1 == it2)
                continue;
            
            if (it2->find(*it1) == 0)
                return false;
            else
                break;
        }
    }        
    
    return answer;
}