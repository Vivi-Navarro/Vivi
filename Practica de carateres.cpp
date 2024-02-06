#include <stdio.h>

int main () {
  char nombre[20], lugar [20], carrera [20], mes [10], calendario[2];
  int edad, semestre, dia;
  float nf;
  printf ("Presentacion\n");
  printf ("\fCual es tu nombre\?\n");
  scanf ("%s", nombre);
  printf ("Cual es tu edad\?\n");
  scanf ("%d", &edad);
  printf ("Cual es tu residencia\?\n");
  scanf ("%s", lugar);
  printf ("Cual es la fecha\? \"Dia\"\n");
  scanf ("%d", &dia);
  printf ("Ahora \"Mes\"\n");
  scanf ("%s", mes);
  printf ("Cual es tu carrera\?\n");
  scanf ("%s", carrera);
  printf ("En que calendario estas\? \"a\\b\"\n");
  scanf ("%s", calendario);
  printf ("Cual es tu semestre\?\n");
  scanf ("%d", &semestre);
  printf ("Cual es tu numero favorito con punto decimal\?\n");
  scanf ("%f", &nf);
  printf ("\fFin\b\a");
  return 0;
}
