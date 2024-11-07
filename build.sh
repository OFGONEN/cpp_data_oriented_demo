#!/bin/sh

g++ -std=c++17 -O3 -DNDEBUG -o update_by_pointer.out update_by_pointer.cpp
g++ -std=c++17 -O3 -DNDEBUG -o update_by_value.out update_by_value.cpp
g++ -std=c++17 -O3 -DNDEBUG -pthread -o update_by_pointer_threaded.out update_by_pointer_threaded.cpp
g++ -std=c++17 -O3 -DNDEBUG -pthread -o update_by_value_threaded.out update_by_value_threaded.cpp