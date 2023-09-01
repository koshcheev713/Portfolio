#include <iostream>
#include <fstream>
using namespace std;

int main()
{
	fstream file("shifrText.txt", ios::out);
	string str;
	cout << "Str: ";
	getline(cin >> ws, str);
	
	int outStr[str.length()];

	for (int i = 0; i < str.length(); ++i) {
		outStr[i] = static_cast<int>(str[i]) * 2;
		file << outStr[i] << endl;
	}
	for (int f = 0; f < str.length(); ++f) {
		cout << outStr[f] << ", ";
	}
	cout << endl;
	return 0;
}
