#include <iostream>
#include "functions.h"

using std::cout, std::endl;

bool is_valid_range(int a, int b) {
	// TODO(student): validate input range
	if ((a>=10 && a<10000)&&(b>=10 && b<10000)&&(a <= b)){
		
		return true;
	} else {
		return false;
	}
	return false;
}

char classify_mv_range_type(int number) {
	// TODO(student): return 'M' if number has /\/\... pattern,
	// return 'V' if number has \/\/ pattern, and return 'N' otherwise
	
	int bill;
	int hundmill;
	int tenmill;
	int mill;
	int hundthou;
	int tenthou;
	int thou;
	int hund;
	int tens;
	int ones;

	if (number < 0){
		number *= -1;
	}
	
	if (number >= 1000000000 && number < 2147483646){
		bill = number/1000000000;
		hundmill = (number/100000000)%10;
		tenmill = (number/10000000)%10;
		mill = (number/1000000)%10;
		hundthou = (number/100000)%10;
		tenthou = (number/10000)%10;
		thou = (number/1000)%10;
		hund = (number/100)%10;
		tens = (number/10)%10;
		ones = number%10;

		if (bill > hundmill && hundmill < tenmill && tenmill > mill && mill < hundthou && hundthou > tenthou && tenthou < thou && thou > hund && hund < tens && tens > ones){
			return 'V';
		} else if (bill < hundmill && hundmill > tenmill && tenmill < mill && mill > hundthou && hundthou < tenthou && tenthou > thou && thou < hund && hund > tens && tens < ones){
			return 'M';
		} else {
			return 'N';
		}

	} else if (number >= 100000000 && number < 1000000000){
		hundmill = number/100000000;
		tenmill = (number/10000000)%10;
		mill = (number/1000000)%10;
		hundthou = (number/100000)%10;
		tenthou = (number/10000)%10;
		thou = (number/1000)%10;
		hund = (number/100)%10;
		tens = (number/10)%10;
		ones = number%10;

		if (hundmill < tenmill && tenmill > mill && mill < hundthou && hundthou > tenthou && tenthou < thou && thou > hund && hund < tens && tens > ones){
			return 'M';
		} else if (hundmill > tenmill && tenmill < mill && mill > hundthou && hundthou < tenthou && tenthou > thou && thou < hund && hund > tens && tens < ones){
			return 'V';
		} else {
			return 'N';
		}

	} else if (number >= 10000000 && number < 100000000){
		tenmill = number/10000000;
		mill = (number/1000000)%10;
		hundthou = (number/100000)%10;
		tenthou = (number/10000)%10;
		thou = (number/1000)%10;
		hund = (number/100)%10;
		tens = (number/10)%10;
		ones = number%10;

		if (tenmill > mill && mill < hundthou && hundthou > tenthou && tenthou < thou && thou > hund && hund < tens && tens > ones){
			return 'V';
		} else if (tenmill < mill && mill > hundthou && hundthou < tenthou && tenthou > thou && thou < hund && hund > tens && tens < ones){
			return 'M';
		} else {
			return 'N';
		}

	} else if (number >= 1000000 && number < 10000000){
		mill = number/1000000;
		hundthou = (number/100000)%10;
		tenthou = (number/10000)%10;
		thou = (number/1000)%10;
		hund = (number/100)%10;
		tens = (number/10)%10;
		ones = number%10;

		if (mill < hundthou && hundthou > tenthou && tenthou < thou && thou > hund && hund < tens && tens > ones){
			return 'M';
		} else if (mill > hundthou && hundthou < tenthou && tenthou > thou && thou < hund && hund > tens && tens < ones){
			return 'V';
		} else {
			return 'N';
		}

	} else if (number >= 100000 && number < 1000000){
		hundthou = number/100000;
		tenthou = (number/10000)%10;
		thou = (number/1000)%10;
		hund = (number/100)%10;
		tens = (number/10)%10;
		ones = number%10;

		if (hundthou > tenthou && tenthou < thou && thou > hund && hund < tens && tens > ones){
			return 'V';
		} else if (hundthou < tenthou && tenthou > thou && thou < hund && hund > tens && tens < ones){
			return 'M';
		} else {
			return 'N';
		}

	} else if (number >= 10000 && number < 100000){
		tenthou = number/10000;
		thou = (number/1000)%10;
		hund = (number/100)%10;
		tens = (number/10)%10;
		ones = number%10;

		if (tenthou < thou && thou > hund && hund < tens && tens > ones){
			return 'M';
		} else if (tenthou > thou && thou < hund && hund > tens && tens < ones){
			return 'V';
		} else {
			return 'N';
		}

	} else if (number >= 1000 && number < 10000){
		thou = number/1000;
		hund = (number/100)%10;
		tens = (number/10)%10;
		ones = number%10;

		if (thou < hund && hund > tens && tens < ones){
			return 'M';
		} else if (thou > hund && hund < tens && tens > ones){
			return 'V';
		} else {
			return 'N';
		}

	} else if (number >= 100 && number < 1000){
		hund = number/100;
		tens = (number/10)%10;
		ones = number%10;

		if (hund > tens && tens < ones){
			return 'V';
		} else if (hund < tens && tens > ones){
			return 'M';
		} else {
			return 'N';
		}

	} else if (number >= 10 && number < 100){
		tens = number/10;
		ones = number%10;

		if (tens < ones){
			return 'M';
		} else if (tens > ones){
			return 'V';
		} else {
			return 'N';
		}

	} 
/*
	//int temp;
	//int answ;
	int curr_digit;
	int prev_digit;
	int digit_count = 0;
	int mount_count = 0;
	int vall_count = 0;
	int start = 0;
	if (number >= 10000){
		while (number >= 10){
			curr_digit = number % 10;
			prev_digit = (number/10) % 10;
			if (prev_digit < curr_digit){
				if (digit_count == 0){
					start = -1;
				}
				vall_count++;
			} else if (prev_digit > curr_digit){
				if (digit_count == 0){
					start = 1;
				}
				mount_count--;
			} else if (prev_digit == curr_digit){
				return 'N';
			}
			digit_count++;
			number /= 10;
		}
		if (mount_count == (digit_count/2) && start == 1){
			return 'M';
		} else if (vall_count == (digit_count/2) && start == -1){
			return 'V';
		} else {
			return 'N';
		}
	}*/

	return 'N';
}

void count_valid_mv_numbers(int a, int b) {
	// TODO(student): count the number of valid mountain ranges and valley
	// ranges in the range [a, b] and print out to console using the format
	// in Requirement 4 of the homework prompt
	int numMount = 0;
	int numVall = 0;
	//if (is_valid_range(a,b)){
		for (int i=a;i<=b;i++){
			if (classify_mv_range_type(i) == 'M'){
				numMount++;
			} else if (classify_mv_range_type(i) == 'V'){
				numVall++;
			}
		}
		cout<<"There are "<<numMount<<" mountain ranges and "<<numVall<<" valley ranges between "<<a<<" and "<<b<<"."<<endl;
	//}
	/*else {
		cout<<"Invalid Input"<<endl;
	}*/
	
}