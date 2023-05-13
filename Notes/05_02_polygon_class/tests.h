#include <utility>
#include "terminal_colors.h"

#define test(X) { unsigned p,f; std::tie(p, f) = test_##X(); pass_cnt += p; fail_cnt += f; }

using PassFailCount = std::pair<unsigned,unsigned>;

PassFailCount test_triangle();
PassFailCount test_rectangle();
PassFailCount test_square();