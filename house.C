#include <stdio.h>
#include <string.h>

struct room{
  char* name;
  int guests;
};

struct house {
  char* name;
  int old;
  struct room *rooms[11];
};

struct house createHouse();
void createRooms(struct house *home);
void showHouse(struct house* home);
struct room createRoom(char* name, int guests);

int main()
{
  struct house home = createHouse("PD", 69);
  struct room r1 = createRoom("PD", 500);
  home.rooms[0] = &r1;
  showHouse(&home);
  return 0;
}

struct house createHouse(char* name, int age)
{
  struct house home = {name, age, NULL};
  return home;
}

void createRooms(struct house *home) {
  for(int i = 0; i < 11; i++)
  {
    home->rooms[i] = NULL;
  }
}

void showHouse(struct house* home)
{
  for(int i = 0; i < 11; i++)
  {
    if(home->rooms[i] != NULL){
      struct room r = *home->rooms[i];
      printf("Room number: %d\nRoom name: %s\nNumber of guests: %d", i, r.name, r.guests);
    }
  }
}


struct room createRoom(char* name, int guests)
{
  struct room res;
  res.name = name;
  res.guests = guests;
  return res;
}
