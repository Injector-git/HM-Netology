#include "Vehicle.h"

    int Vehicle::get_id() { return id; }
    std::string  Vehicle::get_name() { return name; }
    bool  Vehicle::get_type() { return type; }
    int  Vehicle::get_speed() { return speed; }
    int  Vehicle::get_dtbr() { return dtbr; }
    double   Vehicle::get_rest(int time) { return rest[time]; }
    double  Vehicle::get_distance_reduction() { return distance_reduction; }

    Vehicle::Vehicle() {
        id = 0;
        name = "ТС";
        type = ground;
        speed = -1;
        dtbr = -1;
        distance_reduction = -1;
    }