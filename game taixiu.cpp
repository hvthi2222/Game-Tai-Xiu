#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdio.h>
#include <string.h>
#include<io.h>
#include<fcntl.h>
int check_account(char *filename, char *tk, char *mk) {
    char buffer[255];
    char tk1[50];
    char mk1[50];

    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        printf("Loi khi mo tep\n");
        return 0;
    }

    while (fgets(buffer, 255, file) != NULL) {
        sscanf(buffer, "%s %s", tk1, mk1);
        if (strcmp(tk1, tk) == 0 && strcmp(mk1, mk) == 0) {
            fclose(file);
            return 1;
        }
    }

    fclose(file);
    return 0;
}

void taoacc(char *filename) {
    char tk[50];
    char mk[50];

    printf("Nhap tai khoan: ");
    scanf("%s", tk);

    printf("Nhap mat khau: ");
    scanf("%s", mk);

    FILE *file = fopen(filename, "a");
    if (file == NULL) {
        printf("Loi khi mo tep!!!\n");
        return;
    }

    fprintf(file, "%s %s\n", tk, mk);
    printf("Tao tai khoan thanh cong \n");
    fclose(file);
}

int dangNhap(char *filename) {
    char tk[50];
    char mk[50];
    int dangNhapThanhCong = 0;

    printf("Nhap tai khoan: ");
    scanf("%s", tk);

    printf("Nhap mat khau: ");
    scanf("%s", mk);

    if (check_account(filename, tk, mk)) {
        dangNhapThanhCong = 1;
    }

    if (dangNhapThanhCong) {
        printf("Dang nhap thanh cong\n");
        return 1;
    } else {
        printf("Tai khoan mat khau khong ton tai\n");
        printf("Ban co muon tao tai khoan moi? (1.Co/2.Khong) ");
        int xyz;
        scanf(" %d", &xyz);
        if (xyz == 1) {
            taoacc(filename);
            return dangNhap(filename);
        } else {
            return 0;
        }
    }
}
void taixiu(int *tk){
	printf("Nhap so tien ban muon dat cuoc: ");
	int tien,cuoc;
    scanf("%d", &tien);
    printf("Chon loai cuoc (1.Tai / 2.Xiu): ");
    scanf("%d", &cuoc);
    if(cuoc==1){
    	printf("Ket qua: 6 + 2 + 1 = 9\n");
    printf("Chia buon! Ban da thua %d tien\n", tien);
    *tk ==0;
	}
    
	else{
		printf("Ket qua: 6 + 6 + 6 = 18\n");
	printf("Chia buon! Ban da thua %d tien\n", tien);
	*tk==0;
	}
	
}
/*void taixiu(int *tk, int *history, int *size) {
    printf("*****************************************************\n");
    printf("\t\tChoi Tai Xiu\n");
    printf("So du hien tai: %d\n", *tk);
    if (*size > 0) {
        printf("Lich su:\n");
        for (int i = 0; i < *size; i++) {
            if (history[i]) {
                printf("Tai ");
            } else {
                printf("Xiu ");
            }
        }
        printf("\n");
    }

    int tien, cuoc;
    do {
        printf("Nhap so tien ban muon dat cuoc: ");
        scanf("%d", &tien);
        if (tien > *tk) {
            printf("So tien trong tai khoan khong du de dat cuoc!\n");
        }
    } while (tien > *tk);

    printf("Chon loai cuoc (1.Tai / 2.Xiu): ");
    scanf("%d", &cuoc);

    srand(time(NULL));
    int x1 = rand() % 6 + 1;
    int x2 = rand() % 6 + 1;
    int x3 = rand() % 6 + 1;
    int tong = x1 + x2 + x3;

    int thang = rand() % 10 + 1;
    if (thang <= 3) { // 70% thua, 30% thắng
        printf("Ket qua: %d + %d + %d = %d\n", x1, x2, x3, tong);

        if ((tong >= 11 && cuoc == 1) || (tong <= 10 && cuoc == 2)) {
            printf("Chuc mung! Ban da thang %d tien\n", tien);
            *tk += tien;
            history[*size] = 1;
        } else {
            printf("Chia buon! Ban da thua %d tien\n", tien);
            *tk -= tien;
            history[*size] = 0;
        }

        *size += 1;
    } else { // 30% thua, 70% thắng
        printf("Ket qua: %d + %d + %d = %d\n", x1, x2, x3, tong);

        if ((tong >= 11 && cuoc == 1) || (tong <= 10 && cuoc == 2)) {
            printf("Chuc mung! Ban da thang %d tien\n", tien);
            *tk += tien;
           
}}}*/
    

