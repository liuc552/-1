TAG = ../lib/liblc.so
SRC = ./usr_list.o ./book_list.o ./login.o
CC = gcc
O = -o
C = -c
F = -fPIC
S = -shared

CONFIG = -I ../inc
C1 = usr_list.c
C2 = book_list.c
C3 = login.c 

O1 = usr_list.o
O2 = book_list.o
O3 = login.o 

CO = $(O1) $(O2) $(O3) 

RM = rm -f 

all : #$(TAG)

#$(O1):$(C1)
	$(CC) $(C1) $(O) $(O1) $(C) $(F) $(CONFIG)
#$(O2):$(C2)
	$(CC) $(C2) $(O) $(O2) $(C) $(F) $(CONFIG)
#$(O3):$(C3)
	$(CC) $(C3) $(O) $(O3) $(C) $(F) $(CONFIG)
#$(TAG):$(CO)
	$(CC) $(F) $(S) $(O) $(TAG) $(CO) $(CONFIG)

clean :
	$(RM) $(CO)	
	
	

	
