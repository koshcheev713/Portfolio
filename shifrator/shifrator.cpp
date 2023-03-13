#include <iostream>

int main() {
	using namespace std;
	cout << "Hello, this simple shifrator.\n";
	cout << "How use? Example: 'Hello,_world1', between words you must type '_'.\n";
	cout << "Ok, Enter message:\n";
	string mess;
	getline(cin, mess);

	int key = 33;
	while (key <= -1 || key >= 31) {
		cout << "Enter key (0-30): ";
		cin >> key;
	}
	char shfr_mess[mess.length()];
	for (int i = 0; i < static_cast<int>(mess.length()); ++i) {
		shfr_mess[i] = static_cast<int>(mess[i]) - key;
	}
	cout << shfr_mess << '\n';
	return 0;
}
