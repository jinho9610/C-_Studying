#include <string.h>

#include <cstring>
#include <iostream>

using namespace std;

class Marine {
   private:
    int hp;
    int coord_x, coord_y;
    int damage;
    bool is_dead;
    char* name;

   public:
    Marine();
    Marine(int x, int y);
    Marine(int x, int y, const char* marine_name);
    ~Marine();  // destructor(needed to delete name memory)

    int attack();
    void be_attacked(int damage_earn);
    void move(int x, int y);

    void show_status();
};