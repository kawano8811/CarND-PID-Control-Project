#include <uWS/uWS.h>
#include "PID.h"
#include <math.h>

/**
 * TODO: Complete the PID class. You may add any additional desired functions.
 */

PID::PID() {}

PID::~PID() {}

void PID::Init(double Kp_, double Ki_, double Kd_) {
  /**
   * TODO: Initialize PID coefficients (and errors, if needed)
   */
   // Initialize PID coefficients
   Kp = Kp_;
   Ki = Ki_;
   Kd = Kd_;

   // Initialize PID errors
   p_error = 0;
   i_error = 0;
   d_error = 0;

}

void PID::UpdateError(double cte) {
  /**
   * TODO: Update PID errors based on cte.
   */
   d_error = cte - p_error;
   i_error += cte;
   p_error = cte;
}

double PID::TotalError() {
  /**
   * TODO: Calculate and return the total error
   */
  double total_err = -(Kp * p_error) - (Ki * i_error) - (Kd * d_error);
  if (total_err > 1) {
    total_err = 1;
  } else if (total_err < -1) {
    total_err = -1;
  }
  return total_err;  // TODO: Add your total error calc here!
}
