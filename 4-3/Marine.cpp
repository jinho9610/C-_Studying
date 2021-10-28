#include "Marine.hpp"

int Marine::total_marine_num = 0;

// initializer list 사용 이유 - 생성과 동시에 초기화 진행(연산 효율성 상승)
// 반드시 생성과 동시에 초기화 되어야 하는 레퍼런스나 상수를 위함
Marine::Marine()  // defualt contructor
    : hp(50), coord_x(0), coord_y(0), damage(5), is_dead(false) {
    ++total_marine_num;
    show_total_marine();
};

Marine::Marine(int x, int y)  // init coords
    : hp(50), coord_x(x), coord_y(y), damage(5), is_dead(false) {
    ++total_marine_num;
    show_total_marine();
};

Marine::Marine(int x, int y, const char* marine_name) {
    name = new char[strlen(marine_name) + 1];
    strcpy(name, marine_name);

    coord_x = x, coord_y = y;
    hp = 50;
    damage = 5;
    is_dead = false;
    ++total_marine_num;
    show_total_marine();
}

Marine::~Marine() {
    cout << "Marine - " << name << " - destructor called!" << endl;
    if (name != nullptr)
        delete[] name;
    --total_marine_num;
    show_total_marine();
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

void Marine::show_total_marine() {
    cout << "current total marine num : " << total_marine_num << endl;
}