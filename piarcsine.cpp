/* CmSc 117 Exercise 3 (Extra Credit)
 * Name: Gisselle Derije
 * Date: 30 November 2020
*/

#include <iostream>
#include <iomanip>
#include <cmath>
#include "timer.hpp"

double PiArcSinForward(long N){
  double s = 1;
  double x = 0.125;

  for(double k = 1; k <= N - 1; k++){
    s = s + (x / ((2 * k) + 1));
    x = x * ((0.125 * ((2 * k) + 1)) / (k + 1));
  }
  s = 3 * s;
  return s;
}

double  PiArcSinCompensated(long N){
  double s = 1, x = 0.125, e = 0;

  for(double k = 1; k <= N - 1; k++){
    double y = (x / ((2 * k) + 1)) - e;
    double t = s + y;
    
    e = (t - s) - y;
    s = t;
    x = x * ((0.125 * ((2 * k) + 1)) / (k + 1));
  }
  s = 3 * s;
  return s;
}

void printPiArcSin(double x){  
  std::cout << "Computed values using the power series of arc sine function:\n\n";

  std::cout << "------------------------------------------------------------------------------" << std::endl;

  std::cout << "N\tSUM\t\t\t\t\tRELATIVE ERROR\t\tCOMPENSATED SUM\t\tRELATIVE ERROR\n";

  std::cout << "------------------------------------------------------------------------------" << std::endl;

  timer stopwatch;
  stopwatch.start();

  for(int s = 1; s < 25; s++){
    std::cout << s << "\t";

    std::cout << std::fixed << std::setprecision(16) << PiArcSinForward(s) << "\t";

    std::cout << std::scientific << std::setprecision(8) << std::abs(x - (PiArcSinForward(s))) / std::abs(x) << "\t\t";

    std::cout << std::fixed << std::setprecision(16) << PiArcSinCompensated(s) << "\t";

    std::cout << std::scientific << std::setprecision(8) << std::abs(x - (PiArcSinCompensated(s))) / std::abs(x) << std::endl;
  }

  std::cout << "------------------------------------------------------------------------------" << std::endl;

  unsigned long sum = 0;
    for (unsigned long k = 1; k < 10000001; k++) {
        sum = k + sum;
    }
    stopwatch.stop();

    std::cout << "\nElapsed time for approximating pi using arc sine: " << std::scientific << stopwatch.get_elapsed_time() << " seconds.\n" << std::endl;
}

void printPi(double x){
  std::cout << std::fixed << std::setprecision(16) << "Machine value of pi:\n\t\t" << x << std::endl << std::endl;
}

int main() {
  double x = M_PI;

  printPi(x);
  printPiArcSin(x);
}