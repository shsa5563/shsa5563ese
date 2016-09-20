#SOURCES FILE 
#Author Shekhar Satyanarayana , Rohit Sali
#09-19-2016
SRC= \
     main.c\
     memory.c\
     project_1.c\
     data.c

HEAD=./Headers

LIB= \
     memory.c\
     data.c

VPATH: Memory Data

vpath %.c Memory
vpath %.c Data
