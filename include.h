#ifndef INCLUDE_H_
#define INCLUDE_H_

#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <string.h>
#include <stdint.h>

typedef struct linked_list_s
{
    char data[64];
    struct linked_list_s *next;
} linked_list_t;

#endif
