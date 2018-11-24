#pragma once

#include "libs.h"

class Scene
{
    gl::GLuint vbo_handle;
    gl::GLuint vao_handle;
    gl::GLuint simple_program;

public:
	Scene(void);
	~Scene(void);

    // metoda wywolywana na poczatku (przy starcie aplikacji, zaraz po inicjalizacji OGL)
    bool init(void);
    // metoda wywolywana co klatke
	bool draw(float delta_time);
    // metoda wywolywana przy zamknieciu aplikacji
	void release(void);
};
