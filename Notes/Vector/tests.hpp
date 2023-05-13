#ifndef TESTS_HPP
#define TESTS_HPP

bool test_constructor();
bool test_push_back();
bool test_pop_back();
bool test_back();

bool test_reserve();
bool test_resize();

bool test_at();
bool test_front();
bool test_empty();
bool test_shrink_to_fit();
bool test_clear();
bool test_insert();
bool test_erase();

bool test_rule_of_three();
bool integration_test();
bool test_iterator();

#endif