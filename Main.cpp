#include<iostream>
#include"MatrixMult.h"


int main()
{

	//	Define matrix as double array and vector as simple array:
	std::cout << "============Test1: providing a compatible operands============" << std::endl;
	const float A1[2][3] = { {1.0f,2.0f,3.0f},{4.0f,5.0f,6.0f} };
	const float x1[2] = { 1.0f,2.0f };
	//float y1[3] = { 0,0,0 };
	float y1[3]{};

	//  x   *   A =   y
	//  1xN x MxR = 1xL ==> make sure that (N==M && R==L)
	//	Template paramaters are: <type:float or int,Dim_x:N ,Dim_A:MxR,Dim_y:L>
	MatrixMult<float, 2, 2, 3, 3>::vecmultmat(x1, A1, y1);


	//	Test 1: check the dimensions
	std::cout << "============Test2: providing a uncompatible operands============" << std::endl;
	const float x2[3] = { 1.0f / 3,1.0f / 6,1.0f / 9 };
	const float A2[3][3] = { {9,0,0},{0,9,0},{0,0,9} };
	float y2[2] = { 0, 0 };

	MatrixMult<float, 3, 3, 3, 2>::vecmultmat(x2, A2, y2);

	//	Test 2: multiply a vector by an identity matrix with int16
	std::cout << "============Test3: multiplying a vector by the identity matrix============" << std::endl;
	const int16_t x3[3] = { 20,2,-10 };
	const int16_t A3[3][3] = { {1,0,0},{0,1,0},{0,0,1} };
	int16_t y3[3] = { 0, 0, 0 };

	MatrixMult<int16_t, 3, 3, 3, 3>::vecmultmat(x3, A3, y3);

	//	Test 3: Test Template specialization for char type
	std::cout << "============Test4: the vector and the matrix are of char type============" << std::endl;
	const char x4[3] = { '1','2','3' };
	const char A4[3][3] = { {'9','0','0'},{'0','9','0'},{'0','0','9'} };
	char y4[3] = { '0', '0', '0' };

	MatrixMult<char, 3, 3, 3, 3>::vecmultmat(x4, A4, y4);

	std::cin.get();

}