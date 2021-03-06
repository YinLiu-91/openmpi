﻿////openmpi编程作业3-2.2020.09.03
///*
//* 1.这里用到了MPI_Bcast和MPI_Reduce函数
//* 2.MPI_Bcast形式
//		 int MPI_Bcast(
//		 void *			data_p				//要广播的数据指针,
//		 int			count				//数量,
//		 MPI_Datatype	datatype			//数据类型,
//		 int			source_proc			//数据源的秩,
//		 MPI_Comm		comm				//属于哪一个通信子
//		 )
//*3.MPI_Reduce形式
//		 int MPI_Reduce(
//		 void*				input_data_p			//输人数据指针,
//		 void*				output_data_p			//输出数据指针,
//		 int				count					//数据数量,
//		 MPI_Datatype		datatype				//数据类型,
//		 MPI_Operator		operator				//操作符,
//		 int				dest_process			//目标进程的秩,
//		 MPI_Comm			comm					//属于的通信子
//		 )
//*/
//#include <stdio.h>
//#include <stdlib.h>
//#include <mpi.h>
//void Get_input(long long int* number_of_tosses, int my_rank, MPI_Comm comm);
//long long int Monte_carlo(long long number_of_tosses, int my_rank);
//
//int main(int argc, char** argv) {
//	
//		long long int number_of_tosses;
//		long long int local_number_of_tosses;
//		long long int number_in_circle;
//		long long int local_number_in_circle;
//
//		double pi_estimate;
//		int my_rank, comm_sz;
//		MPI_Comm comm;
//
//		MPI_Init(&argc, &argv);
//		comm = MPI_COMM_WORLD;
//		MPI_Comm_size(comm, &comm_sz);
//		MPI_Comm_rank(comm, &my_rank);
//
//		Get_input(&number_of_tosses, my_rank, comm);
//		local_number_of_tosses = number_of_tosses / comm_sz;
//
//#ifdef DEBUG
//		printf("Proc %d >number of tosses = %lld,local number= %lld\n",
//			my_rank, number_of_tosses, local_number_of_tosses);
//#endif
//		local_number_in_circle = Monte_carlo(local_number_of_tosses, my_rank);
//		MPI_Reduce(&local_number_of_tosses, &number_in_circle, 1, MPI_LONG_LONG, MPI_SUM, 0, comm);
//
//		if (my_rank == 0) {
//			pi_estimate = 4 * number_in_circle / ((double)number_of_tosses);
//			printf("pi estimate = %f\n", pi_estimate);
//		}
//		MPI_Finalize();
//	
//	return 0;
//}
//
//void Get_input(long long int* number_of_tosses, int my_rank, MPI_Comm comm) {
//	if (my_rank == 0) {
//		printf("Enter the total number of tosses\n");
//		scanf_s("%lld", number_of_tosses);
//	}
//	MPI_Bcast(number_of_tosses, 1, MPI_LONG_LONG, 0, comm);
//}
//
//
//long long int Monte_carlo(long long local_number_of_tosses, int my_rank) {
//	long long int i;
//	double x, y;
//	double distance_squared;
//	long long int number_in_circle = 0;
//
//	srand(my_rank + 1);
//	for (int i = 0; i < local_number_of_tosses; i++) {
//		x = 2 * rand() / ((double)RAND_MAX) - 1.0;
//		y = 2 * rand() / ((double)RAND_MAX) - 1.0;
//
//		distance_squared = x * x + y * y;
//#ifdef _DEBUG
//		printf("Proc %d > x= %f ,dist squared = %f\n", my_rank, x, y, distance_squared);
//#endif
//		if (distance_squared <= 1) {
//			number_in_circle++;
//		}
//
//
//	}
//
//	return number_in_circle;
//}
//}


