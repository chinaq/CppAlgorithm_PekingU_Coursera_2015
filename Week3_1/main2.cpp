//#include<iostream>
//using namespace std;
//
//
//struct Value{
//	int pos0, pos1, pos2;
//}value;
//
//int result[100];
//int nowRound = 0;
//int col = 0;
//
//
//
//Value allLand(){
//	Value nextValue;
//	nextValue.pos0 = 1;
//	nextValue.pos1 = 1;
//	nextValue.pos2 = 1;
//	return nextValue;
//}
//
//
//Value LandVertical(){
//	Value nextValue;
//	nextValue.pos0 = 1;
//	nextValue.pos1 = 0;
//	nextValue.pos2 = 0;
//	return nextValue;
//}
//
//Value VerticalLand(){
//	Value nextValue;
//	nextValue.pos0 = 0;
//	nextValue.pos1 = 0;
//	nextValue.pos2 = 1;
//	return nextValue;
//}
//
//Value LandLandFromPos1(){
//	Value nextValue;
//	nextValue.pos0 = 0;
//	nextValue.pos1 = 1;
//	nextValue.pos2 = 1;
//	return nextValue;
//}
//
//Value LandLandFromPos0(){
//	Value nextValue;
//	nextValue.pos0 = 1;
//	nextValue.pos1 = 1;
//	nextValue.pos2 = 0;
//	return nextValue;
//}
//
//Value LandPos2(){
//	Value nextValue;
//	nextValue.pos0 = 0;
//	nextValue.pos1 = 0;
//	nextValue.pos2 = 1;
//	return nextValue;
//}
//
//Value LandPos0(){
//	Value nextValue;
//	nextValue.pos0 = 1;
//	nextValue.pos1 = 0;
//	nextValue.pos2 = 0;
//	return nextValue;
//}
//
//Value VerticalPos0(){
//	Value nextValue;
//	nextValue.pos0 = 0;
//	nextValue.pos1 = 0;
//	nextValue.pos2 = 0;
//	return nextValue;
//}
//
//Value VerticalPos1(){
//	Value nextValue;
//	nextValue.pos0 = 0;
//	nextValue.pos1 = 0;
//	nextValue.pos2 = 0;
//	return nextValue;
//}
//
//
//Value pushNothing(){
//	Value nextValue;
//	nextValue.pos0 = 0;
//	nextValue.pos1 = 0;
//	nextValue.pos2 = 0;
//	return nextValue;
//}
//
//void cover(int pos, Value value){
//
//	if (pos == col - 1){
//		result[nowRound]++;
//		return;
//	}
//
//	Value nextValue;
//	//pos++;
//	
//	if (value.pos0 == 0 && value.pos1 == 0 && value.pos2 == 0){
//		nextValue = allLand();
//		cover(pos + 1, nextValue);
//
//		nextValue = LandVertical();
//		cover(pos + 1, nextValue);
//
//		nextValue = VerticalLand();
//		cover(pos + 1, nextValue);
//
//	}
//	else if (value.pos0 == 1 && value.pos1 == 0 && value.pos2 == 0){
//		nextValue = LandLandFromPos1();
//		cover(pos + 1, nextValue);
//		
//		nextValue = VerticalPos1();
//		cover(pos + 1, nextValue);
//	}
//	else if (value.pos0 == 0 && value.pos1 == 0 && value.pos2 == 1){
//		nextValue = LandLandFromPos0();
//		cover(pos + 1, nextValue);
//
//		nextValue = VerticalPos0();
//		cover(pos + 1, nextValue);
//	}
//	else if (value.pos0 == 1 && value.pos1 == 1 && value.pos2 == 0){
//		nextValue = LandPos2();
//		cover(pos + 1, nextValue);
//	}
//	else if (value.pos0 == 0 && value.pos1 == 1 && value.pos2 == 1){
//		nextValue = LandPos0();
//		cover(pos + 1, nextValue);
//	}
//	else if (value.pos0 == 1 && value.pos1 == 1 && value.pos2 == 1){
//		nextValue = pushNothing();
//		cover(pos + 1, nextValue);
//	}
//
//
//
//}
//
//
//
//int main(){
//	//result«Â¡„
//	for (int i = 0; i < 10000; i++)
//		result[i] = 0;
//	
//	while (cin >> col, col != -1){	
//		int pos = 0;
//
//		if (col % 2 == 1){
//			result[nowRound] = 0;
//			nowRound++;
//			continue;
//		}
//		
//		cover(pos, value);
//		nowRound++;
//	}
//	
//	for (int i = 0; i < nowRound; i++)
//		cout << result[i] << endl;	
//	
//}