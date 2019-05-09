#include <iostream>
#include <fstream>
#include <cmath>

using namespace std;

int main(void){
  int m = 100;
  double beta = 0.05;
  double c = 1;
  double dx = 1./m;
  double dt = beta*dx/c;
  double T_final = 0.1;
  int n = int(T_final/dt);

  double u[m+1];
  double u0[m+1];

  for(int i = 0; i < m+1; i++){
    u[i]=0.;
    u0[i]=0.;
  }

  double x;
  for(int i = 0; i < m+1; i++){
    x = i*dx;
    u0[i] = sin(2*6.4*x);
  }
  ofstream MiData("Data.dat");
  for(int j = 0; j < n+1; j++){
    for(int i = 0; i < m-1; i++){
      u[i+1]=u0[i+1]-(beta/4.)*(u0[i+2]*u0[i+2]-u0[i]*u0[i]) + (beta*beta/8.)*((u0[i+2]+u0[i+1])*(u0[i+2]*u0[i+2] - u0[i+1]*u0[i+1]) - (u0[i+1]+u0[i])*(u0[i+1]*u0[i+1] - u0[i]*u0[i]));
      u[0]=0;
      u[m-1]=0;
      u0[i]=u[i];
    }
    for(int i = 0; i < m; i++){
      MiData << u[i] << endl;
    }
  }
  return 0;
}

