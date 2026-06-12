project('Kepler', 'c')

# On récupère le compilateur C :
cc = meson.get_compiler('c')

# On cherche la bibliothèque mathématique :
math_dep = cc.find_library('m')

sources = files(
  'src/main.c',
  'src/physic_calc.c',
  'src/algo.c',
  'src/export.c'
)

# On rajoute les dépendances à la fin :
executable('kepler.exe', sources, dependencies: math_dep)

#gcc src/main.c -I $(RAYLIB) -L $(RAYLIB) -lraylib -lGL -lm -lpthread -ldl -lrt -lX11