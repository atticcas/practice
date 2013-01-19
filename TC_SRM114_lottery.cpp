nclude<string>
#include<vector>
#include<sstream>
#include<iostream>

using namespace std; 

struct ticket {
	string name;
	int choices;
	int blanks;
	bool sorted;
	bool unique;
	long double valid;
};

int stoi (string s){
	int ii = 0;
	for (int i = s.size()-1; i>=0; i--){
		ii =ii * 10 + (s[i] -'0');	
	}
	return ii;
};

ticket stringToT(string input){
	int pos = input.find(':');
	ticket token;
	token.name = input.substr(0, pos);
	input = input.substr(pos+2);
	pos = input.find(' ');
	istringstream ist(input);
	char cSorted, cUnique;
	ist >> token.choices >>token.blanks>> cSorted>> cUnique;
	//cout <<'original: ' <<input<<'\n';
	//cout << token.choices << ' ' <<token.blanks <<' ' << "sort/unique ";
	//if (token.sorted) cout << 'T'; else cout <<  'F';
	//if (token.unique) cout << 'T'; else cout << 'F';
	token.sorted = (cSorted == 'T' ? true : false);
	token.unique = (cUnique == 'T' ? true : false);
	return token;
};
long double power(int a, int b){
	long double result = 1;
	for (int i=1; i<=b; i++) result *= a;
	return result;
};
long double fact(int a){
	long double result = 1;
	for(int i=1; i<=a; i++){
	result *= i;
	}
	return result;
};
long double nchoosek (int n, int k){
	return fact(n)/(fact(k)*fact(n-k));

};
long double calculation(ticket& token){
	long double total = 0;
	//int i = token.blanks;
	total = power(token.choices, token.blanks);
	
	if(token.unique && token.sorted) 
		return nchoosek(token.choices, token.blanks);
	else if (!token.sorted && token.unique)
		return nchoosek(token.choices, token.blanks) * fact (token.blanks);
	else if (token.sorted && !token.unique)
		return nchoosek(token.choices + token.blanks -1, token.blanks);
	else if(!token.unique && !token.sorted) 
		return total; 
		
};

class Lottery{
public: 
	vector<string> sortByOdds(vector<string> rules){
		ticket a[50];
		int count = 0;
		vector<string> result;
		vector<pair<long double, string> > ned;
	//cout << "input size: "<<rules.size()<<'\n';
		for (int i=0; i <rules.size(); i++ ){
		//cout << rules[i] << ' ' << i << '\n'; 
			(a[i]) = stringToT(rules[i]);
			(a[i]).valid = calculation((a[i]));
			ned.push_back( make_pair(a[i].valid, a[i].name));
		cerr << "Goupe name: " << a[i].name <<" possibles: "<< (a[i]).valid <<endl;
		}
		sort(ned.begin(), ned.end());
		for (int k =0; k < ned.size(); k++){
		result.push_back(ned[k].second);
		}
		return result;
	}


};
