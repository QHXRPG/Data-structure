cmake_minimum_required(VERSION 3.24)
project(Data_structure C)

set(CMAKE_C_STANDARD 17)

add_executable(Data_structure main.c
        SeqList/SeqList.c SeqList/SeqList.h homework/1.c homework/1.h SList/SList.c SList/SList.h BList/BList.c BList/BList.h)
