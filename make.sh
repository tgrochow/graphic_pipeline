clang++ test.cpp\
 source/pipeline.cpp\
 source/program.cpp\
 source/stage.cpp\
 source/uniform_map.cpp\
 -otest\
 -std=c++11\
 -Wall\
 -pedantic\
 -Iinclude\
 -lGLEW -lglut\
 -L/usr/lib/nvidia-331\
 -lGL
