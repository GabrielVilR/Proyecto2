#include <GL/glut.h>
#include <stdio.h>
#include <math.h>
#include <time.h>
#include <string.h>

typedef struct {
  floar color[3]={1.0,0.0,0.0};
  int figura[]={200,100,50,30};
  int cantidad = 1;
} objet;


void get_first_intersection(int xe, int ye, int ze, int xd, int yd, int zd){
  float distancia;
  INTERSECTION *interseccion;
  ESFERA *esfera;
  long double tmin;
  interseccion = NULL;
  tmin = 999999;
  for (int i; i<objet.cantidad){
    esfera=objet.figura;
    int xc=esfera[0];
    int yc=esfera[1];
    int zc=esfera[2];
    int R = esfera[3];
    float b = 2*(xd*(xe-xc)+yd*(ye-yc)+zd*(ze-zc));
    float c = (xe-xc)*(xe-xc)+(ye-yc)*(ye-yc)+(ze-zc)*(ze-zc)+R*R;
    float dis = b*b-4*c;
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
      interseccion=objet.color;
    }
  }
  return (interseccion);
}

void get_color_pixel(int xe, int ye, int ze, int xd, int yd, int zd){
  BACKGROUND[] = {0.0,0.0,0.0};
  INTERSECCION *interseccion;
  interseccion = get_first_intersection(xe,ye,ze,xd,yd,zd);
  if (!interseccion){
    color = BACKGROUND;
  }
  else {
    color = interseccion;
  }
  return(color);
}

void basic(){
  int xe = 100;
  int ye = 100;
  int ze = -100;
  for (int i;i<hor;i++){
    for(int j;j<ver;j++){
      float xw = (i+1/2)*(xmax-xmin)/hor+xmin;
      float xw = (j+1/2)*(ymax-ymin)/ver+ymin;
      float zw = 0;
      float L = sqrt((xw+xe)**2+(yw-ye)**2+(zw-ze)**2);
      int xd = (xw-xe)/L;
      int yd = (yw-ye)/L;
      int zd = (zw-ze)/L;
      color = get_color_pixel((xe,ye,ze),(xd,yd,zd));
      frame_buffer[i][j]=color;
    }
  }
  //guardar imagen
}

int main(){

}
