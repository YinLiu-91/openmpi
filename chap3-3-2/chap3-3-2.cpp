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


 //2020.09.04//3.5
#include <stdio.h>
#include <stdlib.h>
#include <mpi.h>

void Check_for_error(int local_ok, char fname[], char message[], MPI_Comm comm);
void Get_dims(int* m_p, int* local_m_p, int* n_p, int* local_n_p,
	int my_rank, int comm_sz, MPI_Comm comm);
void Allocate_arrays(double** local_A_pp, double** local_x_pp,
	double** local_y_pp, int m, int local_m, int local_n,
	MPI_Comm comm);
void Build_derived_type(int m, int local_m, int n, int local_n,
	MPI_Datatype* block_col_mpi_t_p);
void Read_matrix(char prompt[], double local_A[], int m, int local_n,
	int n, MPI_Datatype block_col_mpi_t, int my_rank, MPI_Comm comm);
void Print_matrix(char title[], double local_A[], int m, int local_n,
	int n, MPI_Datatype block_col_mpi_t, int my_rank, MPI_Comm comm);
void Read_vector(char prompt[], double local_vec[], int n, int local_n,
	int my_rank, MPI_Comm comm);
void Print_vector(char title[], double local_vec[], int n,
	int local_n, int my_rank, MPI_Comm comm);
void Mat_vect_mult(double local_A[], double local_x[],
	double local_y[], int local_m, int m, int n, int local_n,
	int comm_sz, MPI_Comm comm);


int main(int argc, char** argv)
{
	double* local_A;
	double* local_x;
	double* local_y;

	int m, n;
	int local_m, local_n;

	int my_rank, comm_sz;
	MPI_Comm comm;
	MPI_Datatype block_col_mpi_t;//??

	MPI_Init(&argc, &argv);
	comm = MPI_COMM_WORLD;
	MPI_Comm_size(comm, &comm_sz);
	MPI_Comm_rank(comm, &my_rank);

	Get_dims(&m, &local_m, &n, &local_n, my_rank, comm_sz, comm);
	Allocate_arrays(&local_A, &local_x, & local_y, m, local_m, local_n, comm);
	Build_derived_type(m, local_m, n, local_n, &block_col_mpi_t);
	Read_matrix("A", local_A, m, local_n, n, block_col_mpi_t, my_rank, comm);

#ifdef DEBUG
	Print_matrix("A", local_A, m, local_n, n, block_col_mpi_t, my_rank, comm);
#endif

	Read_vector("x", local_x, n, local_n, my_rank, comm);
#ifdef DEBUG
	Print_vector("x", local_x, n, local_m, my_rank, comm);
#endif

	Mat_vect_mult(local_A, local_x, local_y, local_m, m, n, local_n, comm_sz, comm);
	Print_vector("y", local_y, m, local_m, my_rank, comm);

	free(local_A);
	free(local_x);
	free(local_y);

	MPI_Type_free(&block_col_mpi_t);
	MPI_Finalize();
	


	return 0;
}

void Check_for_error(int local_ok, char fname[], char message[], MPI_Comm comm) {
	int ok;

	MPI_Allreduce(&local_ok, &ok, 1, MPI_INT, MPI_MIN, comm);//找到每个秩中的最小值
	if (ok == 0) {
		int my_rank;
		MPI_Comm_rank(comm, &my_rank);//得到进程的秩
		if (my_rank == 0) {
			fprintf(stderr, "Proc %d > In %s ,%s\n", my_rank, fname, message);
			fflush(stderr);
		}
		MPI_Finalize();
		exit(-1);
	}
}

void Get_dims(int* m_p, int* local_m_p, int* n_p, int* local_n_p, int my_rank, int comm_sz, MPI_Comm comm)
{
	int local_ok = 1;
	if (my_rank == 0) {
		printf("Enter the order of the matrix\n");
		scanf("%d", m_p);
	}
	MPI_Bcast(m_p, 1, MPI_INT, 0, comm);
	*n_p = *m_p;
	if (*m_p <= 0 || *m_p % comm_sz != 0)local_ok = 0;
	Check_for_error(local_ok, "Get_dims", "m and n must be positive and evenly divisible by comm_sz", comm);
	*local_m_p = *m_p / comm_sz;
	*local_n_p = *n_p / comm_sz;
}

void Allocate_arrays(double** local_A_pp, double** local_x_pp, double** local_y_pp, int m, int local_m, int local_n, MPI_Comm comm)
{
	int local_ok = 1;
	*local_A_pp = (double*)malloc(m * local_n * sizeof(double));
	*local_x_pp = (double*)malloc(local_n * sizeof(double));
	*local_y_pp = (double*)malloc(local_m * sizeof(double));

	if (*local_A_pp == nullptr || *local_x_pp == nullptr || local_y_pp == nullptr)
		local_ok = 0;

	Check_for_error(local_ok, "Allcate_arrays", "Can't allocate local arrays", comm);
}

void Build_derived_type(int m, int local_m, int n, int local_n, MPI_Datatype* block_col_mpi_t_p) {
	MPI_Datatype vect_mpi_t;


	MPI_Type_vector(m, local_n, n, MPI_DOUBLE, vect_mpi_t);

	MPI_Type_create_resized(vect_mpi_t, 0, local_n * sizeof(double), block_col_mpi_t_p);//创建一个新的下界并且其扩展自现有的数据类型的新的数据类型

	MPI_Type_commit(block_col_mpi_t_p);
}

