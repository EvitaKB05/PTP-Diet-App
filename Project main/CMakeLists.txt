cmake_minimum_required(VERSION 3.17)

set(project "DietApp")
project(${project})

set(CMAKE_CXX_STANDARD 17)

set(${project}_SOURCES
        main.cpp)

add_subdirectory(WeightLossDiet)
add_subdirectory(WeightGainDiet)
add_subdirectory(HealthyWeightDiet)
add_subdirectory(Person)
add_subdirectory(CalorieCounter)
add_subdirectory(DataBase)


set(${project}_SOURCE_LIST
        ${${project}_SOURCES})

configure_file(dataBase/BD_Diet.txt
        ${CMAKE_CURRENT_BINARY_DIR}/BD_Diet.txt COPYONLY)

add_executable(${project}
        ${${project}_SOURCE_LIST}
        Diet/Diet.cpp
        Diet/Diet.h
        main.cpp
        main.cpp main.h CalorieCounter/CalorieCounter.cpp CalorieCounter/CalorieCounter.h dataBase/dataBase.h dataBase/dataBase.cpp WeightLossDiet/WeightLossDiet.cpp WeightLossDiet/WeightLossDiet.h Person/Person.cpp Person/Person.h HealthyWeightDiet/HealthyWeightDiet.cpp HealthyWeightDiet/HealthyWeightDiet.h Diet/Diet.cpp Diet/Diet.h WeightGainDiet/WeightGainDiet.cpp WeightGainDiet/WeightGainDiet.h)

target_link_libraries(${project} WeightLossDiet)
target_link_libraries(${project} WeightGainDiet)
target_link_libraries(${project} HealthyWeightDiet)
target_link_libraries(${project} Person)
target_link_libraries(${project} CalorieCounter)
target_link_libraries(${project} DataBase)
