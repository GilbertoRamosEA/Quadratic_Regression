#include <iostream>
#include <stdlib.h>
#include <vector>
#include <cmath>

using namespace std;

int main()
{

    vector<double> x = {-3, -2, -1, 0, 1, 2, 3};
    vector<double> y = {7.5, 3, 0.5, 1, 3, 6, 14};

    double YH, YHr,Xi, YP, R2, SST, SSR, sumX = 0, sumY = 0, sumX2 = 0, sumX3 = 0, sumX4 = 0, sumXY = 0, sumX2Y = 0, n1 = 7;

    for (int i = 0; i<n1; i++){
        sumX = sumX + x[i];
        sumY = sumY + y[i];
        sumX2 = sumX2 + pow(x[i], 2);
        sumX3 = sumX3 + pow(x[i], 3);
        sumX4 = sumX4 + pow(x[i], 4);
        sumXY = sumXY + (x[i] * y[i]);
        sumX2Y = sumX2Y + (pow(x[i], 2) * y[i]);
    }

    YP = sumY/n1;

    vector<vector<double>> A = {{sumX2, sumX, n1, sumY},
                                {sumX3, sumX2, sumX, sumXY},
                                {sumX4, sumX3, sumX2, sumX2Y}};

    double i,j,k,n=3;
    double c;

    for(i=0;i<n;i++){
      for(j=i+1;j<n;j++){
         c=A.at(j).at(i)/A.at(i).at(i);
         for(k=0;k<=n;k++){
            A.at(j).at(k)=A.at(j).at(k)-c*A.at(i).at(k);
         }
      }
    }

    for(i=n-1;i>=0;i--){
      for(j=i-1;j>=0;j--){
         c=A.at(j).at(i)/A.at(i).at(i);
         for(k=n;k>=i;k--){
            A.at(j).at(k)=A.at(j).at(k)-c*A.at(i).at(k);
         }
      }
    }

    for(i=0;i<n;i++){
      c=A.at(i).at(i);
      for(j=0;j<=n;j++){
         A.at(i).at(j)=A.at(i).at(j)/c;
      }
    }

    double Ar, Br, Cr;

    Ar = A.at(0).at(n);
    Br = A.at(1).at(n);
    Cr = A.at(2).at(n);

    cout << "Ingrese el valor de x para predecir y: ";
    cin >> Xi;

    YH = (Ar*(Xi * Xi)) + (Br * Xi) + Cr;

    cout <<"El valor predicho es: " << YH << endl;

    for (int i = 0; i<n1; i++){
        YHr = (Ar*(x[i] * x[i])) + (Br * x[i]) + Cr;
        SSR = SSR + ((YHr-YP)*(YHr-YP));
        SST = SST + ((y[i]-YP)*(y[i]-YP));
    }

    R2 = SSR / SST;

    cout <<"El valor de R - squered es: " << R2 << endl;

    return 0;
}
