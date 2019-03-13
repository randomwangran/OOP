#include <iostream>
#include <time.h>  
#include <cstring>


class Array

{

public:

	Array(int S):Size(S)                          //构造函数

	{

		p = new double[Size];

	}

 

	Array(int S, double n):Size(S)        //构造函数

	{

		p = new double[Size];

		for (int i = 0; i < Size; i++)p[i] = n;

	}

 

	~Array()                       //析构函数

	{

		delete[] p;

	}

 

	Array & operator=(const Array & A)                      //重载=

	{

		if (this == &A)

			return *this;

		delete[] p;

		Size = A.Size;

		p = new double[Size];

		memcpy(p, A.p, Size * sizeof(double));

		return *this;

	}

 

	Array operator*(const Array & A)                 //对应元素*

	{

		Array result(Size);

		for (int i = 0; i < Size; i++)result.p[i] = p[i] * A.p[i];

		return result;

	}

 

private:

	int Size;

	double *p;

};

 

 

int main()

{

	clock_t time1, time2;

	Array A(10000, 1.0);

	Array B(10000, 1.0);

	Array C(10000, 1.0);

// 	time1 = clock();

// 	for (int t = 0; t < 1000000; t++)C = A * B;

// 	time2 = clock();

// 	std::cout<< "Time1 = " << (double)(time2 - time1) / CLOCKS_PER_SEC << "S" << std::endl;

// //测试直接使用double数组的速度

// 	double a[10000];

// 	double b[10000];

// 	double c[10000];

// 	for (int i = 0; i < 10000; i++)a[i] = 1, b[i] = 1;

 

// 	time1 = clock();

// 	for (int t = 0; t < 1000000; t++) 

// 		for (int i = 0; i < 10000; i++)c[i]=a[i] * b[i];

// 	time2 = clock();

// 	std::cout << "Time2 = " << (double)(time2 - time1) / CLOCKS_PER_SEC << "S" << std::endl;

 
	return 0;

}
