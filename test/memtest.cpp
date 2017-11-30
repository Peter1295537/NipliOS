#include <iostream>
#include <fstream>
#include "../include/mem_mgmt.h"
using namespace std;

int main(){
  memory mainmem;
  cout<<"Total memory: "<<mainmem.getTotalMemory()<<endl;
  cout<<"Memory used: "<<mainmem.getUsedMemory()<<endl;
  cout<<"Free memory: "<<mainmem.getFreeMemory()<<endl;
  mainmem.createProcess("data/process_template");
  cout<<"Total memory: "<<mainmem.getTotalMemory()<<endl;
  cout<<"Memory used: "<<mainmem.getUsedMemory()<<endl;
  cout<<"Free memory: "<<mainmem.getFreeMemory()<<endl;
  
  return 0;
}
