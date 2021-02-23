#include<iostream>
using namespace std;

template<typename T>
class Array2D {
private:
	class Array1D {
		friend  class Array2D; //`{\color{green}声明为友元类}`
	public:
		~Array1D() { delete[] m_arr; }
		T & operator[](int idx) { return m_arr[idx]; }
	private:
		size_t m_size = 0; //`{\color{green}第二维长度}`
		T *m_arr = nullptr;
	};
	size_t m_size; //`{\color{green}第一维长度}`
	Array1D *m_arr; //`{\color{green}元素类型为Array1D}`
public:
	Array2D(size_t s1, size_t s2) :m_size(s1), m_arr(new Array1D[s1]) {
		for (int i = 0; i<m_size; i++) {
			m_arr[i].m_size = s2;
			m_arr[i].m_arr = new T[s2];
		}
	}
	~Array2D() { delete[] m_arr; }
	Array1D & operator[](int idx) { return m_arr[idx]; }
	size_t size() { return m_size; }
};

int main() {
	Array2D<int> arr(2, 2);
	arr[0][0] = 1;
	cout << arr[0][0] << endl;
}
