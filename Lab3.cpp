//============================================================================
// Name        : Lab3.cpp
// Author      : Alyssa Gibson
// Version     :
// Copyright   : 
// Description : Lab3 - Linux Programming
//============================================================================

#include <iostream>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <errno.h>
#include <iostream>

using namespace std;

long int fib(int n) {
	if(n == 1 || n == 2){
		return 1;
	}
	return fib(n-1) + fib(n-2);
}

int main() {
	int fibs[40];
	int fd = open("/tmp/file", O_CREAT | O_RDWR, S_IRWXU);
	for(int i = 1; i <= 40; i++) {
		fibs[i] = fib(i);
	}
	write(fd, fibs, sizeof(int)*40);
	read(fd, fibs, sizeof(int)*40);
	for(int i = 1; i <= 40; i++) {
		cout << fibs[i] << endl;
	}
	close(fd);
	return 0;
}

