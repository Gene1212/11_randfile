#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>
#include <fcntl.h>

int rng()
{
    int *buff = malloc(sizeof(int *));

    int fd = open("/dev/urandom", O_RDONLY);

    //printf("File descriptor: %d\n", fd);
    //printf("%s\n", strerror(errno));

    int returnval = read(fd, buff, 4);

    //printf("Number of Bytes read: %d\n", returnval);
    //printf("%s\n", strerror(errno));

    int newval = *buff;
    free(buff);
    return newval;
}