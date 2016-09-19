#Readme File for the Makefile
include source.mk 								--To include the source.mk file
CC=gcc										--To choose gcc as the default compiler
CFLAGS= -Wall -g -O0 -std=c99							--Add the flags -Wall, -g , O0, -std=c99
EXE= project 									--name the executable as project
BBB_Connection =root@192.168.7.2 						-- give the static IP root address of Beagle Bone
FRDM_FLAG=									--giving no values to Freescale Freedom Platform Flag 
MAP_FLAG = -Wl,-Map,$(strip $(EXE)).map 					--Mapping Flags
OBJDUMP= 									--giving no values to the Objdump (input from user -default 											  value is empty)
DEPS:=$(SRC:.c=.dep)								--The source .c files must be linked/converted to .dep files 
										  (for Dependency files)
PRE:=$(SRC:.c=.i)								--The source .c files must be linked/converted to .i files 											  (for Preprocessor)
ASM:=$(SRC:.c=.s)							 	--The source .c files must be linked/converted to .s files

ifeq ($(platform),host) 							--check which platform the user wants to execute the code in
CC=gcc										  if it is "host" - then compile in GCC 
else ifeq ($(platform),bbb)							--if it is  "bbb" - then compile in arm-linux-gnueabihf-gcc
CC=arm-linux-gnueabihf-gcc
else ifeq ($(platform),frdm)							--if it is "frdm" - then compile in arm-none-eabi-gcc
CC= arm-none-eabi-gcc
FRDM_FLAG= --specs=rdimon.specs							-- add the -specs=rdimon.specs flag to printf in FRDM instead 
										   pragma
endif

ifeq ($(objdump),true) 								--check if the user wants to dump the compiled code
OBJDUMP=objdump -d object/$@ 							--if so then dump the files usin the shown command
endif

.PHONY: build-lib								--to build the liraries of the memory.c and data.c
build-lib: $(LIB)
	ar rvs libproject1.a $(LIB)

.PHONY: file.i									-- to create the preprocessed file 
file.i:
	make $(PRE)
	
.PHONY: file.s									-- to create the assembly file
file.s:
	make $(ASM)

 
.PHONY: compile-all 								--to compile all the .c files into .o files
compile-all:
	make $(OBJ)

.PHONY: build									--to generate an executable file called project 
build: $(SRC)
	$(CC) $(FRDM_FLAG) $(CFLAGS)  -I$(HEAD) -v $^ -o $(EXE)
	make $(DEPS)							     	--generate dependencies for all the source files

.PHONY: build-all								--to generate an executable file called project 
build-all: $(SRC)
	$(CC) $(FRDM_FLAG) $(CFLAGS) $(MAP_FLAG) -I$(HEAD) -v $^ -o $(EXE)
	make $(DEPS)								-- generate dependencies for all the course files
	size $(EXE)								--to calculate the size of the executable file
	
%.o: %.c
	$(CC) $(FRDM_FLAG) $(CFLAGS) -c  -I$(HEAD) $< -o object/$@		--to create the object files from the source files
	$(OBJDUMP)								--to dump the compiled codes
%.i: %.c									
	$(CC) $(FRDM_FLAG) $(CFLAGS) -E -I$(HEAD)  $< -o $@ 			--to create the preprocessed file from the source files
																			
 %.s: %.c 
	$(CC) $(FRDM_FLAG) $(CFLAGS) -S  -I$(HEAD) $< -o assembly/$@		--to create the assembly files from the source files

%.dep:%.c
	$(CC) $(FRDM_FLAG) $(CFLAGS) -MM $< -o $@				--to create the dependency for the source files

upload:
	ssh $(BBB_Connection) "rm -rf /home/debian/bin/release"			--to copy the executable code to the beagle bone black board
	ssh $(BBB_Connection) "mkdir /home/debian/bin/release"                  --put the executable code in release directory 
	scp $(EXE) $(BBB_Connection):/home/debian/bin/release

.PHONY : clean									--to clean all the generated files in the directory including
clean :										  the executable files
	-rm -f *.o *.i *.dep *.lib *.s *.map *.a project

