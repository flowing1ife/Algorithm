#include <iostream>
#include <vector>
#include <stack>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    int due; //작업기간
    stack<int> s;
    vector<int> answer;

    for (int i = (progresses.size() - 1); i >= 0; i--) { // progresses size 만큼 반복

        // 연산 
        due = ((100 - progresses[i]) / speeds[i]);

        if (((100 - progresses[i]) % speeds[i]) != 0) {
            // 나머지가 존재한다면
            due++;
        }

        s.push(due);
    }

    //한번에 배포되는 기능의 개수 연산
    while (!s.empty()) { //스택이 빌 때까지 반복
        int num = 0; //한번에 배포되는 기능의 개수
        int top = s.top();

        while (!s.empty() && s.top() <= top) {
            num++;
            s.pop();
        }
        answer.push_back(num);
    }


    return answer;
}