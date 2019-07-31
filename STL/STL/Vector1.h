#pragma once
#include <assert.h>

namespace bite
{
	// 动态的顺序表
	template<class T>
	class vector
	{
	public:
		typedef T* iterator;  // vector<int>::iterator

	public:
		vector()
			: start(nullptr)
			, finish(nullptr)
			, endofstorage(nullptr)
		{}

		vector(int n, const T& data)
		{
			start = new T[n];
			for (size_t i = 0; i < n; ++i)
				start[i] = data;

			finish = start + n;
			endofstorage = start + n;
		}

		vector(const vector<T>& v)
		{
			size_t n = v.size();
			start = new T[n];
			for (size_t i = 0; i < n; ++i)
				start[i] = v[i];

			finish = start + n;
			endofstorage = finish;
		}

#if 1
		template<class Iterator>
		vector(Iterator first, Iterator last)
		{
			// 求[first, last)区间中元素的个数
			Iterator it = first;
			size_t n = 0;
			//distance(first, last, n);
			while (it != last)
			{
				n++;
				++it;
			}

			start = new T[n];
			finish = start;
			while (first != last)
			{
				*finish = *first;
				++first;
				++finish;
			}

			endofstorage = finish;
		}
#endif

		// 注意：深拷贝
		// vector<T>& operator=(const vector<T>& v);
		~vector()
		{
			if (start)
			{
				delete[] start;
				start = finish = endofstorage = nullptr;
			}
		}

		//////////////////////////////////////
		// iterator--->指针
		iterator begin()
		{
			return start;
		}

		iterator end()
		{
			return finish;
		}

		///////////////////////////////////////
		// capacity
		size_t size()const
		{
			return finish - start;
		}

		size_t capacity()const
		{
			return endofstorage - start;
		}

		bool empty()const
		{
			return finish == start;
		}

		void resize(size_t newSize, const T& data = T())
		{
			size_t oldSize = size();
			if (newSize <= oldSize)
				finish = start + newSize;
			else
			{
				if (newSize > capacity())
					reserve(newSize);

				size_t n = newSize - oldSize;
				for (size_t i = oldSize; i < newSize; ++i)
					start[i] = data;

				finish = start + newSize;
			}
		}

		void reserve(size_t newCapacity)
		{
			size_t oldCapacity = capacity();
			if (newCapacity > oldCapacity)
			{
				// 开辟新空间
				T* temp = new T[newCapacity];
				size_t n = size();
				// 拷贝元素
				if (start)
				{
					// 有些情况行，有些情况不行
					//memcpy(temp, start, size()*sizeof(T));
					for (size_t i = 0; i < n; ++i)
						temp[i] = start[i];

					// 释放旧空间
					delete[] start;
				}

				start = temp;
				finish = start + n;
				endofstorage = start + newCapacity;
			}
		}
		// 1 2 3 2 4 2
		///////////////////////////////////////
		// access
		T& operator[](size_t index)
		{
			assert(index < size());
			return start[index];
		}

		const T& operator[](size_t index)const
		{
			assert(index < size());
			return start[index];
		}

		T& front()
		{
			return start[0];
		}

		const T& front()const
		{
			return start[0];
		}

		T& back()
		{
			return *(finish-1);
		}

		const T& back()const
		{
			return *(finish - 1);;
		}

		//////////////////////////////////
		// modify
		void push_back(const T& data)
		{
			Expand();
			*finish = data;
			++finish;
		}

		void pop_back()
		{
			--finish;
		}

		iterator insert(iterator pos, const T& data)
		{
			Expand();

			//for (size_t i = size(); i >= pos - finish - 1; i--)
			iterator it = end();
			while (it != pos)
			{
				*it = *(it - 1);
				--it;
			}

			*pos = data;
			++finish;
			return pos;
		}

		iterator erase(iterator pos)
		{
			iterator it = pos;
			while (it+1 != finish)
			{
				*it = *(it + 1);
				++it;
			}

			--finish;
			return pos;
		}

		void clear()
		{
			finish = start;
		}

		void swap(vector<T>& v)
		{
			swap(start, v.start);
			swap(finish, v.finish);
			swap(endofstorage, v.endofstorage);
		}

	private:
		void Expand()
		{
			if (size() == capacity())
			{
				reserve(capacity() * 2 + 3);
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

