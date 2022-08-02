/*-----------------------------------------------------------LIBRARES-----------------------------------------------------------------*/
#include <stdio.h>
#include <string.h>
#include "esp_log.h"
#include "rc522.h"
#include "driver/gpio.h"
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "APP_NETWORK/APP_Network.h"

/*-----------------------------------------------------------DEFINES-----------------------------------------------------------------*/

/*---------RFID----------*/
#define PIN_LED 2
#define PIN_MISO 25
#define PIN_MOSI 23
#define PIN_SDA 22
#define PIN_SCK 19

/*----------------------------------------STRUCTS----------------------------------------------------------*/
typedef struct
{
  char ssid[21];
  char password[21];
} Network_st;

typedef struct Device
{
 char id[5];
 char name[5];
 Network_st conection
} Device ;

/*----------------------------------------FUNCTIONS--------------------------------------------------------*/

void tag_handler(uint8_t *serial_no){

  printf("RFID on\n");
  for(int i = 0; i < 5; i++){
    printf("%#x", serial_no[i]);
  }

  printf("\n");
}

Network_st setNetwork(char * ssid, char * password)
{
    Network_st conection;
    strcpy( conection.ssid,ssid);   
    strcpy( conection.password,password);
    return conection;
}

Device setDevice(char * id, char * name , Network_st conection){
    Device device;
    strcpy( device.id,id);
    strcpy( device.name,name);
    device.conection = conection;
    return device;
}

void app_main(void){
  const rc522_start_args_t start_args = {
    .miso_io  = PIN_MISO,
    .mosi_io  = PIN_MOSI,
    .sck_io   = PIN_SCK,
    .sda_io   = PIN_SDA,
    .callback = &tag_handler

  };

   Network_st network_config = setNetwork ("Lieno", "ijta1920");
  
  printf("RFID initialize\n");
  rc522_start(start_args);
  network_start(network_config.ssid, network_config.password);
}
