#pragma once

#include "libs.h"

// funkcja wczytujaca shader-y z plikow, kompilujaca je i tworzaca program
// przyjmuje na wejscie sciezki do VS i FS
// w przypadku powodzenia zwraca uchwyt (handle) do programu
std::optional<gl::GLuint> createProgram(const std::string &vs_source_path, const std::string &fs_source_path);
