cmake_minimum_required(VERSION 3.17)
cmake_policy(SET CMP0100 NEW)  # handle .hh files
project(CLAP_HOST C CXX)

set(UsePkgConfig TRUE CACHE BOOL "Use PkgConfig to find RtMidi and RtAudio dependencies")

add_subdirectory(clap)
add_subdirectory(clap-helpers)
add_subdirectory(host)
