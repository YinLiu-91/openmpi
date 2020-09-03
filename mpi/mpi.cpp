// mpi.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

//#include <iostream>
//#include<mpi.h>
//int main()
//{
//   
//    std::cout << "Hello World!\n";
//}
//
//// 运行程序: Ctrl + F5 或调试 >“开始执行(不调试)”菜单
//// 调试程序: F5 或调试 >“开始调试”菜单
//
//// 入门使用技巧: 
////   1. 使用解决方案资源管理器窗口添加/管理文件
////   2. 使用团队资源管理器窗口连接到源代码管理
////   3. 使用输出窗口查看生成输出和其他消息
////   4. 使用错误列表窗口查看错误
////   5. 转到“项目”>“添加新项”以创建新的代码文件，或转到“项目”>“添加现有项”以将现有代码文件添加到项目
////   6. 将来，若要再次打开此项目，请转到“文件”>“打开”>“项目”并选择 .sln 文件


//#include "mpi.h"
//#include<stdlib.h>
//#include<stdio.h>
//int main(int argc, char* argv[]) {
//	int numtasks, rank, rc;
//	rc = MPI_Init(&argc, &argv);//必须有 
//	if (rc != MPI_SUCCESS) {
//		printf("Error starting MPI program. Terminating.\n"); MPI_Abort(MPI_COMM_WORLD, rc);
//	}
//	MPI_Comm_size(MPI_COMM_WORLD, &numtasks);
//	MPI_Comm_rank(MPI_COMM_WORLD, &rank);
//	
//	printf("Number of tasks= %d My rank= %d\n", numtasks, rank);
//	MPI_Finalize();//必须有
//}


////并行不能用debug模式
//#include <thread>
//#include<ctime>
//#include"thread_pool.hpp"
//#include<vector>
//#include<omp.h>
//size_t num = 0;
//size_t num1 = 0;
//size_t num2 = 0;
//size_t num3 = 0;
//size_t num4 = 0;
//int a = 1;
//int N = 10000000000;
//int N1 = 10000000000;
//int N2 = 10000000000;
//int N3 = 10000000000;
//int N4 = 10000000000;
//void fun()
//{
//	for (int i = 0; i < N; ++i)
//		num += a;
//}
//void fun1()
//{
//	for (int i = 0; i < N; ++i)
//		num1 += a;
//}
//void fun2()
//{
//	for (int i = 0; i < N; ++i)
//		num2 += a;
//}
//void fun3()
//{
//	for (int i = 0; i < N; ++i)
//		num3 += a;
//}
//void fun4()
//{
//	for (int i = 0; i < N; ++i)
//		num4 += a;
//}
//int main()
//{
//	
//	std::clock_t st, end;
//	st = std::clock();
//#pragma omp parallel for num_threads(5)
//	{
//		for (int i = 0; i < 30; ++i)
//		{
//			//fun();
//			std::vector<std::thread>ith;
//			for (int i = 0; i < 10; ++i)
//			{
//				ith.push_back(std::thread(fun));
//				//ith[i].join();
//			}
//			for (int i = 0; i < 10; ++i)
//				ith[i].join();
//
//			//std::thread t1(fun);
//			////t1.join();
//			//std::thread t2(fun1);
//			////t2.join();
//			//std::thread t3(fun2);
//			////t3.join();
//			//std::thread t4(fun3);
//			////t4.join();
//			//std::thread t5(fun4);
//			//t1.join();
//			//t2.join();
//			//t3.join();
//			//t4.join();
//			//t5.join();
//
//
//		}
//	}
//	end = std::clock();
//	double tiem = double(end - st);
//
//	return 0;
//}


//#include<omp.h>
//#include<stdio.h>
//int main()
//{
//#pragma omp parallel num_threads(2)
//	{
//		printf("hello world");
//	}
//	return 0;
//}

//#include <omp.h>
//#define NUM_THREAD 2
//#define CHUNKSIZE 100
//#define N 1000
//using namespace std;
//int main() {
//	int a[N], b[N], c[N];
//	/* Some initializations */
//	for (int i = 0; i < N; i++)
//		a[i] = b[i] = i;
//	int chunk = CHUNKSIZE;
//	int thread = NUM_THREAD;
//#pragma omp parallel num_thread(thread) shared(a,b,c) private(i)
//	{
//#pragma omp for schedule(dynamic,chunk) nowait
//		for (int i = 0; i < N; i++) c[i] = a[i] + b[i];
//	} /* end of parallel section */
//}

