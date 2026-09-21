#ifndef FILESYSTEM_H
#define FILESYSTEM_H

#include <string>
#include <cstdlib>

// PROJECT_ROOT is supplied by CMake via target_compile_definitions / add_compile_definitions.
#ifndef PROJECT_ROOT
#define PROJECT_ROOT ""
#endif

class FileSystem
{
private:
  typedef std::string (*Builder) (const std::string& path);

public:
  static std::string getPath(const std::string& path)
  {
    static Builder pathBuilder = getPathBuilder();
    return (*pathBuilder)(path);
  }

private:
  static std::string const & getRoot()
  {
    static char const * envRoot = std::getenv("LOGL_ROOT_PATH");
    static std::string root = (envRoot != nullptr ? envRoot : PROJECT_ROOT);
    return root;
  }

  static Builder getPathBuilder()
  {
    if (!getRoot().empty())
      return &FileSystem::getPathRelativeRoot;
    else
      return &FileSystem::getPathRelativeBinary;
  }

  static std::string getPathRelativeRoot(const std::string& path)
  {
    return getRoot() + "/" + path;
  }

  static std::string getPathRelativeBinary(const std::string& path)
  {
    return "../../../" + path;
  }
};

#endif // FILESYSTEM_H