#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int availTime(vector<vector<int>>& arr, int n, int m, int s) { //���� ������ �ð��� �����ϴ� �Լ�
	int t = -1; // �⺻��

	if (arr[0][0] != 0 && m <= arr[0][0]) { //���� �ʹݿ� �ð��� ��ٸ�
		return 0;
	}

	for (int i = 0; i < n; i++) {  
		if (i == n - 1) {
			if ((arr[n - 1][1] + m) <= s) { // �� �Ĺݿ� �ð��� �����
				t = arr[n - 1][1];
			}
			break;
		}

		if (arr[i + 1][0] >= (arr[i][1] + m)) {// �迭 �߰��� �ð��� �� ���
			t = arr[i][1];
			break;
		}

	}

	return t; // ���� ��� ��� �ش���� ������ -1 return
}

int main()
{
	int n, m, s;
	int x, y;


	//�Է�
	cin >> n >> m >> s;

	vector<vector<int>>arr(n, vector<int>(2, 0));




	for(int i = 0; i < n; i++) {

		//���� �ð� �Է�
		cin >> x >> y;
		arr[i][0] = x; // ���� �ð�
		arr[i][1] = x + y; // ������ �ð�
	}

	//���� �ð������� ���� 
	sort(arr.begin(), arr.end());

	//����
	
	cout << availTime(arr, n, m, s);

}