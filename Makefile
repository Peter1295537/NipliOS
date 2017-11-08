CLASS=process_class
TEST=process_test
SAN_FLAGS=-lxml2 -lasan -g -std=c++11 -fsanitize=address -fno-omit-frame-pointer -fstack-protector -Wstack-protector 
FLAGS=-lxml2 -g -std=c++11 -fno-omit-frame-pointer -fstack-protector -Wstack-protector 

test: $(CLASS)
	g++ $(TEST).cpp $(CLASS).o $(FLAGS)

$(CLASS):
	g++ -c $(CLASS).cpp $(FLAGS)

clean:
	rm *.o 
	rm a.out
