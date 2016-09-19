#SOURCES FILE 

SRC= \
     main.c\
     data.c


HEAD=./Headers

LIB= \
     memory.c\
     data.c

VPATH: Memory Data

#vpath %.c memory
vpath %.c Data
