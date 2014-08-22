// header
#include <pipeline.hpp>


// add, define program and shading stages
void pipeline::

add_program(std::string const& name,std::vector<std::string> const& stage_path)
{
  if(programs_.find(name) == programs_.end())
  {
    program new_program(name);

    for(auto p_it(stage_path.begin()) ; p_it != stage_path.end() ; ++p_it)
    {
      std::string path(*p_it);

      stages_.find(path);

      std::shared_ptr<stage> new_stage(std::make_shared<stage>(stage(path)));

      /*auto stage_it(stages_.insert(std::make_pair(path,new_stage)));

      new_program.define_stage(stage_it->second);*/
    }

    programs_.emplace(name,new_program);
  }
}
