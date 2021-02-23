#ifndef ARRAY_H
#include <initializer_list>

//7.2.3
template<typename T>
struct Less{
	bool operator()(const T &a, const T &b) {
		return a < b;
	}
};

template<typename T, size_t N>
class Array {
private:
	T m_ele[N];
public:
	Array() {}
	Array(const std::initializer_list<T> &);
	T& operator[](size_t i);
	constexpr size_t size() {	return N;	}


	template<typename F = Less<T> >
	void selectionSort(F f = F());

	template<typename F = Less<T> >
	void insertionSort(F f = F());
	
	template<typename F = Less<T> >
	void bubbleSort(F f = F());

	int binarySearch(const T &, int left = 0, int right = N - 1);


	template<typename F = Less<T> >
	void quickSort(int left, int right, F f = F());

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

// 7.3.1 节
template<typename T, size_t N>
template<typename F >
void  Array<T, N>::selectionSort(F f) {
	for (int i = 0; i < N - 1; ++i){
		int min = i;  // record the position of the smallest
		for (int j = i + 1; j < N; ++j)	{
			// update min when finding a smaller element
			if (f(m_ele[j], m_ele[min]))
				min = j;
		}
		// put the smallest element at position i
		swap(i, min);
	}
}

// 7.3.1 节
template<typename T, size_t N>
template<typename F >
void  Array<T, N>::insertionSort(F f) {
	for (int i = 1, j; i < N; ++i) {
		// a temporary copy of the current element
		T t = m_ele[i];

		// find the position for insertion
		for (j = i; j > 0; --j) {
			if (f(m_ele[j - 1],  t))
				break;
			// shift the sorted part to right
			m_ele[j] = m_ele[j - 1];
		}

		// insert the current element
		m_ele[j] = t;
	}
}

// 7.3.1 节
template<typename T, size_t N>
template<typename F >
void  Array<T, N>::bubbleSort(F f){
	for (int i = N - 1; i >= 0; --i){
		// bubble up
		for (int j = 0; j <= i - 1; ++j)
		{
			if (f(m_ele[j + 1], m_ele[j]))
				swap(j, j + 1);
		}
	}
}

template<typename T, size_t N>
template<typename F >
void Array<T, N>::quickSort(int left, int right,F f) {
	if (left < right){
		int i = left, j = right;
		T x = m_ele[left];
		while (i < j)		{
			while (i < j && f(x,m_ele[j]))		// 从右向左找第一个小于x的数
				j--;
			if (i < j)
				m_ele[i++] = m_ele[j];
			while (i < j && f(m_ele[i],x))		// 从左向右找第一个大于等于x的数
				i++;
			if (i < j)
				m_ele[j--] = m_ele[i];
		}
		m_ele[i] = x;
		quickSort(left, i - 1,f); // 递归调用
		quickSort(i + 1, right,f);
	}
}

// 7.3.2 节
template<typename T, size_t N>
int Array<T, N>::binarySearch(const T &value, int left, int right) {
	while (left <= right) {
		int middle = (left + right) / 2;
		if (m_ele[middle] == value)
			return middle;
		else if (m_ele[middle] > value)
			right = middle - 1;
		else
			left = middle + 1;
	}
	return -1;
}

#endif // !ARRAY_H

