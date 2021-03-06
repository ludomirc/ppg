#include "libs.h"
#include "Scene.h"

// funkcja do poczatkowej inicjalizacji OGL
bool init(Scene &scene)
{
    std::cout << "Init..." << std::endl;
    // ustalamy domyślny kolor ekranu
    gl::glClearColor(0.f, 0.f, 0.f, 1.f);

    // wlaczmy renderowanie tylko jednej strony poligon-ow
//    gl::glEnable(gl::GL_CULL_FACE);
    // ustalamy, ktora strona jest "przodem"
//    gl::glFrontFace(gl::GL_CCW);
    // ustalamy, ktorej strony nie bedziemy renderowac
//    gl::glCullFace(gl::GL_BACK);

    return scene.init();
}

// funkcja wywolywana podczas zmiany rozmiaru okna
void reshape(GLFWwindow *window, int width, int height)
{
    std::cout << "Reshape..." << std::endl;
    gl::glViewport(0, 0, width, height);
}

// funkcja wywolywana co klatke
void frame(float delta_time, Scene &scene)
{
    gl::glClear(gl::GL_COLOR_BUFFER_BIT | gl::GL_DEPTH_BUFFER_BIT);
    gl::glClearColor(0.f, 0.f, 0.f,0.f);

    scene.draw(delta_time);
}

// funkcja wywolywana przy wyjsciu z aplikacji
void release(Scene &scene)
{
    std::cout << "Release..." << std::endl;
    scene.release();
}

// funkcja wywolywana podczas bledy w GLFW
void errorCallbackForGLFW(int error, const char* description)
{
	std::cerr << "GLFW error - " << std::hex << error << " - " << description << std::endl;
}

// glowna funkcja programu
int main(void)
{
    // ustawienie funkcji, ktora ma sie wywolac podczas bledu GLFW
    glfwSetErrorCallback(errorCallbackForGLFW);

    // inicjalizacja GLFW
    if(!glfwInit())
    {
        std::cerr << "Error - glfwInit failed" << std::endl;
        return -1;
    }

    // ustawienie wartosci dla glownego framebuffer-a
    glfwWindowHint(GLFW_RED_BITS, 8);
    glfwWindowHint(GLFW_GREEN_BITS, 8);
    glfwWindowHint(GLFW_BLUE_BITS, 8);
    glfwWindowHint(GLFW_DEPTH_BITS, 32);
    glfwWindowHint(GLFW_STENCIL_BITS, 0);
	

    // wymuszenie minimalnej wersji OGL wymaganej dla naszej aplikacji
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, true);

    // stworzenie okna
    auto *window = glfwCreateWindow(1366, 768, "OGLSample", nullptr, nullptr);
    if(!window)
    {
        std::cerr << "Error - glfwCreateWindow failed" << std::endl;
        glfwTerminate();
        return -1;
    }

    // stworzenie kontekstu OGL dla okna
    glfwMakeContextCurrent(window);
    // inicjalizacja glbinding
    glbinding::Binding::initialize(glfwGetProcAddress);
    // wlaczenie V-sync jesli jest obslugiwane...
    glfwSwapInterval(1);

    // ustawienie callback-a po każdej funkcji OGL, tak aby wywolywana byla funkcja glGetError, sprawdzajaca czy nie wystapil jakis blad
    glbinding::setCallbackMaskExcept(glbinding::CallbackMask::After, { "glGetError" });
    glbinding::setAfterCallback([](const glbinding::FunctionCall &)
    {
        const auto error = gl::glGetError();
        if(error != gl::GL_NO_ERROR)
            std::cout << "OpenGL error - " << std::hex << static_cast<int>(error) << std::endl;
    });

    // ustawienie funkcji wywolywanej podczas zmiany rozmiaru okna
    glfwSetFramebufferSizeCallback(window, reshape);

    {
        // stworzenie obiektu naszej sceny
        Scene scene;
        // wywolanie funkcji init
        bool go = init(scene);
        float time_from_start_to_last_frame = 0.f;
        // glowna petla programu
        while(go && !glfwWindowShouldClose(window))
        {
            // pobranie i obsluga event-ow
            glfwPollEvents();
            float time_from_start = glfwGetTime();
            float last_frame_time = time_from_start - time_from_start_to_last_frame;
            time_from_start_to_last_frame = time_from_start;
            // wywolanie funkcji frame (co klatke)
            frame(last_frame_time, scene);
            // podmiana backbuffer-a
            glfwSwapBuffers(window);
        }
        // wywolanie funkcji release (na zakonczenie)
        release(scene);
    }

    // zniszczenie okna
    glfwDestroyWindow(window);

    // posprzatanie po GLFW
    glfwTerminate();

#if WIN32
	std::cin.ignore();
#endif
    return 0;
}
