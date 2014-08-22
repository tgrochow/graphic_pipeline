#ifndef PIPELINE_HPP
#define PIPELINE_HPP

// project
#include <program.hpp>

// std
#include <map>
#include <vector>

class pipeline
{
  public :

  void add_program(std::string const&,std::vector<std::string> const&);

  private :

  std::map<std::string,program> programs_;
  std::map<std::string,std::shared_ptr<stage> > stages_;
};

#endif
