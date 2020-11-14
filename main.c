#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "generator.h"
#include <errno.h>
#include <fcntl.h>

int main()
{

    int arr1[10];
    int i;
    for (i = 0; i < 10; i++)
    {
        arr1[i] = rng();
    }

    printf("Printing contents of first array\n");
    for (i = 0; i < 10; i++)
    {
        printf("%d\n", arr1[i]);
    }

    printf("\n");

    printf("Writing array1 to a file and reading the file to array2\n");
    int fd = open("./test.txt", O_RDWR | O_CREAT, 0777);
    printf("File descriptor %d\n", fd);

    int written = write(fd, arr1, sizeof(arr1));
    printf("Bytes written: %d\n", written);

    int arr2[10];
    fd = open("./test.txt", O_RDONLY);
    int bytes = read(fd, arr2, 40);
    printf("Bytes read: %d\n", bytes);
    printf("%s\n", strerror(errno));

    printf("\n");
    printf("Printing contents of second array\n");
    for (i = 0; i < 10; i++)
    {
        printf("%d\n", arr2[i]);
    }



    return 0;

    //include free later
}