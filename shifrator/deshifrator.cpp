#include <iostream>
#include <fstream>
using namespace std;

int main()
{
	fstream file("shifrText.txt", ios::in);
	int str[100] {};
	string outStr[100] {};

	int l = 0;
	while (!file.eof()) {
		file >> str[l];
		++l;
	}
	for (int i = 0; i < static_cast<int>(sizeof(str)/sizeof(str[0])); ++i) {
		outStr[i] = char(str[i]/2);
	}
	for (auto i : outStr) {
		cout << i;
			
	}
	cout << endl;
	return 0;
}
