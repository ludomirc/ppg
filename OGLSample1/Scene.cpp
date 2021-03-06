#include "Scene.h"
#include "Utilities.h"

Scene::Scene(void) : vbo_handle(0u), vao_handle(0u), simple_program(0u)
{
}

Scene::~Scene(void)
{
}

bool Scene::init(void)
{
    std::cout << "Shaders compilation..." << std::endl;
    // wczytanie z plikow i skompilowanie shaderow oraz utworzenie programu (VS + FS)
#if WIN32
	if (auto create_program_result = createProgram("../../../../OGL/Shaders/very_simple_vs.glsl", "../../../../OGL/Shaders/very_simple_fs.glsl"))
#else
	if (auto create_program_result = createProgram("./Shaders/very_simple_vs.glsl", "./Shaders/very_simple_fs.glsl"))
#endif
    {
        simple_program = create_program_result.value();
    }
    else
    {
        std::cerr << "Error - can't create program..." << std::endl;
        return false;
    }

    // ustawienie informacji o lokalizacji atrybutu pozycji w vs (musi sie zgadzac z tym co mamy w VS!!!)
    gl::GLuint vertex_position_loction = 0u;

    // ustawienie programu, ktory bedzie uzywany podczas rysowania
    gl::glUseProgram(simple_program);

    // stworzenie tablicy z danymi o wierzcholkach 3x (x, y, z)
    gl::GLfloat vertices[] = {
		-0.5f, 0.f, 0.f,
		0.5f, 0.f, 0.f,
		0.f, 0.5f, 0.f
	};

    std::cout << "Generating buffers..." << std::endl;
    // stworzenie bufora
    gl::glGenBuffers(1, &vbo_handle);
    // zbindowanie bufora jako VBO
    gl::glBindBuffer(gl::GL_ARRAY_BUFFER, vbo_handle);
    // alokacja pamieci dla bufora zbindowanego jako VBO i skopiowanie danych z tablicy "vertices"
    gl::glBufferData(gl::GL_ARRAY_BUFFER, 9 * sizeof(gl::GLfloat), vertices, gl::GL_STATIC_DRAW);
    // odbindowanie buffora zbindowanego jako VBO (zeby przypadkiem nie narobic sobie klopotow...)
    gl::glBindBuffer(gl::GL_ARRAY_BUFFER, 0);

    // stworzenie VAO
    gl::glGenVertexArrays(1, &vao_handle);
    // zbindowanie VAO
    gl::glBindVertexArray(vao_handle);

    // zbindowanie VBO do aktualnego VAO
    gl::glBindBuffer(gl::GL_ARRAY_BUFFER, vbo_handle);
    // ustalenie jak maja byc interpretowane dane z VBO
    gl::glVertexAttribPointer(vertex_position_loction, 3, gl::GL_FLOAT, gl::GL_FALSE, sizeof(float)* 3, (const gl::GLvoid*)0);
    // odblokowanie mozliwosci wczytywania danych z danej lokalizacji
    gl::glEnableVertexAttribArray(vertex_position_loction);
    // odbindowanie VAO (ma ono teraz informacje m.in. o VBO, wiec gdy zajdzie potrzeba uzycia VBO, wystarczy zbindowac VAO)
    gl::glBindVertexArray(0u);

    // odbindowanie buffora zbindowanego jako VBO (zeby przypadkiem nie narobic sobie klopotow...)
    gl::glBindBuffer(gl::GL_ARRAY_BUFFER, 0);

    // na tym mozna zakonczyc
    // w tej prostej aplikacji bedziemy rysowac tylko 1 (powyzej stworzony) model, dlatego mozemy juz teraz ustawic odpowiednie dane dla naszych shaderow (nie beda sie one zmieniac co klatke...)
    // zeby narysowac nasz model musimy ustawic odpowiednie VBO (a dzieki temu ze VAO ma o nim iformacje sprowadza sie to do ustawienia odpowiedniego VAO)
    // Czyli znowu bindujemy VAO
    gl::glBindVertexArray(vao_handle);

	return true;
}

bool Scene::draw(float delta_time)
{
    // rozpoczynamy rysowanie uzywajac ustawionego programu (shaderow) i ustawionych buforow
    gl::glDrawArrays(gl::GL_TRIANGLES, 0, 9);

	return true;
}

void Scene::release(void)
{
    // odbindowanie VAO
    gl::glBindVertexArray(0);
    if (vao_handle)
    {
        // usuniecie VAO
        gl::glDeleteVertexArrays(1, &vao_handle);
        vao_handle = 0;
    }

    // odbindowanie VBO
    gl::glBindBuffer(gl::GL_ARRAY_BUFFER, 0);
    if (vbo_handle)
    {
        // usuniecie VBO
        gl::glDeleteBuffers(1, &vbo_handle);
        vbo_handle = 0;
    }

    // ustawienie aktywnego programu na 0 (zaden)
    gl::glUseProgram(0);

    // usuniecie programu
    gl::glDeleteProgram(simple_program);
}
