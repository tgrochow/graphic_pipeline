// project
#include <pipeline.hpp>

// std
#include <iostream>

// openGL
#include <GL/freeglut.h>
#include <glm/gtc/matrix_transform.hpp>

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

    p.uniforms_.set("projection",glm::perspective(45.0f,1.25f,0.1f,100.0f));
    p.uniforms_.set("view",glm::mat4(1.0f));

    p.add_program("example");

    p.set_stage("example","stage/simple.vert");
    p.set_stage("example","stage/simple.frag");

    p.link_programs();

    p.set_link("example","projection");
    p.set_link("example","view");

    p.enable("example");
  }

  return 0;
}
