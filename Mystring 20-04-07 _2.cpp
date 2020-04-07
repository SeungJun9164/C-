#include<iostream>

class MyString {
	char* string_content; //문자열을 가르키는 포인터
	int string_length; //문자열 길이
	int memory_capacity;
public:
	MyString(char c) {
		string_content = new char[1];
		string_content[0] = c;
		string_length = 1;
		memory_capacity = 1;
	}
	MyString(const char* str) {
		string_length = strlen(str);
		memory_capacity = string_length;
		string_content = new char[string_length];
		for (int i = 0; i < string_length; i++) 
			string_content[i] = str[i];
	}
	MyString(const MyString& str) {
		string_length = str.string_length;
		memory_capacity = str.string_length;
		string_content = new char[string_length];
		for (int i = 0; i < string_length; i++)
			string_content[i] = str.string_content[i];
	}
	~MyString() { delete[] string_content; }
	int length() const { return string_length; }
	void print() const { for (int i = 0; i < string_length; i++) std::cout << string_content[i]; }
	void println() const {
		for (int i = 0; i != string_length; i++) std::cout << string_content[i]; std::cout << "\n"; }
	
	MyString& assign(const MyString& str) {
		if (str.string_length > string_length) {
			delete[] string_content;			
			string_content = new char[string_length];
			memory_capacity = str.string_length;
		}
		string_length = str.string_length;
		for (int i = 0; i < str.string_length; i++)
			string_content[i] = str.string_content[i];
		return *this;
	}

	MyString& assign(const char* str) {
		int str_length = strlen(str);
		if (str_length > string_length) {
			delete[] string_content;
			string_content = new char[str_length];
			memory_capacity = str_length;
		}
		string_length = str_length;
		for (int i = 0; i < str_length; i++)
			string_content[i] = str[i];

		return *this;
	}
	int capacity() const { return memory_capacity; }
	void reserve(int size) {
		if (size > memory_capacity) {
			char* prev_string_content = string_content;

			string_content = new char[size];
			memory_capacity = size;

			for (int i = 0; i < string_length; i++)
				string_content[i] = prev_string_content[i];

			delete[] prev_string_content;
		}
	}
};

int main() {
	/*MyString str1("hello world!");
	MyString str2(str1);

	str1.println();
	str2.println();*/
	MyString str1("very very very long string");
	str1.reserve(30);

	std::cout << "Capacity : " << str1.capacity() << std::endl;
	std::cout << "String length : " << str1.length() << std::endl;
	str1.println();
	return 0;
}