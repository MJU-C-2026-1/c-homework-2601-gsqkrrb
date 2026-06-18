/* 
  파일이름: main.c 
  작 성 자:박규현
  하 는 일: 카페 키오스크 주문 관리
*/

#include <stdio.h>

int menuNumber[5];
int prices[5];
int quantities[5];
int finalPrices[5];

int orderCount = 0;

void printAllOrders(int arr[], int count){
    if (count == 0){
        printf("\n저장된 주문 내역이 없습니다.\n");
        return;
    }
    printf("\n==전체 주문 내역 조회 ==\n");
    for(int i = 0; i<count; i++){
        printf("[%d번주문] 메뉴번호: %d번 단가:%d원 수량:%d개 결제금액:%d원\n", i+1, menuNumber[i], prices[i], quantities[i], arr[i]);
    }
    printf("=================================\n");
}


int calculateTotalSalesWithPointer(int *ptr, int count){
    int sum = 0;
    for(int i=0; i<count; i++){
        sum = sum +*(ptr+i);
    }
    return sum;
}

int main(){
    int choice;

    while(1){
        printf("\n--- 카페 키오스크 ---\n");
        printf("1. 주문 입력\n");
        printf("2. 주문 내역 조회\n");
        printf("3. 총 매출 조회\n");
        printf("4. 프로그램 종료\n");
        printf("선택: ");

        if(scanf("%d", &choice) !=1){
            printf("숫자만 입력 가능합니다!\n");

            while(getchar() != '\n');
            continue;
        }
        

        

        if (choice == 4){
            printf("프로그램을 종료합니다.\n");
            break;
        }
        if (choice == 1){
            if (orderCount >= 5) {
                printf("더 이상 주문을 저장할 수 없습니다! \n");
                continue;
            }

            printf("\n[%d번째 주문 입력]\n", orderCount + 1);

            printf("메뉴 번호 :");
            scanf("%d", &menuNumber[orderCount]);

            printf("가격: ");
            scanf("%d", &prices[orderCount]);

            printf("수량: ");
            scanf("%d", &quantities[orderCount]);

            int userGrade;
            printf("등급(1.VVIP, 2:VIP, 3:일반): ");
            scanf("%d", &userGrade);

            float rate = 0.0f;
            int total = prices[orderCount]*quantities[orderCount];

            if(userGrade == 1){
                rate = 0.20f;
            } else if (userGrade == 2){
                rate = 0.10f;
            } else{
                rate = 0.05f;
            }

            int amount = (int)(total*(1.0f - rate));
            finalPrices[orderCount]= amount;

            int cash;
            printf("최종 금액: %d원\n현금입력: ", amount);
            scanf("%d", &cash);

            if (cash >= amount){
                printf("결제 완료! 거스름돈: %d원\n", cash - amount);
                orderCount++;
            }else {
                printf("결제 실패: 금액이 부족하여 주문이 취소되었습니다.\n");
            }
        }
        else if (choice==2){
            printAllOrders(finalPrices, orderCount);
        }
        else if ( choice == 3) {
            int totalSales = calculateTotalSalesWithPointer(finalPrices, orderCount);
            printf("\n현재 누적 총 매출: %d원\n", totalSales);
        }
        else{
            printf("잘못된 선택입니다.\n");
        }
    }

    return 0;
}
