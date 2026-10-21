cmake_minimum_required(VERSION 4.0.0)

project(
  TicTacToe
  VERSION 0.1.0
  LANGUAGES C
)

add_executable(TicTacToe
  src/TicTacToe.h
  src/TicTacToe.c
  src/main.c
)
