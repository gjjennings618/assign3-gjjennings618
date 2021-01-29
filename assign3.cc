/* 	Garrett Jennings | ZID: Z1927185
	Assignment 03 | Implement cat
	CS330 - 1
	
	I certify that this is my own work and where appropriate an extension 
	of the starter code provided for the assignment.
*/
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>

using namespace std;
const ssize_t BUFF_SIZE = 1024;

int main(int argc, char *argv[])
{
    for (int i = 0; i <= argc; ++i){

		int fd;

		if (*argv[i] != '-'){
			// Open file
			fd = open(argv[i], O_RDONLY);

			// Handle Errors
			if (fd == -1){ 
				perror("Opening File"); 
				exit(1);
			}
		}
		else { fd = 0; }	// '-' is given instead of a file, so read from stdin
		
		char buf[BUFF_SIZE];
		ssize_t bytesRead;

		while ( (bytesRead = read(fd, buf, BUFF_SIZE - 1) ) != 0){
			
			// Handle Errors
			if (bytesRead == -1) { 
				perror("Reading File");
				exit(2);
			}

			ssize_t bytesWritten = write(fd, buf, bytesRead);

			// Handle Errors
			if (bytesWritten == -1) { 
				perror("Writing File");
				exit(3);
			}
		} 
		

		if (!fd){
			//Close File
			int clerror = close(fd);

			// Handle Errors
			if (clerror == -1) { 
				perror("Closing File");
				exit(4);
			}
		}
    }

	return 0;
}// End of main() routine.
