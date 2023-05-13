string multiply(string lhs, string rhs) {
    // TODO(student): implement
    string holder = "0";
    string finals;
    int carry = 0;
    int count = 0;
    bool oneneg = false;
    if(lhs.at(0) == '-' && rhs.at(0) == '-'){
        lhs.replace(0,1,"");
        rhs.replace(0,1,"");
        lhs = trim_leading_zeros(lhs);
        rhs = trim_leading_zeros(rhs);
    }else if(lhs.at(0) == '-' && rhs.at(0) != '-'){
        lhs.replace(0,1,"");
        oneneg = true;
        lhs = trim_leading_zeros(lhs);
        rhs = trim_leading_zeros(rhs);
    }else if(lhs.at(0) != '-' && rhs.at(0) == '-'){
        rhs.replace(0,1,"");
        oneneg = true;
        lhs = trim_leading_zeros(lhs);
        rhs = trim_leading_zeros(rhs);
    }else{
        lhs = trim_leading_zeros(lhs);
        rhs = trim_leading_zeros(rhs);
    }
    if(lhs.size() > rhs.size()){

        for(int i = int(rhs.size() - 1); i > -1; i--){
            finals = "";
            for(int j = int(lhs.size() - 1); j > -1; j--){
                char a = rhs.at(i);
                char b = lhs.at(j);
                int c = digit_to_decimal(a);
                int d = digit_to_decimal(b);
                int e = c * d + carry;
                carry = 0;
                if(e > 9){
                    carry = e / 10;
                    e = e % 10;
                    char f = decimal_to_digit(e);
                    string l = chartostring(f);
                    finals.insert(0,l);
                }else{
                    string g = chartostring(decimal_to_digit(e));
                    finals.insert(0,g);
                }
        
            }
            if(count != 0){
                int counter = count;
                while(counter > 0){
                    finals.insert(int(finals.size()),"0");
                    counter = counter - 1;
                }
            }
            count += 1;
            if(carry != 0){
                char q = decimal_to_digit(carry);
                string x = chartostring(q);
                finals.insert(0,x);
                carry = 0;
            }
            holder = add(holder,finals);
        }
        finals = holder;

    }else if(lhs.size() < rhs.size()){

        for(int i = int(lhs.size() - 1); i > -1; i--){
            finals = "";
            for(int j = int(rhs.size() - 1); j > -1; j--){
                char a = rhs.at(j);
                char b = lhs.at(i);
                int c = digit_to_decimal(a);
                int d = digit_to_decimal(b);
                int e = c * d + carry;
                carry = 0;
                if(e > 9){
                    carry = e / 10;
                    e = e % 10;
                    char f = decimal_to_digit(e);
                    string l = chartostring(f);
                    finals.insert(0,l);
                    
                }else{
                    string g = chartostring(decimal_to_digit(e));
                    finals.insert(0,g);
                }
        
            }
            if(carry != 0){
                char q = decimal_to_digit(carry);
                string x = chartostring(q);
                finals.insert(0,x);
                carry = 0;
            }
            if(count != 0){
                int counter = count;
                while(counter > 0){
                    finals.insert(int(finals.size()),"0");
                    counter = counter - 1;
                }
            }
            count += 1;
            cout << finals << endl;
            holder = add(holder,finals);
        }
        finals = holder;


    }else{
        for(int i = int(lhs.size() - 1); i > -1; i--){
            finals = "";
            for(int j = int(rhs.size() - 1); j > -1; j--){
                char a = rhs.at(j);
                char b = lhs.at(i);
                int c = digit_to_decimal(a);
                int d = digit_to_decimal(b);
                int e = c * d + carry;
                carry = 0;
                if(e > 9){
                    carry = e / 10;
                    e = e % 10;
                    char f = decimal_to_digit(e);
                    string l = chartostring(f);
                    finals.insert(0,l);
                    
                }else{
                    string g = chartostring(decimal_to_digit(e));
                    finals.insert(0,g);
                }
        
            }
            if(carry != 0){
                char q = decimal_to_digit(carry);
                string x = chartostring(q);
                finals.insert(0,x);
                carry = 0;
            }
            if(count != 0){
                int counter = count;
                while(counter > 0){
                    finals.insert(int(finals.size()),"0");
                    counter = counter - 1;
                }
            }
            count += 1;
            holder = add(holder,finals);
        }
        finals = holder;
    }
    if(oneneg == true){
        finals.insert(0,"-");
    }
    return finals;
}