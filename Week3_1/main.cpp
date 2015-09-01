//#include<iostream>
//using namespace std;
//
//struct Point{
//	int x, y;
//}point;
//
//int puzzle[3][30];
//int result[10000];
//int nowRound = 0;
//int col = 0;
//
//
//void cover();
//
//
//void clearPuzzle(){
//	for (int i = 0; i < 3; i++)
//		for (int j = 0; j < col; j++)
//			puzzle[i][j] = 0;
//}
//
//
//
//bool needChangeLine(){
//	bool isNeed = true;
//	for (int c = point.y + 1; c < col; c++){
//		if (puzzle[point.x][c] == 0){
//			isNeed = false;
//			break;
//		}
//	}
//	return isNeed;
//}
//
//
//void setPoint(){
//	if (!needChangeLine()){ //不换行
//		point.y++;
//	}
//	else{                   //换行
//		point.x++;
//		point.y = 0;
//	}
//}
//
//
//void posBack(int backX, int backY){
//	point.x = backX;
//	point.y = backY;
//}
//
//void landTurnBack(int backX, int backY){
//	posBack(backX, backY);
//	puzzle[point.x][point.y] = puzzle[point.x][point.y + 1] = 0;
//}
//
//
//void verticalTurnBack(int backX, int backY){
//	posBack(backX, backY);
//	puzzle[point.x][point.y] = puzzle[point.x + 1][point.y] = 0;
//
//}
//
//
//
//bool isLastLineCovered(){
//	bool isCoverd = true;
//	for (int i = 0; i < col; i++){
//		if (puzzle[2][i] == 0)
//			isCoverd = false;
//	}
//	return isCoverd;
//}
//
//
//
//
//void pushLand(){
//	int tempX = point.x;
//	int tempY = point.y;
//
//	if (point.x > 2 || point.y >= col - 1){
//		return;
//	}
//
//	if (puzzle[point.x][point.y] == 0
//		&& puzzle[point.x][point.y + 1] == 0)  //两个横向都为0 
//	{
//		puzzle[point.x][point.y] = puzzle[point.x][point.y + 1] = 1;  //横向置1
//		bool isChangeLine = needChangeLine();
//		setPoint();
//		if (isChangeLine && point.x == 3 && point.y == 0){
//			result[nowRound] = result[nowRound] + 1;
//			landTurnBack(tempX, tempY);
//			return;
//		}
//		cover();
//		landTurnBack(tempX, tempY);
//	}
//	else if (puzzle[point.x][point.y] != 0){ //如果当前格为1
//		point.y++;
//		pushLand();
//		posBack(tempX, tempY);
//	}
//}
//
//
//
//void pushVertical(){
//	int tempX = point.x;
//	int tempY = point.y;
//
//
//	if (point.x > 1 || point.y > col){
//		return;
//	}
//
//	if (puzzle[point.x][point.y] == 0
//		&& puzzle[point.x + 1][point.y] == 0)  //两个竖向都为0 
//	{
//		puzzle[point.x][point.y] = puzzle[point.x + 1][point.y] = 1;  //竖向置1
//		bool isChangeLine = needChangeLine();
//		setPoint();
//		if (isChangeLine && point.x == 2 && point.y == 0 && isLastLineCovered()){
//			result[nowRound] = result[nowRound] + 1;
//			verticalTurnBack(tempX, tempY);
//			return;
//		}
//
//
//		cover();
//		verticalTurnBack(tempX, tempY);
//	}
//	else if (puzzle[point.x][point.y] != 0){ //如果当前格为1
//		point.y++;
//		pushVertical();
//		posBack(tempX, tempY);
//	}
//}
//
//
//void cover(){
//	pushLand();
//	pushVertical();
//}
//
//
//
//int main(){
//
//	//result清零
//	for (int i = 0; i < 10000; i++)
//		result[i] = 0;
//
//	while (cin >> col, col != -1){
//
//		if (col % 2 == 1){
//			result[nowRound] = 0;
//			nowRound++;
//			continue;
//		}
//
//		clearPuzzle();
//		point.x = point.y = 0;
//
//		cover();
//		nowRound++;
//	}
//
//	for (int i = 0; i < nowRound; i++)
//		cout << result[i] << endl;
//
//
//}




//完美覆盖
//
//描述
//一张普通的国际象棋棋盘，它被分成 8 乘 8 (8 行 8 列) 的 64 个方格。
//设有形状一样的多米诺牌，每张牌恰好覆盖棋盘上相邻的两个方格，
//即一张多米诺牌是一张 1 行 2 列或者 2 行 1 列的牌。
//那么，是否能够把 32 张多米诺牌摆放到棋盘上，使得任何两张多米诺牌均不重叠，
//每张多米诺牌覆盖两个方格，并且棋盘上所有的方格都被覆盖住？
//我们把这样一种排列称为棋盘被多米诺牌完美覆盖。
//这是一个简单的排列问题，同学们能够很快构造出许多不同的完美覆盖。
//但是，计算不同的完美覆盖的总数就不是一件容易的事情了。
//不过，同学们 发挥自己的聪明才智，还是有可能做到的。
//现在我们通过计算机编程对 3 乘 n 棋盘的不同的完美覆盖的总数进行计算。
//
//任务
//对 3 乘 n 棋盘的不同的完美覆盖的总数进行计算。
//
//输入
//一次输入可能包含多行，每一行分别给出不同的 n 值(即 3 乘 n 棋盘的列数)。当输入 - 1 的时候结束。
//n 的值最大不超过 30.
//
//输出
//针对每一行的 n 值，输出 3 乘 n 棋盘的不同的完美覆盖的总数。
//
//样例输入
//2
//8
//12
//- 1
//
//样例输出
//3
//153
//2131