#pragma once
#include<iostream>
#include <deque>
#include <list>

using namespace std;
namespace que {
	template<class T,class Containter = deque<T>>
	class queue {
	public:
		queue()
		{}

		void push(const T& data) {
			_con.push_back(data);
		}

		void pop() {
			_con.pop_front();
		}

		T& front() {
			return _con.front();
		}

		const T& front() const {
			return _con.front();
		}

		T& back() {
			return _con.back();
		}

		const T& back() const {
			return _con.back();
		}

		size_t size() const {
			return _con.size();
		}

		bool empty() const {
			return _con.empty();
		}
	private:
		Containter _con;
	};
}

void test1() {
	que::queue<int> s;
	s.push(1);
	s.push(2);
	s.push(3);
	s.push(4);
	s.push(5);
	s.push(6);
	cout << s.front() << endl;
	cout << s.back() << endl;
	cout << s.size() << endl;
	s.pop();
	s.pop();
	cout << s.front() << endl;
	cout << s.back() << endl;
	cout << s.size() << endl;
}
void test2() {
	que::queue<int,list<int>> s;
	s.push(1);
	s.push(2);
	s.push(3);
	s.push(4);
	s.push(5);
	s.push(6);
	cout << s.front() << endl;
	cout << s.back() << endl;
	cout << s.size() << endl;
	s.pop();
	s.pop();
	cout << s.front() << endl;
	cout << s.back() << endl;
	cout << s.size() << endl;
}