#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void JsonExtract(char json[], char hoten[], char gioitinh[], char sodienthoai[], char email[])
{
    char info[4][100];
    int i;

     //Cat chuoi JSON bang dau ","
    char *token = strtok(json, ",");

   // Tiep tuc cat chuoi cho den khi duoc 4 doan gia tri
    i = 0;
    while (token != NULL)
    {
        strcpy(info[i], token);
        i++;
        token = strtok(NULL, ",");
    }

    char *hoten_token = strtok(info[0], ":");
    strcpy (hoten, strtok(NULL, ":"));

    token = strtok(NULL, ":");
    char *gioitinh_token= strtok(info[1], ":");
    strcpy (gioitinh, strtok(NULL, ":"));

    token = strtok(NULL, ":");
    char *sodienthoai_token= strtok(info[2], ":");
    strcpy (sodienthoai, strtok(NULL, ":"));

    token = strtok(NULL, ":");
    char *email_token= strtok(info[3], ":");
    strcpy (email, strtok(NULL, ":"));

    if (email[strlen(email) -1] == '}')
    {
        email[strlen(email) - 1] = '\0';
    }

}

char *multi_tok(char *input, char *delimiter)
{
    static char *string;
    if(input != NULL)
    {
        string = input;
    }

    if (string == NULL)
    {
        return string;
    }

    char *end = strstr(string, delimiter);
    if (end == NULL)
    {
        char *temp = string;
        string = NULL;
        return temp;
    }
    char *temp = string;

    *end = '\0';
    string = end + strlen(delimiter);
    return temp;
}

int main()
{
    char json[] =  "[{\"hoten\":\"Le Thi My Duyen\",\"gioitinh\":\"nu\",\"sodienthoai\":\"0935777888\",\"email\":\"duyen86@gmail.com\"},
                    "{\"hoten\":\"Tran Trung Thanh\",\"gioitinh\":\"nam\",\"sodienthoai\":\"0976333444\",\"email\":\"thanhtt98.com\"},
                    "{\"hoten\":\"Huynh Anh Hoang\",\"gioitinh\":\"nu\",\"sodienthoai\":\"0939745220\",\"email\":\"hahoang88@gmail.com\"},
                    "{\"hoten\":\"Nguyen Minh Khoi\",\"gioitinh\":\"nam\",\"sodienthoai\":\"0703666777\",\"email\":\"khoimaster@gmail.com\"}]";

  /*  char json[] =   [{\"hoten\":\"Le Thi My Duyen\",\"gioitinh\":\"nu\",\"sodienthoai\":\"0935777888\",\"email\":\"duyen86@gmail.com\"},
                    {\"hoten\":\"Tran Trung Thanh\",\"gioitinh\":\"nam\",\"sodienthoai\":\"0976333444\",\"email\":\"thanhtt98.com\"},
                    {\"hoten\":\"Huynh Anh Hoang\",\"gioitinh\":\"nu\",\"sodienthoai\":\"0939745220\",\"email\":\"hahoang88@gmail.com\"},
                    {\"hoten\":\"Nguyen Minh Khoi\",\"gioitinh\":\"nam\",\"sodienthoai\":\"0703666777\",\"email\":\"khoimaster@gmail.com\"}]";
                    */
    char hoten[100], gioitinh[100], sodienthoai[100], email[100];

    JsonExtract(json, hoten, gioitinh, sodienthoai, email);

    printf("Thong tin cua doi tuong JSON:\n");
    printf("Ho ten    : %s\n", hoten);
    printf("Gioi tinh : %s\n", gioitinh);
    printf("Dien thoai: %s\n", sodienthoai);
    printf("Email     : %s\n", email);
    return 0;
}
