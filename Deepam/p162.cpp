#include<bits/stdc++.h>
using namespace std;

int cardValue(string card){
    if(card[1] == 'A'){
        return 4;
    }else if(card[1] == 'K'){
        return 3;
    }else if(card[1] == 'Q'){
        return 2;
    }else if(card[1] == 'J'){
        return 1;
    }else{
        return 0;
    }
}

int main(){
    char end = ' ';
    while(true){
        int cardND = 26, cardD = 26;
        vector<string> nd, d, cp;
        for(int i=0; i<52; i++){
            string temp;
            cin >> temp;
            if(temp == "#"){
				end = '#';
				break;
			}
            if(i%2 == 0){
                nd.push_back(temp);
            }else{
                d.push_back(temp);
            }
        }
        if(end == '#'){
			break;
		}
        bool penalty = false;
        int p, turn = 0;
        while(1){
            
            if(!turn){
				if(nd.size() == 0){
					break;
				}
                if(penalty){
                    while(p--){
						if(nd.size() == 0){
							break;
						}
                        cp.push_back(nd.back());
                        if(cardValue(nd.back())){
                            p = cardValue(nd.back());
                            penalty = true;
                            nd.pop_back();
                            cardND--;
                            turn = (turn+1)%2;
                            break;
                        }
                        nd.pop_back();
                        cardND--;
                        if(!p){
                            for(int i=0; i<(int)cp.size(); i++){
                                d.insert(d.begin(), cp[i]);
                            }
                            cp.clear();
                            penalty = false;
                            turn = (turn+1)%2;
                        }
                    
                    }
                }else{
                    cp.push_back(nd.back());
                    turn = (turn+1)%2;
                    if(cardValue(nd.back())){
                        penalty = true;
                        p = cardValue(nd.back());
                    }
                    nd.pop_back();
                    cardND--;
                }
            }else{
				if(d.size() == 0){
					break;
				}
                if(penalty){
                    while(p--){
						if(d.size() == 0){
							break;
						}
                        cp.push_back(d.back());
                        if(cardValue(d.back())){
                            p = cardValue(d.back());
                            penalty = true;
                            d.pop_back();
                            cardD--;
                            turn = (turn+1)%2;
                            break;
                        }
                        d.pop_back();
                        cardD--;
                        if(!p){
                            for(int i=0; i<(int)cp.size(); i++){
                                nd.insert(nd.begin(), cp[i]);
                            }
                            cp.clear();
                            penalty = false;
                            turn = (turn+1)%2;
                        }
					
                    }
                }else{
                    cp.push_back(d.back());
                    turn = (turn+1)%2;
                    if(cardValue(d.back())){
                        penalty = true;
                        p = cardValue(d.back());
                    }
                    d.pop_back();
                    cardD--;
                }
            }  
        }
        if(nd.size()){
			cout << "2 "<< setw(2) << (int)nd.size() << endl;
		}else{
			cout << "1 "<< setw(2) << (int)d.size() << endl;
		}
    }
    return 0;
}

