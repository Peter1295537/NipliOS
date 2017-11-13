# NipliOS
g++ mem_mgmt.cpp process_class.cpp queue.cpp cpu.cpp rr.cpp NipliOS.cpp -lxml2 -ggdb -o NipliOS

4096 MB Memory
I/O between 25 and 50 cycles

needed classes:

  process class (critical sections)
  
  cpu class (cores/core status/methods for running programs (requesting memory?)/dispatcher)
  
  memory manager 
  
  system class (handle critical sections/system calls implementation)
  
  queue class(deadlock avoidance/scheduler)
  
  main class/running class ( scheduler/status/cmd )
  
  
