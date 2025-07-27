cmake_minimum_required(VERSION 4.0)
project(ollama VERSION 1.0.0 LANGUAGES CXX)

# Set C++ version to 23 and disable compiler extensions
set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# add curl and nlohman-json library using FetchContent
find_package(CURL REQUIRED)

include(FetchContent)
FetchContent_Declare(
  nlohmann_json
  GIT_REPOSITORY https://github.com/nlohmann/json
  GIT_TAG v3.12.0
)


FetchContent_Declare(
  liboai
  GIT_REPOSITORY https://github.com/D7EAD/liboai.git
  GIT_TAG main
)

find_package(nlohmann_json CONFIG REQUIRED)
set(nlohmann-json_IMPLICIT_CONVERSIONS OFF)
FetchContent_MakeAvailable(liboai)

add_executable(ollama main.cpp)
target_include_directories(ollama PRIVATE ${CURL_INCLUDE_DIRS})
target_link_libraries(ollama PRIVATE 
oai 
nlohmann_json::nlohmann_json 
# ${CURL_LIBRARIES}
CURL::libcurl
)

