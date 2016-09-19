#Make File for Project 1
include source_1.mk
target=host
CC=gcc
CFLAGS= -Wall -g -O0 -std=c99

EXE= project 
BBB_Connection =root@192.168.7.2
FRDM_FLAG=
MAP_FLAG = -Wl,-Map,$(strip $(EXE)).map
OBJDUMP= 


DEPS:=$(SRC:.c=.dep)
PRE:=$(SRC:.c=.i)
ASM:=$(SRC:.c=.s)
OBJ:=$(SRC:.c=.o)

ifeq ($(platform),host)
CC=gcc
else ifeq ($(platform),bbb)
CC=arm-linux-gnueabihf-gcc
else ifeq ($(platform),frdm)
CC= arm-none-eabi-gcc
FRDM_FLAG= --specs=rdimon.specs
endif

ifeq ($(objdump),true)
OBJDUMP=objdump -d object/$@ 
endif

.PHONY: build-lib
build-lib: $(LIB)
	ar rvs libproject1.a $(LIB)

.PHONY: file.i
file.i:
	make $(PRE)
	
.PHONY: file.s
file.s:
	make $(ASM)


.PHONY: compile-all
compile-all:
	make $(OBJ)

.PHONY: build
build:$(SRC)
	$(CC) $(FRDM_FLAG) $(CFLAGS) -I$(HEAD) -v $^ -o $(EXE)
	make $(DEPS)

.PHONY: build-all
build-all:$(SRC)
	$(CC) $(FRDM_FLAG) $(CFLAGS) $(MAP_FLAG) -I$(HEAD) -v $^ -o $(EXE)
	make $(DEPS)
	size $(EXE)
	
%.o: %.c
	mkdir -p Object
	$(CC) $(FRDM_FLAG) $(CFLAGS) -I$(HEAD) -c $< -o Object/$@ 
	$(OBJDUMP)
%.i: %.c
	mkdir -p Preprocess
	$(CC) $(FRDM_FLAG) $(CFLAGS) -I$(HEAD) -E $< -o Preprocess/$@ 

%.s: %.c
	mkdir -p Assembly
	$(CC) $(FRDM_FLAG) $(CFLAGS) -I$(HEAD) -S $< -o Assembly/$@

%.dep:%.c
	$(CC) $(FRDM_FLAG) $(CFLAGS) -I$(HEAD) -MM $< -o $@

upload:
	ssh $(BBB_Connection) "rm -rf /home/debian/bin/release"
	ssh $(BBB_Connection) "mkdir /home/debian/bin/release"
	scp $(EXE) $(BBB_Connection):/home/debian/bin/release

.PHONY : clean
clean :
	-rm -f *.dep *.map *.a project *.o *.i *.s
	-rm -rf Assembly
	-rm -rf Preprocess
	-rm -rf Object
