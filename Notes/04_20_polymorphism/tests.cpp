#include <iostream>
#include "functions.h"
#include "tests.h"

#ifndef debug
#define debug(x) cout << "[DEBUG] (" << __FILE__ << ":" << __FUNCTION__ << ":" << __LINE__ << ") " << #x << " := " << (x) << endl;
#endif

using std::cout, std::endl;

namespace {
    bool test_passed = true;
}

// example to help get you started
bool test_addition() {
    {
        Complex a(1,2); // 1 + 2i
        Complex b(3,4); // 3 + 4i
        Complex c(4,6); // 4 + 6i
        // debug((a+b).real());
        // debug((a+b).imaginary());
        expect(a+b to_be c);
    }

    {
        // TODO(student): define another test case here
        Complex a(1,-2); // 1 - 2i
        Complex b(-3,4); // -3 + 4i
        Complex c(-2,2); // -2 + 2i
        // debug((a+b).real());
        // debug((a+b).imaginary());
        expect(a+b to_be c);
    }

    // TODO(student): and so on...
    {
        // TODO(student): define another test case here
        Complex a(-1,2); // -1 + 2i
        Complex b(3,-4); // 3 - 4i
        Complex c(2,-2); // 2 - 2i
        // debug((a+b).real());
        // debug((a+b).imaginary());
        expect(a+b to_be c);
    }

    END_TEST;
}

bool test_ostream_insertion() {
    {
        Complex a(1,2); // 1 + 2i
        // TODO(student): uncomment when ready to begin testing ostream insertion operator overload
        //debug (a);
        expect_output(a, "1 + 2i");
    }
    {
        Complex a(-1,2); // -1 + 2i
        //debug (a);
        expect_output(a, "-1 + 2i");
    }
    {
        Complex a(-1,-2); // -1 - 2i
        debug (a);
        expect_output(a, "-1 - 2i");
    }

    END_TEST;
}

// TODO(student): add tests for complex operators -, *, /

bool test_NAME() {
    {
        // TODO(student): define a test case here
    }

    {
        // TODO(student): define another test case here
    }

    // TODO(student): and so on...

    END_TEST;
}

int main() {
    unsigned pass_cnt = 0, fail_cnt = 0, skip_cnt = 0;

    test(addition);
    test(ostream_insertion);
    skip(NAME);
    
    cout << endl;
    cout << magenta << "summary:" << reset << endl;
    cout << green << pass_cnt << " tests passing." << reset << endl;
    cout << red << fail_cnt << " tests failing." << reset << endl;
    cout << yellow << skip_cnt << " tests skipped." << reset << endl;

    return 0;
}