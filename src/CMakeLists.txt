add_library(BanditSolvers BanditSolver.cpp EpsilonGreedySolver.cpp SampleAverageEpsilonGreedySolver.cpp)

add_library(BanditTests ConstantRewardTestBed.cpp  TestBed.cpp TestResult.cpp)

target_link_libraries(BanditTests PUBLIC BanditSolvers)

target_include_directories(BanditSolvers INTERFACE ${CMAKE_CURRENT_SOURCE_DIR})
target_include_directories(BanditTests INTERFACE ${CMAKE_CURRENT_SOURCE_DIR})

add_executable(KArmedBandit main.cpp)

target_link_libraries(KArmedBandit PUBLIC BanditTests BanditSolvers)
