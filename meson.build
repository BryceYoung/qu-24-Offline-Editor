project('Qu24 Offline Editor', 'cpp',
  version : '0.1.0',
  license : 'CC BY-SA 4.0'
)

cpp = meson.get_compiler('cpp')
#lib_kaitai = cpp.find_library('kaitai_struct_cpp_stl_runtime', dirs : ['/home/bryce/prog/qu-24/kaitai_struct_cpp_stl_runtime/out/lib/'])
lib_kaitai = declare_dependency(link_args : ['kaitai_struct_cpp_stl_runtime/out/lib/libkaitai_struct_cpp_stl_runtime.so'])
inc_kaitai = include_directories('kaitai_struct_cpp_stl_runtime')

gtk = dependency('gtkmm-3.0')

inc = include_directories('include')

executable('editor',
  ['src/GUI.cpp', 'src/qu_scene.cpp', 'src/QU24-Offline-Editor.cpp'],
  dependencies : [gtk, lib_kaitai],
  include_directories: [inc_kaitai, inc]
)