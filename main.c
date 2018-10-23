#include <stdio.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
 
int main()
{
	//variables to store the file and its contents
	int file;
	char contents[500];
	
	//opens the file
	file = open("read.txt", O_RDONLY);
	//reads the file, stores its contents in contents, and stores the bytes read
	int bytes_read = read(file, contents, 500);
	//have to manually set the terminating NULL
	contents[bytes_read] = NULL;
	//print the file read, and then closes the file
	printf("File read: read.txt\nBytes read: %d\n%s", bytes_read, contents);
	close(file);

	file = open("write.txt", O_RDWR | O_CREAT);
	int bytes_written = write(file, contents, 500);
	char new_contents[500];

	bytes_read = read(file, new_contents, 500);
	contents[bytes_read] = NULL;

	printf("File written to: write.txt\nBytes written: %d\n%s", bytes_written, new_contents);
	close(file);
	return 0;
}
