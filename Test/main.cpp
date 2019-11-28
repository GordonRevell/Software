#include <iostream>
#include <cmath>
#include <utility>

double func(double x)
{
    return fabs(x) * x - 10.0;
}

void swap(double& a, double& b) // Hide library call to allow C++ version caompatibility
{
    swap(a, b);
}

double findRoot(double limits[], int numVars, double (*f)(double))
{
    const double tol = 0.0001;

    double result = 0.0;

    if(numVars == 1)
    {
        double a = limits[0];
        double b = limits[1];

        for(;;)
        {
            if(a > b)
            {
                swap(a, b);
            }

            double m = (a + b) / 2.0;

            double fa = f(a);
            double fb = f(b);
            double fm = f(m);

            if(fa * fm < 0) // Root in low half
            {
                if(fabs(a - m) < tol)
                {
                    result = (a + m) / 2.0;
                    break;
                }
                else
                {
                    b = m;
                }
            }
            else if(fm * fb < 0) // Root in high half
            {
                if(fabs(m - b) < tol)
                {
                    result = (m + b) / 2.0;
                    break;
                }
                else
                {
                    a = m;
                }
            }
            else
            {
                break;
            }
        }
    }

    return result;
}

int main()
{
    std::cout << "Root = " << findRoot(new double[2]{10.0, -10.0}, 1, func) << std::endl;

    return 0;
}
