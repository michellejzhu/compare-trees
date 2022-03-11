#
# N.B. If you're using files with .cc extensions, then you need to search
# and replace cpp with cc.
#

CC = g++ -std=c++0x
CFLAGS = -Wall -g
#CFLAGS = -std=c++11 -Wall -g
SRCS = main.cpp BSTnode.cpp BSTree.cpp AVLnode.cpp AVLTree.cpp SNode.cpp SplayTree.cpp
#SRCS = ${wildcard *.cpp}
OBJS = ${SRCS:.cpp=.o} 
INCLS = ${SRCS:.cpp=.h} 

p2: $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o p2

$(OBJS):
	$(CC) $(CFLAGS) -c $*.cpp

depend: Makefile.dep
	$(CC) -MM $(SRCS) > Makefile.dep

Makefile.dep:
	touch Makefile.dep

.PHONY: submit clean

submit:
	rm -f submit.zip
	zip submit.zip $(SRCS) $(INCLS) Makefile Makefile.dep

clean:
	rm -f *.o p2 core

include Makefile.dep

