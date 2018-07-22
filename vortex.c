//  main.c
//  C_P
//
//  Created by rpp[t on 2018. 4. 8..
//  Copyright © 2018년 rppt. All rights reserved.
//
//  This is the program encrypting passwords by using my algorithzm.
//  It is called on RPPT_ver0


#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

typedef unsigned long long size_l;

int count_xor_index = 0;
int c;

char hex[] = {0x00, 0x01, 0x02, 0x03
    ,0x04, 0x05, 0x06, 0x07
    ,0x08, 0x09, 0x0a, 0x0b
    ,0x0c, 0x0d, 0x0e, 0x0f
};//in decmials(0<=x<=15)

char * ret_complete_binary(long long _sum_bits)
{ 
   int i;
   int cnt = 0;

   long long copy =  _sum_bits;

   char * encrypted_str = NULL;
for(i =0; sizeof hex; i++)
   {
  if(hex[i] > 0){
    if(_sum_bits % hex[i] == _sum_bits)
      break;
     if(_sum_bits % hex[i] == 0 )
      {
         _sum_bits /=  hex[i];
      }else if(_sum_bits % hex[i] != 0 ){
          _sum_bits += 1;
          _sum_bits /=  hex[i];
         //printf("Integer_2 : %d\n", hex[i]);
        }
      }
   }

  copy = _sum_bits;

   printf("Compress_Binary_Integer  : %lld\n", _sum_bits);
  
   while( 1 ) 
   {
     if(_sum_bits == 1)
       break;
     _sum_bits /= 2;
     cnt++;
   }
   cnt++;
   c= cnt;  
   encrypted_str = (char *)malloc(cnt);

   printf("cnt : %d\n", cnt);
 for(i = 0; i<cnt; i++)
  {
    if(copy %2 == 0) 
       *(encrypted_str + i)  = 1;
    else
       *(encrypted_str + i)  = 0;
         copy /= 2;
   }
  
  return encrypted_str; 
}
size_l ret_binary_num(const char * full_str, int len){
    long long _sum_bits = 0;
    int i, j;

    for(i =len - 1; i >=0 ; i--){
       if(*(full_str + i) == 1)
          _sum_bits += 1 << abs(len - i - 1);
    }
    return  _sum_bits;
}
void print_change_string(const char * str, int len)
{
    char bit[9] = {0,};// bucket to hex
    char * full_bit = (char *)malloc(len * 0x08);
    int count_index = 0;
    int i;
    
    for(i =0; i<len ; i++)
    {
        int t_element =  *(str + i);
        for(int j =0 ; j<0x08; j++){
            if(t_element %2 == 0){
                bit[j] = 0;
            }else{
                bit[j] = 1;
            }
             t_element /= 2;
        }
        for(int k = 0; k<0x08  /2 ; k++)
        {
            int t_str = bit[k];
            bit[k] = bit[0x08 - 0x01 - k];
            bit[0x08 - 0x01 - k] = t_str;
        }
        for(int l = 0; l<0x08; l++){
            full_bit[count_index++] = bit[l];
        }
    }
   
    long long temp = 0;
   printf("sum_bits : %lld\n", temp = ret_binary_num(full_bit, len * 0x08));
    
    fputs("\nDefault_BIT : ", stdout);
    
    for(int m  = 0; m<len * 0x08; m++)
    {
        printf("%d", *(full_bit + m));
    }
    puts("\n");

    fputs("\nCompress_BIT : ", stdout);

    full_bit = ret_complete_binary(temp);
    for(int m  = 0; m<c; m++)
    {
        printf("%d", *(full_bit + m));
    }
      puts("\n");
    free(full_bit);

    return;
}
void encrypt_string(char * str)
{
    int null_index = 0;
    
    printf("string : %s\n\n",  str);
    
    for(int i =0; ; i++){
        printf("value[%d] : %d\n", i , *(str + i));
        if(*(str + i) == 0)
        {
            null_index = i;
            break;
        }
    }
    puts("");
    for(int i=0 ; i<null_index; i++)
    {
        for(int j =0; j<null_index; j++)
        {
            *(str + i) =  *(str + i) ^ hex[j];
            printf("xor String [%d] : %s\n", ++count_xor_index, str);
        }
    }
    print_change_string(str, null_index);
    printf("\nResult  : %s\n", str);
    return;
}
int main(int argc, char * argv[]) {
    char * str = NULL;
    
    if(argc == 2){
        system("figlet Made By rppT");
        str =  argv[argc - 1];
        encrypt_string(str);
    }
    
    return 0;
}

