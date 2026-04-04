/* 
  파일이름: main.c 
  작 성 자:박규현
  하 는 일: 카페 키오스크 주문 관리
*/

#include <stdio.h>

int main()
{
  // --- 1. 변수 선언 (3가지 자료형, 7개의 변수) ---
  char menuName[20] = "바니랄 라떼";       //[문자형] 메뉴 이름
  char cheerUpMsg[50] = "오늘도 당신의 하루를 응원합니다!"; // [문자형] 응원 문구

  int price = 5000;               // [정수형] 메뉴가격
  int orderQty;                   // [정수형] 주문 수량
  float discountRate = 0.05f;     // [실수형] 단골 할인율 (5%)

  int totalPrice;                 // [정수형] 할인 전 총액
  float finalPrice;               // [실수형] 할인 적용 후 최종 금액
  int cashReceived;               // [정수형] 받은 현금
  int change;                     // [정수형] 거스름돈

  // --- 2. 입출력 시작 ---
  printf("====================================\n");
  printf("        CAFE HOPE 키오스크 v1.2       \n");
  printf("====================================\n");
  printf("현재 주문 메뉴: %s (%d원)\n", menuName, price);

  printf("주문하실 수량을 입력해 주세요: ");
  scanf("%d", &orderQty);

  // --- 3. 연산 과정 ---
  totalPrice = price * orderQty;
  // (1.0 - 할인율)을 곱해 최종 금액을 계산 (실수 연산)
  finalPrice = totalPrice * (1.0f - discountRate);

  // --- 4. 주문 확인 및 결제 ---
  printf("\n[주문 확인]\n");
  printf("- 합계 금액:%d원\n" , finalPrice); // 소수점 없이 출력
  printf("--------------------------\n");

  printf("현금을 넣어주세요: ");
  scanf("%d", &cashReceived);

  // 거스름돈 계산 (형변환 주의: 실수를 정수로 계산)
  change = cashReceived -- (int)finalPrice

  // --- 5. 최종 영수증 및 응원 문구 출력 ---
  printf("\n[결제 완료]\n");
  printf("- 받은 금액: %d원\n", cashReceived);
  printf("- 거스름돈 : %d원\n", change);
  printf("------------------------------------\n");

  // 요청하신 응원 문구 출력
  printf("%s\n", cheerUpMsg);
  printf("====================================\n");

  return 0;
}
