#pragma once
#include <iostream>
#include <queue>
#include <list>
using namespace std;

namespace priori {
	template<class T,class Container = vector<T>,class Compare = less<T>>
	class priority_queue {
	public:
		priority_queue()
		{}

		template<class Iterator>
		priority_queue(Iterator first, Iterator last) 
			:_con(first,last)
		{
			size_t left = (_con.size() - 2) >> 1;
			for (int root = left; root >= 0; root--) {
				_AdjustDown(root);
			}

		}

		void push(const T& data) {
			_con.push_back(data);
			_AdjustUp();
		}

		void pop() {
			if (_con.empty()) {
				return;
			}
			swap(_con.front(), _con.back());
			_con.pop_back();
			_AdjustDown(0);
		}

		size_t size() const {
			return _con.size();
		}

		bool empty() const {
			return _con.empty();
		}

		const T& top() const {
			return _con.front();
		}
	private:
		void _AdjustUp() {
			size_t child = _con.size() - 1;
			size_t parent = ((child - 1) >> 1);
			Compare com;
			while (child) {
				if (com(_con[parent], _con[child])) {
					swap(_con[parent], _con[child]);
					child = parent;
					parent = ((child - 1) >> 1);
				}
				else {
					return;
				}
			}
		}

		void _AdjustDown(size_t parent) {
			size_t child = parent * 2 + 1;
			size_t size = _con.size();
			Compare com;
			while (child < size) {
				if (com(_con[child], _con[child + 1])) {
					child++;
				}
				if (com(_con[parent], _con[child])) {
					swap(_con[parent], _con[child]);
					parent = child;
					child = parent * 2 + 1;
				}
				else {
					return;
				}
			}
		}
	private:
		Container _con;
	};
}

#include   <functional>
void test1() {
	list<int> l{ 3,1,9,6,8 };
	priori::priority_queue<int,vector<int>,greater<int>> q(l.begin(),l.end());
	cout << q.top() << endl;
	cout << q.size() << endl;
	q.push(1);
	cout << q.top() << endl;
	cout << q.size() << endl;
	q.pop();
	cout << q.top() << endl;
	cout << q.size() << endl;
}