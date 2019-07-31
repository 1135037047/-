#pragma once
#include <assert.h>
#include <iterator>
using namespace std;
namespace bite {
	template <class T>
	class vector {
	public:
		typedef T* iterator;
		vector()
			: start(nullptr)
			, finish(nullptr)
			, endofstorage(nullptr)
		{}

		vector(size_t n,const T& val) {
			start = new T[n];
			for (int i = 0; i < n; ++i) {
				start[i] = val;
			}
			finish = start + n;
			endofstorage = start + n;
		}

		vector(const vector<T>& v) {
			start = new T[v.size()];
			for (int i = 0; i < v.size(); ++i) {
				start[i] = v[i];
			}
			finish = start + v.size();
			endofstorage = finish;
			reserve(v.capacity());
		}
		template<class Iterator>
		vector(Iterator first, Iterator last) {
			Iterator it = first;
			size_t n = 0;
			while (it != last) {
				n++;
				it++;
			}
			//n = distace(first, last);
			start = new T[n];
			finish = start;
			while (first != last) {
				*finish = *first;
				finish++;
				first++;
			}
			endofstorage = finish;
		}
		vector<T>& operator=(const vector<T>& v) {
			if (start == nullptr) {
				vector(v);
			}
			else {
				T* temp = new T[v.size()];
				for (int i = 0; i < v.size(); ++i) {
					temp[i] = v[i];
				}
				delete[] start;
				start = temp;
				finish = start + v.size();
				endofstorage = finish;
				reserve(v.capacity());
			}
			return *this;
		}



		~vector() {
			if (start) {
				delete[] start;
				start = finish = endofstorage = nullptr;
			}
		}  
		iterator begin() {
			return start;
		}

		iterator end() {
			return finish;
		}

		size_t capacity() const{
			return endofstorage - start;
		}

		size_t size() const {
			return finish - start;
		}

		bool empty() const {
			return finish == start;
		}

		void resize(size_t newsize,const T& val = T()) {
			size_t oldsize = size();
			if (newsize > oldsize) {
				if (newsize > capacity()) {
					reserve(newsize);
				}
				for (int i = 0; i < newsize - oldsize;++i) {
					*finish = val;
					finish++;
				}
			}
			else {
				finish = start + newsize;
			}
		}

		void reserve(size_t newcapacity) {
			if (newcapacity > capacity()) {
				size_t n = size();
				T* temp = new T[newcapacity];
				for (size_t i = 0; i < n; ++i) {
					temp[i] = start[i];
				}
				delete[] start;
				start = temp;
				finish = start + n;
				endofstorage = start + newcapacity;
			}
		}

		T& operator[](size_t index) {
			assert(index < size());
			return start[index];
		}

		const T& operator[](size_t index) const{
			assert(index < size());
			return start[index];
		}

		T& front()  {
			return start[0];
		}

		const T& front() const {
			return start[0];
		}

		T& back()  {
			return start[finish - 1];
		}

		const T& back() const {
			return start[finish - 1];
		}

		void push_back(const T& val) {
			Expand();
			*finish = val;
			finish++;
		}

		void pop_back() {
			finish--;
		}

		iterator insert (iterator pos, const T& val) {
			Expand();
			iterator it = end();
			while (it != pos) {
				*it = *(it - 1);
				it--;
			}
			*pos = val;
			finish++;
			return pos;
		}

		iterator erase(iterator pos) {
			iterator it = pos;
			while (it != end()) {
				*it = *(it + 1);
				it++;
			}
			finish--;
			return pos;
		}

		void clear() {
			finish = start;
		}

		void swap(vector<T>& v) {
			swap(start, v.start);
			swap(finish, v.finish);
			swap(endofstorage, v.endofstorage);
		}

	private:
		void Expand() {
			if (size() == capacity()) {
				reserve(2 * capacity() + 3);
			}
		}

	private:
		T* start;
		T* finish;
		T* endofstorage;
	};
}

#include <list>
#include <iostream>
using namespace std;

template<class T>
void PrintVector(bite::vector<T>& v)
{
	// begin end
	for (auto e : v)
	{
		cout << e << " ";
	}
	cout << endl;
}

void TestVector1()
{
	bite::vector<int> v1;
	bite::vector<int> v2(10, 5);
	PrintVector(v2);

	bite::vector<int> v3(v2);
	PrintVector(v3);
	cout << v3.size() << endl;
	cout << v3.capacity() << endl;

	int array[] = { 1, 2, 3, 4, 5 };
	bite::vector<int> v4(array, array + sizeof(array) / sizeof(array[0]));
	PrintVector(v4);

	std::list<int> L{ 1, 2, 3, 4, 5, 6, 7, 8, 9, 0 };
	bite::vector<int> v5(L.begin(), L.end());
	PrintVector(v5);
}

void TestVector2()
{
	bite::vector<int> v;
	v.push_back(1);
	v.push_back(2);
	v.push_back(3);
	v.push_back(4);
	PrintVector(v);

	v.pop_back();
	PrintVector(v);

	v.insert(v.begin(), 0);
	PrintVector(v);
	v.pop_back();

	v.erase(v.begin());
	PrintVector(v);

	v.clear();
	cout << v.size() << endl;
}

void TestVector3()
{
	bite::vector<int> v;
	v.push_back(1);
	v.push_back(2);
	bite::vector<int> x = v;
	bite::vector<int> c = v;
	c = x;
	cout << v.size() << endl;
	cout << v.capacity() << endl;

	// 元素增多，需要扩容
	v.resize(10, 5);
	cout << v.size() << endl;
	cout << v.capacity() << endl;
	PrintVector(v);

	// 减少元素个数  不需要扩容
	v.resize(4);
	cout << v.size() << endl;
	cout << v.capacity() << endl;
	PrintVector(v);

	// 元素增多
	v.resize(7);
	cout << v.size() << endl;
	cout << v.capacity() << endl;
	PrintVector(v);
}
