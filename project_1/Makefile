#Make File for Project 1
include source.mk
target=host
CC=gcc
CFLAGS= -Wall -g -O0 -std=c99
DEPS = hw1.h
EXE= project 
BBB_Connection =root@192.168.7.2
FRDM_FLAG=
MAP_FLAG = -Wl,-Map,$(strip $(EXE)).map
OBJDUMP= 
ifeq ($(platform),host)
CC=gcc
else ifeq ($(platform),bbb)
CC=arm-linux-gnueabihf-gcc
else ifeq ($(platform),frdm)
CC= arm-none-eabi-gcc
FRDM_FLAG= --specs=rdimon.specs
endif

ifeq ($(ss),true)
OBJDUMP=objdump -d object/$@ 
endif

.PHONY: build-lib
build-lib: $(SRC)
	ar rvs libproject1.a $(SRC)

.PHONY: file.i
file.i:$(PRE)
	
.PHONY: file.s
file.s:$(ASM)

DEPS:=$(SRC:.c=.dep)

.PHONY: compile-all
compile-all:
	make $(OBJ)

.PHONY: build
build: $(SRC)
	$(CC) $(FRDM_FLAG) $(CFLAGS) -v $^ -o $(EXE)
	make $(DEPS)

.PHONY: build-all
build-all: $(SRC)
	$(CC) $(FRDM_FLAG) $(CFLAGS) $(MAP_FLAG) -v $^ -o $(EXE)
	make $(DEPS)
	size $(EXE)
	
%.o: %.c
	mkdir -p object
	touch object/$@	
	$(CC) $(CFLAGS) -c $< -o object/$@ 
	$(OBJDUMP)
%.i: %.c
	mkdir -p preprocess
	touch preprocess/$@
	$(CC) $(CFLAGS) -E $< -o preprocess/$@  
%.s: %.c 
	mkdir -p assembly
	$(CC) $(CFLAGS) -S $< -o assembly/$@

%.dep:%.c
	$(CC) $(FRDM_FLAG) $(CFLAGS) -MM $< -o $@

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