//#include <iostream> 
//#include <mpi.h> 
//#include<string>
//int main(int argc, char* argv[])
//{
//	 
//	//argc = 1;
//	//argv[0] = "mpi.exe";
//	MPI_Init(&argc, &argv);
//
//	int RankID;
//	MPI_Comm_rank(MPI_COMM_WORLD, &RankID);
//
//	if (0 == RankID)
//	{
//		int SendNum = 16;
//		MPI_Send(&SendNum, 1, MPI_INT, 1, 0, MPI_COMM_WORLD);
//	}
//	else if (1 == RankID)
//	{
//		int RecvNum = 0;
//		MPI_Recv(&RecvNum, 1, MPI_INT, 0, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
//		std::cout << "Receive from rank 0: " << RecvNum << std::endl;
//	}
//
//	MPI_Finalize();
//	return 0;
//} 


//#include <mpi.h>
//#include <stdio.h>
//
//int main(int argc, char** argv) {
//    // 初始化 MPI 环境
//    MPI_Init(NULL, NULL);
//
//    // 通过调用以下方法来得到所有可以工作的进程数量
//    int world_size;
//    MPI_Comm_size(MPI_COMM_WORLD, &world_size);
//
//    // 得到当前进程的秩
//    int world_rank;
//    MPI_Comm_rank(MPI_COMM_WORLD, &world_rank);
//
//    // 得到当前进程的名字
//    char processor_name[MPI_MAX_PROCESSOR_NAME];
//    int name_len;
//    MPI_Get_processor_name(processor_name, &name_len);
//
//    // 打印一条带有当前进程名字，秩以及
//    // 整个 communicator 的大小的 hello world 消息。
//    printf("Hello world from processor %s, rank %d out of %d processors\n",
//        processor_name, world_rank, world_size);
//
//    // 释放 MPI 的一些资源
//    MPI_Finalize();
//}

// Author: Wes Kendall
// Copyright 2011 www.mpitutorial.com
// This code is provided freely with the tutorials on mpitutorial.com. Feel
// free to modify it for your own use. Any distribution of the code must
// either provide a link to www.mpitutorial.com or keep this header intact.
//
// MPI_Send, MPI_Recv example. Communicates the number -1 from process 0
// to process 1.
//

////https://mpitutorial.com/tutorials/mpi-send-and-receive/zh_cn/
//#include <mpi.h>
//#include <stdio.h>
//#include <stdlib.h>
//#include<cstdlib>
//#include<stdexcept>
//int main(int argc, char** argv) {
//   
//
//    MPI_Init(&argc, &argv);
//    // Find out rank, size
//    int world_rank;
//    MPI_Comm_rank(MPI_COMM_WORLD, &world_rank);
//    int world_size;
//    MPI_Comm_size(MPI_COMM_WORLD, &world_size);
//
//    // We are assuming at least 2 processes for this task
//    if (world_size < 2) {
//        fprintf(stderr, "World size must be greater than 1 for %s\n", argv[0]);
//        MPI_Abort(MPI_COMM_WORLD, 1);
//    }
//
//    int number;
//    if (world_rank == 0) {
//        // If we are rank 0, set the number to -1 and send it to process 1
//        number = -1;
//        MPI_Send(
//            /* data         = */ &number,
//            /* count        = */ 1,
//            /* datatype     = */ MPI_INT,
//            /* destination  = */ 1,
//            /* tag          = */ 0,
//            /* communicator = */ MPI_COMM_WORLD);
//    }
//    else if (world_rank == 1) {
//        MPI_Recv(
//            /* data         = */ &number,
//            /* count        = */ 1,
//            /* datatype     = */ MPI_INT,
//            /* source       = */ 0,
//            /* tag          = */ 0,
//            /* communicator = */ MPI_COMM_WORLD,
//            /* status       = */ MPI_STATUS_IGNORE);
//        printf("Process 1 received number %d from process 0\n", number);
//    }
//    MPI_Finalize();
//    //std::system("pause");
//}


