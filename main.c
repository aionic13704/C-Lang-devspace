// 음료수 자판기 프로그램
// 구성요소 : 돈넣, 돈 반환, 물건(재고), 남은 돈, 관리자/고객
#include <stdio.h>

int initKey();
int isAdmin();
int insert_Money();
int welcome_menu();

int main(){
  int select = welcome_menu();
  int res = isAdmin();
  if(select == 0) isAdmin();

  return 0;
}

int initKey(){
  int key;
  printf("Insert to init Key : ");
  scanf("%d", &key);

  return key;
}

int isAdmin(){
  int ins_key, fir_key = 3080, count = 0;
  printf("Insert key(num) : ");
  scanf("%d", &ins_key);

  if(fir_key == ins_key) return 1;
  return 0;
}

int insert_Money(){   // 돈을 넣는 것을 담당함
  int n;
  printf("Insert Money : ");
  scanf("%d", &n);

  return n;
}

int welcome_menu(){
  int select;
  printf("========Vending Machine========\n");

  insert_back:
  printf("0. Admin\n1.Customer\n");
  scanf("%d", &select);

  if(select == 0 || select == 1) return select;
  else {
    printf("!Insert Error!\nPlz insert exactly!!\n");
    goto insert_back;
  }
}

void show_List(){

}