////编程作业3-3./2020.09.03
////利用树形通信结构计算全局总和
//
//#include <stdio.h>
//#include <stdlib.h>
//#include <mpi.h>
//
//int Global_sum(int my_int, int my_rank, int comm_sz, MPI_Comm comm);
//const int MAX_CONTRIB = 20;
//
//int main(int argc, char** argv) {
//
//	int i, sum, my_int;
//	int my_rank, comm_sz;
//	MPI_Comm comm;
//	int* all_ints = nullptr;
//
//
//	MPI_Init(&argc, &argv);
//	comm = MPI_Comm;
//	MPI_Comm_size(comm, &comm_sz);
//	MPI_Comm_rank(comm, &my_rank);
//
//	srand(my_rank + 1);
//	my_int = rand() % MAX_CONTRIB;
//
//	sum = Global_sum(my_int, my_rank, comm_sz, comm);
//
//	if (my_rank == 0) {
//		all_ints = (int*)malloc(comm_sz * sizeof(int));
//
//		MPI_Gather(&my_int, 1, MPI_INT, all_ints, 1, MPI_INT, 0, comm);//反树形
//		printf("Ints being summed:\n  ");
//		for (int i = 0; i < comm_sz; ++i)
//			printf("%d ", all_ints[i]);
//		printf("\n");
//		printf("Sum = %d\n", sum);
//		free(all_ints);
//	}
//	else {
//		MPI_Gather(&my_int, 1, MPI_INT, all_ints, 1, MPI_INT, 0, comm);
//	}
//	MPI_Finalize();
//	return 0;
//}
//int Global_sum(int my_int, int my_rank, int comm_sz, MPI_Comm comm) {
//	int partner, recvtemp;
//	int my_sum = my_int;
//	unsigned bitmask = 1;
//
//	while (bitmask < comm_sz) {
//		partner = my_rank ^ bitmask;
//
//		if(my_rank < partner) {
//			MPI_Recv(&recvtemp, 1, MPI_INT, partner, 0, comm, MPI_STATUS_IGNORE);
//			my_sum += recvtemp;
//			bitmask <<= 1;
//		}
//		else {
//			MPI_Send(&my_sum, 1, MPI_INT, partner, 0, comm);
//			break;
//		}
//	}
//	return my_sum;
//}

/*---------------------------------------------------------------------------------------------------------*/

