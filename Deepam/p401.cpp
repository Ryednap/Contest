#include <bits/stdc++.h>
using namespace std;

char reverse(char inp){
	switch (inp){
		case 'E' : return '3';
					break;
		case '3' : return 'E';
					break;
		case 'S' : return '2';
					break;
		case '2' : return 'S';
					break;
		case '5' : return 'Z';
					break;
		case 'Z' : return '5';
					break;
		case 'A' : return 'A';
					break;
		case 'H' : return 'H';
					break;
		case 'I' : return 'I';
					break;
		case 'J' : return 'L';
					break;
		case 'L' : return 'J';
					break;
		case 'M' : return 'M';
					break;
		case 'O' : return 'O';
					break;
		case 'T' : return 'T';
					break;
		case 'U' : return 'U';
					break;
		case 'V' : return 'V';
					break;
		case 'W' : return 'W';
					break;
		case 'X' : return 'X';
					break;
		case 'Y' : return 'Y';
					break;
		case '1' : return '1';
					break;
		case '8' : return '8';
					break;
		default : return '0';
					break;
	}
}

bool checkMirror(string input){
	bool success = true;
	if(input.length() == 1 && input[0] != reverse(input[0])){
		return false;
	}
	for(int i=0; i<((int)input.length())/2; i++){
		//char s,e;
		if(input.length()%2 != 0 && reverse(input[(input.length()/2)]) != input[(input.length()/2)]){
			success = false;
			break;
		}
		if(reverse(input[i]) == '0' || reverse(input[(input.size() - 1) -i]) == '0'){
			success = false;
			break;
		}
		if(input[i] != reverse(input[(input.size() - 1) -i])){
			success = false;
			break;
		}
	}
	return success;
}

bool checkPal(string input){
	bool success = true;
	for(int i=0; i<((int)input.length())/2; i++){
		if(input[i] != input[(input.size() - 1) -i]){
			success = false;
			break;
		}
	}
	return success;
}

int main(){
	string check;
	cin >> check;
	while(!cin.eof()){
		if(checkMirror(check) && checkPal(check)){
			cout << check << " -- is a mirrored palindrome." << endl << endl;
		}else if(checkPal(check) && !checkMirror(check)){
			cout << check << " -- is a regular palindrome." << endl << endl;
		}else if(checkMirror(check)){
			cout << check << " -- is a mirrored string." << endl << endl;
		}else{
			cout << check << " -- is not a palindrome." << endl << endl;
		}
		cin >> check;
	}
	return 0;
}
