#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#define FILES 50
#define SIZE sizeof(int) + 1

int choice3 (int);

int main() {
  char yesno [2][4] = {{"Yes"}, {"No"}};
  char problemarea [5][11] = {{"Problem 1"}, {"Problem 2"}, {"Problem 3"}, {"Problem 4"}, {"Other"}};
  char callcenter [5][13] = {{"CallCenter 1"}, {"Callcenter 2"}, {"Callcenter 3"}, {"Callcenter 4"}, {"Other"}};
  char lastname [6][6] = {{"Mitra"}, {"Sam"}, {"Tom"}, {"Ann"}, {"Mary"}, {"Todd"}};
  char comment [4][22] = {{"The call went great!"}, {"The call was boring."}, {"The call was annoying."}, {"The call was bad."}};

  FILE *fp;
  char prefix [10] = {"data"};


    for (int file_index = 0; file_index < FILES; file_index++){
      char suffix [SIZE + 5];
      sprintf(suffix, "%d", file_index);
      strcat(suffix, ".txt");
      strcat(prefix, suffix);
      printf("Now creating ");
      printf("%s\n", prefix);
      fp = fopen(prefix, "w+");
      fprintf(fp,"{\n \"formdata\": {\n\t\"blocked\": \"%s\",\n\t\"abandoned\": \"%s\",\n\t\"waitingtime\": \"%d\",\n\t\"problemarea\": \"%s\",\n\t\"issueresolved\": \"%s\",\n\t\"resolvetime\": \"%d\",\n\t\"calltime\": \"%d\",\n\t\"aftercallwork\": \"%d\",\n\t\"lname\": \"%s\",\n\t\"country\": \"%s\",\n\t\"subject\": \"%s\",\n},\n}",
      (yesno[choice3(2)]),
      (yesno[choice3(2)]),
      1 + rand()%10,
      (problemarea[choice3(5)]),
      (yesno[choice3(2)]),
      1 + rand()%10,
      1 + rand()%10,
      1 + rand()%10,
      (lastname[choice3(6)]),
      (callcenter[choice3(6)]),
      (comment[choice3(4)])
    );
      fclose(fp);
      strcpy(prefix, "data");

    }


}
int choice3 (int size){
  srand(time(0));
  return rand()%(size-1);
}