// //2020.09.04//3.5
//#include <stdio.h>
//#include <stdlib.h>
//#include <mpi.h>
//
//void Check_for_error(int local_ok,   char fname[], const  char message[], MPI_Comm comm);
//void Get_dims(int* m_p, int* local_m_p, int* n_p, int* local_n_p,
//	int my_rank, int comm_sz, MPI_Comm comm);
//void Allocate_arrays(double** local_A_pp, double** local_x_pp,
//	double** local_y_pp, int m, int local_m, int local_n,
//	MPI_Comm comm);
//void Build_derived_type(int m, int local_m, int n, int local_n,
//	MPI_Datatype* block_col_mpi_t_p);
//void Read_matrix(const char prompt[], double local_A[], int m, int local_n,
//	int n, MPI_Datatype block_col_mpi_t, int my_rank, MPI_Comm comm);
//void Print_matrix(const char title[], double local_A[], int m, int local_n,
//	int n, MPI_Datatype block_col_mpi_t, int my_rank, MPI_Comm comm);
//void Read_vector(const char prompt[], double local_vec[], int n, int local_n,
//	int my_rank, MPI_Comm comm);
//void Print_vector(const char title[], double local_vec[], int n,
//	int local_n, int my_rank, MPI_Comm comm);
//void Mat_vect_mult(double local_A[], double local_x[],
//	double local_y[], int local_m, int m, int n, int local_n,
//	int comm_sz, MPI_Comm comm);
//
//
//int main(int argc, char** argv)
//{
//	double* local_A;
//	double* local_x;
//	double* local_y;
//
//	int m, n;
//	int local_m, local_n;
//
//	int my_rank, comm_sz;
//	MPI_Comm comm;
//	MPI_Datatype block_col_mpi_t;//??自定义数据类型
//
//	MPI_Init(&argc, &argv);
//	comm = MPI_COMM_WORLD;
//	MPI_Comm_size(comm, &comm_sz);
//	MPI_Comm_rank(comm, &my_rank);
//
//	Get_dims(&m, &local_m, &n, &local_n, my_rank, comm_sz, comm);
//	Allocate_arrays(&local_A, &local_x, & local_y, m, local_m, local_n, comm);
//	Build_derived_type(m, local_m, n, local_n, &block_col_mpi_t);
//	Read_matrix("A", local_A, m, local_n, n, block_col_mpi_t, my_rank, comm);
//
//#ifdef DEBUG
//	Print_matrix("A", local_A, m, local_n, n, block_col_mpi_t, my_rank, comm);
//#endif
//
//	Read_vector("x", local_x, n, local_n, my_rank, comm);
//#ifdef DEBUG
//	Print_vector("x", local_x, n, local_m, my_rank, comm);
//#endif
//
//	Mat_vect_mult(local_A, local_x, local_y, local_m, m, n, local_n, comm_sz, comm);
//	Print_vector("y", local_y, m, local_m, my_rank, comm);
//
//	free(local_A);
//	free(local_x);
//	free(local_y);
//
//	MPI_Type_free(&block_col_mpi_t);
//	MPI_Finalize();
//	
//
//
//	return 0;
//}
//
//void Check_for_error(int local_ok, const char fname[], const  char message[], MPI_Comm comm) {
//	int ok;
//
//	MPI_Allreduce(&local_ok, &ok, 1, MPI_INT, MPI_MIN, comm);//找到每个秩中的最小值
//	if (ok == 0) {
//		int my_rank;
//		MPI_Comm_rank(comm, &my_rank);//得到进程的秩
//		if (my_rank == 0) {
//			fprintf(stderr, "Proc %d > In %s ,%s\n", my_rank, fname, message);
//			fflush(stderr);
//		}
//		MPI_Finalize();//程序出错，需要结束程序
//		exit(-1);
//	}
//}
//
////得到矩阵的大小，使得n=m；
//void Get_dims(int* m_p, int* local_m_p, int* n_p, int* local_n_p, int my_rank, int comm_sz, MPI_Comm comm)
//{
//	int local_ok = 1;
//	if (my_rank == 0) {
//		printf("Enter the order of the matrix\n");
//		scanf_s("%d", m_p);
//	}
//	MPI_Bcast(m_p, 1, MPI_INT, 0, comm);//需要向全体广播
//	*n_p = *m_p;//这里m和n相等
//	if (*m_p <= 0 || *m_p % comm_sz != 0)local_ok = 0;
//	Check_for_error(local_ok, "Get_dims", "m and n must be positive and evenly divisible by comm_sz", comm);
//	*local_m_p = *m_p / comm_sz;
//	*local_n_p = *n_p / comm_sz;
//}
//
//
////将矩阵开辟空间
//void Allocate_arrays(double** local_A_pp, double** local_x_pp, double** local_y_pp, int m, int local_m, int local_n, MPI_Comm comm)
//{
//	int local_ok = 1;
//	//矩阵A是利用一维数据代替二维数组
//	*local_A_pp = (double*)malloc(m * local_n * sizeof(double));//解引用指向指针的指针得到一个一级指针
//	*local_x_pp = (double*)malloc(local_n * sizeof(double));
//	*local_y_pp = (double*)malloc(local_m * sizeof(double));
//
//	if (*local_A_pp == nullptr || *local_x_pp == nullptr || local_y_pp == nullptr)
//		local_ok = 0;
//
//	Check_for_error(local_ok, "Allcate_arrays", "Can't allocate local arrays", comm);
//}
//
//
//
//void Build_derived_type(int m, int local_m, int n, int local_n, MPI_Datatype* block_col_mpi_t_p) {
//	MPI_Datatype vect_mpi_t;
//
//
//	MPI_Type_vector(m, local_n, n, MPI_DOUBLE, &vect_mpi_t);//创建一个向量数据类型
//
//	MPI_Type_create_resized(vect_mpi_t, 0, local_n * sizeof(double), block_col_mpi_t_p);//创建一个新的下界并且其扩展自现有的数据类型的新的数据类型
//
//	MPI_Type_commit(block_col_mpi_t_p);
//}
//
//
////读取矩阵
//void Read_matrix(const char prompt[], double local_A[], int m, int local_n, int n, MPI_Datatype block_col_mpi_t, int my_rank, MPI_Comm comm)
//{
//	double* A = nullptr;
//	int local_ok = 1;
//	int i, j;
//
//	if (my_rank == 0) {
//		A = (double*)malloc(m * n * sizeof(double));
//		if (A == nullptr)local_ok = 0;
//		Check_for_error(local_ok, "Read_matrix", "Can't allocate temporary matrix", comm);
//		printf("Enter the matrix %s\n", prompt);
//
//		for ( i = 0; i < m; ++i)
//			for (j = 0; j < n; ++j)
//				scanf_s("%lf", &A[i * n + j]);
//		//利用scatter将矩阵的其中一块分配到某一个进程上去
//		MPI_Scatter(A, 1, block_col_mpi_t, local_A, m * local_n, MPI_DOUBLE, 0, comm);
//		free(A);
//	}
//	else {
//		Check_for_error(local_ok, "Read_matrix",
//			"Can't allocate temporary matrix", comm);
//		MPI_Scatter(A, 1, block_col_mpi_t, local_A, m * local_n, MPI_DOUBLE,
//			0, comm);
//	}
//}
//
//void Print_matrix(const char title[], double local_A[], int m, int local_n, int n, MPI_Datatype block_col_mpi_t, int my_rank, MPI_Comm comm)
//{
//	double* A = nullptr;
//	int local_ok = 1;
//	int i, j;
//
//	if (my_rank == 0) {
//		A = (double*)malloc(m * n * sizeof(double));
//		if (A == nullptr)local_ok = 0;
//		Check_for_error(local_ok, "Print_matrix", "Can't allocate temporary matrix ", comm);
//		MPI_Gather(local_A, m * local_n, MPI_DOUBLE, A, 1, block_col_mpi_t, 0, comm);
//
//		printf("The matrix %s\n", title);
//		for (int i = 0; i < m; ++i) {
//			for (j = 0; j < n; ++j)
//				printf("%.2f ", A[i * n + j]);
//			printf("\n");
//		}
//		free(A);
//	}
//	else {
//		Check_for_error(local_ok, "Print_matrix",
//			"Can't allocate temporary matrix", comm);
//		MPI_Gather(local_A, m * local_n, MPI_DOUBLE, A, 1, block_col_mpi_t, 0, comm);
//	}
//}
//
//void Read_vector(const char prompt[], double local_vec[], int n, int local_n, int my_rank, MPI_Comm comm)
//{
//	double* vec = nullptr;
//	int i, local_ok = 1;
//
//	if (my_rank == 0) {
//		vec = (double*)malloc(n * sizeof(double));
//		if (vec == nullptr)local_ok = 0;
//		Check_for_error(local_ok, "Read_vector", "Can't allocate temporary vector", comm);
//		printf("Enter the vector %s\n", prompt);
//		for (int i = 0; i < n; ++i)
//			scanf_s("%lf", &vec[i]);
//		MPI_Scatter(vec, local_n, MPI_DOUBLE, local_vec, local_n, MPI_DOUBLE, 0, comm);
//		free(vec);
//	}
//	else {
//		Check_for_error(local_ok, "Read_vector",
//			"Can't allocate temporary vector", comm);
//		MPI_Scatter(vec, local_n, MPI_DOUBLE, local_vec, local_n, MPI_DOUBLE, 0, comm);
//
//	}
//}
//
//
//void Mat_vect_mult(double local_A[], double local_x[], double local_y[], int local_m, int m, int n, int local_n, int comm_sz, MPI_Comm comm)
//{
//	double* my_y;
//	int* recv_counts;
//	int i, loc_j;
//	int local_ok = 1;
//
//	recv_counts = (int*)malloc(comm_sz * sizeof(int));
//	my_y = (double*) malloc(n * sizeof(double));//下面循环是my_y[i]是m大小
//	if (recv_counts == nullptr || my_y == nullptr)local_ok = 0;
//	Check_for_error(local_ok, "Mat_vect_mult", "Can't allocate temporary arrays", comm);
//	for ( i = 0; i < m; ++i) {
//		my_y[i] = 0.0;
//		for (loc_j = 0; loc_j < local_n; ++loc_j)
//			my_y[i] += local_A[i * local_n + loc_j] * local_x[loc_j];
//	}
//
//	for (i = 0; i < comm_sz; ++i) {
//		recv_counts[i] = local_m;
//	}
//	//因为是按列分块，但是矩阵相乘是一行乘以一个向量。所以矩阵每一行的结果是分布在不同
//	//线程上的，所以需要reduce，就是需要将每个线程上的my_y（表示某某一行此线程上的乘积和
//	//相加得到矩阵此行的结果。scatter用来修饰reduce？？？
//	MPI_Reduce_scatter(my_y, local_y, recv_counts, MPI_DOUBLE, MPI_SUM, comm);//combine values and scatters the results
//	free(my_y);
//}
//
//void Print_vector(
//	const char      title[]     /* in */,
//	double    local_vec[] /* in */,
//	int       n           /* in */,
//	int       local_n     /* in */,
//	int       my_rank     /* in */,
//	MPI_Comm  comm        /* in */) {
//	double* vec = NULL;
//	int i, local_ok = 1;
//
//	if (my_rank == 0) {
//		vec = (double*)(n * sizeof(double));
//		if (vec == NULL) local_ok = 0;
//		Check_for_error(local_ok, "Print_vector",
//			"Can't allocate temporary vector", comm);
//		MPI_Gather(local_vec, local_n, MPI_DOUBLE,
//			vec, local_n, MPI_DOUBLE, 0, comm);
//		printf("\nThe vector %s\n", title);
//		for (i = 0; i < n; i++)
//			printf("%f ", vec[i]);
//		printf("\n");
//		free(vec);
//	}
//	else {
//		Check_for_error(local_ok, "Print_vector",
//			"Can't allocate temporary vector", comm);
//
//		MPI_Gather(local_vec, local_n, MPI_DOUBLE,
//			vec, local_n, MPI_DOUBLE, 0, comm);
//	}
//}  /* Print_vector */