////https://github.com/wesleykendall/mpitutorial/blob/gh-pages/tutorials/mpi-send-and-receive/code/ping_pong.c
//// Author: Wes Kendall
//// Copyright 2011 www.mpitutorial.com
//// This code is provided freely with the tutorials on mpitutorial.com. Feel
//// free to modify it for your own use. Any distribution of the code must
//// either provide a link to www.mpitutorial.com or keep this header intact.
////
//// Ping pong example with MPI_Send and MPI_Recv. Two processes ping pong a
//// number back and forth, incrementing it until it reaches a given value.
////
//#include <mpi.h>
//#include <stdio.h>
//#include <stdlib.h>
//
//int main(int argc, char** argv) {
//    const int PING_PONG_LIMIT = 10;
//
//    // Initialize the MPI environment
//   // MPI_Init(NULL, NULL);
//    MPI_Init(&argc, &argv);
//    // Find out rank, size
//    int world_rank;
//    MPI_Comm_rank(MPI_COMM_WORLD, &world_rank);
//    int world_size;
//    MPI_Comm_size(MPI_COMM_WORLD, &world_size);
//
//    // We are assuming 2 processes for this task
//    if (world_size != 2) {
//        fprintf(stderr, "World size must be two for %s\n", argv[0]);
//        MPI_Abort(MPI_COMM_WORLD, 1);
//    }
//
//    int ping_pong_count = 0;
//    int partner_rank = (world_rank + 1) % 2;
//    while (ping_pong_count < PING_PONG_LIMIT) {
//        if (world_rank == ping_pong_count % 2) {
//            // Increment the ping pong count before you send it
//            ping_pong_count++;
//            MPI_Send(&ping_pong_count, 1, MPI_INT, partner_rank, 0, MPI_COMM_WORLD);
//            printf("%d sent and incremented ping_pong_count %d to %d\n",
//                world_rank, ping_pong_count, partner_rank);
//        }
//        else {
//            MPI_Recv(&ping_pong_count, 1, MPI_INT, partner_rank, 0, MPI_COMM_WORLD,
//                MPI_STATUS_IGNORE);
//            printf("%d received ping_pong_count %d from %d\n",
//                world_rank, ping_pong_count, partner_rank);
//        }
//    }
//    MPI_Finalize();
//}



////https://github.com/wesleykendall/mpitutorial/blob/gh-pages/tutorials/mpi-send-and-receive/code/ring.c
//// Author: Wes Kendall
//// Copyright 2011 www.mpitutorial.com
//// This code is provided freely with the tutorials on mpitutorial.com. Feel
//// free to modify it for your own use. Any distribution of the code must
//// either provide a link to www.mpitutorial.com or keep this header intact.
////
//// Example using MPI_Send and MPI_Recv to pass a message around in a ring.
////
//#include <mpi.h>
//#include <stdio.h>
//#include <stdlib.h>
//
//int main(int argc, char** argv) {
//    // Initialize the MPI environment
//   // MPI_Init(NULL, NULL);
//    MPI_Init(&argc, &argv);
//    // Find out rank, size
//    int world_rank;
//    MPI_Comm_rank(MPI_COMM_WORLD, &world_rank);
//    int world_size;
//    MPI_Comm_size(MPI_COMM_WORLD, &world_size);
//
//    int token;
//    // Receive from the lower process and send to the higher process. Take care
//    // of the special case when you are the first process to prevent deadlock.
//    if (world_rank != 0) {
//        MPI_Recv(&token, 1, MPI_INT, world_rank - 1, 0, MPI_COMM_WORLD,
//            MPI_STATUS_IGNORE);
//        printf("Process %d received token %d from process %d\n", world_rank, token,
//            world_rank - 1);
//    }
//    else {
//        // Set the token's value if you are process 0
//        token = -1;
//    }
//    MPI_Send(&token, 1, MPI_INT, (world_rank + 1) % world_size, 0,
//        MPI_COMM_WORLD);
//    // Now process 0 can receive from the last process. This makes sure that at
//    // least one MPI_Send is initialized before all MPI_Recvs (again, to prevent
//    // deadlock)
//    if (world_rank == 0) {
//        MPI_Recv(&token, 1, MPI_INT, world_size - 1, 0, MPI_COMM_WORLD,
//            MPI_STATUS_IGNORE);
//        printf("Process %d received token %d from process %d\n", world_rank, token,
//            world_size - 1);
//    }
//    MPI_Finalize();
//}

