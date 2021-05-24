#include <iostream>
#include <vector>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <fstream>

using namespace std;

int main(){
 ifstream finn ("input.txt");
 string str = "";
 char a, b, result1;
 int result2 = 0, max = 0;
 getline(finn, str);
 b = str[0];
 result1 = str[0];
  for (int i = 0; i <= str.size(); i ++){
    a = str[i];
        if (b == a){
            max ++;
        }
        if (max > result2){
            result2 = max;
            result1 = b;
        }
        if (b != a){
            max = 1;
            b = a;
        }
    }
cout << result1 << " " << result2;
return 0;

}