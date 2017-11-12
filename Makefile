CLASS=process_class
TEST=process_test
CPU=cpu
SAN_FLAGS=-lxml2 -lasan -g -std=c++11 -fsanitize=address -fno-omit-frame-pointer -fstack-protector -Wstack-protector 
FLAGS=-lxml2 -g -std=c++11 -fno-omit-frame-pointer -fstack-protector -Wstack-protector 
MEM=mem_mgmt
cputest: $(CPU)
	g++ cputest.cpp $(CLASS).o $(CPU).o $(FLAGS)

classtest: $(CLASS)
	g++ $(TEST).cpp $(CLASS).o $(FLAGS)

$(CPU): $(CLASS)
	g++  -c $(CPU).cpp $(CLASS).o $(FLAGS)

$(CLASS):
	g++ -c $(CLASS).cpp $(FLAGS)

clean:
	rm *.o 
	rm a.out
