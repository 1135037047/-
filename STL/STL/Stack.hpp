#pragma once
#include <iostream>
#include <deque>
#include <vector>
using namespace std;
namespace sta {
	template<class T,class Container = std::deque<T>>
	class stack {
	public:
		stack() 
		{}

		void push(const T& data) {
			_con.push_back(data);
		}

		void pop() {
			_con.pop_back();
		}

		T& top() {
			return _con.back();
		}

		const T& top() const {
			return _con.back();
		}

		size_t size() const {
			return _con.size();
		}

		bool empty() const {
			return _con.empty();
		}
	private:
		Container _con;
	};
}

void test1() {
	sta::stack<int> s;
	s.push(1);
	s.push(2);
	s.push(3);
	s.push(4);
	s.push(5);
	s.push(6);
	cout << s.top() << endl;
	cout << s.size() << endl;
	s.pop();
	s.pop();

}

void test2() {
	sta::stack<int, vector<int>> s;
	s.push(1);
	s.push(2);
	s.push(3);
	s.push(4);
	s.push(5);
	s.push(6);
	cout << s.top() << endl;
	cout << s.size() << endl;
	s.pop();
	s.pop();
}