#include<iostream>
#include<cstdio>
using namespace std;

int const MAX_STEP = 10000;

int result[20];
int cases;
int n;
int nowRound;

int puzzle[17][17], press[17][17];


bool guess(){
	//����press��һ�к�puzzle���飬��������press��
	for (int r = 1; r < n; r++)
		for (int c = 1; c < n + 1; c++){
		press[r + 1][c] = (puzzle[r][c] +
			press[r][c] + press[r - 1][c] + press[r][c - 1] + press[r][c + 1])
			% 2;
		}

	//�ж��������press�����ܷ�Ϩ�����һ�����еĵ�
	for (int c = 1; c < n + 1; c++){
		if ((press[n][c - 1] + press[n][c] + press[n][c + 1] + press[n-1][c])
			% 2
			!= puzzle[n][c])
			return false;
	}

	int steps = 0;
	for (int r = 1; r < n + 1; r++)
		for (int c = 1; c < n + 1; c++){
		if (press[r][c] == 1)
			steps++;
		}

	if (steps<result[nowRound])
		result[nowRound] = steps;
	return true;
}


void enumerate(){
	//bool success;
	for (int j = 0; j < n + 2; j++){
		press[1][j] = 0;
	}

	int total = 0;
	int c = 0;
	

	guess();
	do
	{
		press[1][1]++;
		c = 1;
		//ģ��������ۼ�
		while (press[1][c] > 1 && c < n + 1){
			press[1][c] = 0;
			c++;
			press[1][c]++;
		}

		total = 0;
		for (int j = 1; j < n + 1; j++){
			total += press[1][j];
		}

		guess();
	} while (total < n); 
		

}



int main(){
	for (int i = 0; i < 20; i++){
		result[i] = MAX_STEP;
	}

	cin >> cases;
	for (int a = 0; a < cases; a++){
		nowRound = a;
		cin >> n;

		//��ΧһȦ����
		//for (int c = 0; c < n + 2; c++)
		//	press[0][c] = press[n + 1][c] = 0;
		//for (int r = 0; r < n + 2; r++)
		//	press[r][0] = press[r][n + 1] = 0;

		//ͨͨ����
		for (int r = 0; r < n + 2; r++)
			for (int c = 0; c < n + 2; c++)
				puzzle[r][c] = press[r][c] = 0;


		for (int i = 1; i <= n; i++){
			for (int j = 1; j <= n; j++){
				char color;
				cin >> color;
				if (color == 'y')
					puzzle[i][j] = 0;
				else
					puzzle[i][j] = 1;
			}
		}
		enumerate();
	}


	for (int a = 0; a < cases; a++){
		if (result[a] < MAX_STEP)
			cout << result[a] << endl;
		else
			cout << "inf" << endl;
	}

}



//��������
//
//����
//��һ�������ε�ǽ����N*N�������ε�ש��ɣ�����һЩש�ǰ�ɫ�ģ�����һЩש�ǻ�ɫ�ġ�
//Bob�Ǹ����ң����ȫ����ש��Ϳ�ɻ�ɫ�������Ļ��ʲ���ʹ�������û���Ϳ����(i, j)��λ�õ�שʱ�� 
//λ��(i - 1, j)��(i + 1, j)��(i, j - 1)��(i, j + 1)�ϵ�ש����ı���ɫ��
//�������Bob�����������ҪͿ�����ٿ�ש������ʹ����ש����ɫ����ɻ�ɫ��
//
//����
//��һ���Ǹ�����t(1��t ��20)����ʾҪ���Եİ�������Ȼ����t��������
//ÿ��������������һ������n(1��n ��15)����ʾǽ�Ĵ�С����������n�б�ʾǽ�ĳ�ʼ״̬��
//ÿһ�а���n���ַ�����i�еĵ�j���ַ���ʾλ��λ��(i, j)�ϵ�ש����ɫ����w����ʾ��ש����y����ʾ��ש��
//
//���
//ÿ���������һ�С����Bob�ܹ������е�ש��Ϳ�ɻ�ɫ�������������ҪͿ����ש�������������inf����
//
//��������
//2
//3
//yyy
//yyy
//yyy
//5
//wwwww
//wwwww
//wwwww
//wwwww
//wwwww
//
//�������
//0
//15