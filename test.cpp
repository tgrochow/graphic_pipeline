// project
#include <program.hpp>

// std
#include <iostream>
#include <memory>

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
    stage v("shader/pass.vert"),
          g("shader/glyph.geom"),
          f("shader/phong.frag");

    std::shared_ptr<stage> v_ptr(std::make_shared<stage>(v)),
                           g_ptr(std::make_shared<stage>(g)),
                           f_ptr(std::make_shared<stage>(f));

    program p("test");

    p.define_stage(v_ptr);
    p.define_stage(g_ptr);
    p.define_stage(f_ptr);

    p.link();

    p.reset_stage(GL_GEOMETRY_SHADER);
  }

  return 0;
}
