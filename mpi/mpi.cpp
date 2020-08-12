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
//int main(int argc, char** argv)
//{
//	//初始化
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
