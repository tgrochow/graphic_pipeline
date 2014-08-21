// project
#include <stage.hpp>

// std
#include <iostream>

// openGL
#include <GL/freeglut.h>

int main(int argc,char ** argv)
{
  glutInit(&argc,argv);
  glutInitContextVersion(4,4);
  glutInitContextFlags(GLUT_FORWARD_COMPATIBLE);
  glutInitContextProfile(GLUT_CORE_PROFILE);

  glutCreateWindow("test");

  glewExperimental = GL_TRUE;
  GLenum glew_init = glewInit();

  if(glew_init != GLEW_OK)
  {
    std::cerr << ("glew initialisation failed") << std::endl;
  }

  else
  {
    stage s("shader/pass.vert");

    s.compile();
  }

  return 0;
}
