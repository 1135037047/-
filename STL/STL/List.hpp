#pragma once
namespace bite
{
	template<class T>
	struct ListNode {
		ListNode(const T& data = T())
			: _pNext(nullptr)
			, _pPre(nullptr)
			,_data(data)
		{}

		ListNode<T>* _pNext;
		ListNode<T>* _pPre;
		T _data;
	};

	template<class T>
	struct listiterator {
		typedef ListNode<T> Node;
		typedef listiterator<T> Self;
	public:
		listiterator(Node* pNode)
			:_pNode(pNode)
		{}

		T& operator*() {
			return _pNode->_data;
		}

		T* operator&() {
			return &(operator*());
		}

		Self& operator++() {
			_pNode = _pNode->_pNext;
			return *this;
		}

		Self& operator++(int) {
			Self temp(*this);
			_pNode = _pNode->_pNext;
			return temp;
		}

		Self& operator--() {
			_pNode = _pNode->_pPre;
			return _pNode;
		}

		Self& operator--(int) {
			Self temp(*this);
			_pNode = _pNode->_pPre;
			return temp;
		}

		bool operator!=(const Self& s)const {
			return _pNode != s._pNode;
		}

		bool operator==(const Self& s) const {
			return s._pNode == _pNode;
		}

		Node* _pNode;
	};

	template<class T>
	class list {
		typedef ListNode<T> Node;
		typedef listiterator<T> iterator;
	public:
		list() {
			CreateHead();
		}

		list(int n, const T& data) {
			CreateHead();
			for (int i = 0; i < n; ++i) {
				push_back(data);
			}
		}

		list(const list<T>& L) {
			CreateHead();
			Node* pCur = L._pHead->_pNext;
			while (pCur != L._pHead) {
				push_back(pCur->_data);
				pCur = pCur->_pNext;
			}
		}

		template<class Iterator>
		list(Iterator first, Iterator last) {
			CreateHead();
			while (first != last) {
				push_back(*first);
				++first;
			}
		}

		list<T>& operator=(const list<T>& L) {
			if (*this != L) {
				Node* pCur = L._pHead->_pNext;
				while (pCur != L._pHead) {
					push_back(pCur->_data);
					pCur = pCur->_pNext;
				}
			}
			return *this;
		}

		~list() {
			clear();
			delete _pHead;
			_pHead = nullptr;
		}

		iterator begin() {
			return iterator(_pHead->_pNext);
		}

		iterator end() {
			return iterator(_pHead);
		}

		bool empty() const {
			return _pHead->_pNext == _pHead;
		}

		size_t size() const {
			size_t count = 0;
			Node* pCur = _pHead->_pNext;
			while (pCur != _pHead) {
				pCur = pCur->_pNext;
				++count;
			}
			return count;
		}

		void resize(size_t newsize, const T& data = T()) {
			size_t oldsize = size();
			if (oldsize < newsize) {
				for (int i = oldsize; i < newsize; ++i) {
					Node* pNode = new Node;
					push_back(data);
				}
			}
			else {
				for (int i = newsize; i < oldsize; ++i) {
					pop_back();
				}
			}
		}

		T& front() {
			return _pHead->_pNext->_data;
		}

		const T& front() const {
			return _pHead->_pNext->_data;
		}

		T& back() {
			return _pHead->_pPre->_data;
		}

		const T& back() const {
			return _pHead->_pPre->_data;
		}
		
		void push_back(const T& data) {
			Node* pNode = new Node;
			pNode->_data = data;
			pNode->_pNext = _pHead;
			pNode->_pPre = _pHead->_pPre;
			_pHead->_pPre = pNode;
			pNode->_pPre->_pNext = pNode;
		}

		void pop_back() {
			if (empty()) {
				return;
			}
			Node* pCur = _pHead->_pPre;
			_pHead->_pPre = _pHead->_pPre->_pPre;
			_pHead->_pPre->_pNext = _pHead;
			delete pCur;
		}

