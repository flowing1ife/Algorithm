#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int availTime(vector<vector<int>>& arr, int n, int m, int s) { //시험 가능한 시간을 연산하는 함수
	int t = -1; // 기본값

	if (arr[0][0] != 0 && m <= arr[0][0]) { //만약 초반에 시간이 빈다면
		return 0;
	}

	for (int i = 0; i < n; i++) {  
		if (i == n - 1) {
			if ((arr[n - 1][1] + m) <= s) { // 맨 후반에 시간이 빌경우
				t = arr[n - 1][1];
			}
			break;
		}

		if (arr[i + 1][0] >= (arr[i][1] + m)) {// 배열 중간에 시간이 빌 경우
			t = arr[i][1];
			break;
		}

	}

	return t; // 위의 경우 모두 해당되지 않으면 -1 return
}

int main()
{
	int n, m, s;
	int x, y;


	//입력
	cin >> n >> m >> s;

	vector<vector<int>>arr(n, vector<int>(2, 0));




	for(int i = 0; i < n; i++) {

		//시험 시간 입력
		cin >> x >> y;
		arr[i][0] = x; // 시작 시간
		arr[i][1] = x + y; // 끝나는 시간
	}

	//시작 시간순으로 정렬 
	sort(arr.begin(), arr.end());

	//연산
	
	cout << availTime(arr, n, m, s);

}