////https://mpitutorial.com/tutorials/dynamic-receiving-with-mpi-probe-and-mpi-status/
//// Author: Wes Kendall
//// Copyright 2011 www.mpitutorial.com
//// This code is provided freely with the tutorials on mpitutorial.com. Feel
//// free to modify it for your own use. Any distribution of the code must
//// either provide a link to www.mpitutorial.com or keep this header intact.
////
//// Example of checking the MPI_Status object from an MPI_Recv call
////
//#include <mpi.h>
//#include <stdio.h>
//#include <stdlib.h>
//#include <time.h>
//
//int main(int argc, char** argv) {
//    //MPI_Init(NULL, NULL);
//    MPI_Init(&argc, &argv);
//    int world_size;
//    MPI_Comm_size(MPI_COMM_WORLD, &world_size);
//    if (world_size != 2) {
//        fprintf(stderr, "Must use two processes for this example\n");
//        MPI_Abort(MPI_COMM_WORLD, 1);
//    }
//    int world_rank;
//    MPI_Comm_rank(MPI_COMM_WORLD, &world_rank);
//
//    const int MAX_NUMBERS = 100;
//    int numbers[MAX_NUMBERS];
//    int number_amount;
//    if (world_rank == 0) {
//        // Pick a random amount of integers to send to process one
//        srand(time(NULL));
//        number_amount = (rand() / (float)RAND_MAX) * MAX_NUMBERS;
//        // Send the amount of integers to process one
//        MPI_Send(numbers, number_amount, MPI_INT, 1, 0, MPI_COMM_WORLD);
//        printf("0 sent %d numbers to 1\n", number_amount);
//    }
//    else if (world_rank == 1) {
//        MPI_Status status;
//        // Receive at most MAX_NUMBERS from process zero
//        MPI_Recv(numbers, MAX_NUMBERS, MPI_INT, 0, 0, MPI_COMM_WORLD, &status);
//        // After receiving the message, check the status to determine how many
//        // numbers were actually received
//        MPI_Get_count(&status, MPI_INT, &number_amount);
//        // Print off the amount of numbers, and also print additional information
//        // in the status object
//        printf("1 received %d numbers from 0. Message source = %d, tag = %d\n",
//            number_amount, status.MPI_SOURCE, status.MPI_TAG);
//    }
//    MPI_Barrier(MPI_COMM_WORLD);
//    MPI_Finalize();
//}


//2020.08.12

//#include <mpi.h>
//#include <stdio.h>
//#include <mpi.h>
//#include <iostream>
//int main(int argc,char** argv)
//{
//
//	//初始化MPI环境
//	MPI_Init(&argc, &argv);
//
//	//通过以下方法得到所有可以工作的进程数量
//	int world_size;
//	MPI_Comm_size(MPI_COMM_WORLD, &world_size);
//
//	//得到当前进程的秩序
//	int world_rank;
//	MPI_Comm_rank(MPI_COMM_WORLD, &world_rank);
//
//	//得到当前进程的名字
//	char processor_name[MPI_MAX_PROCESSOR_NAME];
//	int name_len;
//	MPI_Get_processor_name(processor_name,&name_len);
//
//	//打印一条带有当前进程的名字，秩以及
//	//整个communicator的大小的hello world信息
//	printf("Hello world form processor %s,ran %d out of %d processor s\n",
//		processor_name, world_rank, world_size);
//
//	MPI_Finalize();
	
	//}


////程序是 simd的
////2020.08.12 -08.13.00:26
//#include<mpi.h>
//#include<stdio.h>
//#include<stdlib.h>
//#include <string>
//int main(int argc, char** argv)
//{
//	//初始化
//	
//
//	MPI_Init(&argc, &argv);
//	
//	//得到秩
//	int world_rank;
//	MPI_Comm_rank(MPI_COMM_WORLD, &world_rank);
//
//	//得到size
//	int world_size;
//	MPI_Comm_size(MPI_COMM_WORLD, &world_size);
//
//	//假设至少2个进程
//	if (world_size < 2) {
//		fprintf(stderr, "world size must be greater than 1 for %s\n", argv[0]);
//		MPI_Abort(MPI_COMM_WORLD, 1);
//	}
//
//	int number;
//	if (world_rank == 0) {
//
//		//如果在秩0中，将number值设置为 -1 并且送个进程1
//		number = 1;
//		MPI_Send(
//			/*data			=*/&number,
//			/*count			=*/1,
//			/*datatype		=*/MPI_INT,
//			/*destination	=*/1,
//			/*tag			=*/0,
//			/*commmunicator =*/MPI_COMM_WORLD);
//	}
//	else if(world_rank==1){
//		MPI_Recv(
//			/* data         = */ &number,
//			/* count        = */ 1,
//			/* datatype     = */ MPI_INT,
//			/* source       = */ 0,
//			/* tag          = */ 0,
//			/* communicator = */ MPI_COMM_WORLD,
//			/* status       = */ MPI_STATUS_IGNORE);
//		printf("Process 1 received number %d from process 0\n", number);
//	}
//	MPI_Finalize();
//}


