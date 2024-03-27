#include "Broom.h"

Broom::Broom() {
    id = 2;
    name = "Метла";
    type = air;
    speed = 20;
}
Broom::Broom(int distance) : Broom() {
    distance_reduction = (distance / 1000) / 100.0;
}
