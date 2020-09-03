////openmpi编程作业3-2.2020.09.03
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


//编程作业3-3./2020.09.03
//利用树形通信结构计算全局总和

#include <stdio.h>
#include <stdlib.h>
#include <mpi.h>

int Global_sum(int my_int, int my_rank, int comm_sz, MPI_Comm comm);
const int MAX_CONTRIB = 20;

int main(int argc, char** argv) {

	int i, sum, my_int;
	int my_rank, comm_sz;
	MPI_Comm comm;
	int* all_ints = nullptr;


	MPI_Init(&argc, &argv);
	comm = MPI_Comm;
	MPI_Comm_size(comm, &comm_sz);
	MPI_Comm_rank(comm, &my_rank);

	srand(my_rank + 1);
	my_int = rand() % MAX_CONTRIB;

	sum = Global_sum(my_int, my_rank, comm_sz, comm);

	if (my_rank == 0) {
		all_ints = (int*)malloc(comm_sz * sizeof(int));

		MPI_Gather(&my_int, 1, MPI_INT, all_ints, 1, MPI_INT, 0, comm);
		printf("Ints being summed:\n  ");
		for (int i = 0; i < comm_sz; ++i)
			printf("%d ", all_ints[i]);
		printf("\n");
		printf("Sum = %d\n", sum);
		free(all_ints);
	}
	else {
		MPI_Gather(&my_int, 1, MPI_INT, all_ints, 1, MPI_INT, 0, comm);
	}
	MPI_Finalize();
	return 0;
}
int Global_sum(int my_int, int my_rank, int comm_sz, MPI_Comm comm) {
	int partner, recvtemp;
	int my_sum = my_int;
	unsigned bitmask = 1;

	while (bitmask < comm_sz) {
		partner = my_rank ^ bitmask;

		if(my_rank < partner) {
			MPI_Recv(&recvtemp, 1, MPI_INT, partner, 0, comm, MPI_STATUS_IGNORE);
			my_sum += recvtemp;
			bitmask <<= 1;
		}
		else {
			MPI_Send(&my_sum, 1, MPI_INT, partner, 0, comm);
			break;
		}
	}
	return my_sum;
}