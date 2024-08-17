#3 now
#gcc src/main.c -o main -I inc/ -L lib/ -llc
TAG = main
SRC = src/main.c
CC = gcc
O = -o
CONFIG = -I ./inc -L lib -llc
RM = rm -f

$(TAG):$(SRC)
	$(CC) $(SRC) $(O) $(TAG) $(CONFIG)

clean :
	$(RM) $(TAG)

MV :
	sudo mv lib/liblc.so /lib/
RM :
	sudo rm /lib/liblc.so
#1次
# bin/mian:src/main.c src/login.c src/book_list.c src/usr_list.c
# 	gcc $^ -o $@ -I ./inc
# clean:
# 	rm bin/mian
# 1:
# 	@echo helloworld!
#2次
# TAG = ./bin/mian
# SRC = ./src/*.c
# CC = gcc
# O = -o
# CONFIG = -I ./inc #-L ./lib -lmy_lib
# RM = rm -f

# $(TAG):$(SRC)
# 	$(CC) $(SRC) $(O) $(TAG) $(CONFIG)

# clean :
# 	$(RM) $(TAG)

# #run :            错误写法 当我运行程序时，Makefile脚本也在运行
# #	./$(TAG)

