// header
#include <program.hpp>

// std
#include <iostream>

// user constructor
program::

program(std::string const& name) :
id_(0),
name_(name),
stages_()
{}

// load, compile, link to a program
void program::

link()
{
  if(id_ != 0)
  {
    glDeleteProgram(id_);

    id_ = 0;
  }

  id_ = glCreateProgram();

  if(id_ != 0)
  {
    for(auto it(stages_.begin()) ; it != stages_.end() ; ++it)
    {
      stage* stage_ptr(it->get());

      if(stage_ptr != nullptr)
      {
        GLuint stage_id(stage_ptr->compile());

        if(stage_id != 0)
        {
          glAttachShader(id_,stage_id);
        }
      }
    }

    glLinkProgram(id_);
    clear();
  }
}

// reset shading stage
void program::

reset_stage(GLenum type)
{
  switch(type)
  {
    case GL_VERTEX_SHADER :

    if(stages_[0].get() != nullptr) stages_[0].reset();
    break;

    case GL_GEOMETRY_SHADER :

    if(stages_[3].get() != nullptr) stages_[3].reset();
    break;

    case GL_FRAGMENT_SHADER :

    if(stages_[4].get() != nullptr) stages_[4].reset();
    break;
  }
}

// define one stage of the pipeline
void program::

define_stage(std::shared_ptr<stage> & stage_ptr)
{
  switch(stage_ptr->type())
  {
    case GL_VERTEX_SHADER :

    stages_[0].swap(stage_ptr);
    break;

    case GL_GEOMETRY_SHADER :

    stages_[3].swap(stage_ptr);
    break;

    case GL_FRAGMENT_SHADER :

    stages_[4].swap(stage_ptr);
    break;
  }
}

// detach, clear shading objects
void program::

clear() const
{
  for(auto it(stages_.begin()) ; it != stages_.end() ; ++it)
  {
    stage* stage_ptr(it->get());

    if(stage_ptr != nullptr)
    {
      if(id_ != 0)
      {
        glDetachShader(id_,stage_ptr->id());
      }

      stage_ptr->clear();
    }
  }
}
