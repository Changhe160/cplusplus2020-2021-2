#ifndef ARRAY_H
#include <initializer_list>

//7.2.3
template<typename T>
struct Less{
	bool operator()(const T &a, const T &b) {
		return a < b;
	}
};

template<typename T, size_t N = 10>
class Array {
private:
	T m_ele[N];
public:
	Array() {}
	Array(const std::initializer_list<T> &);
	T& operator[](size_t i);
	constexpr size_t size() {	return N;	}

private:
	void swap(int i, int j){
		T t = m_ele[i];
		m_ele[i] = m_ele[j];
		m_ele[j] = t;
	}

};

template<typename T, size_t N>
Array<T, N>::Array(const std::initializer_list<T> &l) :m_ele{ T() } {
	size_t m = l.size() < N ? l.size() : N;
	for (size_t i = 0; i < m; ++i) {
		m_ele[i] = *(l.begin() + i);
	}
}
template<typename T, size_t N>
T& Array<T, N>::operator[](size_t i) {
	return m_ele[i];
}


#endif // !ARRAY_H

