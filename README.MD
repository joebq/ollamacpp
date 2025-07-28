# Ollama C++

> [!NOTE]
> **Ollama** is an AI tool that allows the running of LLM locally on the machine. The interaction can be either via CLI or programmatically via API calls. Ollama adheres to [OpenAI API architecture](https://platform.openai.com/docs/overview).

### LESSON LEARNT FROM OLLAMA C++

> **Ollama** has an unofficial OpenAI API libraries written in C++ that is located @ https://github.com/D7EAD/liboai The library has dependencies on `nlohmann-json` and `crul` libraries for it to run.

> `liboai` can be installed using `cmake FetchContent` command.

> `Curl` library can be installed locally on the machine using the operating system package manager.

> `nlohmann-json` can be installed using `vcpkg` package manager and added to the project before running adding the `liboai` library.

### SAMPLE CODE OF CMAKELISTS.TXT FILE

```cmake
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
```

### LOCAL OLLAMA

> OpenAI API for **ollama** does not directly support `liboai` call for local ollama model, this can though be achieved by another library @ https://github.com/jmont-dev/ollama-hpp. In such manner, the program can switch dynamically between OpenAI with API Keys or connected locally.

```cpp
Ollama ollama("http://localhost:11434");
  std::cout << ollama.generate("llama3.2", "what is today's date?") << std::endl;
```

</aside>

### Resources

- [https://ollama.com](https://ollama.com/)
- [https://github.com/D7EAD/liboai/tree/main](https://github.com/D7EAD/liboai/tree/main)
- [https://github.com/nlohmann/json](https://github.com/nlohmann/json)
- [https://curl.se](https://curl.se/)
- [https://github.com/podofo/podofo](https://github.com/podofo/podofo)
- [https://github.com/ollama/ollama](https://github.com/ollama/ollama)
- [https://github.com/jmont-dev/ollama-hpp](https://github.com/jmont-dev/ollama-hpp)
- [https://vcpkg.io/en/](https://vcpkg.io/en/)