/*---------------------------------------------------------------------------------------------------------*/



////2020.09.06
////3.6
//#include <stdlib.h>
//#include <stdio.h>
//#include <math.h>
//#include <string.h>
//#include<mpi.h>
//
//int my_rank, comm_sz;
//int row_comm_sz, col_comm_sz, diag_comm_sz;
//int my_row_rank, my_col_rank, my_diag_rank;
//MPI_Comm comm, row_comm, col_comm, diag_comm;
//int diag, which_row_comm, which_col_comm;
//MPI_Datatype submat_mpi_t;
//int* distrib_counts, * distrib_disps;
//
//void Build_comms(void);
//void Build_diag_comm(void);
//void Check_for_error(int loc_ok, const  char fname[], const  char message[]);
//void Get_dims(int* m_p, int* loc_m_p, int* n_p, int* loc_n_p);
//void Allocate_arrays(double** loc_A_pp, double** loc_x_pp,
//	double** loc_y_pp, int m, int loc_m, int n, int loc_n);
//void Init_distrib_data(int m, int loc_m, int n, int loc_n);
//void Read_matrix(const char prompt[], double loc_A[], int m, int loc_m,
//	int n, int loc_n);
//void Print_matrix(const char title[], double loc_A[], int m, int loc_m,
//	int n, int loc_n);
//void Read_vector(const char prompt[], double loc_vec[], int n, int loc_n);
//void Print_vector(const char title[], double loc_vec[], int n, int loc_n);
//void Mat_vect_mult(const double loc_A[], double loc_x[],
//	double loc_y[], int m, int loc_m, int n, int loc_n);
//void Print_loc_vects(const char title[], double loc_vec[], int loc_n);
//
//
//int main(int argc, char** argv)
//{
//	double* loc_A;
//	double* loc_x;
//	double* loc_y;
//
//	int m, n;
//	int loc_m, loc_n;
//
//
//	MPI_Init(&argc, &argv);
//
//	Build_comms();
//	Build_diag_comm();
//#ifdef DEBUG
//	printf("Proc %d >row_comm_sz=%d ,clo_comm_sz= %d\n",
//		my_rank, row_comm_sz, col_comm_sz);
//	fflush(stdout);
//#endif
//
//	Get_dims(&m, &loc_m, &n, &loc_n);
//	Allocate_arrays(&loc_A, &loc_x, &loc_y, m, loc_m, n, loc_n);
//	Init_distrib_data(m, loc_m, n, loc_n);
//
//	Read_matrix("A", loc_A, m, loc_m, n, loc_n);
//
//#ifdef  DEBUG
//	Print_matrix("A", loc_A, m, loc_m, n, loc_n);
//#endif //  DEBUG
//
//	Read_vector("x", loc_x, n, loc_n);
//#ifdef DEBUG
//	Print_vector("x", loc_x, n, loc_n);
//#endif
//	Mat_vect_mult(loc_A, loc_x, loc_y, m, loc_m, n, loc_n);
//
//	Print_vector("y", loc_y, m, loc_m);
//
//	free(loc_A);
//	free(loc_x);
//	free(distrib_counts);
//	free(distrib_disps);
//
//	MPI_Type_free(&submat_mpi_t);
//	MPI_Comm_free(&comm);
//	MPI_Comm_free(&row_comm);
//	MPI_Comm_free(&col_comm);
//	if (diag)MPI_Comm_free(&diag_comm);
//	MPI_Finalize();
//	
//
//
//
//	return 0;
//}
//
//void Check_for_error(int loc_ok, const char fname[], const char message[])
//{
//	int ok;
//
//	MPI_Allreduce(&loc_ok, &ok, 1, MPI_INT, MPI_MIN, comm);
//	if (ok == 0) {
//		int my_rank;
//		MPI_Comm_rank(comm, &my_rank);
//		if (my_rank == 0) {
//			fprintf_s(stderr, "Proc %d >In %s, %s\n", my_rank, fname,
//				message);
//			fflush(stderr);
//		}
//		MPI_Finalize();
//		exit(-1);
//	}
//}
//
//void Get_dims(int* m_p, int* loc_m_p, int* n_p, int* loc_n_p) {
//	int loc_ok = 1;
//	if (my_rank == 0)
//	{
//		printf_s("Enter the order of the matrix\n");
//		scanf_s("%d", m_p);
//	}
//	MPI_Bcast(m_p, 1, MPI_INT, 0, comm);
//	*n_p = *m_p;
//	if (*m_p <= 0 || *m_p % col_comm_sz != 0)loc_ok = 0;
//	Check_for_error(loc_ok,"Get_dims",
//		"order must be positive and evenly divisible by sqrt(comm_sz)");
//
//	*loc_m_p = *m_p / col_comm_sz;
//	*loc_n_p = *n_p / row_comm_sz;
//}//




