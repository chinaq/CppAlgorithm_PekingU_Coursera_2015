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
	//根据press第一行和puzzle数组，计算其他press行
	for (int r = 1; r < n; r++)
		for (int c = 1; c < n + 1; c++){
		press[r + 1][c] = (puzzle[r][c] +
			press[r][c] + press[r - 1][c] + press[r][c - 1] + press[r][c + 1])
			% 2;
		}

	//判断所计算的press数组能否熄灭最后一行所有的灯
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
		//模拟二进制累加
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

		//周围一圈清零
		//for (int c = 0; c < n + 2; c++)
		//	press[0][c] = press[n + 1][c] = 0;
		//for (int r = 0; r < n + 2; r++)
		//	press[r][0] = press[r][n + 1] = 0;

		//通通清零
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



//画家问题
//
//描述
//有一个正方形的墙，由N*N个正方形的砖组成，其中一些砖是白色的，另外一些砖是黄色的。
//Bob是个画家，想把全部的砖都涂成黄色。但他的画笔不好使。当他用画笔涂画第(i, j)个位置的砖时， 
//位置(i - 1, j)、(i + 1, j)、(i, j - 1)、(i, j + 1)上的砖都会改变颜色。
//请你帮助Bob计算出最少需要涂画多少块砖，才能使所有砖的颜色都变成黄色。
//
//输入
//第一行是个整数t(1≤t ≤20)，表示要测试的案例数。然后是t个案例。
//每个案例的首行是一个整数n(1≤n ≤15)，表示墙的大小。接下来的n行表示墙的初始状态。
//每一行包含n个字符。第i行的第j个字符表示位于位置(i, j)上的砖的颜色。“w”表示白砖，“y”表示黄砖。
//
//输出
//每个案例输出一行。如果Bob能够将所有的砖都涂成黄色，则输出最少需要涂画的砖数，否则输出“inf”。
//
//样例输入
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
//样例输出
//0
//15