#ifndef PROGRAM_HPP
#define PROGRAM_HPP

// project
#include <stage.hpp>

// std
#include <array>
#include <memory>

class program
{
  public :

  program(std::string const&);
  ~program();

  void link();

  void reset_stage(GLenum);
  void define_stage(std::shared_ptr<stage> &);


  private :

  void clear();
  void clear_stages() const;

  bool link_feedback() const;

  // member
  GLuint      id_;
  std::string name_;

  std::array<std::shared_ptr<stage>,5> stages_;
};

#endif
