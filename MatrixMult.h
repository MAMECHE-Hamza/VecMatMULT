#pragma once
#include<chrono>
template<typename T = float, size_t N = 1, size_t M = 1, size_t R = 1, size_t L = 1>
class MatrixMult
{
public:
	struct timer
	{
		std::chrono::steady_clock::time_point  start_time, end_time;
		std::chrono::steady_clock::duration elapsed_time;
		timer() : start_time(std::chrono::steady_clock::now()), end_time({}), elapsed_time({})
		{

		}

		~timer()
		{
			end_time = std::chrono::steady_clock::now();
			elapsed_time = end_time - start_time;
			std::cout << "elapsd time = " << elapsed_time.count() / 1000000.0f << "ms" << std::endl;
		}
	};

	MatrixMult() = delete;
	~MatrixMult() = delete;

	// cast to T at the function call to force unique type among paramaters and to get compile-time error if the inputs type and T are different -> type safe
	static void vecmultmat(const T vector[N], const T matrix[M][R], T outvector[L])
	{
		//	timer
		timer function_timer{};
		
		//   x   *   A =   y
		//   1xN x MxR = 1xL ==> check if (N==M && R==L)
		if (!(N == M && R == L))
		{
			std::cout << "Incompatible sizes! Make sure to enter the template paramaters correctly" << std::endl;
		}
		else
		{
			for (size_t i = 0; i < N; ++i)
				for (size_t j = 0; j < L; ++j) //	Put j (the matrix columns index) in the 
				{							   //	inner loop to decrease cache readings
					if (i == 0) outvector[j] = (T)0;  //	Initialize the output vector
					outvector[j] += vector[i] * matrix[i][j];
				}
			std::cout << "Vector = ";
			printvector(vector);
			std::cout << "Matrix = ";
			MatrixMult<T, M, R>::printmatrix(matrix);
			std::cout << "Vector*Matrix = ";
			MatrixMult<T, L>::printvector(outvector);

		}

	}
	static void printmatrix(const T matrix[N][M])
	{
		for (size_t i = 0; i < N; ++i)
		{
			std::cout << "\n\t[";
			for (size_t j = 0; j < M; ++j)
			{
				std::cout << " " << matrix[i][j];
			}
			std::cout << " ]";
		}
		std::cout << std::endl;
	}
	static void printvector(const T vector[N])
	{
		std::cout << "\n\t[";
		for (size_t i = 0; i < N; ++i)
		{
			std::cout << " " << vector[i];
		}
		std::cout << " ]" << std::endl;
	}
};

//	Template specialization for char type; This is just one sample, need more specializations for other char types like unsigned char ...
template<size_t N, size_t M, size_t R, size_t L>
class MatrixMult<char, N, M, R, L>
{
public:
	MatrixMult() = delete;
	~MatrixMult() = delete;

	static void vecmultmat(const char vector[N], const char matrix[M][R], char outvector[L])
	{
		std::cout << "Datatype must be numerical!" << std::endl;
	}
	static void printmatrix(const char matrix[N][M])
	{
		std::cout << "Datatype must be numerical!" << std::endl;
	}
	static void printvector(const char vector[N])
	{
		std::cout << "Datatype must be numerical!" << std::endl;
	}
};