///*---------------------------------------------------------------------------------------------------------*/
//
//
////p98 3.7题
//#include <stdio.h>
//#include <stdlib.h>
//#include <string.h>
//#include <time.h>
//#include "mpi.h"
//
//#ifndef DEBUG
//#define WARMUP_ITERS 10
//#define RES_TEST_ITERS 10
//#define PING_PONG_ITERS 1000
//#define MIN_MESG_SIZE 0
//#define MAX_MESG_SIZE 131072
//#define INCREMENT 1024
//#define TEST_COUNT 1
//#endif
//
//
//#ifdef DEBUG
//#define WARMUP_ITERS 1
//#define RES_TEST_ITERS 1
//#define PING_PONG_ITERS 1
//#define MIN_MESG_SIZE 2
//#define MAX_MESG_SIZE 4
//#define INCREMENT 2
//#define TEST_COUNT 1
//#endif
//
//const double clocks_per_sec = (double)CLOCKS_PER_SEC;
//
//void print_buffer(char mesg[], int mesg_size, int my_rank);
//double ping_pong(char mesg[], int mesg_size, int iters, MPI_Comm comm,
//	int p, int my_rank);
//int next_size(int current_size);
//
//int main(int argc, char** argv) {
//
//	int test, mesg_size, i;
//	double elapsed;
//	double times[TEST_COUNT];
//	char message[MAX_MESG_SIZE];
//	char c = 'B';
//	MPI_Comm comm;
//	int p;
//	int my_rank;
//
//	MPI_Init(&argc, &argv);
//	comm = MPI_COMM_WORLD;
//	MPI_Comm_size(comm, &p);
//	MPI_Comm_rank(comm, &my_rank);
//	if (p != 2) {
//		if (my_rank == 0)
//			fprintf_s(stderr, "Use two processes\n");
//		MPI_Finalize();
//		return 0;
//	}
//
//	if (my_rank == 0)
//		c = 'A';
//	for (i = 0; i < MAX_MESG_SIZE; ++i)
//		message[i] = c;
//
//	/* warmup */
//	elapsed = ping_pong(message, MAX_MESG_SIZE, WARMUP_ITERS, comm, p, my_rank);
//
//	/* Resolution */
//	elapsed = ping_pong(message, 0, RES_TEST_ITERS, comm, p, my_rank);
//	if (my_rank == 0)
//#ifndef CLOCK
//		fprintf_s(stderr, "Min ping_pong = %8.5e,Clock tick = %8.5e\n", elapsed / (2 * RES_TEST_ITERS), MPI_Wtick());
//#     else
//		fprintf(stderr, "Min ping_pong = %8.5e, Clock tick = %8.5e\n",
//			elapsed / (2 * RES_TEST_ITERS), 1.0 / clocks_per_sec);
//#     endif
//
//	for (mesg_size = MIN_MESG_SIZE; mesg_size <= MAX_MESG_SIZE;
//		mesg_size = next_size(mesg_size)) {
//		for (test = 0; test < TEST_COUNT; test++) {
//			times[test] = ping_pong(message, mesg_size, PING_PONG_ITERS,
//				comm, p, my_rank);
//		}  /* for test */
//
//		if (my_rank == 0) {
//			for (test = 0; test < TEST_COUNT; test++)
//				printf("%d %8.5e\n", mesg_size,
//					times[test] / (2 * PING_PONG_ITERS));
//		}
//	} /* for mesg_size */
//
//	MPI_Finalize();
//	return 0;
//}
//
//
//double ping_pong(char mesg[], int mesg_size, int iters, MPI_Comm comm, int p, int my_rank)
//{
//	int i;
//	MPI_Status status;
//	double start;
//
//	if (my_rank == 0) {
//#ifndef CLOCK
//		start = MPI_Wtime();
//# else
//		start = clock() / CLOCKS_PER_SEC;
//#endif
//		for (i = 0; i < iters; ++i) {
//			MPI_Send(mesg, mesg_size, MPI_CHAR, 1, 0, comm);
//			MPI_Recv(mesg, mesg_size, MPI_CHAR, 0, comm, &status);
//		}
//#ifndef CLOCK
//		return MPI_Wtime() - start;
//#else
//		return clock() / CLOCKS_PER_SEC - start;
//#endif
//	}
//	else if (my_rank == 1) {
//		for (i = 0; i < iters; i++) {
//			MPI_Recv(mesg, mesg_size, MPI_CHAR, 0, 0, comm, &status);
//#        ifdef DEBUG
//			print_buffer(mesg, mesg_size, 1);
//#        endif
//			MPI_Send(mesg, mesg_size, MPI_CHAR, 0, 0, comm);
//		}
//
//	}
//	return 0.0;
//}
//
///*-------------------------------------------------------------------*/
//void print_buffer(char mesg[], int mesg_size, int my_rank) {
//	char temp[MAX_MESG_SIZE + 1];
//
//	memcpy(temp, mesg, mesg_size);
//	temp[mesg_size] = '\0';
//	printf("Process %d > %s\n", my_rank, temp);
//	fflush(stdout);
//}  /* print_buffer */
//
//
///*-------------------------------------------------------------------*/
//int next_size(int current_size) {
//	/* return current_size + INCREMENT; */
//
//	if (current_size == 0)
//		return 1;
//	else
//		return 2 * current_size;
//
//}  /* next_size */


