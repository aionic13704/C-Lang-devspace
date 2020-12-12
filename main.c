// 음료수 자판기 프로그램
// 구성요소 : 돈넣, 돈 반환, 물건(재고), 남은 돈, 관리자/고객
#include <stdio.h>
#define MAX 50;     // 종류별 자판기에 저장 가능한 최대개수

int initKey();      // 키를 초기화 하는 함수(용도 미정)
int isAdmin();      // admin인지 아닌지 판단
int insert_Money(); // 돈을 넣는 것을 담당함
int welcome_menu(); // 처음 맞이하는 화면
int show_List(int p);  // 사용자에 따라 다른 화면을 보여줌

// 각 음료의 가격
const int cola = 900, cider = 900, pocari = 700, sparking = 800, juice = 600, dew = 800;
int total_money = 0;    // 보유중인 금액

int main(){
  int select = welcome_menu();
  int res;
  if(select == 0) {
    if(isAdmin()){
      show_List(0);
    }
  }
  else show_List(1);

  return 0;
}

int initKey(){        // 키를 초기화 하는 함수(용도 미정)
  int key;
  printf("Insert to init Key : ");
  scanf("%d", &key);

  return key;
}

int isAdmin(){        // admin인지 아닌지 판단
  int ins_key, fir_key = 3080, count = 0;
  printf("Insert key(num) : ");
  scanf("%d", &ins_key);

  if(fir_key == ins_key) return 1;
  return 0;
}

int insert_Money(){   // 돈을 넣는 것을 담당함
  int money;
  printf("Insert money : ");
  scanf("%d", &money);

  return money;
}

int welcome_menu(){   // 처음 맞이하는 화면
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
int show_List(int p){    // 사용자에 따라 다른 화면을 보여줌
  int select_ad, select_cu;
  int needs_money, ins_money, return_money;
  if(p == 0){     // 관리자 메뉴
    printf("=======Admin Menu=======\n\n");

    back_ad:
    printf("1. Withdraw  2. Refill\n");
    scanf("%d", &select_ad);

    if(select_ad != 1 || select_ad != 2){
      printf("!Insert Error!\nPlz insert exactly\n");
      goto back_ad;
    }
  }

  else{   // 고객 메뉴
    printf("=======Customer Menu=======\n\n");

    back_cu:
    printf("1. Coka Cola  2. Pocari Sweat  3. Mountain Dew\n4. cider\t  5. Grape Juice   6. Sparking\n\n");
    scanf("%d", &select_cu);

    if(select_cu < 1 || select_cu > 6){
      printf("!Insert Error!\nPlz insert exactly\n");
      goto back_cu;
    }

    switch(select_cu){
      case 1:
        needs_money = cola;
        break;

      case 2:
        needs_money = pocari;
        break;

      case 3:
        needs_money = dew;
        break;

      case 4:
        needs_money = cider;
        break;

      case 5:
        needs_money = juice;
        break;

      case 6:
        needs_money = sparking;
        break;

      default:
        printf("Error\n");
        break;
    }

    printf("You can insert %dwon to drink!\n", needs_money);

    in_mon:
    ins_money = insert_Money();

    if(ins_money < needs_money){
      printf("!Insert Error!\nPlz insert exactly\n");
      goto in_mon;
    }
    else if(ins_money == needs_money) printf("음료가 정상적으로 결재되었습니다.\n");
    else{
      printf("결재 후 남은 금액 %d원이 반환되었습니다.\n", ins_money - needs_money);
      total_money += needs_money;
    }
  }

  return 0;
}

void withdraw(){
  
}