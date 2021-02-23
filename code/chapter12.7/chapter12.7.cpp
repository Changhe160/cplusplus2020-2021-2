#define _CRT_SECURE_NO_WARNINGS
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
#include<bitset>
#include<chrono>
#include<iomanip>
#include <ctime> 
using namespace std;



int main() {
	
	{
		tuple<string, double, int, list<string>> book("title", 58.99, 2017, { "Mandy","Lisha","Rosieta" });
		auto book2 = make_tuple(string("title"), 58.99, 2017, list<string>{ "Mandy", "Lisha", "Rosieta" });
		auto item1 = get<0>(book);
		get<1>(book) = 48.99;
		for (auto &i : get<3>(book))
			cout << i << " ";

		string title;
		double price;
		int year;
		list<string> author;
		if (book<book2)
			tie(title, price, year, author) = book;
		auto book3 = tie(title, price, year, author);
		cout << &get<1>(book3) << " " << &price << endl;
		cout << title << " " << price << " " << year << endl;
	}
	{
		bitset<12> b(1002);
		cout << b << endl;
		bitset<8> b1(1002);
		cout << b1 << endl;
		bitset<12> b2("110010");
		cout << b.to_ullong() << endl;
	}
	{
		using namespace chrono;

		//time_t tt = system_clock::to_time_t(system_clock::now());
		//auto ptm = localtime(&tt);
		//cout << put_time(ptm, "%F %T") << endl;

		time_t now = system_clock::to_time_t(system_clock::now()); 
		cout<< put_time(gmtime(&now), "\%F \%T") <<endl; 

		auto start = steady_clock::now();
		//DoSomething(); // 执行某些耗时的操作
		auto end = steady_clock::now();
		auto interval = duration_cast<milliseconds>(end - start);
		cout << interval.count() << endl;

	}
}