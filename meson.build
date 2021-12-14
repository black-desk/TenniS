project(
  'seeta-tennis',
  'cpp',
  default_options: [
    'cpp_std=c++11',
  ]
)

cc = meson.get_compiler('cpp')

tennis_deps = []

tennis_deps += dependency('threads')
tennis_deps += cc.find_library('dl', required: true)

if get_option('with_cuda')
  tennis_deps += dependency('cuda', version : '>=10', modules : ['cublas'])
  add_project_arguments('-DTS_USE_CUBLAS', language: 'cpp')
  add_languages('cuda')
endif

if get_option('with_openmp')
  tennis_deps += dependency('openmp')
  add_project_arguments('-DTS_USE_OPENMP', language: 'cpp')
endif

if get_option('build_test')
  tennis_deps += dependency('opencv')
  add_project_arguments('-DTS_USE_OPENCV -DTS_USE_DEBUG_API', language: 'cpp')
endif

if get_option('on_arm')
  add_project_arguments('-DTS_ON_ARM', language: 'cpp')
endif

if get_option('on_armv7')
  add_project_arguments('-DTS_ON_ARMV7', language: 'cpp')
endif

# https://mesonbuild.com/howtox.html#add-math-library-lm-portably
tennis_deps += cc.find_library('m', required : false)

if get_option('with_simd')
  add_project_arguments('-DTS_USE_SIMD', language: 'cpp')
  if get_option('on_haswell')
    add_project_arguments('-DTS_USE_AVX -DTS_USE_FMA -mavx -mavx2 -mfma', language: 'cpp')
  elif get_option('on_sandybridge')
    add_project_arguments('-DTS_USE_AVX -mavx -mavx2', language: 'cpp')
  elif get_option('on_pentium')
    add_project_arguments('-DTS_USE_SSE -msse2', language: 'cpp')
  elif get_option('with_neon')
    add_project_arguments('-DTS_USE_NEON', language: 'cpp')
  endif
endif

sources = []

subdir('src')
subdir('include/api')

tennis = library('seeta-tennis', sources,
  version: '1.0.6',
  include_directories: include_directories('include','src'),
  dependencies: tennis_deps,
  install: true
)

pkg = import('pkgconfig')
pkg.generate(tennis, subdirs: ['seeta/tennis'])

if get_option('build_test')
  subdir('test')
endif

if get_option('build_tools')
  subdir('tools')
endif
