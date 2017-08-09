#include "PID.h"

using namespace std;

/*
* TODO: Complete the PID class.
*/

PID::PID() {}

PID::~PID() {}

void PID::Init(double Kp_init, double Ki_init, double Kd_init) {
  p_error = 0;
  i_error = 0;
  d_error = 0;
  Kp = Kp_init;
  Ki = Ki_init;
  Kd = Kd_init;
}

void PID::UpdateError(double cte) {
	double prev_error = p_error;
	i_error += cte;
	d_error = cte - prev_error;
	p_error = cte;
}

double PID::TotalError() {
	return -(Kp*p_error + Ki*i_error + Kd*d_error);
}

