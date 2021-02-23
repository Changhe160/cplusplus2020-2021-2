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

template<typename T, size_t N>
const T* Begin(const  T (&arr)[N]) {
	return arr;
}

template<typename T, size_t N>
const T* End(const T (&arr)[N]) {
	return arr+N;
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



	vector<int> vi = { 1,2,3,4 };
	if (auto p = Find(vi, 4))
		cout << *p << endl;
	int arr[]= { 1,2,3,4 };

	if (auto p = Find(arr, sizeof(arr) / sizeof(int), 4))
		cout << *p << endl;	

	Find(Begin(vi), End(vi), 4);
	Find(Begin(arr), End(arr), 5);

	if (auto p = Find(&vi[0], &vi[vi.size() - 1]+1, 4)) 
		cout << *p << endl;

	if (auto p = Find(arr, arr + sizeof(arr) / sizeof(int), 5)) 
		cout << *p << endl;
	


	auto it1 = vi.cbegin();

	vector<Foo> vf;
	vf.push_back(Foo("Lisha", 10002));
	vf.insert(vf.begin(),Foo("Mandy", 10003));
	vf.emplace_back("Kevin", 10001);
	{
		array<int, 4> arr = { 1,2,3,4 };
		for (auto it = arr.begin(); it != arr.end(); ++it) {
			cout << *it << endl;
		}
		array<int, 4> arr2 = arr;
		arr2.fill(0);
		int *p = arr.data();
	}

	cout << "-------------------------------------------\n";
	{
		vector<int> v1 = { 0, 1 };
		vector<int> v2 = { 0, 1, 2, 3 };
		swap(v1, v2);
		for (auto &i : v1)
			cout << i << " ";
		cout << endl;
		for (auto &i : v2)
			cout << i << " ";
		cout << endl;
	}
	cout << "-------------------------------------------\n";
	{
		array<int, 4> arr = { 1,2,3,4 };
		for (auto it = arr.begin(); it != arr.end(); ++it)
			cout << *it << endl;
		array<int, 4> arr2 = arr;
		arr2.fill(0);
		for (auto it = arr2.begin(); it != arr2.end(); ++it)
			cout << *it << endl; 
	}
	cout << "-------------------------------------------\n";

	{
		deque<int> dq = {1,2,3};
		dq.push_back(4);
		dq.push_front(0);
		cout << dq[3] << endl;

	}
	
	{
		forward_list<int> flst = { 2,3 };
		flst.push_front(1);
		flst.insert_after(flst.before_begin(), 0);
		cout <<"size: "<< distance(flst.begin(), flst.end())<<endl;
		for (auto it = flst.begin(); it != flst.end(); ++it)
			cout << *it << '\t';
		cout << endl;
	}
	{
		list<int> lst1 = { 2,3 }, lst2 = {1};
		lst1.push_back(5);
		lst2.push_front(0);
		auto pos = find(lst1.begin(), lst1.end(), 5);
		lst1.insert(pos, 4);

		lst1.splice(lst1.begin(), lst2);
		for (auto it = lst1.begin(); it != lst1.end(); ++it)
			cout << *it << '\t';
		cout << endl;

		list<int> lst3 = { 6,7,8 };
		auto it = lst3.begin();
		advance(it , 2);
		lst1.splice(lst1.end(), lst3, lst3.begin(),it);

	}
	{
		/*set<int> counter;
		int number;
		while (cin >> number) {
			auto it = counter.insert(number);
			if (it.second) 
				cout << "suc" <<*it.first<< endl;
			else
				cout << "fail" << *it.first<< endl;
			
		}
			
		cout << "不同的数字的个数：" << counter.size() << endl;
		for (auto &i : counter) 
			cout << i << " ";
		
		vector<int> v = { 1, 8, 4, 2, 0, 1, 4, 3, 5, 4,7 };
		set<int> s(v.begin(), v.end());
		auto it = s.find(0);
		
		s.erase(it);		
		s.erase(s.find(3),s.find(7));
		for (auto &i : s)
			cout << i << " ";
			*/
	}
	{
		
	/*	pair<int, int> p1;
		pair<string, int> p2 = {"Hello",0};
		auto p3 = make_pair("Hello", 1);

		cout << p2.first << p2.second << endl;

		
		map<int, int> counter;
		int number;
		while (cin >> number) 
			++counter[number];
		for (auto &i : counter) {
			cout << i.first << ": " << i.second << endl;
		}

		counter.insert({ 3,0 });
		counter.insert(make_pair(3, 0));

		auto res = counter.insert(pair<int, int>(2, 0));
		if (!res.second)
			++res.first->second;
			
		multimap<string, unsigned long long> contact;
		contact.insert({ "Kevin",15387120203 });
		contact.insert({ "Kevin",15387120204 });
		for (auto &i : contact)
			cout << i.first << ": " << i.second << endl;
		auto entries = contact.count("Kevin");
		auto it = contact.find("Kevin");
		while (entries) {
			cout << it->second << endl;
			++it;
			--entries;
		}*/
	}

	{
	/*	
		struct LargeData {
			LargeData(int id): m_id(id){}
			int m_id;
			int m_arr[1000];
		};
		


		vector<unique_ptr<LargeData>> t;
		t.push_back(make_unique<LargeData>(1));
		t.push_back(std::move(unique_ptr<LargeData>(new LargeData(2))));
		t.emplace_back(new LargeData(3));


		vector<unique_ptr<LargeData>> vsp;
		vector<LargeData> vo;
		vector<LargeData*> vp;
		for (int i = 0; i < 50000; i++) {
			int n = rand()%1000000;
			vp.emplace_back(new LargeData(n));
			vo.emplace_back(n);
			vsp.emplace_back(new LargeData(n));
		}

		auto t1=std::chrono::high_resolution_clock::now();
		//reverse(vsp.begin(), vsp.end());
		sort(vsp.begin(), vsp.end(), [](const unique_ptr<LargeData> &a, const unique_ptr<LargeData> &b) {return a->m_id > b->m_id; });
		auto t2 = std::chrono::high_resolution_clock::now();
		cout << chrono::duration_cast<chrono::milliseconds>(t2 - t1).count() << endl;


		auto t3 = std::chrono::high_resolution_clock::now();
		sort(vo.begin(), vo.end(), [](const LargeData &a, const LargeData &b) {return a.m_id > b.m_id; });
		//reverse(vo.begin(), vo.end());
		auto t4 = std::chrono::high_resolution_clock::now();
		cout << chrono::duration_cast<chrono::milliseconds>(t4 - t3).count() << endl;

		auto t5 = std::chrono::high_resolution_clock::now();
		sort(vp.begin(), vp.end(), [](const LargeData *a, const LargeData *b) {return a->m_id > b->m_id; });
		//reverse(vp.begin(), vp.end());
		auto t6 = std::chrono::high_resolution_clock::now();
		cout << chrono::duration_cast<chrono::milliseconds>(t6 - t5).count() << endl;*/
	}
	
	{
		int arr[] = { 1,2,4,10,5,4,1,8,20,30,15 };
		vector<int> vi;

		vi.assign(arr, arr + 7);

		for (int i = 0; i < 7; i++) {
			vi.push_back(arr[i]);
		}
	}
	{
		vector<int> vi;
		cout << "预留前，容量：" << vi.capacity() << "，大小：" << vi.size() << endl;
		vi.reserve(1000);
		cout <<"预留后，容量：" <<vi.capacity() << "，大小：" <<vi.size()<< endl;

	}
	{
		struct Foo
		{
			string m_str;
			Foo(const string & s) :m_str(s) {
				cout << "constructor" << endl;
			}
			Foo(const Foo & rhs) :m_str(rhs.m_str) {
				cout << "copied" << endl;
			}
			Foo(Foo && rhs) :m_str(std::move(rhs.m_str)) {
				cout << "moved" << endl;
			}
			Foo& operator=(Foo && rhs)  {
				m_str = std::move(rhs.m_str);
				cout << "moved =" << endl;
			}
		};

		vector<Foo> vf;
		//vf.push_back(Foo("push"));
		Foo f("test");
		vf.push_back(f);
		vf.emplace_back("emplace");
	}
	{
	//insert vs operator[]
		struct Foo
		{
			string m_str;
			Foo(const string & s="") :m_str(s) {
				cout << "constructor" << endl;
			}
			Foo(const Foo & rhs) :m_str(rhs.m_str) {
				cout << "copied" << endl;
			}
			Foo(Foo && rhs) :m_str(std::move(rhs.m_str)) {
				cout << "moved" << endl;
			}
			Foo& operator=(Foo && rhs) {
				m_str = std::move(rhs.m_str);
				cout << "moved =" << endl;
			}
			Foo& operator=(const Foo &) = default;
		};
		map<int, Foo> mp;
		Foo f1("insert"),f2("subscript");
		cout << "result" << endl;
		mp.insert({ 10,f1 });
		mp[20] = f2;

	}
	{
		//use set to create an ordered vector
	/*	multiset<int> s;
		int number;
		while (cin >> number)
			s.insert(number);
		vector<int> v(s.begin(), s.end());
		
		if (binary_search(v.begin(), v.end(), 10))
			cout << "10 is found" << endl;
		else cout << "10 is not found" << endl;

		auto range = equal_range(v.begin(), v.end(), 10);*/

	}
	{
		vector<int> v = { 3, 7, 3, 11, 3, 3, 2 };
		set<int> s(v.begin(), v.end());
		auto it1=find(s.begin(), s.end(), 10);
		auto it2 = s.find(10);
	}
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


