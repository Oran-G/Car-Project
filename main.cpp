#include <Arduino.h>
int radius = 18;
int circum = radius * 2 * 3;
int c_delay = 1000 / (10 * circum);

void setup() {
  // put your setup code here, to run once:
  pinMode(3, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(7, OUTPUT);
  pinMode(9, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  
}



// car basic movements class 
// will prob make much better and not use long delays in V2
class Car
{
	public:
		// prf, prb, plf, plb, - Pins
		// w_radius -  radius of wheels
		// c_delay - the delay to make the car move 1 centimeter
		// db - distance beetween wheels
		// dbc - cicumference of the circle created when using db as the diameter
		// circum - circumference of the wheels


		int prf, prb, plf, plb, w_radius, c_delay, db, d_delay;
		float circum, dbc;


		// constructor

		// rf - right forward pin, rd, right backwards pin
		// lf - left forward pin, ld, left backwards pin
		// w_radius - radius radius of wheel, might be depreceated in a future version, using diameter instead - mm
		// rate - revolutions of the motor per second
		// b_w_distance - distance beetween the wheels - cm

		Car (int rf, int rb, int lf, int lb, int w_radius, int rate, int b_w_distance)
		{
			prf = rf;
			prb = rb;
			plf = lf;
			plb = lb;
			
			w_radius = w_radius;
			circum = w_radius * 3 / 10;
			c_delay = 1000 / (rate * circum);

			db = b_w_distance;
			dbc = (db/2) * 3;
			d_delay = (dbc * c_delay) / 360;
			pinMode(prf, OUTPUT);
			pinMode(prb, OUTPUT);
			pinMode(plf, OUTPUT);
			pinMode(plb, OUTPUT);

		}

		// move forward centimeters amount of centimeters
		void forward(int centimeters)
		{
		analogWrite(prb, 0);
		analogWrite(plb, 0);

		analogWrite(prf, 256);
		analogWrite(plf, 256);
		
		delay(c_delay * centimeters);
		analogWrite(prf, 0);
		analogWrite(plf, 0);
		}

		// turn left degrees amount of degrees
		void left(int degrees)
		{

		analogWrite(prb, 0);
		analogWrite(plf, 0);
		analogWrite(prf, 256);
		analogWrite(plb, 256);
		delay(d_delay * degrees);
		analogWrite(plf, 0);
		analogWrite(prb, 0);
		}

		// turn right degrees amount of degrees
		void right(int degrees)
		{

		analogWrite(prf, 0);
		analogWrite(plb, 0);
		analogWrite(prb, 256);
		analogWrite(plf, 256);
		delay(d_delay * degrees);
		analogWrite(prb, 0);
		analogWrite(plf, 0);
		}

		// move backwards centimeters amount of centimeters
		void backwards(int centimeters)
		{
		analogWrite(prf, 0);
		analogWrite(plf, 0);
		analogWrite(prb, 256);
		analogWrite(plb, 256);
		delay(c_delay * centimeters);
		analogWrite(prb, 0);
		analogWrite(plb, 0);
		}
};
