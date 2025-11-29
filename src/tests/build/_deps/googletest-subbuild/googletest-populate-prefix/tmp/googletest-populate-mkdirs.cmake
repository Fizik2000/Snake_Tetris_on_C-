# Distributed under the OSI-approved BSD 3-Clause License.  See accompanying
# file Copyright.txt or https://cmake.org/licensing for details.

cmake_minimum_required(VERSION 3.5)

file(MAKE_DIRECTORY
  "/home/sirazhudin_ubuntu/projects_s21/CPP3_BrickGame_v2.0.ID_1396153-1/src/tests/build/_deps/googletest-src"
  "/home/sirazhudin_ubuntu/projects_s21/CPP3_BrickGame_v2.0.ID_1396153-1/src/tests/build/_deps/googletest-build"
  "/home/sirazhudin_ubuntu/projects_s21/CPP3_BrickGame_v2.0.ID_1396153-1/src/tests/build/_deps/googletest-subbuild/googletest-populate-prefix"
  "/home/sirazhudin_ubuntu/projects_s21/CPP3_BrickGame_v2.0.ID_1396153-1/src/tests/build/_deps/googletest-subbuild/googletest-populate-prefix/tmp"
  "/home/sirazhudin_ubuntu/projects_s21/CPP3_BrickGame_v2.0.ID_1396153-1/src/tests/build/_deps/googletest-subbuild/googletest-populate-prefix/src/googletest-populate-stamp"
  "/home/sirazhudin_ubuntu/projects_s21/CPP3_BrickGame_v2.0.ID_1396153-1/src/tests/build/_deps/googletest-subbuild/googletest-populate-prefix/src"
  "/home/sirazhudin_ubuntu/projects_s21/CPP3_BrickGame_v2.0.ID_1396153-1/src/tests/build/_deps/googletest-subbuild/googletest-populate-prefix/src/googletest-populate-stamp"
)

set(configSubDirs )
foreach(subDir IN LISTS configSubDirs)
    file(MAKE_DIRECTORY "/home/sirazhudin_ubuntu/projects_s21/CPP3_BrickGame_v2.0.ID_1396153-1/src/tests/build/_deps/googletest-subbuild/googletest-populate-prefix/src/googletest-populate-stamp/${subDir}")
endforeach()
if(cfgdir)
  file(MAKE_DIRECTORY "/home/sirazhudin_ubuntu/projects_s21/CPP3_BrickGame_v2.0.ID_1396153-1/src/tests/build/_deps/googletest-subbuild/googletest-populate-prefix/src/googletest-populate-stamp${cfgdir}") # cfgdir has leading slash
endif()
