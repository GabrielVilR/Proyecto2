#include <GL/glut.h>
#include <stdio.h>
#include <math.h>
#include <time.h>
#include <string.h>

typedef struct {
  floar colors[3]={1.0,0.0,0.0};
  int figursa[]={200,100,50,10};
  int cantidad = 1;
} objet;


void get_first_intersection(int xe, int ye, int ze, int xd, int yd, int zd){
  float distancia;
  INTERSECTION *interseccion;
  ESFERA *esfera;
  long double tmin;
  interseccion = NULL;
  tmin = 999999;
  esfera=objet.figuras;
  int cant = objet.cantidad;
  //calculo para esferas
  for (int i; i<cant*4; i=i+4){

    int xc=esfera[i];
    int yc=esfera[i+1];
    int zc=esfera[i+2];
    int R = esfera[i+3];
    long double b = 2*(xd*(xe-xc)+yd*(ye-yc)+zd*(ze-zc));
    long double c = (xe-xc)*(xe-xc)+(ye-yc)*(ye-yc)+(ze-zc)*(ze-zc)+R*R;
    long double dis = b*b-4*c;
    if (dis==0){
      //interseccion=objet.color;
      distancia = (-b+sqrt(dis))/2;
    }
    else if (dis>0){
      float t1=(-b+sqrt(dis))/2;
      float t2=(-b-sqrt(dis))/2;
      if (t1<t2){
        //interseccion=objet.color;
        distancia =t1;
      }
      else {
        //interseccion=objet.color;
        distancia = t2;
      }
    }
    else {
      interseccion = NULL;
    }
    //calcular INTERSECCION
    if (interseccion!=NULL && distancia<tmin){
      tmin=distancia;
      interseccion=objet.colors;
    }
  }
  return (interseccion);
}

void get_color_pixel(int xe, int ye, int ze, int xd, int yd, int zd){
  BACKGROUND[] = {0.0,0.0,0.0};
  float *interseccion;
  float *col;
  interseccion = get_first_intersection(xe,ye,ze,xd,yd,zd);
  if (!interseccion){
    col = BACKGROUND;
  }
  else {
    col = interseccion;
  }
  return(col);
}

void basic(){
  int xe = 10;
  int ye = 10;
  int ze = -10;
  float *color;
  for (int i;i<1000;i++){
    for(int j;j<1000;j++){
      long double xw = (i+1/2)*(xmax-xmin)/hor+xmin;
      long double yw = (j+1/2)*(ymax-ymin)/ver+ymin;
      long double zw = 0;
      long double L = sqrt((xw+xe)**2+(yw-ye)**2+(zw-ze)**2);
      long double xd = (xw-xe)/L;
      long double yd = (yw-ye)/L;
      long double zd = (zw-ze)/L;
      color = get_color_pixel((xe,ye,ze),(xd,yd,zd));
      plot_pixel(i,j,color);
    }
  }
  //guardar imagen
}

int main(){

}
