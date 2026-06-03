cmake_minimum_required(VERSION 4.2)
project(PetBudgetCLION)

set(CMAKE_CXX_STANDARD 20)

add_executable(PetBudgetCLION main.cpp
        vacuna.h
        gasto.h
        mascota.h
        perro.h
        gato.h
        presupuesto.h)
