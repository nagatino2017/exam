#include <iostream>
#include <cmath>

using namespace std;
bool charge(int nomer)
{
if(nomer < 2) { return false; }
if(nomer == 2) { return true; }
if(nomer % 2 == 0) { return false; }
for(int net = 3; net <= sqrt(nomer); net += 2)
{
if(nomer % net == 0) { return false; }
}
return true;
}
int main()
{
int from, to;
cin >> from >> to;
for (int net = from; net <= to; ++net) {
if(net % 2 == 0){
int da = sqrt(net/2);
if (da*da*2 == net and charge(da)){
cout  << net << endl;
}
}
}
cout << 0;
return 0;
}