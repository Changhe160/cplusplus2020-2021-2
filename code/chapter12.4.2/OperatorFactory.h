/**************************************************************************
ObjectFactory class only for Operator 
**************************************************************************/

#ifndef OPERATORFACTORY_H
#define OPERATORFACTORY_H

#include<string>
#include<map>
#include<functional>
#include<memory>
#include"Operator.h"

// 注册Object的宏声明
#define REGISTRAR(T, Key)  Factory::RegisterClass<T> reg_##T(Key);

using namespace std;

class Factory{
public:
	template<typename T>
	struct RegisterClass {
		RegisterClass(char opr) {
			Factory::ms_operator.emplace(opr, []{return make_unique<T>();});
		}
	};

	static unique_ptr<Operator> create(char opr) {
		auto it = ms_operator.find(opr);
		if (it != ms_operator.end())
			return it->second();
		else
			throw "Unregisted operator";
	}
//private:
	static map<char, function<unique_ptr<Operator>()>> ms_operator; // 存储已注册运算符名及对应构建函数指针的map
};

#endif


