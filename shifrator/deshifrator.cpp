#include <iostream>

int main() {
	using namespace std;
	cout << "Hello, Enter shifr-message:\n";
	string shfr_mess;
	getline(cin, shfr_mess);
	cout << "Ok, Enter key: ";
	int key = 33;
	while (key <= -1 || key >= 31) {
		cout << "Enter key (0-30): ";
		cin >> key;
	}
	char deshfr_mess[shfr_mess.length()];
	for (int j = 0; j < static_cast<int>(shfr_mess.length()); ++j) {
		deshfr_mess[j] = char(static_cast<int>(shfr_mess[j]) + key);
	}
	cout << deshfr_mess << '\n';
	cout << sizeof(deshfr_mess) / sizeof(deshfr_mess[0]) << '\n';
	return 0;
}
