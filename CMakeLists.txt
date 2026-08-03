cmake_minimum_required(VERSION 3.20)
project(leetcode_solutions CXX)

set(CMAKE_CXX_STANDARD 17)

# Bütün klasörlerdeki tüm .cpp dosyalarını otomatik bul
file(GLOB_RECURSE SOURCES "*.cpp")

# Bulunan her .cpp dosyası için çalıştırılabilir bir hedef oluştur
foreach(source_file ${SOURCES})
    get_filename_component(name ${source_file} NAME_WE)
    add_executable(${name} ${source_file}
            03-arrays-and-math/0013-roman-to-integer.cpp
            03-arrays-and-math/0035-search-insert-position.cpp
            03-arrays-and-math/0134-gas-station.cpp
            02-linked-list/0002-add-two-numbers.cpp
            04-backtracking/0046-permutations.cpp
            03-arrays-and-math/0238-product-of-array-except-self.cpp
            02-linked-list/0019-remove-nth-node-from-end-of-list.cpp
            05-stack/0739-daily-temperatures.cpp
    )
endforeach()