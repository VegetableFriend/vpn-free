#makefile

CXX = clang++

server.out: server.o vf_sock.o
	$(CXX) -o server.out server.o vf_sock.o

server.o: vf_sock.h server.cpp
	$(CXX) -c server.cpp

vf_sock.o: vf_sock.h vf_sock.cpp
	$(CXX) -c vf_sock.cpp

clean: 
	rm server.o vf_sock.o

run:
	./server