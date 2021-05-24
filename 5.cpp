#include <iostream>
#include <vector>
#include <string>

using namespace std;


bool delim (char c) {
	return c == ' ';
}

bool is_op (char c) {
	return c=='+' || c=='-' || c=='*' || c=='/' || c=='%';
}

int priority (char op) {
	return
		op == '+' || op == '-' ? 1 :
		op == '*' || op == '/' || op == '%' ? 2 :
		-1;
}

void process_op (vector<int> & st, char op) {
	int r = st.back();  st.pop_back();
	int l = st.back();  st.pop_back();
	switch (op) {
		case '+':  st.push_back (l + r);  break;
		case '-':  st.push_back (l - r);  break;
		case '*':  st.push_back (l * r);  break;
		case '/':  st.push_back (l / r);  break;
		case '%':  st.push_back (l % r);  break;
	}
}

int calc (string & s) {
	vector<int> st;
	vector<char> op;
	for (size_t i=0; i<s.length(); ++i)
		if (!delim (s[i]))
			if (s[i] == '(')
				op.push_back ('(');
			else if (s[i] == ')') {
				while (op.back() != '(')
					process_op (st, op.back()),  op.pop_back();
				op.pop_back();
			}
			else if (is_op (s[i])) {
				char curop = s[i];
				while (!op.empty() && priority(op.back()) >= priority(s[i]))
					process_op (st, op.back()),  op.pop_back();
				op.push_back (curop);
			}
			else {
				string operand;
				while (i < s.length() && isalnum (s[i]))
					operand += s[i++];
				--i;
				if (isdigit (operand[0]))
					st.push_back (atoi (operand.c_str()));
				else
					st.push_back (operand[0]);
			}
	while (!op.empty())
		process_op (st, op.back()),  op.pop_back();
	return st.back();
}

int main()
{
	string line;
	getline(cin, line);
	cout << calc(line) << endl;
}
