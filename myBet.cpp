#include <iostream>
#include "stack.h"
#include <fstream>

using namespace std;

string postfix(string in);
string prefix(string pf);
bool isFunct(char &curr);
int comp(char x);

int main()
{
	ifstream input("infix.dat");
	if(input.is_open()){					// if file is open
	string in;
	while(getline(input, in)){				// read line by line
		string pf = postfix(in);			// convert to postfix first
		cout<< prefix(pf)<<endl;			// convert from postfix to infix
	}							// end of read
	input.close();
	}

    return 0;
}
/////////////////////////////////////////////////////////////////////

// parameter:	infix input from infix.dat
// output: 	returns string in postfix form
string postfix(string in){
	stack<char> bet;
	string result;

	for(int i = 0; i<in.length(); i++){
		char x = in[i];
			if(isdigit(x))
				result += x;
			else if(x == '(')
				bet.push('(');
			else if(x == ')'){
				while(bet.top()!='('){
					char y = bet.topAndPop();
					result += y;
				}
			bet.pop();
			}
			else if(isFunct(x)){
				while(!bet.isEmpty() && bet.top() != '(' && comp(in[i]) <= comp(bet.top())){
					char z = bet.topAndPop();
					result += z; 
				}
			bet.push(x);
			} 
	}
	while(!bet.isEmpty()){
		result += bet.top();
		bet.pop();
	} 
	return result;
}

// parameter:	postfix string after conversion
// output:	returns string in prefix form
string prefix(string pf){
	stack<string> temp;
	string pref;
	for(int i=0; i<pf.length(); i++){	
		if(isFunct(pf[i])){
			string a = temp.topAndPop();
			string b = temp.topAndPop();
			string c = pf[i]+ b+ a;
			temp.push(c);
		}
		else{
			temp.push(string(1, pf[i]));
		}
	}
	while(!temp.isEmpty()){
		pref += temp.topAndPop();	// build string to return
	}
	return pref;
}

bool isFunct(char &curr){
        if(curr == '+'|| curr == '-' || curr == '*' || curr == '/')	// from postfix.cpp
		return true;
        else
                return false;
}
int comp(char x){							// order of operation precedence s.t. comparable
	if(x == '*' || x == '/')
		return 2;
	else
		return 1;
}

