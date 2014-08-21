clang++ test.cpp\
 source/program.cpp\
 source/stage.cpp\
 -otest\
 -std=c++11\
 -Wall\
 -pedantic\
 -Iinclude\
 -lGLEW -lglut\
 -L/usr/lib/nvidia-331\
 -lGL
