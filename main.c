#include <stdio.h>


int totalSales = 0;
char menuName[20];
int price, orderQty, userGrade, finalPrice;

void inputOrder() {
    printf("메뉴명: ");   
    scanf(" %[^\n]s", menuName);
    printf("가격: "); 
    scanf("%d", &price);
    printf("수량: "); 
    scanf("%d", &orderQty);
    printf("등급(1:VVIP, 2:VIP, 3:일반): "); 
    scanf("%d", &userGrade);
}


int calculatePrice(int p, int qty, int grade) {
    float rate = 0.0f;
    int total = p * qty;

    // 삼항 연산자 대신 완벽히 배운 if-else문만 사용
    if (grade == 1) {
        rate = 0.20f;
    } else if (grade == 2) {
        rate = 0.10f;
    } else {
        rate = 0.05f;
    }

    return (int)(total * (1.0f - rate));
}


void processPayment(int amount) {
    int cash;
    printf("최종 금액: %d원\n현금 입력: ", amount);
    scanf("%d", &cash);

    if (cash >= amount) {
        printf("결제 완료! 거스름돈: %d원\n", cash - amount);
        totalSales = totalSales + amount; // 전역 변수 값 변경
    } else {
        printf("결제 실패: 금액 부족\n");
    }
}

int main() {
    int choice;

   
    while (1) {
        printf("\n1.주문 2.매출조회 3.종료\n선택: ");
        scanf("%d", &choice);

        if (choice == 3) {
            printf("종료합니다.\n");
            break; // 루프 탈출
        }

        
        if (choice == 1) {
            inputOrder();
            finalPrice = calculatePrice(price, orderQty, userGrade);
            processPayment(finalPrice);
        } 
        else if (choice == 2) {
            printf("현재 누적 총 매출: %d원\n", totalSales);
        } 
        else {
            printf("잘못된 선택입니다.\n");
        }
    }
    return 0;
}
