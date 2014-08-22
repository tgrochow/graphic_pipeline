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

    p.add_program("triangle");

    p.set_stage("triangle","shader/pass.vert");
    p.set_stage("triangle","shader/glyph.geom");
    p.set_stage("triangle","shader/phong.frag");

    p.link_programs();

    p.uniforms_.set("view",glm::mat4(1.0));

    p.set_link("triangle","view");

    p.enable("triangle");
  }

  return 0;
}
