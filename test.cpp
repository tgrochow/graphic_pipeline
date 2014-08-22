// project
#include <pipeline.hpp>

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
    pipeline p;

    std::vector<std::string> stage_path(3);

    stage_path[0] = "shader/pass.vert";
    stage_path[1] = "shader/glyph.geom";
    stage_path[2] = "shader/phong.frag";

    p.add_program("test",stage_path);
  }

  return 0;
}
