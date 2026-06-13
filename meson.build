project('Kepler', 'c')

cc = meson.get_compiler('c')

# 1. Les dépendances système de base
math_dep = cc.find_library('m')

# 2. On cherche Raylib manuellement
raylib_dep = cc.find_library('raylib', required: true)

# 3. Les dépendances système requises par Raylib sous Linux
gl_dep = dependency('gl')
x11_dep = dependency('x11')
threads_dep = dependency('threads')

sources = files(
  'src/main.c',
  'src/physic_calc.c',
  'src/algo.c',
  'src/export.c',
  'src/logic.c',
  'src/render.c'
)

# 4. On assemble le tout
executable('kepler.exe', 
  sources,
  dependencies: [math_dep, raylib_dep, gl_dep, x11_dep, threads_dep]
)

