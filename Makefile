CLASS=process_class
TEST=process_test
CPU=cpu
QUEUE=queue
RR=rr
IO=iodevice
OS=NipliOS
SAN_FLAGS=-lxml2 -lasan -g -std=c++11 -fsanitize=address -fno-omit-frame-pointer -fstack-protector -Wstack-protector 
FLAGS=-g -std=c++11 -fno-omit-frame-pointer -fstack-protector -Wstack-protector 
MEM=mem_mgmt
THREAD=-lpthread
cputest: $(CPU)
	g++ test/cputest.cpp lib/$(CLASS).o lib/$(CPU).o $(FLAGS) -o bin/cputest

classtest: $(CLASS)
	g++ test/$(TEST).cpp lib/$(CLASS).o $(FLAGS) -o bin/classtest

$(CPU): $(CLASS)
	g++  -c lib/$(CPU).cpp lib/$(CLASS).o $(FLAGS) -o lib/$(CPU).o

$(CLASS):
	g++ -c lib/$(CLASS).cpp $(FLAGS) -o lib/$(CLASS).o

makeOS: 
	g++ lib/$(MEM).cpp lib/$(CLASS).cpp lib/$(QUEUE).cpp lib/$(CPU).cpp lib/$(IO).cpp lib/$(RR).cpp bin/$(OS).cpp -lxml2 $(THREAD) $(FLAGS) $(SAN_FLAGS) -ggdb -o bin/$(OS)

clean:
	rm bin/$(OS)
	rm a.out
	rm bin/classtest
	rm bin/cputest
	rm lib/*.o 
