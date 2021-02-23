#pragma once
#ifndef GOO_H
#define GOO_H
namespace Wang {
	namespace Goo {
		int doSomething(int x, int y) {
			return x - y;
		}
	}
	namespace Boo {
		class Y {};
	}
}
namespace FistVersion {
	void fun(int) {}
}
inline namespace SecondVersion {
	void fun(int) {}
	void fun(double) {}
}
#endif // !GOO_H