void Read_matrix(char prompt[], double local_A[], int m, int local_n, int n, MPI_Datatype block_col_mpi_t, int my_rank, MPI_Comm comm)
{
	double* A = nullptr;
	int local_ok = 1;
	int i, j;

	if (my_rank == 0) {
		A = (double*)(m * n * sizeof(double));
		if (A == nullptr)local_ok = 0;
		Check_for_error(local_ok, "Read_matrix", "Can't allocate temporary matrix", comm);
		printf("Enter the matrix %s\n", prompt);

		for (int i = 0; i < m; ++i)
			for (j = 0; j < n; ++j)
				scanf("%lf", &A[i * n + j]);
		MPI_Scatter(A, 1, block_col_mpi_t, local_A, m * local_n, MPI_DOUBLE, 0, comm);
	}
}

void Print_matrix(char title[], double local_A[], int m, int local_n, int n, MPI_Datatype block_col_mpi_t, int my_rank, MPI_Comm comm)
{
	double* A = nullptr;
	int local_ok = 1;
	int i, j;

	if (my_rank == 0) {
		A = (double*)malloc(m * n * sizeof(double));
		if (A == nullptr)local_ok = 0;
		Check_for_error(local_ok, "Print_matrix", "Can't allocate temporary matrix ", comm);
		MPI_Gather(local_A, m * local_n, MPI_DOUBLE, A, 1, block_col_mpi_t, 0, comm);

		printf("The matrix %s\n", title);
		for (int i = 0; i < m; ++i) {
			for (j = 0; j < n; ++j)
				printf("%.2f ", A[i * n + j]);
			printf("\n");
		}
		free(A);
	}
	else {
		Check_for_error(local_ok, "Print_matrix",
			"Can't allocate temporary matrix", comm);
		MPI_Gather(local_A, m * local_n, MPI_DOUBLE, A, 1, block_col_mpi_t, 0, comm);
	}
}

void Read_vector(char prompt[], double local_vec[], int n, int local_n, int my_rank, MPI_Comm comm)
{
	double* vec = nullptr;
	int i, local_ok = 1;

	if (my_rank == 0) {
		vec = (double*)malloc(n * sizeof(double));
		if (vec == nullptr)local_ok = 0;
		Check_for_error(local_ok, "Read_vector", "Can't allocate temporary vector", comm);
		printf("Enter the vector %s\n", prompt);
		for (int i = 0; i < n; ++i)
			scanf("%lf", &vec[i]);
		MPI_Scatter(vec, local_n, MPI_DOUBLE, local_vec, local_n, MPI_DOUBLE, 0, comm);
		free(vec);
	}
	else {
		Check_for_error(local_ok, "Read_vector",
			"Can't allocate temporary vector", comm);
		MPI_Scatter(vec, local_n, MPI_DOUBLE, local_vec, local_n, MPI_DOUBLE, 0, comm);

	}
}


void Mat_vect_mult(double local_A[], double local_x[], double local_y[], int local_m, int m, int n, int local_n, int comm_sz, MPI_Comm comm)
{
	double* my_y;
	int* recv_counts;
	int i, loc_j;
	int local_ok = 1;

	recv_counts = (int*)malloc(comm_sz * sizeof(int));
	my_y = (double*) malloc(n * sizeof(double));
	if (recv_counts == nullptr || my_y == nullptr)local_ok = 0;
	Check_for_error(local_ok, "Mat_vect_mult", "Can't allocate temporary arrays", comm);
	for (int i = 0; i < m; ++i) {
		my_y[i] = 0.0;
		for (loc_j = 0; loc_j < local_n; ++loc_j)
			my_y[i] += local_A[i * local_n + loc_j] * local_x[loc_j];
	}

	for (i = 0; i < comm_sz; ++i) {
		recv_counts[i] = local_m;
	}

	MPI_Reduce_scatter(my_y, local_y, recv_counts, MPI_DOUBLE, MPI_SUM, comm);//combine values and scatters the results
	free(my_y);
}

void Print_vector(
	char      title[]     /* in */,
	double    local_vec[] /* in */,
	int       n           /* in */,
	int       local_n     /* in */,
	int       my_rank     /* in */,
	MPI_Comm  comm        /* in */) {
	double* vec = NULL;
	int i, local_ok = 1;

	if (my_rank == 0) {
		vec = (double*)(n * sizeof(double));
		if (vec == NULL) local_ok = 0;
		Check_for_error(local_ok, "Print_vector",
			"Can't allocate temporary vector", comm);
		MPI_Gather(local_vec, local_n, MPI_DOUBLE,
			vec, local_n, MPI_DOUBLE, 0, comm);
		printf("\nThe vector %s\n", title);
		for (i = 0; i < n; i++)
			printf("%f ", vec[i]);
		printf("\n");
		free(vec);
	}
	else {
		Check_for_error(local_ok, "Print_vector",
			"Can't allocate temporary vector", comm);

		MPI_Gather(local_vec, local_n, MPI_DOUBLE,
			vec, local_n, MPI_DOUBLE, 0, comm);
	}
}  /* Print_vector */
