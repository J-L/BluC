#define HC05_TRANSPARENT 0
#define HC05_CONFIGURATION 1

#define ON 1
#define OFF 0

#define MASTER 0
#define SLAVE 1


#define READY 2
#define CONNECTING 3
#define CONNECTED 4
#define INQUIRING 5
#define INITIALIZED 6
#define PAIRABLE 7
#define PAIRING 8
#define DISCONNECTED 9

#define HC05_CHECK_MODE 0x00
#define HC05_SET_MODE 0x01
#define HC05_CHECK_POWER 0x01
#define HC05_SET_POWER 0x02
#define HC05_CHECK_STATE 0x03
#define HC05_SET_STATE 0x04
#define HC05_SET_BAUD_RATE 0x05
#define HC05_SET_STATE 0x06
#define HC05_SET_NAME 0x07
#define HC05_CHECK_NAME 0x08
#define HC05_CHECK_PSWD 0x0A
#define HC05_CHECK_MAC 0x0B
#define HC05_SET_NAME 0x0C



int btCommand =0;

struct bluetoothState{
        int mode;
        int power;
        int state;
        char name[8];
        char pswd[4];
        char mac[8];
}hc05={HC05_TRANSPARENT,OFF, OFF, "TEST","1234" "00000000"};



