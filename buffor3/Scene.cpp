#include "Scene.h"
#include "Utilities.h"

Scene::Scene(void) : vbo_handle(0u), index_buffer_handle(0u), vao_handle(0u), vbo_color(0u) {
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
    gl::glEnable(gl::GL_DEPTH_TEST);
    gl::glEnable(gl::GL_CULL_FACE);
    gl::glFrontFace(gl::GL_CCW);
    gl::glCullFace(gl::GL_BACK);
   // stworzenie tablicy z danymi o wierzcholkach 3x (x, y, z)
    gl::GLfloat vertices[] = {
            -0.5,-0.5,0.0,
            0.5,-0.5,0.0,
            -0.5,0.5,0.0,

            -0.4,-0.4,-0.5,
            0.4,-0.4,-0.5,
            -0.4,0.4,-0.5

    };
    gl::GLfloat colors[] = {
            1.0, 0.0, 0.0,
            1.0, 0.0, 0.0,
            1.0, 0.0, 0.0,

            0.0, 0.0, 1.0,
            0.0, 0.0, 1.0,
            0.0, 0.0, 1.0

    };

    // stworzenie tablicy z danymi o indeksach
    gl::GLushort indices[] = {0,1,2,5,4,3};

    std::cout << "Generating buffers..." << std::endl;
    // stworzenie bufora
    gl::glGenBuffers(1, &vbo_handle);
    // zbindowanie bufora jako VBO
    gl::glBindBuffer(gl::GL_ARRAY_BUFFER, vbo_handle);
    // alokacja pamieci dla bufora zbindowanego jako VBO i skopiowanie danych z tablicy "vertices"
    gl::glBufferData(gl::GL_ARRAY_BUFFER, 3 * 6 * sizeof(gl::GLfloat), vertices, gl::GL_STATIC_DRAW);
    // odbindowanie buffora zbindowanego jako VBO (zeby przypadkiem nie narobic sobie klopotow...)
    gl::glBindBuffer(gl::GL_ARRAY_BUFFER, 0);

    // stworzenie bufora
    gl::glGenBuffers(1, &index_buffer_handle);
    // zbindowanie bufora jako IB
    gl::glBindBuffer(gl::GL_ELEMENT_ARRAY_BUFFER, index_buffer_handle);
    // alokacja pamieci dla bufora zbindowanego jako IB i skopiowanie danych z tablicy "indeices"
    gl::glBufferData(gl::GL_ELEMENT_ARRAY_BUFFER, 3 * 6 * sizeof(gl::GLushort), indices, gl::GL_STATIC_DRAW);
    // odbindowanie buffora zbindowanego jako IB (zeby przypadkiem nie narobic sobie klopotow...)
    gl::glBindBuffer(gl::GL_ELEMENT_ARRAY_BUFFER, 0);

    //kolory
    gl::glGenBuffers(1, &vbo_color);
    // zbindowanie bufora jako VBO
    glBindBuffer(gl::GL_ARRAY_BUFFER, vbo_color);
    // alokacja pamieci dla bufora zbindowanego jako VBO i skopiowanie danych z tablicy "collors"
    glBufferData(gl::GL_ARRAY_BUFFER, 3 * 6 * sizeof(gl::GLfloat), colors, gl::GL_STATIC_DRAW);
    // odbindowanie buffora zbindowanego jako VBO (zeby przypadkiem nie narobic sobie klopotow...)
    glBindBuffer(gl::GL_ARRAY_BUFFER, 0);



    // stworzenie VAO
    gl::glGenVertexArrays(1, &vao_handle);
    // zbindowanie VAO
    gl::glBindVertexArray(vao_handle);

    // zbindowanie VBO do aktualnego VAO
    gl::glBindBuffer(gl::GL_ARRAY_BUFFER, vbo_handle);
    // ustalenie jak maja byc interpretowane dane z VBO
    gl::glVertexAttribPointer(0u, 3 , gl::GL_FLOAT, gl::GL_FALSE,3*sizeof(float),(const gl::GLvoid*)(0) );
    gl::glEnableVertexAttribArray(0u);

    gl::glBindBuffer(gl::GL_ARRAY_BUFFER, vbo_color);
    gl::GLuint vcolor_position_loction {1u};
    gl::glVertexAttribPointer(vcolor_position_loction, 3, gl::GL_FLOAT, gl::GL_FALSE, sizeof(float)* 3, (const gl::GLvoid*)0);
    gl::glEnableVertexAttribArray(vcolor_position_loction);

    // zbindowanie IB do aktualnego VAO
    gl::glBindBuffer(gl::GL_ELEMENT_ARRAY_BUFFER, index_buffer_handle);
    //gl::glBindBuffer(gl::GL_ELEMENT_ARRAY_BUFFER, 0);
    // odbindowanie VAO (ma ono teraz informacje m.in. o VBO + IB, wiec gdy zajdzie potrzeba uzycia VBO + IB, wystarczy zbindowac VAO)

    gl::glBindVertexArray(0u);

    gl::glBindVertexArray(vao_handle);

	return true;
}

void Scene::collorBuffer(const gl::GLfloat *collors) const {


//    gl::glGenBuffers(1, &vbo_color);
//    // zbindowanie bufora jako VBO
//    glBindBuffer(gl::GL_ARRAY_BUFFER, vbo_color);
//    // alokacja pamieci dla bufora zbindowanego jako VBO i skopiowanie danych z tablicy "collors"
//    glBufferData(gl::GL_ARRAY_BUFFER, 3 * 6 * sizeof(gl::GLfloat), collors, gl::GL_STATIC_DRAW);
//    // odbindowanie buffora zbindowanego jako VBO (zeby przypadkiem nie narobic sobie klopotow...)
//    glBindBuffer(gl::GL_ARRAY_BUFFER, 0);
}

bool Scene::draw(float delta_time)
{
    // rozpoczynamy rysowanie uzywajac ustawionego programu (shaderow) i ustawionych buforow
    gl::glDrawElements(gl::GL_TRIANGLES, 6, gl::GL_UNSIGNED_SHORT, 0);

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
