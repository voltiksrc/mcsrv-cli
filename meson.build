project(
  'mcsrv-cli',
  'cpp',
  default_options: ['cpp_std=c++23']
)

curl_dep = dependency('libcurl')

inc = include_directories('include')

executable(
  'mcsrv-cli',
  'main.cpp',
  dependencies: [curl_dep],
  include_directories: inc,
)
