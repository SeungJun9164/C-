#include<iostream>

class MyString {
	char* string_content; //���ڿ��� ����Ű�� ������
	int string_length; //���ڿ� ����
public:
	MyString(char c) {
		string_content = new char[1];
		string_content[0] = c;
		string_length = 1;		
	}
	MyString(const char* str) {
		string_length = strlen(str);
		string_content = new char[string_length];
		for (int i = 0; i < string_length; i++) 
			string_content[i] = str[i];
	}
	MyString(const MyString& str) {
		string_length = str.string_length;
		string_content = new char[string_length];
		for (int i = 0; i < string_length; i++)
			string_content[i] = str.string_content[i];
	}
	~MyString() { delete[] string_content; }
	int length() const { return string_length; }
	void print() const { for (int i = 0; i < string_length; i++) std::cout << string_content[i]; }
	void println() const {
		for (int i = 0; i != string_length; i++) std::cout << string_content[i]; std::cout << "\n"; }
};

int main() {
	MyString str1("hello world!");
	MyString str2(str1);

	str1.println();
	str2.println();
	return 0;
}