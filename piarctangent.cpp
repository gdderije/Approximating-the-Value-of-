/* CmSc 117 Exercise 3 (Extra Credit)
 * Name: Gisselle Derije
 * Date: 30 November 2020
*/

#include <iostream>
#include <iomanip>
#include <cmath>
#include "timer.hpp"

double PiArcTanForward(long N) {
  double s = 1;
  for (double k = 1; k <= N - 1; k++) {
    if (std::fmod(k, 2) == 0) {
      s = s + (1 / ((2 * k) + 1));
    }
    else {
      s = s - (1 / ((2 * k) + 1));
    }
  }
  s = 4 * s;
  return s;
}

double PiArcTanBackward(long N) {
  double s = 0;
  for (double k = N - 1; k > -1; k--) {
    if (std::fmod(k, 2) == 0) {
      s = s + (1 / ((2 * k) + 1));
    }
    else {
      s = s - (1 / ((2 * k) + 1));
    }
  }
  s = 4 * s;
  return s;
}

void printPiArcTan(double x) {
  std::cout << "Computed values using the power series of arc tangent function:\n\n";

  std::cout << "-----------------------------------------------------------------------------------" << std::endl;

  std::cout << "N\t\tFORWARD SUM\t\t\tRELATIVE ERROR\t\tBACKWARD SUM\t\tRELATIVE ERROR\n";

  std::cout << "-----------------------------------------------------------------------------------" << std::endl;

  timer stopwatch;
  stopwatch.start();

  for (int s = 0; s < 11; s++) {
    std::cout << std::scientific << std::setprecision(0) << pow(10, s) << "\t";

    std::cout << std::fixed << std::setprecision(16) << PiArcTanForward(pow(10, s)) << "\t";

    std::cout << std::scientific << std::setprecision(8) << std::abs(x - PiArcTanForward(pow(10, s))) / std::abs(x) << "\t\t";

    std::cout << std::fixed << std::setprecision(16) << PiArcTanBackward(pow(10, s)) << "\t";

    std::cout << std::scientific << std::setprecision(8) << std::abs(x - PiArcTanBackward(pow(10, s))) / std::abs(x) << "\n";
  }

  std::cout << "-----------------------------------------------------------------------------------" << std::endl;

  unsigned long sum = 0;
  for (unsigned long k = 1; k < 10000001; k++) {
    sum = k + sum;
  }

  stopwatch.stop();

  std::cout << "\nElapsed time for approximating pi using arc tangent: " << std::scientific << stopwatch.get_elapsed_time() << " seconds.\n" << std::endl;
}

void printPi(double x) {
    std::cout << std::fixed << std::setprecision(16) << "Machine value of pi:\n\t\t" << x << std::endl << std::endl;
}

int main() {
    double x = M_PI;

    printPi(x);
    printPiArcTan(x);
}