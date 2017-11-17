CLASS=process_class
TEST=process_test
CPU=cpu
QUEUE=queue
RR=rr
OS=NipliOS
SAN_FLAGS=-lxml2 -lasan -g -std=c++11 -fsanitize=address -fno-omit-frame-pointer -fstack-protector -Wstack-protector 
FLAGS=-lxml2 -g -std=c++11 -fno-omit-frame-pointer -fstack-protector -Wstack-protector 
MEM=mem_mgmt
cputest: $(CPU)
	g++ test/cputest.cpp lib/$(CLASS).o lib/$(CPU).o $(FLAGS) -o bin/cputest

classtest: $(CLASS)
	g++ test/$(TEST).cpp lib/$(CLASS).o $(FLAGS) -o bin/classtest

$(CPU): $(CLASS)
	g++  -c lib/$(CPU).cpp lib/$(CLASS).o $(FLAGS) -o lib/$(CPU).o

$(CLASS):
	g++ -c lib/$(CLASS).cpp $(FLAGS) -o lib/$(CLASS).o

makeOS: 
	g++ lib/$(MEM).cpp lib/$(CLASS).cpp lib/$(QUEUE).cpp lib/$(CPU).cpp lib/$(RR).cpp bin/$(OS).cpp -lxml2 -ggdb -o $(OS)

clean:
	rm *.o 
	rm a.out