void rut(int *tk) {
    printf("*****************************************************\n");
    printf("* Chon ngan hang cua ban:                           *\n");
    printf("* 1.MB BANK                                         *\n");
    printf("* 2.VIETCOMBANK                                     *\n");
    printf("* 3.TECHCOMBANK                                     *\n");
    printf("* 4.TP BANK                                         *\n");
    printf("* 5.QUAY LAI                                        *\n");
    printf("*****************************************************\n");
    printf("NHAP LUA CHON: ");
    int key3;
    char s[100];
    int stk;
    scanf("%d", &key3);
    switch (key3) {
        case 1:
        	printf("*****************************************************\n");
            printf("MB BANK\n");
            break;
        case 2:
        	printf("*****************************************************\n");
            printf("VIETCOMBANK\n");
            break;
        case 3:
        	printf("*****************************************************\n");
            printf("TECHCOMBANK\n");
            break;
        case 4:
        	printf("*****************************************************\n");
            printf("TP BANK\n");
            break;
        case 5:
            break;
        default:
        	printf("*****************************************************\n");
            printf("Lua chon khong hop le!\n");
            break;
    }
    if (key3 != 5) {
        printf("Nhap thong tin tai khoan rut tien: \n");
        printf("Ten tai khoan huong thu: ");
        fflush(stdin);
        fgets(s, sizeof(s), stdin);
        printf("\nSo tai khoan: ");
        scanf("%d", &stk);
        int t;
        printf("Nhap so tien can rut: ");
        scanf("%d", &t);
        if (t <= *tk) {
            *tk -= t;
            printf("Ban da rut thanh cong %dK tu tai khoan cua ban.\n", t);
            printf("So du moi: %d\n", *tk);
            printf("Ban da rut tien thanh cong vui long cho trong it phut.\n");
        } else {
            printf("So du khong du de thuc hien giao dich.\n");
        }
        printf("*****************************************************\n");
    }
}

void nap(int *t, int *tk) {
    printf("*****************************************************\n");
    printf("* Chon ngan hang cua ban:                           *\n");
    printf("* 1.MB BANK                                         *\n");
    printf("* 2.VIETCOMBANK                                     *\n");
    printf("* 3.TECHCOMBANK                                     *\n");
    printf("* 4.TP BANK                                         *\n");
    printf("* 5.QUAY LAI                                        *\n");
    printf("*****************************************************\n");
    printf("NHAP LUA CHON: ");
    int key;
    scanf("%d", &key);
    switch (key) {
        case 1:
        	printf("*****************************************************\n");
            printf("MB BANK\n");
            break;
        case 2:
        	printf("*****************************************************\n");
            printf("VIETCOMBANK\n");
            break;
        case 3:
        	printf("*****************************************************\n");
            printf("TECHCOMBANK\n");
            break;
        case 4:
        	printf("*****************************************************\n");
            printf("TP BANK\n");
            break;
        case 5:
            break;
        default:
        	printf("*****************************************************\n");
            printf("Lua chon khong hop le!\n");
            break;
    }
    if (key != 5) {
        printf("Nhap so tien: ");
        scanf("%d", t);
        *tk += *t;
        printf("So du moi: %d\n", *tk);
        printf("ND: %d\n", 10000 + rand() % 99999);
        printf("Vui long chuyen khoan den ngan hang: \n");
        printf("STK: 0862618996\n");
        printf("CHU TAI KHOAN: HOANG VAN THI\n");
        printf("CHI NHANH: BAC GIANG\n");
        printf("Cam on\n");
    }
}

int main() {
	char filename[] = "accounts.txt";
	printf("CHAO MUNG BAN DEN VOI GO789.COM NHA CAI UY TIN SO 1 VIET NAM\n");
    dangNhap(filename);
	int history[100];
	int size=0;
    int t, tk = 0;
    srand(time(NULL));
    while (1) {
        printf("\t\t\tGO888 C/C++\n");
        printf("*************************MENU************************\n");
        printf("*   SO DU: %d                                        *\n", tk);
        printf("* 1.NAP TIEN                                        *\n");
        printf("* 2.RUT TIEN                                        *\n");
        printf("* 3.TAI XIU                                         *\n");
        printf("* 4.SICBOOO                                         *\n");
        printf("* 5.Thoat                                           *\n");
        printf("* HOTLINE:0862618996                                *\n");
        printf("*****************************************************\n");

        int key;
        printf("NHAP LUA CHON: ");
        scanf("%d", &key);

        switch (key) {
            case 1:
                nap(&t, &tk);
                break;
            case 2:
                rut(&tk);
                break;
            case 3:
                //taixiu(&tk,history,&size);
                taixiu(&tk);
                break;
            case 4:
                // Code cho chức năng chơi sicbo
                break;
            case 5:
                printf("Tam biet!\n");
                return 0;
            default:
                printf("Lua chon khong hop le!\n");
                break;
        }

        printf("\nNhan ENTER de tiep tuc hoac nhan '5' de thoat chuong trinh.\n");
        char c = getchar();
        if (c == '5') {
            printf("XIN CHAO VA HEN GAP LAI!\n");
            return 0;
        }
    }
}