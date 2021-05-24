#include <iostream>
#include <fstream>
#include <cstdlib>
#include <stack>
#include <string>
#include <algorithm>

using namespace std;

stack <string> split (string s, char simb){
stack <string> result;
string help = "";
for (int i = 0; i < s.size(); i ++){
if (s[i] != simb){
help += s[i];
} else {
result.push(help);
help = "";
}
}
result.push(help);
help = "";
return result;
}

int main()
{
ifstream finn("input.txt");
ofstream fout("output.txt");
string str;
string a = "+-*/";
stack <int> result;
int help = 0;
while (finn >> str){
if (result.size() < 2 && a.find(str) != -1){
fout << "ERROR";
return 0;
}
if (str == "+"){
help = result.top();
result.pop();
help += result.top();
result.pop();
result.push(help);
} else if (str == "-"){
int l = result.top();
result.pop();
help = result.top();
result.pop();
result.push(help - l);
} else if (str == "*"){
help = result.top();
result.pop();
help *= result.top();
result.pop();
result.push(help);
} else if (str == "/"){
int l = result.top();
result.pop();
help = result.top();
result.pop();
if (l > 0 && help < 0){
result.push(help / l - 1);
} else{
result.push(help / l);
}
} else {
result.push(atoi(str.c_str()));
}
}
int n = result.size();
///cout « n « endl;
if (n > 1){
fout << "ERROR";
return 0;
}
for (int i = 0; i < n; i ++){
///cout « result.top() « " ";
fout << result.top() << " ";
result.pop();
}
finn.close();
fout.close();
return 0;
}