////2020.08.13 
////获取不定大小数据
////https://mpitutorial.com/tutorials/dynamic-receiving-with-mpi-probe-and-mpi-status/
//#include <mpi.h>
//#include <stdio.h>
//#include <stdlib.h>
//#include <time.h>
//#include <math.h>
//int main(int argc, char** argv)
//{
//	MPI_Init(&argc, &argv);
//
//	int world_size;
//	MPI_Comm_size(MPI_COMM_WORLD, &world_size);
//
//	if (world_size != 2) {
//		fprintf(stderr, "must use processes for this example\n");
//		MPI_Abort(MPI_COMM_WORLD, 1);
//	}
//	int  world_rank;
//	MPI_Comm_rank(MPI_COMM_WORLD, &world_rank);
//
//	const int MAX_NUMBERS = 100;
//	int numbers[MAX_NUMBERS];
//	int number_amount;
//	if (world_rank == 0) {
//		//Pick a random amount of integers to send to process one
//		srand(time(nullptr));
//		number_amount = (rand() / (float)RAND_MAX) * MAX_NUMBERS;
//		//SEND THE AMOUNT OF INTEGERS TO PROCESS ONT
//		MPI_Send(numbers, number_amount, MPI_INT, 1, 0, MPI_COMM_WORLD);
//		printf("0 sent %d numbers to 1\n", number_amount);
//	}
//	else if (world_rank == 1)
//	{
//		MPI_Status status;
//		//receive at most max_numbers from process zero
//		MPI_Recv(numbers, MAX_NUMBERS, MPI_INT, 0, 0, MPI_COMM_WORLD, &status);
//		//after receiving the message ,check the status to determine how many
//		//numbers were actually received
//		MPI_Get_count(&status, MPI_INT, &number_amount);
//		//print off the amount of numbers ,and also print addtional information
//		//in the status object
//		printf("1 received %d numbers from 0. message source=%d ,tag=%d\n", number_amount, status.MPI_SOURCE, status.MPI_TAG);
//
//
//	}
//	MPI_Barrier(MPI_COMM_WORLD);
//	MPI_Finalize();
//}


////2020.08.14.23:01
////ping pang 
////https://github.com/mpitutorial/mpitutorial/blob/gh-pages/tutorials/mpi-send-and-receive/code/ping_pong.c
//#include <mpi.h>
//#include <stdio.h>
//#include <stdlib.h>
//
//int main(int argc, char** argv) {
//	const int PING_PONG_LIMIT = 10;
//
//	// Initialize the MPI environment
//	MPI_Init(&argc,&argv);
//	// Find out rank, size
//	int world_rank;
//	MPI_Comm_rank(MPI_COMM_WORLD, &world_rank);
//	int world_size;
//	MPI_Comm_size(MPI_COMM_WORLD, &world_size);
//
//	// We are assuming 2 processes for this task
//	if (world_size != 2) {
//		fprintf(stderr, "World size must be two for %s\n", argv[0]);
//		MPI_Abort(MPI_COMM_WORLD, 1);
//	}
//
//	int ping_pong_count = 0;
//	int partner_rank = (world_rank + 1) % 2;
//	while (ping_pong_count < PING_PONG_LIMIT) {
//		if (world_rank == ping_pong_count % 2) {
//			// Increment the ping pong count before you send it
//			ping_pong_count++;
//			MPI_Send(&ping_pong_count, 1, MPI_INT, partner_rank, 0, MPI_COMM_WORLD);
//			printf("%d sent and incremented ping_pong_count %d to %d\n",
//				world_rank, ping_pong_count, partner_rank);
//		}
//		else {
//			MPI_Recv(&ping_pong_count, 1, MPI_INT, partner_rank, 0, MPI_COMM_WORLD,
//				MPI_STATUS_IGNORE);
//			printf("%d received ping_pong_count %d from %d\n",
//				world_rank, ping_pong_count, partner_rank);
//		}
//	}
//	MPI_Finalize();
//}