/*---------------------------------------------------------------------------------------------------------*/
							//3.4

//#include <stdio.h>
//#include <string.h>
//#include <mpi.h>
//
//const int MAX_STRING = 100;
//
//int main(int argc, char** argv)
//{
//	int src;
//	char msg[MAX_STRING];
//
//	int my_rank, comm_sz;
//	MPI_Comm comm;//mpi_comm是变量名
//
//	MPI_Init(&argc, &argv);
//	comm = MPI_COMM_WORLD;
//	MPI_Comm_size(comm, &comm_sz);
//	MPI_Comm_rank(comm, &my_rank);
//
//	if (my_rank == 0)
//	{
//		printf_s("Proc %d of %d >Does anyone have a tothpick?\n", my_rank, comm_sz);
//		for (src = 1; src < comm_sz; ++src)
//		{
//			MPI_Recv(msg, MAX_STRING, MPI_CHAR, src, 0, comm, MPI_STATUS_IGNORE);
//			printf_s("%s", msg);
//
//		}
//
//	}
//	else
//	{
//		sprintf_s(msg, "Proc %d of %d >Does anyone have a tothpick?\n", my_rank, comm_sz);
//		MPI_Send(msg, strlen(msg) + 1, MPI_CHAR, 0, 0, comm);
//	}
//
//	MPI_Finalize();
//	return 0;
//
//}
/*---------------------------------------------------------------------------------------------------------*/


