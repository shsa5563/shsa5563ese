#SOURCES FILE 

OBJ= \
     main.o\
     hw1.o
SRC= \
     main.c\
     hw1.c
      
PRE= \
     main.i\
     hw1.i

ASM= \
     main.s\
     hw1.s

VPATH: memory data preprocess 

vpath %.o objects
vpath %.h headers
vpath %.s assembly 
vpath %.c memory
vpath %.c data
vpath %.i processor