////2020.08.16
////https://github.com/mpitutorial/mpitutorial/blob/gh-pages/tutorials/mpi-scatter-gather-and-allgather/code/avg.c
//#include <stdio.h>
//#include<stdlib.h>
//#include <time.h>
//#include <mpi.h>
//#include <assert.h>
//
////创建一个随机数数组，数组中值的取值范围是0-1
//float* creat_rand_nums(int num_elements) {
//	float* rand_nums = (float*)malloc(sizeof(float) * num_elements);
//	assert(rand_nums != nullptr);
//	int i;
//	for (i = 0; i < num_elements; i++)
//	{
//		rand_nums[i] = (rand() / (float)RAND_MAX);
//	}
//	return rand_nums;
//}
//
////计算数组的平均值
//float compute_avg(float* array, int num_elements)
//{
//	float sum = 0.f;
//	int i;
//	for (i = 0; i < num_elements; ++i)
//		sum += array[i];
//	return sum / num_elements;
//}
//
//int main(int argc, char** argv) {
//	if (argc != 2) {
//		fprintf(stderr, "Usage:avg num_elements_pre_proc\n");
//		exit(1);
//	}
//
//	int num_elements_per_proc = atoi(argv[1]);
//	srand(time(NULL));
//
//	MPI_Init(nullptr, nullptr);
//
//	int world_rank;
//	MPI_Comm_rank(MPI_COMM_WORLD, &world_rank);
//	int world_size;
//    MPI_Comm_size(MPI_COMM_WORLD, &world_size);
//
//
//	//创建一个随机数数组在根进程。它的总数
//	//将会是每个进程的数组大小乘以数组数量
//	float* rand_nums = nullptr;
//	if (world_rank == 0) {
//		rand_nums = creat_rand_nums(num_elements_per_proc * world_size);
//	}
//
//	//对每一个进程，创建一个缓存来保存数组的一个子集
//	float* sub_rand_nums = (float*)malloc(sizeof(float) * num_elements_per_proc);
//	assert(sub_rand_nums != NULL);
//
//	//将随机数从根线程，分发的到所有线程中去
//	/*
//	各个项的意义
//	MPI_Scatter(
//		void* send_data,			：在根进程上的一个数据数组
//		int send_count,				：发送给每个进程的数据数量和数据类型
//		MPI_Datatype send_datatype,	：数据类型
//		void* recv_data,			：一个缓存
//		int recv_count,				：数据数量
//		MPI_Datatype recv_datatype,	：数据类型
//		int root,					：根进程的rank
//		MPI_Comm communicator)		：对应的communicator
//	*/
//	MPI_Scatter(rand_nums, num_elements_per_proc, MPI_FLOAT, sub_rand_nums, num_elements_per_proc, MPI_FLOAT, 0, MPI_COMM_WORLD);
//
//	//计算子集的平均数
//	float sub_avg = compute_avg(sub_rand_nums, num_elements_per_proc);
//
//	//将每个子部分的数据的平均值在根进程中收集起来
//	float* sub_avgs = nullptr;
//	if (world_rank == 0) {
//		sub_avgs = (float*)malloc(sizeof(float) * world_size);
//		assert(sub_avgs != nullptr);
//
//	}
//	MPI_Gather(&sub_avg, 1, MPI_FLOAT, sub_avgs, 1, MPI_FLOAT, 0, MPI_COMM_WORLD);
//
//	//既然我们在根进程中已经有了所有子集的平均值，计算
//	//总数的平均值就可以达成了。因为我们假定的是每个进程都是计算了相同数量元素的
//	//平均数，那么这样的计算结果是正确的
//	if (world_rank == 0)
//	{
//		float avg = compute_avg(sub_avgs, world_size);
//		printf("Avg of all elements is %f\n", avg);
//		//通过计算原始数组的平均值，来和以上计算得到的平均值比较
//		float original_data_avg = compute_avg(rand_nums, num_elements_per_proc * world_size);
//		printf("Avg computed across original data is %f \n", original_data_avg);
//
//	}
//
//	//clean up
//	if (world_rank == 0)
//	{
//		free(rand_nums);
//		free(sub_avgs);
//	}
//	free(sub_rand_nums);
//
//	MPI_Barrier(MPI_COMM_WORLD);
//	MPI_Finalize();
//}


////2020.08.25
//#include <stdio.h>
//#include <string.h>
//#include <mpi.h>
//
//const int MAX_STRING = 100;
//
//int main(int argc ,char ** argv)
//{
//	char greeting[MAX_STRING];
//	int comm_sz;//number of process
//	int my_rank;//my process rank
//
//	MPI_Init(nullptr, nullptr);
//	MPI_Comm_size(MPI_COMM_WORLD, &comm_sz);
//	MPI_Comm_rank(MPI_COMM_WORLD, &my_rank);
//
//	if (my_rank != 0)
//	{
//		sprintf_s(greeting, "greetings from process %d of %d ", my_rank, comm_sz);
//		MPI_Send(greeting, strlen(greeting) + 1, MPI_CHAR, 0, 0, MPI_COMM_WORLD);
//	}
//	else {
//		printf("Greetings from process %d of %d !\n", my_rank, comm_sz);
//		for (int q = 1; q < comm_sz; q++)
//		{
//			MPI_Recv(greeting, MAX_STRING, MPI_CHAR, q, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
//			printf("%s\n", greeting);
//		}
//	}
//	
//	
//	MPI_Finalize();
//	return 0;
//
//
////	int MPI_Recv(
////			void*				msg_buf_p			/*in*/,
////			int					msg_size			/*in*/,
////			MPI_Datatype		msg_type			/*in*/,
////			int					source				/*in*/,
////			int					tag					/*in*/,
////			MPI_Comm			communicator		/*in*/,
////			MPI_Status*			status_p			/*out*/
////	);
//	
//}




