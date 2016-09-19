#SOURCES FILE 

SRC= \
     main.c\
     hw1.c
      
HEAD=./Headers

LIB= \
     memory.c\
     data.c

VPATH: memory data preprocess 

vpath %.h headers 
vpath %.c memory
vpath %.c data
