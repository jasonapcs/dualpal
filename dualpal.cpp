/*
ID: jason.z2
PROG: dualpal
LANG: C++
*/

#include <algorithm>
#include <fstream>
#include <string>
#include <array>

std::array<char, 20> baseChars = { '0','1','2','3','4','5','6','7','8','9','A','B','C','D','E','F','G','H','I','J' };

bool isPalindrome(const std::string s) {
	std::string _string = s;
	std::string _string2 = s;
	std::reverse(_string2.begin(), _string2.end());
	if (_string != _string2) return false;
	else return true;
}

std::string changeBase(const int base, const int num) {
	int num2 = num;
	std::string s = "";

	while (1) {
		if (base > num2) break;
		s += baseChars[num2 % base];
		num2 /= base;
	}
	s += baseChars[num2 % base];


	std::reverse(s.begin(), s.end());

	return s;
}

int main(){
  std::ifstream input("dualpal.in");
  int N;
  int beginning;
  input >> N >> beginning;
  input.close();
  int amount = -1;
  std::array<int,15> nums;
  unsigned int is;
  for (int i = beginning; i > -1; i++){
    if (N >= amount) break;
    bool pal1 = false;
    is = i * i;
    for (int j = 2; j <= 10; j++) {
      if (isPalindrome(changeBase(j, is)){
        if (pal1){
          amount++;
          nums[amount] = i;
        }
        else {
          pal1 = true;
        }
      }
    }
  }
  std::ofstream output("dualpal.out");
  for (int i = 0; i <= amount; i++)
    output << nums[amount] << "\n";
  output.close();
  return 0;
}
  
