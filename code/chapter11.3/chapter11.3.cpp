#include<vector>
#include<string>
#include<iostream>
#include<array>
#include<deque>
#include<forward_list>
#include<list>
#include<set>
#include<algorithm>
#include<map>
#include<memory>
#include<chrono>
#include<numeric>
#include<functional>

using namespace std;

template<typename T>
const T* Find(const vector<T> &vec, const T &val) {
	for (int i=0;i<vec.size();++i)
		if (vec[i] == val)
			return &vec[i];
	return nullptr;
}

template<typename T>
const T* Find(const T *arr, int size, const T &val) {
	if (!arr || size <= 0) 
		return nullptr;
	
	for (int i = 0; i<size; ++i)
		if (arr[i] == val)
			return &arr[i];
	return nullptr;
}


template<typename T>
const T* Find(const T *first, const T *last, const T &val) {
	if (!first || !last )
		return nullptr;

	for (; first != last; ++first)
		if (*first == val)
			return first;

	return nullptr;
}

template<typename T>
const T* Begin(const vector<T> &vec) {
	return vec.size() > 0 ? &vec[0] : nullptr;
}

template<typename T>
const T* End(const vector<T> &vec) {
	return vec.size() > 0 ? &vec[vec.size()-1]+1 : nullptr;
}

struct Foo{
	Foo(const string &name, int id) :m_name(name), m_id(id) {}
	string m_name;
	int m_id;
};


struct LargeData {
	LargeData(int id) : m_id(id) {}
	int m_id;
	int m_arr[1000];
	bool operator<(const LargeData rhs) {
		return m_id < rhs.m_id;
	}
};
bool Less(const LargeData *a, const LargeData *b) {
	return a->m_id < b->m_id;
}
struct  Compare
{
	bool operator()(const LargeData *a, const LargeData *b) {
		return a->m_id < b->m_id;
	}
};
bool check(const LargeData *a, int n) {
	return a->m_id%n;
}

void filter(int &a, int n) {
	a= a < n ? 0 : a;
}
struct Checker
{
	int m_cnt = 0,m_nth;
	Checker(int n) :m_nth(n) {}
	bool operator()(int) {
		return ++m_cnt == m_nth;
	}
};
void sum(int a, int &s) {
	s += a;
}

int main() {

	{
		vector<int> v = { 3, 7, 3, 11, 3, 3, 2 };
		auto it = find(v.begin(), v.end(), 10);
		//cout << "10 is " << (it != v.end() ? " " : "not ") <<"found"<< endl;
		cout <<"10 is " << (it != v.end() ? "found" : "not found") << endl;
		
		int sum = accumulate(v.begin(), v.end(), 0);

		vector<string> vs = { "Hello ","world" };
		string ssum = accumulate(vs.begin(), vs.end(), string());

	}
	{
		vector<int> v1(10),v2(15);

		fill(v1.begin(), v1.end(), 1);

		copy(v1.begin(), v1.end(), v2.begin());

	}
	{
		vector<int> v = { 3, 7, 3, 11, 3, 3, 2 };
		sort(v.begin(), v.end());
		stable_sort(v.begin(), v.end());
		/*struct LargeData {
			LargeData(int id) : m_id(id) {}
			int m_id;
			int m_arr[1000];
			bool operator<(const LargeData rhs) {
				return m_id < rhs.m_id;
			}
		};*/

		vector<LargeData> vo;
		for (int i = 0; i < 50000; i++) 
			vo.emplace_back(rand() % 1000000);
		
		sort(vo.begin(), vo.end());


		vector<LargeData*> vp;
		for (int i = 0; i < 5; i++) 
			vp.emplace_back(new LargeData(rand() % 1000000));
		
		//sort(vp.begin(), vp.end(), [](const LargeData *a, const LargeData *b) {return a->m_id > b->m_id; });
		//sort(vp.begin(), vp.end(), Less);
		//sort(vp.begin(), vp.end(), Compare());
		
		//sort(vp.begin(), vp.end(), bind(Less, std::placeholders::_2, std::placeholders::_1));

		using CallType = bool(LargeData*, LargeData*);

		function<CallType> f1 = Less;
		function<CallType> f2 = Compare();
		function<CallType> f3 = [](const LargeData *a, const LargeData *b) {return a->m_id < b->m_id; };
		function<CallType> f4 = bind(Less, std::placeholders::_2, std::placeholders::_1);

		LargeData a(0), b(1);
		if (f1(&a, &b)) { cout << "ok" << endl; }
		if (f2(&a, &b)) { cout << "ok" << endl; }
		if (f3(&a, &b)) { cout << "ok" << endl; }
		if (f4(&a, &b)) { cout << "ok" << endl; }
	}
	{
		//parameter binding
		list<int> v = { 3, 7, 1, 11, 3, 3, 2 };
		int n = 3;

		auto it3=find_if(v.begin(), v.end(), Checker(4));

		//for_each(v.begin(), v.end(), [n](int &i) {i = (i < n ? 0 : i); });

		auto uf = bind(filter, std::placeholders::_1, n);
		for_each(v.begin(), v.end(), uf);
		int s = 0;
		for_each(v.begin(), v.end(), bind(sum,std::placeholders::_1,ref(s)));

		int foo(10);

		auto bar = std::cref(foo);

		++foo;
	}

}


