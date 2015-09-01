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
//	if (!needChangeLine()){ //������
//		point.y++;
//	}
//	else{                   //����
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
//		&& puzzle[point.x][point.y + 1] == 0)  //��������Ϊ0 
//	{
//		puzzle[point.x][point.y] = puzzle[point.x][point.y + 1] = 1;  //������1
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
//	else if (puzzle[point.x][point.y] != 0){ //�����ǰ��Ϊ1
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
//		&& puzzle[point.x + 1][point.y] == 0)  //��������Ϊ0 
//	{
//		puzzle[point.x][point.y] = puzzle[point.x + 1][point.y] = 1;  //������1
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
//	else if (puzzle[point.x][point.y] != 0){ //�����ǰ��Ϊ1
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
//	//result����
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




//��������
//
//����
//һ����ͨ�Ĺ����������̣������ֳ� 8 �� 8 (8 �� 8 ��) �� 64 ������
//������״һ���Ķ���ŵ�ƣ�ÿ����ǡ�ø������������ڵ���������
//��һ�Ŷ���ŵ����һ�� 1 �� 2 �л��� 2 �� 1 �е��ơ�
//��ô���Ƿ��ܹ��� 32 �Ŷ���ŵ�ưڷŵ������ϣ�ʹ���κ����Ŷ���ŵ�ƾ����ص���
//ÿ�Ŷ���ŵ�Ƹ����������񣬲������������еķ��񶼱�����ס��
//���ǰ�����һ�����г�Ϊ���̱�����ŵ���������ǡ�
//����һ���򵥵��������⣬ͬѧ���ܹ��ܿ칹�����಻ͬ���������ǡ�
//���ǣ����㲻ͬ���������ǵ������Ͳ���һ�����׵������ˡ�
//������ͬѧ�� �����Լ��Ĵ������ǣ������п��������ġ�
//��������ͨ���������̶� 3 �� n ���̵Ĳ�ͬ���������ǵ��������м��㡣
//
//����
//�� 3 �� n ���̵Ĳ�ͬ���������ǵ��������м��㡣
//
//����
//һ��������ܰ������У�ÿһ�зֱ������ͬ�� n ֵ(�� 3 �� n ���̵�����)�������� - 1 ��ʱ�������
//n ��ֵ��󲻳��� 30.
//
//���
//���ÿһ�е� n ֵ����� 3 �� n ���̵Ĳ�ͬ���������ǵ�������
//
//��������
//2
//8
//12
//- 1
//
//�������
//3
//153
//2131