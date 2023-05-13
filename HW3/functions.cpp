#include <iostream>
//#include <climits>
#include <stdexcept>


int Largest(int a, int b, int c) {
  if(b>=a && b>=c){
    return b;
  } else if (c>=a && c>=b){
    return c;
  } else if (a>=b && a>=c){
    return a;
  }
  return a;
}

bool SumIsEven(int a, int b) {
  int sum = a+b;
  if(sum%2 == 0){
    return true;
  } else{
    return false;
  }
  return false;
}

int BoxesNeeded(int apples) {
  if (apples <= 0){
    return 0;
  } else if (apples%20 != 0){
    return 1 + (int(apples/20.0));
  } else {
    return int(apples/20.0);
  }
}

bool SmarterSection(int A_correct, int A_total, int B_correct, int B_total) {
  if (A_correct < 0 || 
      A_total < 0 || 
      A_correct > A_total){
    throw std::invalid_argument("Invalid Input");
  } else if (B_correct < 0 || 
             B_total < 0 || 
             B_correct > B_total){
    throw std::invalid_argument("Invalid Input");
  }
  double A_percent = double(A_correct)/double(A_total);
  double B_percent = double(B_correct)/double(B_total);
  if (A_percent > B_percent){
    return true;
  } else if (B_percent > A_percent){
    return false;
  }
  return false;
}

bool GoodDinner(int pizzas, bool is_weekend) {
  if (is_weekend){
    if (pizzas >= 10){
      return true;
    } else {
      return false;
    }
  } else if (!is_weekend){
    if (pizzas >= 10 && pizzas <= 20) {
      return true;
    } else {
      return false;
    }
  }
  return false;
}
int SumBetween(int low, int high) {
  std::cout << "low=" << low << std::endl;
  std::cout << "high=" << high << std::endl;
  int MAX = INT32_MAX;
  int MIN = INT32_MIN;
  
  if (high < low){
    throw std::invalid_argument("Wrong Order");
  } 
  
  //simplify first

  if (high == low){
    return low;
  } 
  if (high == low*-1){
    return 0;
  } else if ((low*-1) - high == 1){
    return low;
  } else if (high>0 && low<0){
    if (high > (low*-1)){ //ex: h=152 l=-100, then diff=52 --> newH=52 newL=0
      //difference = high-(-1*low); //152--100
      low = (-1*low) + 1;
      //high stays same
    } else if (high < (low*-1)){ //ex: h=152 l=-200, then diff=48 --> newH=0 newL=-48
      //difference = (-1*low)-high; //--200-152 = 48
      high = (-1*high) - 1;
      //low stays the same
    }
  }

  /*
  if (low < MIN || high > MAX){
    throw std::overflow_error("Overflow Error 0");
  }
  */

  int sum = 0;
  //int difference = 0;
  /*
  if(difference > MAX/2){
    throw std::overflow_error("no way jose 1");
  } else if(difference < MIN/2){
    throw std::overflow_error("no way jose 2");
  }
  */

  std::cout << "newlow=" << low << std::endl;
  std::cout << "newhigh=" << high << std::endl;
  
  for (int n = low; n < high; n++) {
    ////////////////////////////////////////////
    if ((sum) > MAX-n && low>=0 && high>0){
      throw std::overflow_error("Overflow Error 1a");
    } else if ((sum) < MIN-n && low<0 && high<=0){
      throw std::overflow_error("Overflow Error 1b");
    }
    ////////////////////////////////////////////
    
    /*
    else if(sum>=0 && n>=0){ 
      if (long(sum+n) >= 2147483647){
        throw std::overflow_error("Overflow Error 1");
      }
    } else if(sum<0 && n>=0){
      if (long(n) >= -2147483648+sum){
        throw std::overflow_error("Overflow Error 2");
      }
    } else if(sum>=0 && n<0){
      if (long(sum) <= -2147483648+n){
        throw std::overflow_error("Overflow Error 3");
      }
    } else if(sum<0 && n<0){
      if (long(sum) <= -2147483648+n){
        throw std::overflow_error("Overflow Error 4");
      }
    }
    */

    ////////////////////////////////////////////
    sum += n;
  }
  sum += high;
  return sum;
}

int Product(int a, int b) {
  std::cout << "a=" << a << std::endl;
  std::cout << "b=" << b << std::endl;
  int MAX = INT32_MAX;
  int MIN = INT32_MIN;
  /*
  if (long(a*b) > 2147483647){
    throw std::overflow_error("product too big 1");
  } else if (long(a*b) < -2147483648){
    throw std::overflow_error("product too small 2");
  } else {
    return a*b;
  }
  */
  if (a==0 || b==0){
    return 0;
  }
  if (a<0 && b<0){ //both negative
    if(b < MAX/a){
      throw std::overflow_error("double neg too big 1");
    }
  } else if (a<0 && b>0){
    if(b > MIN/a){
      throw std::overflow_error("neg a, pos b overflow error");
    }
  } else if (b<0 && a>0){
    if(b < MIN/a){
      throw std::overflow_error("neg b, pos a OE");
    }
  } else if (a>0 && b>0){
    if(b > MAX/a){
      throw std::overflow_error("both pos OE");
    }
  }
  return a*b;
}