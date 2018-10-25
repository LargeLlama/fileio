#include <stdio.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
 
int main()
{
	//=====WRITING=========

	//opening the file
	int file = open("test.txt", O_WRONLY | O_CREAT, 0666);
	
	//if any erorrs, print out message and return -1
	if (file < 0)
	{
		printf("File writing/creation failed! Yeet\n");
		return -1;
	}
	printf("Writing to file 'test.txt'....\n");
	//string to be written
	char * contents = "UH DEXTER!";

	//write 10 bytes to the file (the string is length ten)
	write(file, contents, 10);

	//close the file
	close(file);

	//========READING=============
	printf("Reading from file 'test.txt'....\n");
	//char array to store the contents of the file
	//must be error, if i try using pointer it gives weird behavior
	char read_contents[10];
	//open the file
	file = open("test.txt", O_RDONLY, 0666);

	//if any errors, print error message and return -1
	if (file < 0)
	{
		printf("File reading failed! Yeet\n");
		return -1;
	}

	//read the file and store it into the array
	read(file, read_contents, 10);
	
	//print the contents of the file, and close
	printf("Contents of file:\n%s", read_contents);
	close(file);

	return 0;
}
