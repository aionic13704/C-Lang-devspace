// 음료수 자판기 프로그램
// 구성요소 : 돈넣, 돈 반환, 물건(재고), 남은 돈, 관리자/고객
#include <stdio.h>
#define MAX 50;     // 종류별 자판기에 저장 가능한 최대개수

int initKey();      // 키를 초기화 하는 함수(용도 미정)
int isAdmin();      // admin인지 아닌지 판단
int insert_Money(); // 돈을 넣는 것을 담당함
int welcome_menu(); // 처음 맞이하는 화면
int show_List(int p);  // 사용자에 따라 다른 화면을 보여줌
int withdraw();       // 출금을 담당하는 함수

// 각 음료의 가격
const int cola = 900, cider = 900, pocari = 700, sparking = 800, juice = 600, dew = 800;
int cola_c = 10, cider_c = 5, pocari_c = 23, sparking_c = 17, juice_c = 22, dew_c = 8;
int total_money = 5000;    // 보유중인 금액

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
  int select_ad, select_cu, select_mn;
  int needs_money, ins_money, return_money;
  int with_mon;

  if(p == 0){     // 관리자 메뉴
    printf("=======Admin Menu=======\n\n");

    back_ad:
    printf("1. Withdraw  2. Refill\n");
    scanf("%d", &select_ad);

    if(select_ad == 1){
      printf("Current balance : %dwon\n", total_money);
      with_mon = withdraw();
      total_money -= with_mon;

      printf("Success withdraw! Balance : %d\n", total_money);
    }

    else if(select_ad == 2){
      if(show_Menu(0) != 0){
        printf("!Success refill!\n====Stock====\nCoka Cola : %d\tPocari Sweat : %d\tMountain Dew : %d\ncider : %d\t   Grape Juice : %d   Sparking : %d\n\n", cola_c, pocari_c, dew_c, cider_c, juice_c, sparking_c);
      }

      else{
        printf("Error!\n");
      }

    }

    else{
      printf("!Insert Error!\nPlz insert exactly\n");
      goto back_ad;
    }
  }

  else{   // 고객 메뉴
    printf("=======Customer Menu=======\n\n");
    needs_money = show_Menu(1);

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

int withdraw(){ // 출금을 담당하는 함수
  int money;
  printf("Enter money : ");
  scanf("%d", &money);

  back:
  if(money > total_money){
    printf("!limit Excess!\nPlz insert exactly\n");
    goto back;
  }

  return money;
}

int show_Menu(int p){
  int select, n, count;
  printf("1. Coka Cola  2. Pocari Sweat  3. Mountain Dew\n4. cider\t  5. Grape Juice   6. Sparking\n\n");
  scanf("%d", &select);

  back_cu:
  if(select < 1 || select > 6){
    printf("!Insert Error!\nPlz insert exactly\n");
    goto back_cu;
  }

  if(p == 1){
    switch(select){
      case 1:
        n = cola;
        break;

      case 2:
        n = pocari;
        break;

      case 3:
        n = dew;
        break;

      case 4:
        n = cider;
        break;

      case 5:
        n = juice;
        break;

      case 6:
        n = sparking;
        break;

      default:
        printf("Error\n");
        break;
    }

    return n;
  }

  else{
    printf("Enter integer : ");
    scanf("%d", &count);

    switch(select){
      case 1:
        cola_c += count;
        break;

      case 2:
        pocari_c += count;
        break;

      case 3:
        dew_c += count;
        break;

      case 4:
        cider_c += count;
        break;

      case 5:
        juice_c += count;
        break;

      case 6:
        sparking_c += count;
        break;

      default:
        printf("Error\n");
        break;
    }
  }

  return 1;
}