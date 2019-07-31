#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <string>
#include <iostream>
#include <assert.h>
namespace Str {
	class string {
	public:
		typedef char* iterator;

		iterator begin() {
			return _str;
		}

		iterator end() {
			return _str + _size;
		}
	public:
		string(const char* str = "") {
			if (nullptr == str) {
				str = "";
			}
			_size = strlen(str);
			_str = new char[_size + 1];
			strcpy(_str, str);
			_capacity = _size;
		}

		string(size_t n, char ch)
			:_str(new char[n + 1])
			, _size(n)
			, _capacity(_size)
		{
			memset(_str, ch, _size);
			_str[_size] = '\0';
		}

		string(const string& s) {
			_capacity = s._capacity;
			_str = new char[_capacity + 1];
			strcpy(_str, s._str);
			_size = s._size;
		}

		string& operator=(const string &s) {
			char* tmp = new char[s._capacity];
			strcpy(tmp, s._str);
			delete[] _str;
			_str = tmp;
			_size = s._size;
			_capacity = s._capacity;
			return *this;
		}

		size_t capacity() const {
			return _capacity;
		}

		size_t size() const {
			return _size;
		}

		bool empty() const {
			return _size == 0;
		}

		void clear() {
			_size = 0;
			_str[0] = '\0';
		}

		void resize(size_t newsize,char ch = '0') {
			if (newsize > _size) {
				if (newsize > _capacity) {
					reserve(newsize);
				}
				memset(_str + _size, ch, newsize - _size);
			}
			_size = newsize;
			_str[_size] = '\0';
		}

		void reserve(size_t newcapacity) {
			if (newcapacity > _capacity) {
				char* pStr = new char[newcapacity + 1];
				strcpy(pStr, _str);
				delete[] _str;
				_str = pStr;
				_capacity = newcapacity;
			}
		}

		char& operator[](size_t index) const {
			assert(index < _size);
			return _str[index];
		}

		string& operator+=(const char ch) {
			while (_capacity < _size + 1) {
				reserve(_capacity * 2);
			}
			_str[_size++] = ch;
			return *this;
		}
		string& operator+=(const char* str) {
			while (_capacity < _size + strlen(str)) {
				reserve(_capacity * 2);
			}
			strcat(_str, str);
			_size += strlen(str);
			return *this;
		}
		string& operator+=(const string& s) {
			while (_capacity < _size + s._size) {
				reserve(_capacity * 2);
			}
			strcat(_str, s._str);
			_size += s._size;
			return *this;
		}

		void push_back(char ch) {
			*this += ch;
		}

		void append(const char * s) {
			*this += s;
		}

		const char* c_str() const {
			return _str;
		}

		size_t find(char ch, size_t pos = 0) const {
			for (int i = pos; i < _size; ++i) {
				if (_str[i] == ch) {
					return i;
				}
			}
			return npos;
		}

		string substr(size_t pos = 0, size_t n = npos) {
			if (n == npos) {
				n = strlen(_str + pos);
			}
			//char* pstr = new char[n + 1];
			//strncpy(pstr, _str + pos, n);
			//string s(pstr);
			//delete[] pstr;
			string s(n + 1, '\0');
			strncpy(s._str, _str + pos, n);
			return s;
		}

		bool operator>(const string &s) {
			if (strcmp(_str, s._str) > 0) {
				return true;
			}
			else {
				return false;
			}
		}

		const static size_t npos = -1;

	private:
		char* _str;
		size_t _size;
		size_t _capacity;
	};
	std::ostream& operator<<(std::ostream& _cout, const string s) {
		_cout << s.c_str();
		return _cout;
	}
}

void stringtest1() {
	using namespace Str;
	string s1("hello");
	string s2(s1);
	string s3(3, 's');
	s3 = s1;
	std::cout << s1.capacity() << std::endl;
	std::cout << s1.size() << std::endl;

	s1.resize(10, '!');
	std::cout << s1.capacity() << std::endl;
	std::cout << s1.size() << std::endl;

	s1.resize(6, '!');
	std::cout << s1.capacity() << std::endl;
	std::cout << s1.size() << std::endl;
	std::string v("asdf");
	v.reserve(2);
	s1.reserve(2);
	std::cout << s1.capacity() << std::endl;
	std::cout << s1.size() << std::endl;
}
