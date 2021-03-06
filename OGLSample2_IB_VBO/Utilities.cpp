#include "Utilities.h"

// funkcja wczytujaca zawartosc pliku
std::string loadFile(const std::string &file_path)
{
    std::ifstream file(file_path, std::ios::in | std::ios::binary);
    if (file)
    {
		std::ostringstream contents;
        contents << file.rdbuf();
        file.close();
        return(contents.str());
    }
    return {};
}

// funkcja kompilujaca shader
// przyjmuje na wejscie kod shader-a i informacje o rodzaju shader-a
// w przypadku powodzenia kompilacji zwraca uchwyt (handle) do skompilowanego shader-a
std::optional<gl::GLuint> createAndCompileShader(const std::string &shader_source, gl::GLenum shader_type)
{
    if(shader_source.length() > 0u)
    {
        gl::GLuint shader = gl::glCreateShader(shader_type);
        const char *shader_source_ptr = shader_source.c_str();
        gl::glShaderSource(shader, 1, &shader_source_ptr, nullptr);
        gl::glCompileShader(shader);
        gl::GLint is_compiled = 0;
        gl::glGetShaderiv(shader, gl::GL_COMPILE_STATUS, &is_compiled);
        if(!is_compiled)
        {
            gl::GLint max_log_length = 0u;
            gl::glGetShaderiv(shader, gl::GL_INFO_LOG_LENGTH, &max_log_length);
            std::string error_log;
            error_log.resize(max_log_length);
            gl::glGetShaderInfoLog(shader, max_log_length, &max_log_length, error_log.data());
            gl::glDeleteShader(shader);
            std::cerr << (shader_type == gl::GL_VERTEX_SHADER ? "Vertex shader" : (shader_type == gl::GL_FRAGMENT_SHADER ? "Fragment shader" : "Shader")) << " compilation error: " << error_log << std::endl;
            return {};
        }
        return shader;
    }
    return {};
}

std::optional<gl::GLuint> createProgram(const std::string &vs_source_path, const std::string &fs_source_path)
{
    std::string vs_source = loadFile(vs_source_path);
    std::string fs_source = loadFile(fs_source_path);

    if(vs_source.length() == 0u || fs_source.length() == 0u)
    {
        std::cerr << "Error - can't load file: " << (vs_source.length() == 0u ? vs_source_path : fs_source_path) << std::endl;
    }

    if(auto compile_vs_result = createAndCompileShader(loadFile(vs_source_path), gl::GL_VERTEX_SHADER))
    {
        if(auto compile_fs_result = createAndCompileShader(loadFile(fs_source_path), gl::GL_FRAGMENT_SHADER))
        {
            gl::GLuint vs = compile_vs_result.value();
            gl::GLuint fs = compile_fs_result.value();

            gl::GLuint program = gl::glCreateProgram();
            gl::glAttachShader(program, vs);
            gl::glAttachShader(program, fs);
            gl::glLinkProgram(program);

            gl::GLint is_linked = 0;
            gl::glGetProgramiv(program, gl::GL_LINK_STATUS, &is_linked);
            if(!is_linked)
            {
                gl::GLint max_log_length = 0;
                gl::glGetProgramiv(program, gl::GL_INFO_LOG_LENGTH, &max_log_length);
                gl::glDeleteProgram(program);
                gl::glDeleteShader(vs);
                gl::glDeleteShader(fs);
                return {};
            }

            return program;
        }
    }

    return {};
}
