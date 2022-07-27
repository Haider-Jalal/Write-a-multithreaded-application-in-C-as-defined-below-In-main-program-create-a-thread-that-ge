#include <iostream>
#include <ctime>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/time.h>
#include <algorithm>
#include <bits/stdc++.h>
using namespace std;

//array for storing 300 random numbers
int ar[300]; 

//array for storing number of even & odd digits of each thread
int arr[6]; 

//thread for generating 300 random numbers
void *randnum(void *arg){

srand(time(NULL));

for (int i = 0; i < 300; i++)
{
   ar[i] = rand()%1000;
}
pthread_exit(NULL);
}

//thread1
void *thread1(void *arg){

       // variable to store number of even digits in first 100 numbers
       int e=0;
       // variable to store number of odd digits in first 100 numbers
       int o=0;
       
for (int i = 0; i < 100; i++)
{
        int even_count = 0;
	int odd_count = 0;
	
	while (ar[i] > 0)
	{
		int rem = ar[i] % 10;
		if (rem % 2 == 0)
			even_count++;
		else
			odd_count++;
		ar[i] = ar[i] / 10;
	}
    
       e=e+even_count;
       o=o+odd_count;      
}
    //storing number of even digits of thread 1 on index 0
    arr[0]=e;
    //storing number of odd digits of thread 1 on index 1
    arr[1]=o;

pthread_exit(NULL);
}

//thread 2
void *thread2(void *arg){

       // variable to store number of even digits between 100-200 
       int e=0;
       // variable to store number of odd digits between 100-200
       int o=0;
       
for (int i = 100; i < 200; i++)
{

        int even_count = 0;
	int odd_count = 0;
	
	while (ar[i] > 0)
	{
		int rem = ar[i] % 10;
		if (rem % 2 == 0)
			even_count++;
		else
			odd_count++;
		ar[i] = ar[i] / 10;
	}
       e=e+even_count;
       o=o+odd_count;
}
    //storing number of even digits of thread 2 on index 2
    arr[2]=e;
    //storing number of odd digits of thread 2 on index 3
    arr[3]=o;


pthread_exit(NULL);
}


//thread3
void *thread3(void *arg){

       // variable to store number of even digits between 200-300 
       int e=0;
       // variable to store number of odd digits between 200-300
       int o=0;

for (int i = 200; i < 300; i++)
{
 int even_count = 0;
	int odd_count = 0;
	
	while (ar[i] > 0)
	{
		int rem = ar[i] % 10;
		if (rem % 2 == 0)
			even_count++;
		else
			odd_count++;
		ar[i] = ar[i] / 10;
	}
       e=e+even_count;
       o=o+odd_count;
}
    //storing number of even digits of thread 3 on index 4
    arr[4]=e;
    //storing number of odd digits of thread 3 on index 5
    arr[5]=o;

pthread_exit(NULL);
}

//main function
int main()
{

pthread_t t,t1,t2,t3;

pthread_create(&t,NULL,randnum,NULL);
pthread_join(t,NULL);

pthread_create(&t1,NULL,thread1,NULL);
pthread_join(t1,NULL);

pthread_create(&t2,NULL,thread2,NULL);
pthread_join(t2,NULL);

pthread_create(&t3,NULL,thread3,NULL);
pthread_join(t3,NULL);

cout<<"Thread 1:"<<endl;
cout<<"Even Count = "<<arr[0]<<endl;
cout<<"Odd Count = "<<arr[1]<<endl;

cout<<" "<<endl;
cout<<"Thread 2:"<<endl;
cout<<"Even Count = "<<arr[2]<<endl;
cout<<"Odd Count = "<<arr[3]<<endl;

cout<<" "<<endl;
cout<<"Thread 3:"<<endl;
cout<<"Even Count = "<<arr[4]<<endl;
cout<<"Odd Count = "<<arr[5]<<endl;

 return 0;
}