/*---------------------------------------------------------------------------------------------------------*/
				//3.7
//#include <mpi.h>
//#include <stdlib.h>
//#include <stdio.h>
//#include <string.h>
//
//const int n = 4;
//
//void Set_buf(int x[], int n);
//void Print_buf(char title[], int x[], int n);
//
//int main(int argc, char** argv)
//{
//	int p, my_rank;
//	MPI_Comm comm;
//
//	int x[n], y[n];
//
//	MPI_Init(&argc, &argv);
//	comm = MPI_COMM_WORLD;
//	MPI_Comm_size(comm, &p);
//	MPI_Comm_rank(comm, &my_rank);
//
//	if (p > 1) {
//		if (my_rank == 0)
//			fprintf_s(stderr, "Only run with one process\n");
//		MPI_Finalize();
//		exit(0);
//	}
//
//	Set_buf(x, n);
//	MPI_Bcast(x, n, MPI_INT, 0, comm);
//	Print_buf("After bcast x = ", x, n);
//
//	Set_buf(x, n);
//	memset(y, 0, n * sizeof(int));
//	MPI_Gather(x, n, MPI_INT, y, n, MPI_INT, 0, comm);
//	Print_buf("After gather y = ", y, n);
//
//	memset(y, 0, n * sizeof(int));
//	Set_buf(x, n);
//	MPI_Scatter(x, n, MPI_INT, y, n, MPI_INT, 0, comm);
//	Print_buf("After scatter y = ", y, n);
//
//	Set_buf(x, n);
//	memset(y, 0, n * sizeof(int));
//	MPI_Allgather(x, n, MPI_INT, y, n, MPI_INT, comm);
//	Print_buf("After Allgather y = ", y, n);
//
//	Set_buf(x, n);
//	memset(y, 0, n * sizeof(int));
//	MPI_Reduce(x, y, n, MPI_INT, MPI_SUM, 0, comm);
//	Print_buf("After reduce y = ", y, n);
//
//	Set_buf(x, n);
//	memset(y, 0, n * sizeof(int));
//	MPI_Allreduce(x, y, n, MPI_INT, MPI_SUM, comm);
//	Print_buf("After Allreduce y = ", y, n);
//
//	MPI_Finalize();
//	return 0;
//}  /* main */
//
//
///*-------------------------------------------------------------------*/
//void Set_buf(int x[], int n) {
//	int i;
//
//	for (i = 0; i < n; i++)
//		x[i] = i + 1;
//}  /* Set_buf */
//
//
///*-------------------------------------------------------------------*/
//void Print_buf(   char[] title, int x[], int n) {
//	int i;
//
//	printf("%s ", title);
//	for (i = 0; i < n; i++)
//		printf("%d ", x[i]);
//	printf("\n");
//}  /* Print_buf */


