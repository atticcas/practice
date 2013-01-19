#include<vector>
#include<string>
#include<iostream>
using namespace std;

string Decode(const string mess, char input){
	int s = mess.size();
	if (s < 2) return "NONE"; 
	string Plaintext = mess;
	Plaintext[0] = input; 
	Plaintext[1] = mess[0] - Plaintext[0] + '0';
	for(int i = 2; i < s; i++) {
		Plaintext[i] = (mess[i-1]-Plaintext[i-1]-Plaintext[i-2]+'0'+'0');
		if (Plaintext[i]!='0' && Plaintext[i] != '1') return "NONE";
	}
	return Plaintext;
}

struct BinaryCode{
public:
	vector <string> decode(string messages) {
	vector <string> output;
	string p = Decode(messages, '0');
	output.push_back(p);
	p = Decode(messages, '1');
	output.push_back(p);
	return output;
	}
};
