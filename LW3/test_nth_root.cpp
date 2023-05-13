#include <iostream>
#include <cmath>
#include "./nth_root.h"
void try_hard(int n, double x){
    double answer = nth_root(n,x);
    std::cout << "nth_root("<<n<<", "<<x<<") = "<<answer<<std::endl;
}

int main() {
    {   // MINIMUM REQUIREMENT (for this lab)
        // just call the function with various values of n and x
        
        //x^(1/n)
        //nth root of x
        //(int n, double x)
        
        float temp;
        
        try {
            //n can be any non-zero integer
            temp = nth_root(2, 1);
        } catch (std::domain_error) {
            std::cout << "Domain Error occurred\n";
        }
        
        try {
            temp = nth_root(-1,2);
        } catch (std::domain_error) {
            std::cout << "Domain Error occurred\n";
        }
        
        try {
            //n = 0
            //throw a domain error exception
            temp = nth_root(0,5);
        } catch (std::domain_error) {
            std::cout << "Domain Error occurred\n";
        }
        
        try {
            //x can be any real number when n is odd
            temp = nth_root(5,0.5);
        } catch (std::domain_error) {
            std::cout << "Domain Error occurred\n";
        }
        
        try {
            //x can be any non-neg real number when n is even
            temp = nth_root(2,1.4);
        } catch (std::domain_error) {
            std::cout << "Domain Error occurred\n";
        }
        
        try {
            //n is even and x<0
            //throw a domain error exception
            temp = nth_root(2,-1);
        } catch (std::domain_error) {
            std::cout << "Domain Error occurred\n";
        }

        try {
            //x can be any non-zero real number when n is negative
            temp = nth_root(-3,1);
            temp = nth_root(-2,-1.5);
        } catch (std::domain_error) {
            std::cout << "Domain Error occurred\n";
        }

        try {
            //n<0 and x=0
            temp = nth_root(-1,0);
        } catch (std::domain_error) {
            std::cout << "Domain Error occurred\n";
        }

        try {
            //the output should be the positive root when n is even
            temp = nth_root(4,0.5);
        } catch (std::domain_error) {
            std::cout << "Domain Error occurred\n";
        }

        try {
            //the output should be a floating-point number
            temp = nth_root(-6, 2);
        } catch (std::domain_error) {
            std::cout << "Domain Error occurred\n";
        }

        try {
            //the output value should be an nth root of the input x
            try_hard(2,1);
        } catch (std::domain_error) {
            std::cout << "Domain Error occurred\n";
        }
        
        ////////////////////////////////////////////////////////////

        try {
            //n=0
            nth_root(0,1);
        } catch (std::domain_error) {
            std::cout << "Domain Error occurred\n";
        }

        try {
            //n is even, x<0
            nth_root(2,-1);
        } catch (std::domain_error) {
            std::cout << "Domain Error occurred\n";
        }

        try {
            //n<0, x=0
            nth_root(-1,0);
        } catch (std::domain_error) {
            std::cout << "Domain Error occurred\n";
        }

        try {
            //n=1
            nth_root(1,-1);
        } catch (std::domain_error) {
            std::cout << "Domain Error occurred\n";
        }
        try {
            //n=1
            nth_root(1,0);
        } catch (std::domain_error) {
            std::cout << "Domain Error occurred\n";
        }
        try {
            //n=1
            nth_root(1,1);
        } catch (std::domain_error) {
            std::cout << "Domain Error occurred\n";
        }
        try {
            //n=1
            nth_root(1,5);
        } catch (std::domain_error) {
            std::cout << "Domain Error occurred\n";
        }

        try {
            //n=-1
            nth_root(-1,-1);
        } catch (std::domain_error) {
            std::cout << "Domain Error occurred\n";
        }
        try {
            //n=-1
            nth_root(-1,0);
        } catch (std::domain_error) {
            std::cout << "Domain Error occurred\n";
        }
        try {
            //n=-1
            nth_root(-1,1);
        } catch (std::domain_error) {
            std::cout << "Domain Error occurred\n";
        }

        try {
            //n<0
            nth_root(-2,-1);
        } catch (std::domain_error) {
            std::cout << "Domain Error occurred\n";
        }
        try {
            //n<0
            nth_root(-2,0);
        } catch (std::domain_error) {
            std::cout << "Domain Error occurred\n";
        }
        try {
            //n<0
            nth_root(-2,1);
        } catch (std::domain_error) {
            std::cout << "Domain Error occurred\n";
        }

        try {
            //n<-5
            nth_root(-6,-1);
        } catch (std::domain_error) {
            std::cout << "Domain Error occurred\n";
        }
        try {
            //n<-5
            nth_root(-6,0);
        } catch (std::domain_error) {
            std::cout << "Domain Error occurred\n";
        }
        try {
            //n<-5
            nth_root(-6,1);
        } catch (std::domain_error) {
            std::cout << "Domain Error occurred\n";
        }

        try {
            //n<-1 but n>=-5
            nth_root(-5,-1);
        } catch (std::domain_error) {
            std::cout << "Domain Error occurred\n";
        }
        try {
            //n<-1 but n>=-5
            nth_root(-5,0);
        } catch (std::domain_error) {
            std::cout << "Domain Error occurred\n";
        }
        try {
            //n<-1 but n>=-5
            nth_root(-5,1);
        } catch (std::domain_error) {
            std::cout << "Domain Error occurred\n";
        }

        try {
            //n>5
            nth_root(6,-1);
        } catch (std::domain_error) {
            std::cout << "Domain Error occurred\n";
        }
        try {
            //n>5
            nth_root(6,0);
        } catch (std::domain_error) {
            std::cout << "Domain Error occurred\n";
        }
        try {
            //n>5
            nth_root(6,1);
        } catch (std::domain_error) {
            std::cout << "Domain Error occurred\n";
        }

        try {
            //n>1 but n<=5
            nth_root(4,-1);
        } catch (std::domain_error) {
            std::cout << "Domain Error occurred\n";
        }
        try {
            //n>1 but n<=5
            nth_root(4,0);
        } catch (std::domain_error) {
            std::cout << "Domain Error occurred\n";
        }
        try {
            //n>1 but n<=5
            nth_root(4,1);
        } catch (std::domain_error) {
            std::cout << "Domain Error occurred\n";
        }
        
        try {
            //n%2 == 1 && x < 0 && x != -1
            nth_root(3,-5);
        } catch (std::domain_error) {
            std::cout << "Domain Error occurred\n";
        }

        try {
            //x>2
            nth_root(3,5);
        } catch (std::domain_error) {
            std::cout << "Domain Error occurred\n";
        }

        try {
            //x - static_cast<int>(x) > 0
            nth_root(3,5.5);
        } catch (std::domain_error) {
            std::cout << "Domain Error occurred\n";
        }

        //the name of the function should be nth_root

        //the function should have 2 parameters: int n, double x

        //the function's return value should be type double

    }

    {   // TRY HARD
        // report the value
        double actual = nth_root(2, 1);
        std::cout << "nth_root(2, 1) = " << actual << std::endl;
    }

    {   // TRY HARDER
        // compare the actual value to the expected value
        double actual = nth_root(2, 1);
        double expected = 1;
        if (std::fabs(actual - expected) > 0.00005) {
            std::cout << "[FAIL] (n=2, x=1)" << std::endl;
            std::cout << "  expected nth_root(2, 1) to be " << expected << std::endl;
            std::cout << "  got " << actual << std::endl;
        } else {
            std::cout << "[PASS] (n=2, x=1)" << std::endl;
        }
    }
}
