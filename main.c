/* 
  파일이름: main.c 
  작 성 자:박규현
  하 는 일: 카페 키오스크 주문 관리
*/

#include <stdio.h>

int main()
{
    char menuName[20];
    int price, orderQty, userGrade;
    float discountRate = 0.0f;
    int totalPrice, finalPrice, cashReceived, change = 0;

    printf("========================\n");
    printf("       CAFE 키오스크     \n");
    printf("========================\n");

    printf("\n[1단계: 주문 정보 입력]\n");
    printf("주문하실 메뉴명을 입력하세요: ");
    // %[^\n]s 를 사용하여 띄어쓰기를 허용합니다.
    scanf(" %[^\n]s", menuName); 

    printf("메뉴의 가격을 입력하세요: ");
    scanf("%d", &price);
    printf("주문 수량을 입력하세요: ");
    scanf("%d", &orderQty);

    printf("\n단골 등급을 선택하세요 (1:VVIP, 2:VIP, 3:일반): ");
    scanf("%d", &userGrade);

    if (userGrade == 1){
        discountRate = 0.20f;
    } else if (userGrade == 2) {
        discountRate = 0.10f;
    } else {
        discountRate = 0.05f;
    }

    totalPrice = price * orderQty;
    finalPrice = (int)(totalPrice * (1.0f - discountRate));
    
    printf("\n[2단계: 결제 금액 계산]\n");
    printf("- %s %d개의 총액: %d원\n", menuName, orderQty, totalPrice);
    printf("- 할인율(%.0f%%) 적용 최종 금액: %d원\n", discountRate * 100, finalPrice);

    printf("\n[3단계: 결제 진행]\n");
    printf("현금을 넣어주세요: ");
    scanf("%d", &cashReceived);

    // 중괄호 위치를 정확히 맞췄습니다.
    if (cashReceived >= finalPrice) {
        change = cashReceived - finalPrice;
        
        if (change > 0 && finalPrice >= 50000){
            printf("✨ 대량 주문 감사 서비스를 준비 중입니다. 잠시만 기다려주세요!\n");
        }
        
        printf("\n============================\n");
        printf("           최종 영수증       \n");
        printf("============================\n");
        printf(" 주문 메뉴 : %s\n", menuName);
        printf(" 주문 수량 : %d개\n", orderQty);
        printf(" 결제 금액 : %d원\n", finalPrice);
        printf(" 받은 금액 : %d원\n", cashReceived);
        printf(" 거스름돈  : %d원\n", change);
        printf("-----------------------------\n");
    }
    else {
        printf("\n[결제 실패] 금액이 %d원 부족합니다. 주문이 취소되었습니다.\n", finalPrice - cashReceived);
    }

    printf("오늘도 당신의 하루를 응원합니다!\n");
    printf("=============================\n");
    
    return 0;
}
