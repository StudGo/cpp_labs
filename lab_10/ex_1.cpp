#include <iostream>
#include "list.h"

struct bus {
    size_t bus_number;
    size_t route_number;
    std::string driver_name;

    bool operator==(const bus& other) const;
};

bool bus::operator==(const bus &other) const {
    return bus_number == other.bus_number &&
    route_number == other.route_number &&
    driver_name == other.driver_name;
}

std::ostream& operator<<(std::ostream& os, bus& b) {
    os << "Bus = " << b.bus_number
    << " Route = " << b.route_number
    << " Driver = " << b.driver_name << std::endl;
    return os;
}


int main() {
    list<bus> park_bus_list, route_bus_list;
    auto bus_entered = [&](const bus& b){
        park_bus_list.append(b);
        route_bus_list.remove(b);
    };
    auto bus_left = [&](const bus& b){
        route_bus_list.append(b);
        park_bus_list.remove(b);
    };
    auto park_init = [&](){
        park_bus_list.append({1,100,"Ivanov I.A."});
        park_bus_list.append({2,110,"Petrov K.V."});
        park_bus_list.append({3,120,"Simonov L.D."});
        park_bus_list.append({4,130,"Orlov L.A."});
        park_bus_list.append({5,140,"Gagarin Y.A."});
    };
    auto print_lists = [&](){
        std::cout << "park list = ["<< std::endl  << park_bus_list << "]" << std::endl;
        std::cout << "route list = [" << std::endl << route_bus_list << "]" << std::endl;
    };

    park_init();
    std::cout << "After init: " << std::endl;
    print_lists();

    bus_left(*park_bus_list.get(0));
    bus_left(*park_bus_list.get(0));
    std::cout << "After bus left from park: " << std::endl;
    print_lists();

    bus_entered(*route_bus_list.get(0));
    bus_entered(*route_bus_list.get(0));
    std::cout << "After bus entered in parg: " << std::endl;
    print_lists();

    bus_left(*park_bus_list.get(0));

    return 0;
}
