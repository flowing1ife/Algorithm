#include <iostream>
#include <vector>
#include <string>

using namespace std;

bool check(int c, int r) {
	if (c > 7 || r > 7 || c < 0 || r < 0) { //체스판을 넘어가면
		return 0;
	}
	return 1;
}


vector<int> calSpot(int r, int c, string way) {
	vector<int> spot(2, 0);
	if (way == "R") {
		c += 1;

	}
	else if (way == "L") {
		c -= 1;
	}
	else if (way == "B") {
		r -= 1;
	}
	else if (way == "T") {
		r += 1;
	}
	else if (way == "RT") {
		c += 1;
		r += 1;
	}
	else if (way == "LT") {
		c -= 1;
		r += 1;
	}
	else if (way == "RB") {
		c += 1;
		r -= 1;
	}
	else if (way == "LB") {
		c -= 1;
		r -= 1;
	}
	spot[0] = c;
	spot[1] = r;

	return spot;
}

void moving(vector<vector <int>>& v, int& king_c, int& king_r, int& stone_c, int& stone_r, string& way) {
	//king이 이동할 곳 계산 
	vector<int> location_k = calSpot(king_r, king_c, way);
	//cout << "king 자리 계산 : " << location_k[0] << location_k[1] << "\n";
	if (check(location_k[0], location_k[1])) { //이동 경로가 체스판 안에 위치할 경우
		//만약 king이 이동할 곳에 돌이 있을 경우 
		if (v[location_k[0]][location_k[1]] == 2) {
			//돌의 이동 위치 계산
			vector<int> location_s = calSpot(stone_r, stone_c, way);
			//cout << "stone 자리 계산 : " << location_s[0] << location_s[1] << "\n";
			//돌의 경로 검사
			if (check(location_s[0], location_s[1])) {//돌의 이동경로도 체스판 안에 위치
				//king의 원래 위치 0으로 설정
				v[king_c][king_r] = 0;
				//cout << "king 원래자리로 설정 : " << king_c << king_r << "\n";
				//돌 옮기기
				stone_c = location_s[0];
				stone_r = location_s[1];
				v[stone_c][stone_r] = 2;
				//cout << "stone 자리 옮기기 : " << stone_c << stone_r << "\n";
				//king 옮기기
				king_c = location_k[0];
				king_r = location_k[1];
				v[king_c][king_r] = 1;
				//cout << "king 자리 옮기기 : " << king_c << king_r << "\n";
			}

		}
		else { //그냥 이동할 경우 
			//king의 원래 위치 0으로 설정
			v[king_c][king_r] = 0;

			//king 옮기기
			king_c = location_k[0];
			king_r = location_k[1];
			v[king_c][king_r] = 1;
		}

	}


}

int main()
{
	string king; //king의 위치
	string stone; //stone의 위치
	int n; // 움직이는 횟수
	vector<vector <int>> v(8, vector<int>(8, 0));


	//입력
	cin >> king >> stone >> n;


	//연산
	//king과 stone의 자리 표시
	v[king[0] - 'A'][king[1] - '1'] = 1;
	v[stone[0] - 'A'][stone[1] - '1'] = 2;

	int king_c = king[0] - 'A';
	int king_r = king[1] - '1';
	int stone_c = stone[0] - 'A';
	int stone_r = stone[1] - '1';

	//cout << "king 자리 : " << king_c << king_r << "\n";
	//cout << "stone 자리 : " << stone_c << stone_r << "\n";


	//n만큼 움직임
	while (n--) {
		string way;
		cin >> way;

		moving(v, king_c, king_r, stone_c, stone_r, way);
	}

	cout << char(king_c + 'A') << king_r + 1 << "\n";
	cout << char(stone_c + 'A') << stone_r + 1 << "\n";

	return 0;


}