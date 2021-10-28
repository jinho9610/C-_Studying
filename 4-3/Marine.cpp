#include "Marine.hpp"

Marine::Marine() {  // defualt contructor
    hp = 50;
    coord_x = coord_y = 0;
    damage = 5;
    is_dead = false;  // means alive
    name = nullptr;
}

Marine::Marine(int x, int y) {  // init coords
    hp = 50;
    coord_x = x, coord_y = y;
    damage = 5;
    is_dead = false;  // means alive
    name = nullptr;
}

Marine::Marine(int x, int y, const char* marine_name) {
    name = new char[strlen(marine_name) + 1];
    strcpy(name, marine_name);

    coord_x = x, coord_y = y;
    hp = 50;
    damage = 5;
    is_dead = false;
}

Marine::~Marine() {
    cout << "Marine - " << name << " - destructor called!" << endl;
    if (name != nullptr)
        delete[] name;
}

void Marine::move(int x, int y) {
    coord_x = x, coord_y = y;
}

int Marine::attack() {
    return damage;
}

void Marine::be_attacked(int damage_earn) {
    hp -= damage_earn;
    if (hp <= 0) is_dead = true;
}

void Marine::show_status() {
    cout << " *** Marine - " << name << " *** " << endl;
    cout << " Location : ( " << coord_x << ", " << coord_y << " ) " << endl;
    cout << " HP : " << hp << endl;
}