#ifndef PID_H
#define PID_H

class PID {
 public:
  /**
   * Constructor
   */
  PID();

  /**
   * Destructor.
   */
  virtual ~PID();

  /**
   * Initialize PID.
   * @param (Kp_, Ki_, Kd_) The initial PID coefficients
   */
  void Init(double Kp_, double Ki_, double Kd_);

  /**
   * Update the PID error variables given cross track error.
   * @param cte The current cross track error
   */
  void UpdateError(double cte);

  /**
   * Calculate the total PID error.
   * @output The total PID error
   */
  double TotalError();

  /*
   * Used to reset the simulator and biring the car back to start position.
   */
  void Restart(uWS::WebSocket<uWS::SERVER> ws);

  /**
   * Calculate parameters by Twiddle
   */
  void Twiddle(double total_error, double hyperparameter);

  /**
   * PID Coefficients
   */
  double Kp;
  double Ki;
  double Kd;

 private:
  /**
   * PID Errors
   */
  double p_error;
  double i_error;
  double d_error;

  /**
   * Twiddle params
   */
  double tolerance;
  double delta_p;
};

#endif  // PID_H
