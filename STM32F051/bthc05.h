#define BT_TRANSPARENT 0
#define BT_CONFIGURATION 1

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

#define BT_CHECK_MODE 	0x0
#define BT_SET_MODE 	0xD
#define BT_CHECK_POWER 	0x01
#define BT_SET_POWER 	0x02
#define BT_CHECK_STATE 	0x03
#define BT_SET_STATE 	0x04
#define BT_SET_BAUD_RATE 0x05
#define BT_SET_STATE 	0x06
#define BT_SET_NAME 	0x07
#define BT_CHECK_NAME 	0x08
#define BT_CHECK_PSWD 	0x0A
#define BT_CHECK_MAC 	0x0B
#define BT_SET_NAME 	0x0C



int btCommand =0;


struct bluetoothState{
        int mode;
        int power;
        int state;
        char name[8];
        char pswd[4];
        char mac[8];
}hc05={HC05_TRANSPARENT,OFF, OFF, "TEST","1234" "00000000"};


int btSetupSerial(int);
int btCheckMode(void);
int btSetMode(int);
int btCheckPower(void);
int btSetPower(int);
int btCheckConnected(int);
int btSetup(BaseSequentialStream);
int btCheckRole(BaseSequentialStream);
int btSetRole(BaseSequentialStream, int);
int btFindDevName(BaseSequentialStream);
int btSetPassword(int);
int btCheckPassword(BaseSequentialStream *);
int btCheckMyName(BaseSequentialStream *);
int btMakeConnection(BaseSequentialStream *);
int btBreakConnection(BaseSequentialStream *);
int btSetBaudRate(BaseSequentialStream *,int);
int btReset(int);
int btSetClass(int);
int btCheckClass(void);
int btCheckStatus(BaseSequentialStream *);
int btResponseCallBack(void);
int btParseParameters(BaseSequentialStream *, int);
