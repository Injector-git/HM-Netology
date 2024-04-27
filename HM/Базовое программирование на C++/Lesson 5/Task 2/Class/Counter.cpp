#include "Counter.h"

Counter::Counter() { value = 1; }
Counter::Counter(int value) { this->value = value; }
void Counter::increment() { value++; }
void Counter::decrement() { value--; } 
int Counter::get_value() { return value; }