#include<iostream>
using namespace std;

const int state0 = 0;   //
						//
						//

const int state1 = 1;   //
						///
						///

const int state2 = 2;   ///
						///
						//



int result[100];
int nowRound = 0;
int col = 0;


void cover(int pos, int state, int count){
	pos = pos + 2;

	if (state == state0){
		if (pos == col){
			result[nowRound] += count * 3;
			return;
		}
		cover(pos, state0, count * 3);
		cover(pos, state1, count * 1);
		cover(pos, state2, count * 1);
	}
	else if (state == state1){
		if (pos == col){
			result[nowRound] += count * 1;
			return;
		}
		cover(pos, state1, count * 1);
		cover(pos, state0, count * 1);
	}
	else if (state == state2){
		if (pos == col){
			result[nowRound] += count * 1;
			return;
		}
		cover(pos, state2, count * 1);
		cover(pos, state0, count * 1);
	}
}


int main(){
	//result«Â¡„
	for (int i = 0; i < 100; i++)
		result[i] = 0;

	while (cin >> col, col != -1){
		int pos = 0;

		if (col % 2 == 1){
			result[nowRound] = 0;
			nowRound++;
			continue;
		}
		else if (col == 0){
			result[nowRound] = 1;
			nowRound++;
			continue;
		}

		cover(pos, state0, 1);
		nowRound++;
	}

	for (int i = 0; i < nowRound; i++)
		cout << result[i] << endl;

}