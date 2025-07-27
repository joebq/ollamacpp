#include "liboai.h"
#include <iostream>
#include <stdexcept>
#include "ollama.hpp"

int main()
{
  Ollama ollama("http://localhost:11434");
  std::cout << ollama.generate("llama3.2", "what is today's date?") << std::endl;
}