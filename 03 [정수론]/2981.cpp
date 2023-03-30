#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

//최대 공약수 구하는 함수
int gcdIter(int a, int b) {
	while (b) {
		a %= b;
		swap(a, b);
	}
	return a;
}


set<int> cal(vector<int>& v, int n) {
	int num; // 최대공약수 구할 기준 수
	set<int> s; //결과를 구할 셋

	//이웃한 수들간의 차끼리 최대공약수 구하기
	num = v[1] - v[0];

	for (int i = 2; i < n; i++) {
		num = gcdIter(num, v[i] - v[i - 1]);
	}

	//최대공약수의 약수 구하기
	for (int i = 2; i * i <= num; i++) { //시간 초과 해결 
		if (num % i == 0) {
			s.insert(i);
			s.insert(num / i);
		}
	}
	s.insert(num); //최대 공약수까지 넣기 

	return s;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, m;
	set<int> result; //결과를 저장할 셋

	//입력 
	cin >> n;

	vector<int> v;

	for (int i = 0; i < n; i++) {
		cin >> m;
		v.push_back(m);
	}

	//연산
	//차를 쉽게 구하기 위해 정렬
	sort(v.begin(), v.end());
	result = cal(v, n);

	//출력
	for (auto iter : result) {
		cout << iter << " ";
	}

	return 0;
}