		void push_front(const T& data) {
			Node* pNode = new Node;
			pNode->_pNext = _pHead->_pNext;
			pNode->_pPre = _pHead;
			pNode->_data = data;
			_pHead->_pNext = pNode;
			pNode->_pNext->_pPre = pNode;
		}

		void pop_front() {
			if (empty()) {
				return;
			}
			Node* pCur = _pHead->_pNext;
			_pHead->_pNext = pCur->_pNext;
			pCur->_pNext->_pPre = _pHead;
			delete pCur;
		}

		void clear() {
			while (_pHead->_pNext != _pHead) {
				pop_front();
			}
		}

		void swap(list<T>& l) {
			swap(_pHead, l._pHead);
		}

		iterator insert(iterator pos, const T& data) {
			Node* pNode = new Node(data);
			Node* pCur = pos._pNode;
			pNode->_pNext = pCur;
			pNode->_pPre = pCur->_pPre;
			pCur->_pPre->_pNext = pNode;
			pCur->_pPre = pNode;
			return (iterator)pNode;
		}

		iterator erase(iterator pos) {
			Node* pCur = pos._pNode;
			pCur->_pPre->_pNext = pCur->_pNext;
			pCur->_pNext->_pPre = pCur->_pPre;
			Node* pNode = pCur->_pNext;
			delete pCur;
			return (iterator)pNode;
		}

	private: 
		void CreateHead() {
			_pHead = new Node;
			_pHead->_pNext = _pHead;
			_pHead->_pPre = _pHead;
		}
	private:
		Node* _pHead;
	};
}


#include <vector>
#include <iostream>
using namespace std;

void TestList1()
{
	bite::list<int> L1;
	bite::list<int> L2(10, 5);

	int array[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 0 };
	bite::list<int> L3(array, array + sizeof(array) / sizeof(array[0]));

	vector<int> v{ 1, 2, 3, 4, 5, 6, 7, 8, 9, 0 };
	bite::list<int> L4(v.begin(), v.end());

	bite::list<int> L5(L4);

	//bite::list<int>::iterator it = L2.begin();
	auto it = L2.begin();
	while (it != L2.end())
	{
		cout << *it << " ";
		++it;
	}
	cout << endl;

	for (auto e : L3)
		cout << e << " ";
	cout << endl;

	for (auto e : L4)
		cout << e << " ";
	cout << endl;

	for (auto e : L5)
		cout << e << " ";
	cout << endl;
}

template<class T>
void PrintList(bite::list<T>& L)
{
	for (auto e : L)
		cout << e << " ";
	cout << endl;
}

void TestList2()
{
	bite::list<int> L;
	L.push_back(1);
	L.push_back(2);
	L.push_back(3);
	L.push_back(4);
	L.push_back(5);
	PrintList(L);

	cout << L.size() << endl;
	L.resize(10, 6);
	PrintList(L);

	L.resize(4);
	PrintList(L);

	L.push_front(0);
	cout << L.front() << endl;
	cout << L.back() << endl;

	L.pop_front();
	PrintList(L);

	L.insert(find(L.begin(), L.end(), 3), 5);
	L.insert(L.begin(), 5);
	PrintList(L);

	L.erase(L.begin());
	PrintList(L);

	L.clear();
	cout << L.size() << endl;
}

// vector ºÍ list
#include <list>

template<class T>
void PrintList(list<T>& L)
{
	for (auto e : L)
		cout << e << " ";
	cout << endl;
}

void TestList3()
{
	list<int> L;
	L.push_back(1);
	L.push_back(2);
	L.push_back(3);
	L.push_back(4);
	L.push_back(5);
	PrintList(L);

	cout << L.size() << endl;
	L.resize(10, 6);
	PrintList(L);

	L.resize(4);
	PrintList(L);

	L.push_front(0);
	cout << L.front() << endl;
	cout << L.back() << endl;

	L.pop_front();
	PrintList(L);

	L.insert(find(L.begin(), L.end(), 3), 5);
	PrintList(L);

	//L.erase(L.begin());
	L.erase(find(L.begin(), L.end(), 5));
	PrintList(L);

	L.clear();
	cout << L.size() << endl;
}




