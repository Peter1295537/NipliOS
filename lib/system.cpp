#include <'../include/system.h'>

using namespace std;

system::system(){

}

int system::spawn(string filename){
	//NEED ERROR CHECKING HERE
	process tmp(filename, mainmem.getPidCounter());
	NEW.push_back(&tmp);

	return 0;
}
int system::requestIO(process* p){
	WAIT.push_back(p);

	return 0;

}
int system::addReady(process* p){
	READY.push_back(p);

	return 0;
}