///*---------------------------------------------------------------------------------------------------------*/
////p3.11(a)
//#include <stdio.h>
//#include <stdlib.h>
//#include <string.h>
//#include <vector>
//void Read_vector(const char prompt[], double vect[], int n);
//void Print_vector(const char title[], double vect[], int n);
//void Compute_prefix_sums(double vect[], double prefix_sums[], int n);
//
//int main(int argc, char** argv)
//{
//	double* vect, * prefix_sums;
//	int n;
//
//	if (argc != 2) {
//		fprintf_s(stderr, "usage: %s <order of vector>\n", argv[0]);
//		exit(0);
//	}
//
//	n = strtol(argv[1], nullptr, 10);
//	vect = (double*)malloc(n * sizeof(double));
//	prefix_sums = (double*)malloc(n * sizeof(double));
//
//	Read_vector("Enter the vector", vect, n);
//	Print_vector("Input vector", vect, n);
//	Compute_prefix_sums(vect, prefix_sums, n);
//	Print_vector("Prefix sums", prefix_sums, n);
//
//	free(vect);
//	free(prefix_sums);
//
//
//
//	return 0;
//}
//
//
///*---------------------------------------------------------------------------*/
//void Read_vector(const char prompt[], double vect[], int n)
//{
//	int i;
//	printf_s("%s\n", prompt);
//	for (int i = 0; i < n; i++)
//		//scanf_s("%lf", &vect[i]);
//		vect[i] = i;
//
//}
//
///*------------------------------------------------------------------------------*/
//void Print_vector(const char title[], double vect[], int n)
//{
//	int i;
//
//	printf_s("%s \n  ", title);
//	for (int i = 0; i < n; ++i)
//		printf_s("%.2f \n", vect[i]);
//	printf_s("\n");
//}
//
///*-----------------------------------------------------------------------------*/
//void Compute_prefix_sums(double vect[], double prefix_sums[], int n)
//{
//	int i;
//
//	prefix_sums[0] = vect[0];
//	for (i = 1; i < n; ++i)
//		prefix_sums[i]=prefix_sums[i - 1] + vect[i];
//}


///*---------------------------------------------------------------------------*/
/// //p3.11(b)
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <mpi.h>

void Check_for_error(int local_ok, char fname[], char message[]);
void Get_n(int argc, char* argv[], int* n_p, int* local_n_p);
void Read_vector(const char prompt[], double loc_vect[], int n, int loc_n);
void Print_vector(const char title[], double loc_vect[], int n, int loc_n);
void Compute_prefix_sums(double loc_vect[], double loc_prefix_sums[],
	int n, int loc_n);

int my_rank, comm_sz;
MPI_Comm comm;

int main(int argc, char* argv[]) {
	int i = 0, &i_r = i;
	
	double* loc_vect, * loc_prefix_sums;
	int n, loc_n;

	MPI_Init(&argc, &argv);
	comm = MPI_COMM_WORLD;
	MPI_Comm_rank(comm, &my_rank);
	MPI_Comm_size(comm, &comm_sz);

	Get_n(argc, argv, &n, &loc_n);
	loc_vect = (double*)malloc(loc_n * sizeof(double));
	loc_prefix_sums = (double*)malloc(loc_n* sizeof(double));

	Read_vector("Enter the vector", loc_vect, n, loc_n);
	Print_vector("Input vector", loc_vect, n, loc_n);
	Compute_prefix_sums(loc_vect, loc_prefix_sums, n, loc_n);
	Print_vector("Prefix sums", loc_prefix_sums, n, loc_n);

	free(loc_vect);
	free(loc_prefix_sums);

	MPI_Finalize();

	return 0;
}

/*-------------------------------------------------------------------*/
void Check_for_error(
	int       local_ok   /* in */,
	char      fname[]    /* in */,
	char      message[]  /* in */) {
	int ok;

	MPI_Allreduce(&local_ok, &ok, 1, MPI_INT, MPI_MIN, comm);
	if (ok == 0) {
		int my_rank;
		MPI_Comm_rank(comm, &my_rank);
		if (my_rank == 0) {
			fprintf(stderr, "Proc %d > In %s, %s\n", my_rank, fname,
				message);
			fflush(stderr);
		}
		MPI_Finalize();
		exit(-1);
	}
}  /* Check_for_error */