////2020.08.25
//
//#include <mpi.h>
//#include <stdlib.h>
//#include <stdio.h>
//
//double Trap(
//	double left_endpt,
//	double right_endpt,
//	int trap_count,
//	double base_len
//)
//{
//	double estimate, x;
//	int i;
//
//	estimate = (left_endpt + right_endpt) / 2.0;
//	for (int i = 1; i <= trap_count - 1; i++)
//	{
//		x = left_endpt + i * base_len;
//		estimate += x;
//
//	}
//	estimate = estimate * base_len;
//	return estimate;
//
//}
//int main(int argc,char** argv)
//{
//	int my_rank, comm_sz, n = 1024, local_n;
//	double a = 0.0, b = 3.0, h, local_a, local_b;
//	double local_int, total_int;
//	int source;
//
//	MPI_Init(nullptr, nullptr);
//	MPI_Comm_rank(MPI_COMM_WORLD, &my_rank);
//	MPI_Comm_rank(MPI_COMM_WORLD, &comm_sz);
//
//	h = (b - a) / n;
//	local_n = n / comm_sz;
//
//	local_a = a + my_rank * local_n * h;
//	local_b = local_a + local_n * h;
//	local_int = Trap(local_a, local_b, local_n, h);
//
//	if (my_rank != 0) {
//		MPI_Send(&local_int, 1, MPI_DOUBLE, 0, 0, MPI_COMM_WORLD);
//
//	}
//	else
//	{
//		total_int = local_int;
//		for (source = 1; source < comm_sz; ++source)
//		{
//
//			MPI_Recv(&local_int, 1, MPI_DOUBLE, source, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
//			total_int += local_int;
//		}
//	}
//	
//
//	if (my_rank == 0)
//	{
//		printf("with n= %d trapezoids,our estimate\n", n);
//		printf("of the integral from %f to %f  =%.15e\n", a, b, total_int);
//	}
//	MPI_Finalize();
//	return 0;
//}



////2020.08.26
//#include <mpi.h>
//#include <stdlib.h>
//#include <stdio.h>
//void Read_vector(
//	double  local_a[],
//	int local_n,
//	int n,
//	char vec_name[],
//	int my_rank,
//	MPI_Comm comm
//)
//{
//	double* a = nullptr;
//	int i;
//	if (my_rank == 0)
//	{
//		a = (double*)malloc(n * sizeof(double));
//		printf("Enter the vector %s\n", vec_name);
//		for (int i = 0; i < n; ++i)
//			//scanf("%lf", &a[i]);
//		a[i] = i;
//		MPI_Scatter(a, local_n, MPI_DOUBLE, local_a, local_n, MPI_DOUBLE, 0, comm);
//		free(a);
//	}
//	else {
//		MPI_Scatter(a, local_n, MPI_DOUBLE, local_a, local_n, MPI_DOUBLE, 0, comm);
//	}
//}
//
//void Print_vector(
//	double local_b[],
//	int local_n,
//	int n,
//	char title[],
//	int my_rank,
//	MPI_Comm comm
//)
//{
//	double* b = nullptr;
//	int i;
//
//	if (my_rank == 0)
//	{
//		b = (double*)malloc(n * sizeof(double));
//		MPI_Gather(local_b, local_n, MPI_DOUBLE, b, local_n, MPI_DOUBLE, 0, comm);
//		printf("%s\n", title);
//		for (int i = 0; i < n; ++i)
//			printf("%lf", b[i]);
//		printf("\n");
//		free(b);
//
//	}
//	else {
//		MPI_Gather(local_b, local_n, MPI_DOUBLE, b, local_n, MPI_DOUBLE, 0, comm);
//	}
//
//}


////2020.08.28
//#include <mpi.h>
//#include <string.h>
//#include <stdio.h>
//
//const int MAX_STRING = 100;
//int main(int argc,char** argv)
//{
//	char greeting[MAX_STRING];
//	int comm_sz;
//	int my_rank;
//
//	MPI_Init(&argc, &argv);
//	MPI_Comm_size(MPI_COMM_WORLD, &comm_sz);
//	MPI_Comm_rank(MPI_COMM_WORLD, &my_rank);
//
//	if (my_rank != 0)
//	{
//		sprintf_s(greeting, "Greetings from process %d of %d!\n", my_rank, comm_sz);
//		MPI_Send(greeting, strlen(greeting + 1) , MPI_CHAR, 0, 0, MPI_COMM_WORLD);
//	}
//	else
//	{
//		printf("Greetings from process %d of %d!\n", my_rank, comm_sz);
//		for (int q = 1; q < comm_sz; q++)
//		{
//			MPI_Recv(greeting, MAX_STRING, MPI_CHAR, q, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
//			printf("%s\n", greeting);
//		}
//	}
//	return 0;
//}


