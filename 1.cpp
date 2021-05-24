#include <iostream>
#include <vector>
using namespace std;

int bin(int num)
{
vector <int> out;
while (num > 0)
{
int strgt = num % 2;
out.push_back(strgt);
num /= 2;
}
int k = out.size();
return out[0];
}
int binary_sum(int n){
int out = 0;
while (n > 0)
{
int strgt = n % 2;
if (strgt)
out++;
n /= 2;
}
return out;
}
int main() {
int a, b;
int kolvo = 0;
int gregv = -1;
cin >> a >> b;
for (int i = a; i <= b; ++i) {
if (bin(abs(i)) == 0 and binary_sum(abs(i)) == 5 and i % 10 != 0){
kolvo++;
if (i > gregv)
gregv = i;
}
}
if (!kolvo)
{
cout << "0 0";
}
cout << kolvo << " " << gregv << endl;
}