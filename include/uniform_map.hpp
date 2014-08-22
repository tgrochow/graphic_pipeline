#ifndef UNIFORM_MAP_HPP
#define UNIFORM_MAP_HPP

// std
#include <map>
#include <memory>
#include <string>

// openGL
#include <GL/glew.h>
#include <glm/glm.hpp>

enum uniform_type {VEC2,VEC3,IVEC3,MAT4};

class uniform_map
{
  public :

  void load_uniform(GLuint,std::string const&) const;

  void set_uniform(std::string const&,glm::vec2 const&);
  void set_uniform(std::string const&,glm::vec3 const&);
  void set_uniform(std::string const&,glm::ivec3 const&);
  void set_uniform(std::string const&,glm::mat4 const&);

  private :

  std::shared_ptr<std::string> const name_ptr(std::string const&);

  std::map<std::string,std::shared_ptr<std::string> > names_;
  std::map<std::shared_ptr<std::string>,uniform_type> types_;
  std::map<std::shared_ptr<std::string>,glm::vec2>    vec2_;
  std::map<std::shared_ptr<std::string>,glm::vec3>    vec3_;
  std::map<std::shared_ptr<std::string>,glm::ivec3>   ivec3_;
  std::map<std::shared_ptr<std::string>,glm::mat4>    mat4_;
};

#endif
