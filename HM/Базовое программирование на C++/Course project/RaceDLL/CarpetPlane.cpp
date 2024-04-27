#include"CarpetPlane.h"

CarpetPlane::CarpetPlane() {
    id = 7;
    name = "Ковёр-самолёт";
    type = air;
    speed = 10;
}
CarpetPlane::CarpetPlane(int distance) : CarpetPlane() {
    if (distance < 1000) distance_reduction = 0;
    else if (distance < 5000) distance_reduction = 0.03;
    else if (distance < 10000) distance_reduction = 0.1;
    else if (distance >= 10000) distance_reduction = 0.05;
}