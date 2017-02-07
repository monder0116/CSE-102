#include <stdio.h>
int extremum( double a, double b, double c, double search_starting_point, double step_size, double* m_x, double* m_y);
double f(int a, int b, int c, double x) { return a*x*x + b*x + c; }

int main()
{
	double m_x = 0, m_y = 0;

	int res = extremum (-2, 5, 5, -3, 3, &m_x, &m_y);

	printf("step: %d, m_x: %.2f, m_y: %.2f\n\n", res, m_x, m_y);

	return 0;

}


int extremum(double a, double b, double c, double search_starting_point, double step_size, double* m_x, double* m_y)

{

	double temp_res, temp;
	double x_val = search_starting_point;
	double old_x, old_y;

	int step = 0;

	if (a == 0 || step_size <= 0) 
		return -1;

	old_x = x_val;
	old_y = f(a, b, c, x_val);

	while(1){
		x_val += step_size;
		temp = f(a, b, c, x_val);
		
		/* a > 0 ise parabolun kolları yukarı bakiyordur. bu nedenle en kucuk noktayi ariyoruz. */
		if (a > 0){	
			/* dolayisiyla yeni hesaplanan noktanin eski degerden kucuk olmasi gerek. */
			if (temp < old_y){
				old_x = x_val;
				old_y = temp;
				++step;
			}

			/* degilse en kucuk noktayi gectik demektir. bir önceki degerler bizim sonucumuz. */
			else {
				*m_x = old_x;
				*m_y = old_y;
				return step;
			}
		}

		/* a < 0 ise parabolun kollari asagi bakiyordur bu nedenle en buyuk noktayi ariyoruz */
		else{
			/* yani yeni hesaplanan nokta eski degerden buyuk olmali */
			if (temp > old_y){
				old_x = x_val;
				old_y = temp;
				++step;
			}

			/* degilse en buyuk noktayi gectik demektir. bir önceki degerler bizim sonucumuz. */
			else {
				*m_x = old_x;
				*m_y = old_y;
				return step;
			}
		}
	}
}