////2020.08.30
//#include <mpi.h>
//#include <stdlib.h>
//#include <stdio.h>
//double Trap(double left_endpt, double right_endpt, int trap_count, double base_len) {
//	double estimate, x;
//
//	int i;
//
//	estimate = (left_endpt + right_endpt) / 2.0;
//	for (int i = 1; i <= trap_count - 1; i++)
//	{
//		x = left_endpt + i * base_len;
//		estimate += x;
//	}
//	estimate = estimate * base_len;
//	return estimate;
//}
//int main(int argc, char** argv) {
//
//	int my_rank;
//	int comm_sz, n = 10024, local_n;
//	double a = 0.0, b = 3.0, h, local_a, local_b;
//	double local_int, total_int;
//	int source;
//
//	MPI_Init(&argc, &argv);
//	MPI_Comm_rank(MPI_COMM_WORLD, &my_rank);
//	MPI_Comm_size(MPI_COMM_WORLD, &comm_sz);
//
//	h = (b - a) / n;
//	local_n = n / comm_sz;
//
//	local_a = a +double( my_rank) * local_n * h;
//	local_b = local_a + local_n * h;
//	local_int = Trap(local_a, local_b, local_n, h);
//
//	if (my_rank != 0)
//	{
//		MPI_Send(&local_int, 1, MPI_DOUBLE, 0, 0, MPI_COMM_WORLD);
//
//	}
//	else
//	{
//		total_int = local_int;
//		for (source = 1; source < comm_sz; source++)
//		{
//			//MPI_Recv(&local_int, 1, MPI_DOUBLE, MPI_ANY_SOURCE, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
//			MPI_Recv(&local_int, 1, MPI_DOUBLE, source, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
//			total_int += local_int;
//		}
//	}
//
//	//MPI_Reduce(&local_int, &total_int, 1, MPI_DOUBLE, MPI_SUM, 0, MPI_COMM_WORLD);
//
//	if (my_rank == 0)
//	{
//		printf("With n = %d trapezoids, our estimate\n", n);
//		printf("of the integral from %f to %f = %.15e\n", a, b, total_int);
//	}
//	MPI_Finalize();
//	return 0;
//}


////2020.08.30 
//
//#include <mpi.h>
//#include <stdlib.h>
//#include <stdio.h>
//void Read_vector(
//	double	local_a[],
//	int		local_n,
//	int		n,
//	char	vec_name[],
//	int		my_rank,
//	MPI_Comm comm
//) {
//	double* a = nullptr;
//	int i;
//
//	if (my_rank == 0) {
//		a = (double*)malloc(n * sizeof(double));
//		printf("Enter the vector %s\n", vec_name);
//		for (int i = 0; i < n; ++i)
//			scanf("%lf", &a[i]);
//		MPI_Scatter(a, local_n, MPI_DOUBLE, local_a, local_n, MPI_DOUBLE, 0, comm);
//		free(a);
//	}
//	else
//	{
//		MPI_Scatter(a, local_n, MPI_DOUBLE, local_a, local_n, MPI_DOUBLE, 0, comm);//非0号进程也可以散射，为了提升效率？？
//	}
//}
//
//void Print_vector(
//	double	local_b[],
//	int		local_n,
//	int		n,
//	char	title[],
//	int		my_rank,
//	MPI_Comm comm)
//{
//	double* b = nullptr;
//	int i;
//
//	if (my_rank == 0) {
//		b = (double*)(n * sizeof(double));
//		MPI_Gather(local_b, local_n, MPI_DOUBLE, b, local_n, MPI_DOUBLE, 0, comm);
//		printf("%s\n", title);
//		for (i = 0; i < n; ++i)
//			printf("%f ", b[i]);
//		printf("\n");
//		free(b);
//	}
//	else
//	{
//		MPI_Gather(local_b, local_n, MPI_DOUBLE, b, local_n, MPI_DOUBLE, 0, comm);
//	}
//}
//
//
////p77
//void Mat_vect_mult(
//	double local_A[],
//	double local_x[],
//	double local_y[],
//	int local_m,
//	int n,
//	int local_n,
//	MPI_Comm comm
//)
//{
//	double* x;
//	int local_i, j;
//	int local_ok = 1;
//
//	x = (double*)malloc(n*sizeof(double));
//	MPI_Allgather(local_x, local_n, MPI_DOUBLE,
//		x, local_n, MPI_DOUBLE, comm);
//
//	for (local_i = 0; local_i < local_m; ++local_i) {
//		local_y[local_i] = 0.0;
//		for (j = 0; j < n; ++j)
//			local_y[local_i] += local_A[local_i * n + j] * x[j];
//	}
//	free(x);
//
//}



//2020.08.31

