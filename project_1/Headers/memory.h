#ifndef MEMORY_H
#define MEMORY_H

#include<stdio.h>
#include<stdint.h>

int8_t my_memmove(uint8_t *source, uint8_t *destination, uint32_t length);

int8_t my_memzero(uint8_t *src, uint32_t length);

int8_t my_reverse(uint8_t *str, int32_t length);

#endif
