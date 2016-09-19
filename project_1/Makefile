#Make File for Project 1
include sources.mk
target=host
CC=gcc
CFLAGS= -Wall -g -O0 -std=c99
DEPS = hw1.h
EXE= project 
BBB_Connection =root@192.168.7.2

ifeq(target,host)
{
$(CC)=gcc
}

.PHONY: build-lib
build-lib: $(SRC)
	ar rvs libproject1.a $(SRC)

.PHONY: file.i
file.i:$(PRE)
	
.PHONY: file.s
file.s:$(ASM)

.PHONY: compile-all
compile-all:
	make $(OBJ)
	
.PHONY: build
build: $(SRC)
	#mkdir -p object
	$(CC) $(CFLAGS) $^ -o $(EXE)
	
%.o: %.c
	mkdir -p object
	touch object/$@	
	$(CC) $(CFLAGS) -c $< -o object/$@ 
%.i: %.c
	mkdir -p preprocess
	touch preprocess/$@
	$(CC) $(CFLAGS) -E $< -o preprocess/$@  
%.s: %.c 
	mkdir -p assembly
	$(CC) $(CFLAGS) -S $< -o assembly/$@

upload:
	ssh $(BBB_Connection) "rm -rf /home/debian/bin/release"
	ssh $(BBB_Connection) "mkdir /home/debian/bin/release"
	scp $(EXE) $(BBB_Connection):/home/debian/bin/release

.PHONY : clean
clean :
	-rm -r  object
	-rm -r assembly
	-rm -r preprocess
	-rm -f $(EXE) 

#$(EXE): $(OBJ)
