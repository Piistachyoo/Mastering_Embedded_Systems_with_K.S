# 0 "CA.c"
# 0 "<built-in>"
# 0 "<command-line>"
# 1 "CA.c"
# 11 "CA.c"
# 1 "CA.h" 1
# 12 "CA.h"
# 1 "state.h" 1
# 13 "CA.h" 2


typedef enum{
 CA_waiting,
 CA_driving
}CA_states;

extern CA_states CA_state_id;
extern void (*CA_state)();


void ST_CA_waiting();
void ST_CA_driving();
# 12 "CA.c" 2


static int CA_speed = 0;
static int CA_distance = 0;
static int CA_threshold = 50;
static CA_states CA_state_id;


void (*CA_state)();


void ST_CA_waiting(){


 CA_state_id = CA_waiting;





}

void ST_CA_driving(){

}
