// header
#include <stage.hpp>

// std
#include <iostream>
#include <fstream>

// user constructor
stage::

stage(std::string const& path) :
id_(0),
type_(GL_INVALID_ENUM),
path_(path)
{
  type_ = recognize_type();
}

// destructor
stage::

~stage()
{
  clear();
}

// load, compile stage source code
GLuint stage::

compile()
{
  if(id_ != 0)
  {
    clear();
  }

  if(type_ != GL_INVALID_ENUM)
  {
    const char* source(load());

    if(source != nullptr)
    {
      id_ = glCreateShader(type_);

      if(id_ != 0)
      {
        glShaderSource(id_,1,&source,nullptr);
        glCompileShader(id_);

        if(!compile_feedback())
        {
          clear();
        }
      }
    }

    delete[] source;
  }

  return id_;
}

// delete shader object
void stage::

clear()
{
  if(id_ != 0)
  {
    glDeleteShader(id_);

    id_ = 0;
  }
}

// load stage source code
const GLchar* const stage::

load() const
{
  GLchar* source(nullptr);

  std::ifstream input(path_);

  if(input.good())
  {
    input.seekg(0,input.end);
    std::streampos length(input.tellg());
    input.seekg(0,input.beg);

    length -= 1;
    source  = new char[length];

    input.read(source,length);
    input.close();
  }

  return source;
}

// write shader compile feedback in error stream
bool stage::

compile_feedback() const
{
  GLint status(GL_FALSE);

  glGetShaderiv(id_,GL_COMPILE_STATUS,&status);

  if(status != GL_TRUE)
  {
    GLint   length(0);
    GLchar* info_buffer(nullptr);

    glGetShaderiv(id_,GL_INFO_LOG_LENGTH,&length);

    if(length != 0)
    {
      info_buffer = new GLchar[length];

      glGetShaderInfoLog(id_,length,nullptr,info_buffer);

      std::cerr << std::endl
                << "[" << path_ << "]"
                << std::endl << std::endl
                << "line " << info_buffer
                << std::endl;

      delete[] info_buffer;
    }

    return false;
  }

  else
  {
    return true;
  }
}

// identify stage type
GLenum stage::

recognize_type() const
{
  GLenum type(GL_INVALID_ENUM);

  size_t suffix_pos(path_.rfind('.'));

  if(suffix_pos != std::string::npos)
  {
    ++suffix_pos;

    size_t suffix_length(path_.length() - suffix_pos);

    std::string suffix(path_.substr(suffix_pos,suffix_length));

    if     (suffix.compare("vert") == 0) type = GL_VERTEX_SHADER;
    else if(suffix.compare("geom") == 0) type = GL_GEOMETRY_SHADER;
    else if(suffix.compare("frag") == 0) type = GL_FRAGMENT_SHADER;
  }

  return type;
}
