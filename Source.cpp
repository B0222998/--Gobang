#include <iostream>
#include <string>
using namespace std;
int main() {
	char checkerboard[21][43];
	int round = 1;
	int win = 0;
	for (int i = 0; i < 21; i++) {
		for (int j = 0; j < 43; j++) {
			checkerboard[i][j] = { ' ' };
		}
	}
	for (int i = 1; i < 21; i++) {

		for (int j = 1; j < 43; j++) {

			if ((j == 5 || j == 9 || j == 13 || j == 17 || j == 21 || j == 25 || j == 29 || j == 33 || j == 37 || j == 41) && (i == 3 || i == 5 || i == 7 || i == 9 || i == 11 || i == 13 || i == 15 || i == 17 || i == 19)) {

				checkerboard[i][j] = '|';

			}

			if (!(j == 0 || j == 1 || j == 2 || j == 3 || j == 4 || j == 5 || j == 9 || j == 13 || j == 17 || j == 21 || j == 25 || j == 29 || j == 33 || j == 37 || j == 41 || j == 42) && (i == 2 || i == 4 || i == 6 || i == 8 || i == 10 || i == 12 || i == 14 || i == 16 || i == 18 || i == 20)) {

				checkerboard[i][j] = '-';

			}

		}
	}
	for (int i = 0; i < 21; i++) {
		for (int j = 0; j < 43; j++) {
			cout << checkerboard[i][j];
		}
		cout << endl;
	}
	int x, y;
	while (win != 1) {
		cout << "請輸入要落子的位置(X Y): " << endl;
		cout << "行:";
		cin >> x;
		cout << "列:";
		cin >> y;
		if (checkerboard[y * 2][x * 4 + 1] == 'X' || checkerboard[y * 2][x * 4 + 1] == 'O') {
			cout << "請勿輸入有棋子的位置" << endl;
			continue;
		}
		else if (x > 10 || y > 10) {
			cout << "請勿輸入超過10以上的數字, 請重新輸入喔0.0" << endl;
			continue;
		}
		else if (x < 1 || y < 1) {
			cout << "請勿輸入低於1以下的數字, 請重新輸入喔0.0" << endl;
			continue;
		}
		//判斷黑白落子
		if (round % 2 == 1)checkerboard[y * 2][x * 4 + 1] = 'X';
		else if (round % 2 == 0)checkerboard[y * 2][x * 4 + 1] = 'O';
		round++;
		//判斷是否勝利
		for (int i = 2; i <= 20; i = i + 2) {
			for (int j = 5; j <= 41; j = j + 4) {

				int connect1 = 1;
				int connect2 = 1;
				int connect3 = 1;
				int connect4 = 1;
				for (int a = 1; a <= 4; a++) {
					if ((checkerboard[i][j] == checkerboard[i][j + a * 4] && checkerboard[i][j] == 'X'))  connect1++;
				}
				if (connect1 == 5)win++;
				for (int a = 1; a <= 4; a++) {
					if ((checkerboard[i][j] == checkerboard[i + a * 2][j] && checkerboard[i][j] == 'X'))  connect2++;
				}
				if (connect2 == 5)win++;
				for (int a = 1; a <= 4; a++) {
					if ((checkerboard[i][j] == checkerboard[i + a * 2][j + a * 4] && checkerboard[i][j] == 'X'))  connect3++;
				}
				if (connect3 == 5)win++;
				for (int a = 1; a <= 4; a++) {
					if ((checkerboard[i][j] == checkerboard[i + a * 2][j - a * 4] && checkerboard[i][j] == 'X'))  connect4++;
				}
				if (connect4 == 5)win++;
			}
		}
		for (int i = 2; i <= 20; i = i + 2) {
			for (int j = 5; j <= 41; j = j + 4) {

				int connect1 = 1;
				int connect2 = 1;
				int connect3 = 1;
				int connect4 = 1;
				for (int a = 1; a <= 4; a++) {
					if ((checkerboard[i][j] == checkerboard[i][j + a * 4] && checkerboard[i][j] == 'O'))  connect1++;
				}
				if (connect1 == 5)win++;
				for (int a = 1; a <= 4; a++) {
					if ((checkerboard[i][j] == checkerboard[i + a * 2][j] && checkerboard[i][j] == 'O'))  connect2++;
				}
				if (connect2 == 5)win++;
				for (int a = 1; a <= 4; a++) {
					if ((checkerboard[i][j] == checkerboard[i + a * 2][j + a * 4] && checkerboard[i][j] == 'O'))  connect3++;
				}
				if (connect3 == 5)win++;
				for (int a = 1; a <= 4; a++) {
					if ((checkerboard[i][j] == checkerboard[i + a * 2][j - a * 4] && checkerboard[i][j] == 'O'))  connect4++;
				}
				if (connect4 == 5)win++;
			}
		}
		system("cls");
		for (int i = 0; i < 21; i++) {
			for (int j = 0; j < 43; j++) {
				cout << checkerboard[i][j];
			}
			cout << endl;
		}
	}
	if (round % 2 == 0 && win == 1) {
		cout << "OOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO" << endl;
		cout << "OOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO" << endl;
		cout << "OOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO" << endl;
		cout << "OOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO" << endl;
		cout << "OOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOkxddkOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO" << endl;
		cout << "OOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOkxocldkOOO0OOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOkxddddldkOOOOOOOOOOOOOOOO" << endl;
		cout << "OOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOkxdlcldkOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOkxdddddc;oOOOOOOOOOOOOOOOO" << endl;
		cout << "OOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOkxl;:cldkOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOkxddddddc;:xOOOOOOOOOOOOOOO" << endl;
		cout << "OOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOkxo:;:clokOOOOOOOOOOOOOOOOOOOOOOOOOOOOOkxxdddodddc;;oO0OOOOOOOOOOOOO" << endl;
		cout << "OOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOkxddo:;;cloxkOOOOOOOOOOOOOOOOOOOOOOOOOkxdddddoloddoc;ckOOOOOOOOOOOOOO" << endl;
		cout << "OOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOkxdooolllloddxxxxxxxxkkkkkkOOOOOOOOkxxdooddolllllodo::dOOOOOOOOOOOOOO" << endl;
		cout << "OOOOOOOOOOOOOOOOOOOOOOOOOOOOOOkxdddxkkkxddddddddddddddddddddxxxxxxddoloodollcllloddc:oOOOOOOOOOOOOOO" << endl;
		cout << "OOOOOOOOOOOOOOOOOOOOOOOOOOOOkxxxkkkkkkkkxddddddddddddddddddddddoddolloddoc:;;;;:lodc:dOOOOOOOOOOOOOO" << endl;
		cout << "OOOOOOOOOOOOOOOOOOOOOOOOOOOOkkkkkkkkkkkkxdddddddddddddddddddddddol:codddol:;;,;:loo::xOOOOOOOOOOOOOO" << endl;
		cout << "OOOOOOOOOOOOOOOOOOOOOOOOOkkkkkkkkkOkkkxddooodddddddddddddddddddddollddddlc;,;;:lodl:lOOOOOOOOOOOOOOO" << endl;
		cout << "OOOOOOOOOOOOOOOOOOOOOkkkkkkkkOkkkkkkkkxdoloddddddddddddddddddddddddooddl:;,,;coddoc:dOOOOOOOOOOOOOOO" << endl;
		cout << "OOOOOOOOOOOOOOOOOOOkkkkkkkkkkkkddkkkkxddooddddxxkxxxxddddddddddddddddolc:;:clodddolcxOOOOOOOOOOOOOOO" << endl;
		cout << "OOOOOOOOOOOOOOOOOOkkkkkkkkkxxdoloxkxxddoodddxkkkkkkkkkxddddddddddddddddddoodddddoddodkOOOOOOOOOOOOOO" << endl;
		cout << "OOOOOOOOOOOOOOOOkkO000OOko;''':llxxddddooddxkkkkkkkkkxdddddddddddddddddddddddddoodddddkOOOOOOOOOOOOO" << endl;
		cout << "OOOOOOOOOOOOOOOOO0XNNXX0xl,...';oddddddddddxkkkkkkkkkxxddddddddddddddddddddddddooooodddkOOOOOOOOOOOO" << endl;
		cout << "OOOOOOOOOOOOOOOO0XNNNXKkkk'  .'lxdddddxkkxdxkkkkdcc:,;:lddddddddddddddddddddddddollddddxOOOOOOOOOOOO" << endl;
		cout << "OOOOOOOOOOOOO0KXNNNNXK0xodc..;dkxxxxxkO0kdooddl;:lol,. .'coddddddddddddddddddddddoodddddkOOOOOOOOOOO" << endl;
		cout << "OOOOOOOOOOOO0KXNNNNNX0kkxddxxOkxxkO0000Oxool:'.;0k;'..  ..:dddkOOOOO0OxxxxkOkxxdddddddddxOOOOOOOOOOO" << endl;
		cout << "OOOOOOOOOOOO0XNNNNNNX0OkOKK00Okk000000Okdxddc'.;Okl,....;coddOXNNNNNNNXXXKKXXX0xdddddddddkOOOOOOOOOO" << endl;
		cout << "OOOOOOOOOOO0KXNNNNNNNXK000000000000000OxxOOxdoc:lddl:::loddk0XNNNXXNNNNNWWNNNNN0xddddddddkOOOOOOOOOO" << endl;
		cout << "OOOOOOOOOOOKXNNNNNNNKOxddddxkO000000000OO00kdddddddddddxxk0XNNNNNNWWWNNNNNWNNNNXkddddddddkOOOOOOOOOO" << endl;
		cout << "OOOOOOOOOO0KXXXXXXXd,....'''.';ok00KK00000OOkkkkkkkkkkOKXNNNWNNNNNNNNNWNNNNNNNWNOxdddddddxOOOOOOOOOO" << endl;
		cout << "OOOOOOOOOOKXXXKKXWO.            :KNNXKK00O000XNNNNNNNNNNNNNNNNNNNNNNNNNNNWNNNNWNOdddddddddkO0OOOOOOO" << endl;
		cout << "OOOOOOOOO0KKKKKXNWXl..         .oKWWNXKKK0OO0XNNNNNNWNNNNNNNNNNNNNNNNNWWWNNWNNNNOdddddddddxkOOOOOOOO" << endl;
		cout << "OOOOOOOOO0KXKKKXNNKc..    ....,okKWNNNXKK00O0XNNNNNNNNWWNNNNNNNNNNNNWWWWWNNWWNNN0kddxddddxdxOOOOOOOO" << endl;
		cout << "OOOOOOOOO0XXXXKXNKxo:..   ..;cokKNNNNNNXOOO0KXXNNNNNNNNNNNNNNNNNWNNNNNXXXXXXXXXXKkdddddddddxOOOOOOOO" << endl;
		cout << "OOOOOOOOOKXXXXKKXKxool:,,;:clddxKNNNNXK0OOOOKXXXXXXXNNNNNNNNNNNNXXKKKKKKKKKKKK0OxxxddddddddxkOOOOOOO" << endl;
		cout << "OOOOOOOO00KXXXXXXXKxlccccllllodxkKXXXKOOOOO00KKKXXXXXXXNNNNNXKKKKKKKKKKKKKKKKK0xddddxddxxddxkOOOOOOO" << endl;
		cout << "OOOOOOOOO0KXXXXXXXXOc'....',;:ldxOOOO0OOOOOOO0KKKKXKKKKXXXKKKKKKKKK0000000KK00Oxddddddddddxxk0OOOOOO" << endl;
		cout << "OOOOOOOOOOKXXXXXXXXOdc;,''....',:ldxxdlclllllx00KKKKKKKKKKKKKK0000000000KKK0OkxdddxddddddddxkO0OOOOO" << endl;
		cout << "OOOOOOOOOO0XXXXXXXXK0kxolc:cccc:,,,;:::clodkOO000KKKKKKKKKKK0000OOO0000KKKKKOxxxddxxddooodddxk00OOOO" << endl;
		cout << "OOOOOOOOOO00XXXXXXKK00OOkkkkOOOkxxxkOOOOOOOO00000KKKKKKKKKK00O000000KKKKKKK0OxddxxddoloodxddxkOOOOOO" << endl;
		cout << "OOOOOOOOOOO0KKKKKK000OOOOO00OO000O00OOOO00000000KKKKKKKK00000OO000KKKKKKK0OkxdddxdollloxxdxdxkOOOOOO" << endl;
		cout << "OOOOOOOOOOOO0OO0000OOOOOOOO00OO0OOOOOOO0000KKKKKKKKKKK0000O00OO000KKKKKK0kxdxddddollodddxddxxOO0OOOO" << endl;
		cout << "OOOOOOOOOOOOOOOOOOO00OO0OOOO0OOOOOO000000KKKKKKKK000000OOOOOO0000KKKKKKKOxxxxddolllloddxddxkOOO0OOOO" << endl;
		cout << "OOOOOOOOOOOOOOOOkkkOOOO00OOOOOO0OOO00000KKKKKKKK000OO0OOOO000000KKKKKK00OkkxdolllllloddxddxOO000OOOO" << endl;
		cout << "OOOOOOOOOOOOOOOOOkkxxkOO00OOOOO0OOOO000000000000000OOOO0OO000000000KKKK0OkxdolllllloddxxxkOO00OOOOOO" << endl;
		cout << "OOOOOOOOOOOOOOOOOkkxdodkOOOO0OOOO000OO00OO000OO00OOO00OOkO00000K00KKKKK00OOxdddlllodxxkOOOOO0OkxkOOO" << endl;
		cout << "OOOOOOOOOOOOOOO0OOkkkkdoodxkOOOOOO0OOOOO0OOOOOOkkkkkkxkkOO0000KKKKKKKKKKKKOxddllodxxkOOOOO0OOOkxkOOO" << endl;
		cout << "OOOOOOOOOOOOOOOOOOOkkkkxxdoooddddxdxxdddddddooolloodxkkOO0000000KKKKKKKK0kxddooxxOOOO0OOOOO0OkddxOOO" << endl;
		cout << "OOOOOOOOOOOOOOOOO00OkkkkkkxxdollllllllllllllloooxxkkkkkOO0000000000000K0kxxxxkOOO0000000OO00OxddxOOO" << endl;
		cout << "OOOOOOOOOOOOOOO0OO0OOOOkkkkkkdollllllllllloddxkkkkkkOOOO00OOOO0OOOO0000OOOOO000000KKK0K00OOOkxxdxkOO" << endl;
		cout << "OOOOOOOOOOOOOOO0OOOOOOOOOkkkkkxoodolllllloxkkkkkOOOOO0OO0OO000OOOOOOOOOOO00000KKKKKKKKK00OOOkxddxkOO" << endl;
		cout << "OOOOOOOOOOOOOOOOOOOOOOOOOOOOkkkkkkxollloddkkkOOOO0000OOOOOOOOOOOO00OOOOOO000KKKKKKKKKKK00OOOkxdddxO0" << endl;
		cout << "OOOOOOOOO0000000OOOOOOO00OOOkkkkkkkdllldxkkOOO00O000OOOO0OOOOOOOO00OOOOO000KKKKKKKKKKKK00OOkxddddxOO" << endl;
		cout << "黑棋勝" << endl;
	}
	else if (round % 2 == 1 && win == 1) {
		cout << "OOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO" << endl;
		cout << "OOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO" << endl;
		cout << "OOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO" << endl;
		cout << "OOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO" << endl;
		cout << "OOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOkxddkOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO" << endl;
		cout << "OOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOkxocldkOOO0OOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOkxddddldkOOOOOOOOOOOOOOOO" << endl;
		cout << "OOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOkxdlcldkOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOkxdddddc;oOOOOOOOOOOOOOOOO" << endl;
		cout << "OOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOkxl;:cldkOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOkxddddddc;:xOOOOOOOOOOOOOOO" << endl;
		cout << "OOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOkxo:;:clokOOOOOOOOOOOOOOOOOOOOOOOOOOOOOkxxdddodddc;;oO0OOOOOOOOOOOOO" << endl;
		cout << "OOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOkxddo:;;cloxkOOOOOOOOOOOOOOOOOOOOOOOOOkxdddddoloddoc;ckOOOOOOOOOOOOOO" << endl;
		cout << "OOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOkxdooolllloddxxxxxxxxkkkkkkOOOOOOOOkxxdooddolllllodo::dOOOOOOOOOOOOOO" << endl;
		cout << "OOOOOOOOOOOOOOOOOOOOOOOOOOOOOOkxdddxkkkxddddddddddddddddddddxxxxxxddoloodollcllloddc:oOOOOOOOOOOOOOO" << endl;
		cout << "OOOOOOOOOOOOOOOOOOOOOOOOOOOOkxxxkkkkkkkkxddddddddddddddddddddddoddolloddoc:;;;;:lodc:dOOOOOOOOOOOOOO" << endl;
		cout << "OOOOOOOOOOOOOOOOOOOOOOOOOOOOkkkkkkkkkkkkxdddddddddddddddddddddddol:codddol:;;,;:loo::xOOOOOOOOOOOOOO" << endl;
		cout << "OOOOOOOOOOOOOOOOOOOOOOOOOkkkkkkkkkOkkkxddooodddddddddddddddddddddollddddlc;,;;:lodl:lOOOOOOOOOOOOOOO" << endl;
		cout << "OOOOOOOOOOOOOOOOOOOOOkkkkkkkkOkkkkkkkkxdoloddddddddddddddddddddddddooddl:;,,;coddoc:dOOOOOOOOOOOOOOO" << endl;
		cout << "OOOOOOOOOOOOOOOOOOOkkkkkkkkkkkkddkkkkxddooddddxxkxxxxddddddddddddddddolc:;:clodddolcxOOOOOOOOOOOOOOO" << endl;
		cout << "OOOOOOOOOOOOOOOOOOkkkkkkkkkxxdoloxkxxddoodddxkkkkkkkkkxddddddddddddddddddoodddddoddodkOOOOOOOOOOOOOO" << endl;
		cout << "OOOOOOOOOOOOOOOOkkO000OOko;''':llxxddddooddxkkkkkkkkkxdddddddddddddddddddddddddoodddddkOOOOOOOOOOOOO" << endl;
		cout << "OOOOOOOOOOOOOOOOO0XNNXX0xl,...';oddddddddddxkkkkkkkkkxxddddddddddddddddddddddddooooodddkOOOOOOOOOOOO" << endl;
		cout << "OOOOOOOOOOOOOOOO0XNNNXKkkk'  .'lxdddddxkkxdxkkkkdcc:,;:lddddddddddddddddddddddddollddddxOOOOOOOOOOOO" << endl;
		cout << "OOOOOOOOOOOOO0KXNNNNXK0xodc..;dkxxxxxkO0kdooddl;:lol,. .'coddddddddddddddddddddddoodddddkOOOOOOOOOOO" << endl;
		cout << "OOOOOOOOOOOO0KXNNNNNX0kkxddxxOkxxkO0000Oxool:'.;0k;'..  ..:dddkOOOOO0OxxxxkOkxxdddddddddxOOOOOOOOOOO" << endl;
		cout << "OOOOOOOOOOOO0XNNNNNNX0OkOKK00Okk000000Okdxddc'.;Okl,....;coddOXNNNNNNNXXXKKXXX0xdddddddddkOOOOOOOOOO" << endl;
		cout << "OOOOOOOOOOO0KXNNNNNNNXK000000000000000OxxOOxdoc:lddl:::loddk0XNNNXXNNNNNWWNNNNN0xddddddddkOOOOOOOOOO" << endl;
		cout << "OOOOOOOOOOOKXNNNNNNNKOxddddxkO000000000OO00kdddddddddddxxk0XNNNNNNWWWNNNNNWNNNNXkddddddddkOOOOOOOOOO" << endl;
		cout << "OOOOOOOOOO0KXXXXXXXd,....'''.';ok00KK00000OOkkkkkkkkkkOKXNNNWNNNNNNNNNWNNNNNNNWNOxdddddddxOOOOOOOOOO" << endl;
		cout << "OOOOOOOOOOKXXXKKXWO.            :KNNXKK00O000XNNNNNNNNNNNNNNNNNNNNNNNNNNNWNNNNWNOdddddddddkO0OOOOOOO" << endl;
		cout << "OOOOOOOOO0KKKKKXNWXl..         .oKWWNXKKK0OO0XNNNNNNWNNNNNNNNNNNNNNNNNWWWNNWNNNNOdddddddddxkOOOOOOOO" << endl;
		cout << "OOOOOOOOO0KXKKKXNNKc..    ....,okKWNNNXKK00O0XNNNNNNNNWWNNNNNNNNNNNNWWWWWNNWWNNN0kddxddddxdxOOOOOOOO" << endl;
		cout << "OOOOOOOOO0XXXXKXNKxo:..   ..;cokKNNNNNNXOOO0KXXNNNNNNNNNNNNNNNNNWNNNNNXXXXXXXXXXKkdddddddddxOOOOOOOO" << endl;
		cout << "OOOOOOOOOKXXXXKKXKxool:,,;:clddxKNNNNXK0OOOOKXXXXXXXNNNNNNNNNNNNXXKKKKKKKKKKKK0OxxxddddddddxkOOOOOOO" << endl;
		cout << "OOOOOOOO00KXXXXXXXKxlccccllllodxkKXXXKOOOOO00KKKXXXXXXXNNNNNXKKKKKKKKKKKKKKKKK0xddddxddxxddxkOOOOOOO" << endl;
		cout << "OOOOOOOOO0KXXXXXXXXOc'....',;:ldxOOOO0OOOOOOO0KKKKXKKKKXXXKKKKKKKKK0000000KK00Oxddddddddddxxk0OOOOOO" << endl;
		cout << "OOOOOOOOOOKXXXXXXXXOdc;,''....',:ldxxdlclllllx00KKKKKKKKKKKKKK0000000000KKK0OkxdddxddddddddxkO0OOOOO" << endl;
		cout << "OOOOOOOOOO0XXXXXXXXK0kxolc:cccc:,,,;:::clodkOO000KKKKKKKKKKK0000OOO0000KKKKKOxxxddxxddooodddxk00OOOO" << endl;
		cout << "OOOOOOOOOO00XXXXXXKK00OOkkkkOOOkxxxkOOOOOOOO00000KKKKKKKKKK00O000000KKKKKKK0OxddxxddoloodxddxkOOOOOO" << endl;
		cout << "OOOOOOOOOOO0KKKKKK000OOOOO00OO000O00OOOO00000000KKKKKKKK00000OO000KKKKKKK0OkxdddxdollloxxdxdxkOOOOOO" << endl;
		cout << "OOOOOOOOOOOO0OO0000OOOOOOOO00OO0OOOOOOO0000KKKKKKKKKKK0000O00OO000KKKKKK0kxdxddddollodddxddxxOO0OOOO" << endl;
		cout << "OOOOOOOOOOOOOOOOOOO00OO0OOOO0OOOOOO000000KKKKKKKK000000OOOOOO0000KKKKKKKOxxxxddolllloddxddxkOOO0OOOO" << endl;
		cout << "OOOOOOOOOOOOOOOOkkkOOOO00OOOOOO0OOO00000KKKKKKKK000OO0OOOO000000KKKKKK00OkkxdolllllloddxddxOO000OOOO" << endl;
		cout << "OOOOOOOOOOOOOOOOOkkxxkOO00OOOOO0OOOO000000000000000OOOO0OO000000000KKKK0OkxdolllllloddxxxkOO00OOOOOO" << endl;
		cout << "OOOOOOOOOOOOOOOOOkkxdodkOOOO0OOOO000OO00OO000OO00OOO00OOkO00000K00KKKKK00OOxdddlllodxxkOOOOO0OkxkOOO" << endl;
		cout << "OOOOOOOOOOOOOOO0OOkkkkdoodxkOOOOOO0OOOOO0OOOOOOkkkkkkxkkOO0000KKKKKKKKKKKKOxddllodxxkOOOOO0OOOkxkOOO" << endl;
		cout << "OOOOOOOOOOOOOOOOOOOkkkkxxdoooddddxdxxdddddddooolloodxkkOO0000000KKKKKKKK0kxddooxxOOOO0OOOOO0OkddxOOO" << endl;
		cout << "OOOOOOOOOOOOOOOOO00OkkkkkkxxdollllllllllllllloooxxkkkkkOO0000000000000K0kxxxxkOOO0000000OO00OxddxOOO" << endl;
		cout << "OOOOOOOOOOOOOOO0OO0OOOOkkkkkkdollllllllllloddxkkkkkkOOOO00OOOO0OOOO0000OOOOO000000KKK0K00OOOkxxdxkOO" << endl;
		cout << "OOOOOOOOOOOOOOO0OOOOOOOOOkkkkkxoodolllllloxkkkkkOOOOO0OO0OO000OOOOOOOOOOO00000KKKKKKKKK00OOOkxddxkOO" << endl;
		cout << "OOOOOOOOOOOOOOOOOOOOOOOOOOOOkkkkkkxollloddkkkOOOO0000OOOOOOOOOOOO00OOOOOO000KKKKKKKKKKK00OOOkxdddxO0" << endl;
		cout << "OOOOOOOOO0000000OOOOOOO00OOOkkkkkkkdllldxkkOOO00O000OOOO0OOOOOOOO00OOOOO000KKKKKKKKKKKK00OOkxddddxOO" << endl;
		cout << "白棋勝" << endl;
	}

}