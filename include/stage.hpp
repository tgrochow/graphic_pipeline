#ifndef STAGE_HPP
#define STAGE_HPP

// std
#include <string>

// openGL
#include <GL/glew.h>

class stage
{
  public :

  stage(std::string const&);
  ~stage();

  GLuint compile();

  void clear();


  private :

  const GLchar* const load() const;

  bool compile_feedback() const;

  GLenum recognize_type() const;

  // member
  GLuint      id_;
  GLenum      type_;
  std::string path_;
};

#endif
