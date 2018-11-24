#include "Scene.h"
#include "Utilities.h"

Scene::Scene(void) : vbo_handle(0u), index_buffer_handle(0u), vao_handle(0u)
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
	if (auto create_program_result = createProgram("../../Shaders/very_simple_vs.glsl", "../../Shaders/very_simple_fs.glsl"))
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
		-0.5f, 0.f, 0.f, 0.583f,  0.771f,  0.014f,
		0.5f, 0.f, 0.f, 0.609f,  0.115f,  0.436f,
		0.f, 0.5f, 0.f, 0.327f,  0.483f,  0.844f
	};

    // stworzenie tablicy z danymi o indeksach
    gl::GLushort indices[] = { 0, 1, 2 };

    std::cout << "Generating buffers..." << std::endl;
    // stworzenie bufora
    gl::glGenBuffers(1, &vbo_handle);
    // zbindowanie bufora jako VBO
    gl::glBindBuffer(gl::GL_ARRAY_BUFFER, vbo_handle);
    // alokacja pamieci dla bufora zbindowanego jako VBO i skopiowanie danych z tablicy "vertices"
    gl::glBufferData(gl::GL_ARRAY_BUFFER, 9 * sizeof(gl::GLfloat), vertices, gl::GL_STATIC_DRAW);
    // odbindowanie buffora zbindowanego jako VBO (zeby przypadkiem nie narobic sobie klopotow...)
    gl::glBindBuffer(gl::GL_ARRAY_BUFFER, 0);

    // stworzenie bufora
    gl::glGenBuffers(1, &index_buffer_handle);
    // zbindowanie bufora jako IB
    gl::glBindBuffer(gl::GL_ELEMENT_ARRAY_BUFFER, index_buffer_handle);
    // alokacja pamieci dla bufora zbindowanego jako IB i skopiowanie danych z tablicy "indeices"
    gl::glBufferData(gl::GL_ELEMENT_ARRAY_BUFFER, 3 * sizeof(gl::GLushort), indices, gl::GL_STATIC_DRAW);
    // odbindowanie buffora zbindowanego jako IB (zeby przypadkiem nie narobic sobie klopotow...)
    gl::glBindBuffer(gl::GL_ELEMENT_ARRAY_BUFFER, 0);

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
    // zbindowanie IB do aktualnego VAO
    gl::glBindBuffer(gl::GL_ELEMENT_ARRAY_BUFFER, index_buffer_handle);
    // odbindowanie VAO (ma ono teraz informacje m.in. o VBO + IB, wiec gdy zajdzie potrzeba uzycia VBO + IB, wystarczy zbindowac VAO)
    gl::glBindVertexArray(0u);

    // odbindowanie buffora zbindowanego jako VBO (zeby przypadkiem nie narobic sobie klopotow...)
    gl::glBindBuffer(gl::GL_ARRAY_BUFFER, 0);
    // odbindowanie buffora zbindowanego jako bufor indeksow (zeby przypadkiem nie narobic sobie klopotow...)
    gl::glBindBuffer(gl::GL_ELEMENT_ARRAY_BUFFER, 0);

    // na tym mozna zakonczyc
    // w tej prostej aplikacji bedziemy rysowac tylko 1 (powyzej stworzony) model, dlatego mozemy juz teraz ustawic odpowiednie dane dla naszych shaderow (nie beda sie one zmieniac co klatke...)
    // zeby narysowac nasz model musimy ustawic odpowiednie VBO + IB (a dzieki temu ze VAO ma o nich iformacje sprowadza sie to do ustawienia odpowiedniego VAO, a przez to reszte buforow)
    // Czyli znowu bindujemy VAO
    gl::glBindVertexArray(vao_handle);

	return true;
}

bool Scene::draw(float delta_time)
{
    // rozpoczynamy rysowanie uzywajac ustawionego programu (shaderow) i ustawionych buforow
    gl::glDrawElements(gl::GL_TRIANGLES, 3, gl::GL_UNSIGNED_SHORT, 0);

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

    // odbindowanie IB
    glBindBuffer(gl::GL_ELEMENT_ARRAY_BUFFER, 0);
    if (index_buffer_handle)
    {
        // usuniecie IB
        gl::glDeleteBuffers(1, &index_buffer_handle);
        index_buffer_handle = 0;
    }

    // ustawienie aktywnego programu na 0 (zaden)
    gl::glUseProgram(0);

    // usuniecie programu
    gl::glDeleteProgram(simple_program);
}
