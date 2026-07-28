cmake_minimum_required(VERSION 3.20)
project(leetcode_solutions CXX)

set(CMAKE_CXX_STANDARD 17)

# Bütün klasörlerdeki tüm .cpp dosyalarını otomatik bul
file(GLOB_RECURSE SOURCES "*.cpp")

# Bulunan her .cpp dosyası için çalıştırılabilir bir hedef oluştur
foreach(source_file ${SOURCES})
    get_filename_component(name ${source_file} NAME_WE)
    add_executable(${name} ${source_file})
endforeach()